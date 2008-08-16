/** 
 * @file llvoicevisualizer.cpp
 * @brief Draws in-world speaking indicators.
 *
 * $LicenseInfo:firstyear=2000&license=viewergpl$
 * 
 * Copyright (c) 2000-2008, Linden Research, Inc.
 * 
 * Second Life Viewer Source Code
 * The source code in this file ("Source Code") is provided by Linden Lab
 * to you under the terms of the GNU General Public License, version 2.0
 * ("GPL"), unless you have obtained a separate licensing agreement
 * ("Other License"), formally executed by you and Linden Lab.  Terms of
 * the GPL can be found in doc/GPL-license.txt in this distribution, or
 * online at http://secondlifegrid.net/programs/open_source/licensing/gplv2
 * 
 * There are special exceptions to the terms and conditions of the GPL as
 * it is applied to this Source Code. View the full text of the exception
 * in the file doc/FLOSS-exception.txt in this software distribution, or
 * online at http://secondlifegrid.net/programs/open_source/licensing/flossexception
 * 
 * By copying, modifying or distributing this software, you acknowledge
 * that you have read and understood your obligations described above,
 * and agree to abide by those obligations.
 * 
 * ALL LINDEN LAB SOURCE CODE IS PROVIDED "AS IS." LINDEN LAB MAKES NO
 * WARRANTIES, EXPRESS, IMPLIED OR OTHERWISE, REGARDING ITS ACCURACY,
 * COMPLETENESS OR PERFORMANCE.
 * $/LicenseInfo$
 */

//----------------------------------------------------------------------
// Voice Visualizer
// author: JJ Ventrella
// (information about this stuff can be found in "llvoicevisualizer.h")
//----------------------------------------------------------------------
#include "llviewerprecompiledheaders.h"
#include "llviewercontrol.h"
#include "llglheaders.h"
#include "llsphere.h"
#include "llvoicevisualizer.h"
#include "llviewercamera.h"
#include "llviewerobject.h"
#include "llimagegl.h"
#include "llviewerimage.h"
#include "llviewerimagelist.h"
#include "llvoiceclient.h"
#include "llglimmediate.h"

//brent's wave image
//29de489d-0491-fb00-7dab-f9e686d31e83


//--------------------------------------------------------------------------------------
// sound symbol constants
//--------------------------------------------------------------------------------------
const F32	HEIGHT_ABOVE_HEAD	= 0.3f;		// how many meters vertically above the av's head the voice symbol will appear
const F32	RED_THRESHOLD		= LLVoiceClient::OVERDRIVEN_POWER_LEVEL;		// value above which speaking amplitude causes the voice symbol to turn red
const F32	GREEN_THRESHOLD		= 0.2f;		// value above which speaking amplitude causes the voice symbol to turn green
const F32	FADE_OUT_DURATION	= 0.4f;		// how many seconds it takes for a pair of waves to fade away
const F32	EXPANSION_RATE		= 1.0f;		// how many seconds it takes for the waves to expand to twice their original size
const F32	EXPANSION_MAX		= 1.5f;		// maximum size scale to which the waves can expand before popping back to 1.0 
const F32	WAVE_WIDTH_SCALE	= 0.03f;	// base width of the waves 
const F32	WAVE_HEIGHT_SCALE	= 0.02f;	// base height of the waves 
const F32	BASE_BRIGHTNESS		= 0.7f;		// gray level of the voice indicator when quiet (below green threshold)
const F32	DOT_SIZE			= 0.05f;	// size of the dot billboard texture
const F32	DOT_OPACITY			= 0.7f;		// how opaque the dot is
const F32	WAVE_MOTION_RATE	= 1.5f;		// scalar applied to consecutive waves as a function of speaking amplitude

//--------------------------------------------------------------------------------------
// gesticulation constants
//--------------------------------------------------------------------------------------
const F32 DEFAULT_MINIMUM_GESTICULATION_AMPLITUDE	= 0.2f; 
const F32 DEFAULT_MAXIMUM_GESTICULATION_AMPLITUDE	= 1.0f;

//--------------------------------------------------------------------------------------
// other constants
//--------------------------------------------------------------------------------------
const F32 ONE_HALF = 1.0f; // to clarify intent and reduce magic numbers in the code. 
const LLVector3 WORLD_UPWARD_DIRECTION = LLVector3( 0.0f, 0.0f, 1.0f ); // Z is up in SL

//-----------------------------------------------
// constructor
//-----------------------------------------------
LLVoiceVisualizer::LLVoiceVisualizer( const U8 type )
:LLHUDEffect( type )
{
	mCurrentTime					= mTimer.getTotalSeconds();
	mPreviousTime					= mCurrentTime;
	mVoiceSourceWorldPosition		= LLVector3( 0.0f, 0.0f, 0.0f );
	mSpeakingAmplitude				= 0.0f;
	mCurrentlySpeaking				= false;
	mVoiceEnabled					= false;
	mMinGesticulationAmplitude		= DEFAULT_MINIMUM_GESTICULATION_AMPLITUDE;
	mMaxGesticulationAmplitude		= DEFAULT_MAXIMUM_GESTICULATION_AMPLITUDE;
	mSoundSymbol.mActive			= true;
	mSoundSymbol.mPosition			= LLVector3( 0.0f, 0.0f, 0.0f );
	
	mTimer.reset();
	
	const char* sound_level_img[] = 
	{
		"041ee5a0-cb6a-9ac5-6e49-41e9320507d5.j2c",
		"29de489d-0491-fb00-7dab-f9e686d31e83.j2c",
		"29de489d-0491-fb00-7dab-f9e686d31e83.j2c",
		"29de489d-0491-fb00-7dab-f9e686d31e83.j2c",
		"29de489d-0491-fb00-7dab-f9e686d31e83.j2c",
		"29de489d-0491-fb00-7dab-f9e686d31e83.j2c",															
		"29de489d-0491-fb00-7dab-f9e686d31e83.j2c"
	};

	for (int i=0; i<NUM_VOICE_SYMBOL_WAVES; i++)
	{
		mSoundSymbol.mWaveFadeOutStartTime	[i] = mCurrentTime;
		mSoundSymbol.mTexture				[i] = gImageList.getImageFromFile(sound_level_img[i], FALSE, TRUE);
		mSoundSymbol.mWaveActive			[i] = false;
		mSoundSymbol.mWaveOpacity			[i] = 1.0f;
		mSoundSymbol.mWaveExpansion			[i] = 1.0f;
	}
			
}//---------------------------------------------------

//---------------------------------------------------
void LLVoiceVisualizer::setMinGesticulationAmplitude( F32 m )
{
	mMinGesticulationAmplitude = m;

}//---------------------------------------------------

//---------------------------------------------------
void LLVoiceVisualizer::setMaxGesticulationAmplitude( F32 m )
{
	mMaxGesticulationAmplitude = m;

}//---------------------------------------------------

//---------------------------------------------------
void LLVoiceVisualizer::setVoiceEnabled( bool v )
{
	mVoiceEnabled = v;

}//---------------------------------------------------

//---------------------------------------------------
void LLVoiceVisualizer::setStartSpeaking()
{
	mCurrentlySpeaking		= true;
	mSoundSymbol.mActive	= true;
		
}//---------------------------------------------------


//---------------------------------------------------
bool LLVoiceVisualizer::getCurrentlySpeaking()
{
	return mCurrentlySpeaking;
	
}//---------------------------------------------------


//---------------------------------------------------
void LLVoiceVisualizer::setStopSpeaking()
{
	mCurrentlySpeaking = false;
	mSpeakingAmplitude = 0.0f;
	
}//---------------------------------------------------


//---------------------------------------------------
void LLVoiceVisualizer::setSpeakingAmplitude( F32 a )
{
	mSpeakingAmplitude = a;
	
}//---------------------------------------------------


//---------------------------------------------------
// this method is inherited from HUD Effect
//---------------------------------------------------
void LLVoiceVisualizer::render()
{
	if ( ! mVoiceEnabled )
	{
		return;
	}
	
	if ( mSoundSymbol.mActive ) 
	{				
		mPreviousTime = mCurrentTime;
		mCurrentTime = mTimer.getTotalSeconds();
	
		//---------------------------------------------------------------
		// set the sound symbol position over the source (avatar's head)
		//---------------------------------------------------------------
		mSoundSymbol.mPosition = mVoiceSourceWorldPosition + WORLD_UPWARD_DIRECTION * HEIGHT_ABOVE_HEAD;
	
		//---------------------------------------------------------------
		// some gl state
		//---------------------------------------------------------------
		LLGLSPipelineAlpha alpha_blend;
		LLGLDepthTest depth(GL_TRUE, GL_FALSE);
		
		//-------------------------------------------------------------
		// create coordinates of the geometry for the dot
		//-------------------------------------------------------------
		LLVector3 l	= LLViewerCamera::getInstance()->getLeftAxis() * DOT_SIZE;
		LLVector3 u	= LLViewerCamera::getInstance()->getUpAxis()   * DOT_SIZE;

		LLVector3 bottomLeft	= mSoundSymbol.mPosition + l - u;
		LLVector3 bottomRight	= mSoundSymbol.mPosition - l - u;
		LLVector3 topLeft		= mSoundSymbol.mPosition + l + u;
		LLVector3 topRight		= mSoundSymbol.mPosition - l + u;
		
		//-----------------------------
		// bind texture 0 (the dot)
		//-----------------------------
		mSoundSymbol.mTexture[0]->bind(); 
		
		//-------------------------------------------------------------
		// now render the dot
		//-------------------------------------------------------------
		gGL.color4fv( LLColor4( 1.0f, 1.0f, 1.0f, DOT_OPACITY ).mV );	
		
		gGL.begin( LLVertexBuffer::TRIANGLE_STRIP );
			gGL.texCoord2i( 0,	0	); gGL.vertex3fv( bottomLeft.mV );
			gGL.texCoord2i( 1,	0	); gGL.vertex3fv( bottomRight.mV );
			gGL.texCoord2i( 0,	1	); gGL.vertex3fv( topLeft.mV );
		gGL.end();

		gGL.begin( LLVertexBuffer::TRIANGLE_STRIP );
			gGL.texCoord2i( 1,	0	); gGL.vertex3fv( bottomRight.mV );
			gGL.texCoord2i( 1,	1	); gGL.vertex3fv( topRight.mV );
			gGL.texCoord2i( 0,	1	); gGL.vertex3fv( topLeft.mV );
		gGL.end();
		
		
		
		//--------------------------------------------------------------------------------------
		// if currently speaking, trigger waves (1 through 6) based on speaking amplitude
		//--------------------------------------------------------------------------------------
		if ( mCurrentlySpeaking )
		{
			F32 min = 0.2f;
			F32 max = 0.7f;
			F32 fraction = ( mSpeakingAmplitude - min ) / ( max - min );
		
			// in case mSpeakingAmplitude > max....
			if ( fraction > 1.0f )
			{
				fraction = 1.0f;
			}
														
			S32 level = 1 + (int)( fraction * ( NUM_VOICE_SYMBOL_WAVES - 2 ) );
																										
			for (int i=0; i<level+1; i++)
			{
				mSoundSymbol.mWaveActive			[i] = true;
				mSoundSymbol.mWaveOpacity			[i] = 1.0f;
				mSoundSymbol.mWaveFadeOutStartTime	[i] = mCurrentTime;
			}			
			
		} // if currently speaking
								
		//---------------------------------------------------
		// determine color
		//---------------------------------------------------
		F32 red		= 0.0f;
		F32 green	= 0.0f;
		F32 blue	= 0.0f;
        if ( mSpeakingAmplitude < RED_THRESHOLD )
        {
			if ( mSpeakingAmplitude < GREEN_THRESHOLD )
			{
				red		= BASE_BRIGHTNESS;
				green	= BASE_BRIGHTNESS;
				blue	= BASE_BRIGHTNESS;
			}
			else
			{
				//---------------------------------------------------
				// fade from gray to bright green
				//---------------------------------------------------
				F32 fraction = ( mSpeakingAmplitude - GREEN_THRESHOLD ) / ( 1.0f - GREEN_THRESHOLD );
				red		= BASE_BRIGHTNESS - ( fraction * BASE_BRIGHTNESS );
				green	= BASE_BRIGHTNESS +   fraction * ( 1.0f - BASE_BRIGHTNESS );
				blue	= BASE_BRIGHTNESS - ( fraction * BASE_BRIGHTNESS );
			}
        }
        else
        {
			//---------------------------------------------------
			// redish
			//---------------------------------------------------
			red		= 1.0f;
			green	= 0.2f;
			blue	= 0.2f;
        }
														
		for (int i=0; i<NUM_VOICE_SYMBOL_WAVES; i++)
		{
			if ( mSoundSymbol.mWaveActive[i] ) 
			{
				F32 fadeOutFraction = (F32)( mCurrentTime - mSoundSymbol.mWaveFadeOutStartTime[i] ) / FADE_OUT_DURATION;

				mSoundSymbol.mWaveOpacity[i] = 1.0f - fadeOutFraction;
				
				if ( mSoundSymbol.mWaveOpacity[i] < 0.0f )
				{
					mSoundSymbol.mWaveFadeOutStartTime	[i] = mCurrentTime;
					mSoundSymbol.mWaveOpacity			[i] = 0.0f;
					mSoundSymbol.mWaveActive			[i] = false;
				}
				
				//----------------------------------------------------------------------------------
				// This is where we calculate the expansion of the waves - that is, the
				// rate at which they are scaled greater than 1.0 so that they grow over time.
				//----------------------------------------------------------------------------------
				F32 timeSlice = (F32)( mCurrentTime - mPreviousTime );
				F32 waveSpeed = mSpeakingAmplitude * WAVE_MOTION_RATE;
				mSoundSymbol.mWaveExpansion[i] *= ( 1.0f + EXPANSION_RATE * timeSlice * waveSpeed );
				
				if ( mSoundSymbol.mWaveExpansion[i] > EXPANSION_MAX )
				{
					mSoundSymbol.mWaveExpansion[i] = 1.0f;
				}			
								
				//----------------------------------------------------------------------------------
				// create geometry for the wave billboard textures
				//----------------------------------------------------------------------------------
				F32 width	= i * WAVE_WIDTH_SCALE  * mSoundSymbol.mWaveExpansion[i];
				F32 height	= i * WAVE_HEIGHT_SCALE * mSoundSymbol.mWaveExpansion[i];

				LLVector3 l	= LLViewerCamera::getInstance()->getLeftAxis() * width;
				LLVector3 u	= LLViewerCamera::getInstance()->getUpAxis()   * height;

				LLVector3 bottomLeft	= mSoundSymbol.mPosition + l - u;
				LLVector3 bottomRight	= mSoundSymbol.mPosition - l - u;
				LLVector3 topLeft		= mSoundSymbol.mPosition + l + u;
				LLVector3 topRight		= mSoundSymbol.mPosition - l + u;
							
				gGL.color4fv( LLColor4( red, green, blue, mSoundSymbol.mWaveOpacity[i] ).mV );		
				mSoundSymbol.mTexture[i]->bind();
				
				//---------------------------------------------------
				// now, render the mofo
				//---------------------------------------------------
				gGL.begin( LLVertexBuffer::TRIANGLE_STRIP );
					gGL.texCoord2i( 0, 0 ); gGL.vertex3fv( bottomLeft.mV );
					gGL.texCoord2i( 1, 0 ); gGL.vertex3fv( bottomRight.mV );
					gGL.texCoord2i( 0, 1 ); gGL.vertex3fv( topLeft.mV );
				gGL.end();

				gGL.begin( LLVertexBuffer::TRIANGLE_STRIP );
					gGL.texCoord2i( 1, 0 ); gGL.vertex3fv( bottomRight.mV );
					gGL.texCoord2i( 1, 1 ); gGL.vertex3fv( topRight.mV );
					gGL.texCoord2i( 0, 1 ); gGL.vertex3fv( topLeft.mV );
				gGL.end();
				
			} //if ( mSoundSymbol.mWaveActive[i] ) 
			
		}// for loop
											
	}//if ( mSoundSymbol.mActive ) 

}//---------------------------------------------------





//---------------------------------------------------
void LLVoiceVisualizer::setVoiceSourceWorldPosition( const LLVector3 &p )
{
	mVoiceSourceWorldPosition	= p;

}//---------------------------------------------------

//---------------------------------------------------
VoiceGesticulationLevel LLVoiceVisualizer::getCurrentGesticulationLevel()
{
	VoiceGesticulationLevel gesticulationLevel = VOICE_GESTICULATION_LEVEL_OFF; //default
	
	//-----------------------------------------------------------------------------------------
	// Within the range of gesticulation amplitudes, the sound signal is split into
	// three equal amplitude regimes, each specifying one of three gesticulation levels.
	//-----------------------------------------------------------------------------------------
	F32 range = mMaxGesticulationAmplitude - mMinGesticulationAmplitude;
	
			if ( mSpeakingAmplitude > mMinGesticulationAmplitude + range * 0.66666f	)	{ gesticulationLevel = VOICE_GESTICULATION_LEVEL_HIGH;		}
	else	if ( mSpeakingAmplitude > mMinGesticulationAmplitude + range * 0.33333f	)	{ gesticulationLevel = VOICE_GESTICULATION_LEVEL_MEDIUM;	}
	else	if ( mSpeakingAmplitude > mMinGesticulationAmplitude + range * 0.00000f	)	{ gesticulationLevel = VOICE_GESTICULATION_LEVEL_LOW;		}

	return gesticulationLevel;

}//---------------------------------------------------



//------------------------------------
// Destructor
//------------------------------------
LLVoiceVisualizer::~LLVoiceVisualizer()
{
}//----------------------------------------------


//---------------------------------------------------
// "packData" is inherited from HUDEffect
//---------------------------------------------------
void LLVoiceVisualizer::packData(LLMessageSystem *mesgsys)
{
	// Pack the default data
	LLHUDEffect::packData(mesgsys);

	// TODO -- pack the relevant data for voice effects
	// we'll come up with some cool configurations....TBD
	//U8 packed_data[41];
	//mesgsys->addBinaryDataFast(_PREHASH_TypeData, packed_data, 41);
	U8 packed_data = 0;
	mesgsys->addBinaryDataFast(_PREHASH_TypeData, &packed_data, 1);
}


//---------------------------------------------------
// "unpackData" is inherited from HUDEffect
//---------------------------------------------------
void LLVoiceVisualizer::unpackData(LLMessageSystem *mesgsys, S32 blocknum)
{
	// TODO -- find the speaker, unpack binary data, set the properties of this effect
	/*
	LLHUDEffect::unpackData(mesgsys, blocknum);
	LLUUID source_id;
	LLUUID target_id;
	S32 size = mesgsys->getSizeFast(_PREHASH_Effect, blocknum, _PREHASH_TypeData);
	if (size != 1)
	{
		llwarns << "Voice effect with bad size " << size << llendl;
		return;
	}
	mesgsys->getBinaryDataFast(_PREHASH_Effect, _PREHASH_TypeData, packed_data, 1, blocknum);
	*/
}


//------------------------------------------------------------------
// this method is inherited from HUD Effect
//------------------------------------------------------------------
void LLVoiceVisualizer::markDead()
{
	mCurrentlySpeaking		= false;
	mVoiceEnabled			= false;
	mSoundSymbol.mActive	= false;

	LLHUDEffect::markDead();
}//------------------------------------------------------------------








