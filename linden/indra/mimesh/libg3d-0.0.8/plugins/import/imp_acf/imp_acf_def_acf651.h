/* $Id:$ */

/*
    libg3d - 3D object loading library

    Copyright (C) 2005-2009  Markus Dahms <mad@automagically.de>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
#ifndef _IMP_ACF_DEF_ACF651_H
#define _IMP_ACF_DEF_ACF651_H

#include "imp_acf_def_proto.h"

static const AcfDef acf_def_acf651[] = {
	{ XCHR, "VIEW__PlatForm",                           1 },
	{ XCHR, "VIEW__Filler",                             4 },
	{ XCHR, "VIEW__tailnum",                           40 },
	{ XCHR, "VIEW__author",                           500 },
	{ XCHR, "VIEW__descrip",                          500 },
	{ XFLT, "VIEW__size_x",                             1 },
	{ XFLT, "VIEW__size_z",                             1 },
	{ XINT, "VIEW__is_APL",                             1 },
	{ XINT, "VIEW__actype",                             1 },
	{ XINT, "VIEW__HUDtype",                            1 },
	{ XINT, "VIEW__asi_kts",                            1 },
	{ XINT, "VIEW__cockpit_type",                       1 },
	{ XINT, "VIEW__has_SC_fd",                          1 },
	{ XINT, "VIEW__has_stallwarn",                      1 },
	{ XINT, "VIEW__has_litemap_tex",                    1 },
	{ XFLT, "VIEW__peX",                                1 },
	{ XFLT, "VIEW__peY",                                1 },
	{ XFLT, "VIEW__peZ",                                1 },
	{ XFLT, "VIEW__Vso",                                1 },
	{ XFLT, "VIEW__Vs",                                 1 },
	{ XFLT, "VIEW__Vfe",                                1 },
	{ XFLT, "VIEW__Vno",                                1 },
	{ XFLT, "VIEW__Vne",                                1 },
	{ XFLT, "VIEW__Mmo",                                1 },
	{ XFLT, "VIEW__Gneg",                               1 },
	{ XFLT, "VIEW__Gpos",                               1 },
	{ XFLT, "VIEW__est_Vs",                             1 },
	{ XFLT, "VIEW__yawstringx",                         1 },
	{ XFLT, "VIEW__yawstringy",                         1 },
	{ XFLT, "VIEW__HUD_cntr",                           1 },
	{ XFLT, "VIEW__HUD_cntry",                          1 },
	{ XFLT, "VIEW__HUD_del",                            1 },
	{ XFLT, "VIEW__HUD_dely",                           1 },
	{ XINT, "VIEW__has_lanlite1",                       1 },
	{ XFLT, "VIEW__lanlite1X",                          1 },
	{ XFLT, "VIEW__lanlite1Y",                          1 },
	{ XFLT, "VIEW__lanlite1Z",                          1 },
	{ XFLT, "VIEW__lanlite_the",                        1 },
	{ XINT, "VIEW__has_lanlite2",                       1 },
	{ XFLT, "VIEW__lanlite2X",                          1 },
	{ XFLT, "VIEW__lanlite2Y",                          1 },
	{ XFLT, "VIEW__lanlite2Z",                          1 },
	{ XINT, "VIEW__has_lanlite3",                       1 },
	{ XFLT, "VIEW__lanlite3X",                          1 },
	{ XFLT, "VIEW__lanlite3Y",                          1 },
	{ XFLT, "VIEW__lanlite3Z",                          1 },
	{ XINT, "VIEW__has_fuserb1",                        1 },
	{ XFLT, "VIEW__fuserb1",                            1 },
	{ XFLT, "VIEW__fuserb1",                            1 },
	{ XFLT, "VIEW__fuserb1Z",                           1 },
	{ XINT, "VIEW__has_fuserb2",                        1 },
	{ XFLT, "VIEW__fuserb2",                            1 },
	{ XFLT, "VIEW__fuserb2",                            1 },
	{ XFLT, "VIEW__fuserb2Z",                           1 },
	{ XINT, "VIEW__has_taillite",                       1 },
	{ XFLT, "VIEW__tailliteX",                          1 },
	{ XFLT, "VIEW__tailliteY",                          1 },
	{ XFLT, "VIEW__tailliteZ",                          1 },
	{ XINT, "VIEW__has_navlites",                       1 },
	{ XINT, "PANEL_ins_type",                         200 },
	{ XFLT, "PANEL_ins_size",                         200 },
	{ XFLT, "PANEL_ins_x",                            200 },
	{ XFLT, "PANEL_ins_y",                            200 },
	{ XFLT, "PANEL_ins_delx",                         200 },
	{ XFLT, "PANEL_ins_dely",                         200 },
	{ XINT, "FORCE_Hydraulic",                          1 },
	{ XINT, "FORCE_Stickshaker",                        1 },
	{ XINT, "ENG___num_engines",                        1 },
	{ XINT, "ENG___auto_feather_EQ",                    1 },
	{ XFLT, "ENG___throtmax_FW",                        1 },
	{ XFLT, "ENG___throtmax_REV",                       1 },
	{ XFLT, "ENG___RSC_idlespeed_en",                   1 },
	{ XFLT, "ENG___RSC_redline_eng",                    1 },
	{ XFLT, "ENG___RSC_mingreen_eng",                   1 },
	{ XFLT, "ENG___RSC_maxgreen_eng",                   1 },
	{ XFLT, "ENG___pmax",                               1 },
	{ XFLT, "ENG___tmax",                               1 },
	{ XFLT, "ENG___burnerinc",                          1 },
	{ XFLT, "ENG___critalt",                            1 },
	{ XFLT, "ENG___mpmax",                              1 },
	{ XFLT, "ENG___gearrat",                            1 },
	{ XFLT, "ENG___face_jet",                           1 },
	{ XFLT, "ENG___face_rocket",                        1 },
	{ XFLT, "ENG___spooltime_jet",                      1 },
	{ XFLT, "ENG___max_mach_eff",                       1 },
	{ XFLT, "ENG___fmax_sl",                            1 },
	{ XFLT, "ENG___fmax_opt",                           1 },
	{ XFLT, "ENG___fmax_vac",                           1 },
	{ XFLT, "ENG___h_opt",                              1 },
	{ XFLT, "ENG___tip_mach_des_50",                    1 },
	{ XFLT, "ENG___tip_mach_des_100",                   1 },
	{ XFLT, "ENG___rotor_mi_rat",                       1 },
	{ XFLT, "ENG___tip_weight",                         1 },
	{ XFLT, "ENG___tail_or_main_omegarat",              1 },
	{ XINT, "PROP__engine_type",                        8 },
	{ XINT, "PROP__revthrust_eq",                       8 },
	{ XINT, "PROP__prop_type",                          8 },
	{ XFLT, "PROP__prop_dir",                           8 },
	{ XFLT, "PROP__num_blades",                         8 },
	{ XFLT, "PROP__SFC",                                8 },
	{ XFLT, "PROP__minpitch",                           8 },
	{ XFLT, "PROP__maxpitch",                           8 },
	{ XFLT, "PROP__revpitch",                           8 },
	{ XFLT, "PROP__sidecant",                           8 },
	{ XFLT, "PROP__vertcant",                           8 },
	{ XFLT, "PROP__propmass",                           8 },
	{ XFLT, "PROP__miprop_RPM",                         8 },
	{ XFLT, "PROP__discarea",                           8 },
	{ XFLT, "PROP__ringarea",                          80 },
	{ XFLT, "PROP__bladesweep",                        80 },
	{ XFLT, "PROP__des_rpm_prp",                        8 },
	{ XFLT, "PROP__des_kts_prp",                        8 },
	{ XFLT, "PROP__des_kts_acf",                        8 },
	{ XINT, "PARTS_part_eq",                           57 },
	{ XCHR, "PARTS_Rafl0",                           2280 },
	{ XCHR, "PARTS_Rafl1",                           2280 },
	{ XCHR, "PARTS_Tafl0",                           2280 },
	{ XCHR, "PARTS_Tafl1",                           2280 },
	{ XINT, "PARTS_els",                               57 },
	{ XFLT, "PARTS_Xarm",                              57 },
	{ XFLT, "PARTS_Yarm",                              57 },
	{ XFLT, "PARTS_Zarm",                              57 },
	{ XFLT, "PARTS_X_body_aero",                       57 },
	{ XFLT, "PARTS_Y_body_aero",                       57 },
	{ XFLT, "PARTS_Z_body_aero",                       57 },
	{ XFLT, "PARTS_Croot",                             57 },
	{ XFLT, "PARTS_Ctip",                              57 },
	{ XFLT, "PARTS_dihed",                             57 },
	{ XFLT, "PARTS_sweep1",                            57 },
	{ XFLT, "PARTS_sweep2",                            57 },
	{ XFLT, "PARTS_sweepnow",                          57 },
	{ XINT, "PARTS_varsweepEQ",                        57 },
	{ XFLT, "PARTS_semilen_SEG",                       57 },
	{ XFLT, "PARTS_semilen_JND",                       57 },
	{ XFLT, "PARTS_e",                                 57 },
	{ XFLT, "PARTS_AR",                                57 },
	{ XFLT, "PARTS_al_D_al0",                          57 },
	{ XFLT, "PARTS_cl_D_cl0",                          57 },
	{ XFLT, "PARTS_cm_D_cm0",                          57 },
	{ XFLT, "PARTS_delta_fac",                         57 },
	{ XFLT, "PARTS_spec_wash",                         57 },
	{ XFLT, "PARTS_alpha_max",                         57 },
	{ XFLT, "PARTS_slat_effect",                       57 },
	{ XFLT, "PARTS_s",                                570 },
	{ XFLT, "PARTS_mac",                              570 },
	{ XFLT, "PARTS_anginc",                           570 },
	{ XINT, "PARTS_ail1",                             570 },
	{ XINT, "PARTS_ail2",                             570 },
	{ XINT, "PARTS_splr",                             570 },
	{ XINT, "PARTS_flap",                             570 },
	{ XINT, "PARTS_flapEQ",                             1 },
	{ XINT, "PARTS_slat",                             570 },
	{ XINT, "PARTS_slatEQ",                             1 },
	{ XINT, "PARTS_sbrk",                             570 },
	{ XINT, "PARTS_sbrkEQ",                             1 },
	{ XINT, "PARTS_drud",                             570 },
	{ XINT, "PARTS_elev",                             570 },
	{ XINT, "PARTS_rudd",                             570 },
	{ XINT, "PARTS_in_downwash",                     32490 },
	{ XFLT, "PARTS_body_r",                            57 },
	{ XFLT, "PARTS_body_X",                          20520 },
	{ XFLT, "PARTS_body_Y",                          20520 },
	{ XFLT, "PARTS_body_Z",                          20520 },
	{ XINT, "PARTS_gear_type",                         57 },
	{ XFLT, "PARTS_gear_latE",                         57 },
	{ XFLT, "PARTS_gear_lonE",                         57 },
	{ XFLT, "PARTS_gear_axiE",                         57 },
	{ XFLT, "PARTS_gear_latR",                         57 },
	{ XFLT, "PARTS_gear_lonR",                         57 },
	{ XFLT, "PARTS_gear_axiR",                         57 },
	{ XFLT, "PARTS_gear_latN",                         57 },
	{ XFLT, "PARTS_gear_lonN",                         57 },
	{ XFLT, "PARTS_gear_axiN",                         57 },
	{ XFLT, "PARTS_gear_leglen",                       57 },
	{ XFLT, "PARTS_gear_tirrad",                       57 },
	{ XFLT, "PARTS_gearcon",                           57 },
	{ XFLT, "PARTS_geardmp",                           57 },
	{ XFLT, "PARTS_gearstatdef",                       57 },
	{ XFLT, "PARTS_gear_def",                          57 },
	{ XFLT, "PARTS_gear_deploy",                       57 },
	{ XFLT, "PARTS_gear_xnodef",                       57 },
	{ XFLT, "PARTS_gear_ynodef",                       57 },
	{ XFLT, "PARTS_gear_znodef",                       57 },
	{ XFLT, "BODY__fuse_cd",                            1 },
	{ XFLT, "CTRLS_ail1_crat",                          1 },
	{ XFLT, "CTRLS_ail1_up",                            1 },
	{ XFLT, "CTRLS_ail1_d",                             1 },
	{ XFLT, "CTRLS_RSC_idlespeed_prp",                  1 },
	{ XFLT, "CTRLS_RSC_redline_prp",                    1 },
	{ XFLT, "CTRLS_ail2_crat",                          1 },
	{ XFLT, "CTRLS_ail2_up",                            1 },
	{ XFLT, "CTRLS_ail2_d",                             1 },
	{ XFLT, "CTRLS_RSC_mingreen_prp",                   1 },
	{ XFLT, "CTRLS_RSC_maxgreen_prp",                   1 },
	{ XFLT, "CTRLS_elev_crat",                          1 },
	{ XFLT, "CTRLS_elev_up",                            1 },
	{ XFLT, "CTRLS_elev_d",                             1 },
	{ XFLT, "CTRLS_trq_max_eng",                        1 },
	{ XFLT, "CTRLS_trq_max_prp",                        1 },
	{ XFLT, "CTRLS_rudd_crat",                          1 },
	{ XFLT, "CTRLS_rudd_l",                             1 },
	{ XFLT, "CTRLS_d07",                                1 },
	{ XFLT, "CTRLS_d08",                                1 },
	{ XFLT, "CTRLS_splr_crat",                          1 },
	{ XFLT, "CTRLS_splr_u",                             1 },
	{ XFLT, "CTRLS_d09",                                1 },
	{ XFLT, "CTRLS_d10",                                1 },
	{ XFLT, "CTRLS_drud_crat",                          1 },
	{ XFLT, "CTRLS_drud_u",                             1 },
	{ XFLT, "CTRLS_d11",                                1 },
	{ XFLT, "CTRLS_d12",                                1 },
	{ XFLT, "CTRLS_sbrk_crat",                          1 },
	{ XFLT, "CTRLS_sbrk_up",                            1 },
	{ XFLT, "CTRLS_flap_crat",                          1 },
	{ XFLT, "CTRLS_flap_dn",                            7 },
	{ XFLT, "CTRLS_d13",                                1 },
	{ XFLT, "CTRLS_d14",                                1 },
	{ XFLT, "CTRLS_hstb_trim_up",                       1 },
	{ XFLT, "CTRLS_hstb_trim_d",                        1 },
	{ XFLT, "CTRLS_d15",                                1 },
	{ XINT, "CTRLS_hstabtype",                          1 },
	{ XINT, "CTRLS_vstabtype",                          1 },
	{ XINT, "CTRLS_flap_type",                          1 },
	{ XINT, "CTRLS_con_smooth",                         1 },
	{ XFLT, "CTRLS_flap_cl",                            1 },
	{ XFLT, "CTRLS_flap_cd",                            1 },
	{ XFLT, "CTRLS_flap_cm",                            1 },
	{ XINT, "CTRLS_flap_detents",                       1 },
	{ XFLT, "CTRLS_flap_deftime",                       1 },
	{ XFLT, "CTRLS_slat_inc",                           1 },
	{ XFLT, "CTXXX_blownflap_addspeed",                 1 },
	{ XFLT, "CTRLS_blownflap_throtred",                 1 },
	{ XFLT, "CTRLS_blownflap_min_engag",                1 },
	{ XINT, "GEAR__gear_retract",                       1 },
	{ XINT, "GEAR__is_taildragger",                     1 },
	{ XINT, "GEAR__gear_is_skid",                       1 },
	{ XFLT, "GEAR__OLD_OVERALL_RETRACT_TIME",           1 },
	{ XFLT, "GEAR__nwsteerdeg1",                        1 },
	{ XFLT, "GEAR__nwsteerdeg2",                        1 },
	{ XFLT, "GEAR__nw_cutoff_speed",                    1 },
	{ XFLT, "GEAR__water_rud_longarm",                  1 },
	{ XFLT, "GEAR__water_rud_area",                     1 },
	{ XFLT, "GEAR__water_rud_maxdef",                   1 },
	{ XFLT, "GEAR__h_eqlbm",                            1 },
	{ XFLT, "GEAR__the_eqlbm",                          1 },
	{ XINT, "GEAR__gear_door_typ",                     10 },
	{ XFLT, "GEAR__gear_door_loc",                     30 },
	{ XFLT, "GEAR__gear_door_geo",                    120 },
	{ XFLT, "GEAR__gear_door_axi_rot",                 10 },
	{ XFLT, "GEAR__gear_door_ext_ang",                 10 },
	{ XFLT, "GEAR__gear_door_ret_ang",                 10 },
	{ XFLT, "GEAR__gear_door_ang_now",                 10 },
	{ XFLT, "WEIGHTcgY",                                1 },
	{ XFLT, "WEIGHTcgZ",                                1 },
	{ XFLT, "WEIGHTJxx_unitmass",                       1 },
	{ XFLT, "WEIGHTJyy_unitmass",                       1 },
	{ XFLT, "WEIGHTJzz_unitmass",                       1 },
	{ XFLT, "WEIGHTm_empty",                            1 },
	{ XFLT, "WEIGHTm_displaced",                        1 },
	{ XFLT, "WEIGHTm_max",                              1 },
	{ XFLT, "WEIGHTm_fuel",                             1 },
	{ XFLT, "WEIGHTm_jettison",                         1 },
	{ XFLT, "WEIGHTm_displaced_y",                      1 },
	{ XFLT, "SPEC__jato_theta",                         1 },
	{ XFLT, "SPEC__jato_thrust",                        1 },
	{ XFLT, "SPEC__jato_dur",                           1 },
	{ XFLT, "SPEC__jato_sfc",                           1 },
	{ XFLT, "SPEC__jato_Y",                             1 },
	{ XFLT, "SPEC__jato_Z",                             1 },
	{ XFLT, "SPEC__brake_area",                         1 },
	{ XFLT, "SPEC__brake_Y",                            1 },
	{ XFLT, "SPEC__brake_Z",                            1 },
	{ XFLT, "SPEC__chute_area",                         1 },
	{ XFLT, "SPEC__chute_Y",                            1 },
	{ XFLT, "SPEC__chute_Z",                            1 },
	{ XFLT, "SPEC__ail1pitch",                          1 },
	{ XFLT, "SPEC__ail1flaps",                          1 },
	{ XFLT, "SPEC__ail2pitch",                          1 },
	{ XFLT, "SPEC__ail2flaps",                          1 },
	{ XFLT, "SPEC__stabroll",                           1 },
	{ XFLT, "SPEC__stabhdng",                           1 },
	{ XFLT, "SPEC__ail2vmax",                           1 },
	{ XFLT, "SPEC__tvec_ptch",                          1 },
	{ XFLT, "SPEC__tvec_roll",                          1 },
	{ XFLT, "SPEC__tvec_hdng",                          1 },
	{ XFLT, "SPEC__diff_thro_with_hdng",                1 },
	{ XINT, "SPEC__arrestingEQ",                        1 },
	{ XINT, "SPEC__antiiceEQ",                          1 },
	{ XINT, "SPEC__warn1EQ",                            1 },
	{ XINT, "SPEC__gearhornEQ",                         1 },
	{ XINT, "SPEC__autosbrkEQ",                         1 },
	{ XINT, "SPEC__autofbrkEQ",                         1 },
	{ XINT, "SPEC__autosweepEQ",                        1 },
	{ XINT, "SPEC__autoslatEQ",                         1 },
	{ XINT, "VTOL__vectEQ",                             1 },
	{ XFLT, "VTOL__vectarmZ",                           1 },
	{ XFLT, "VTOL__cyclic_elev",                        1 },
	{ XFLT, "VTOL__cyclic_ailn",                        1 },
	{ XFLT, "VTOL__delta3",                             1 },
	{ XFLT, "VTOL__puffL",                              1 },
	{ XFLT, "VTOL__puffM",                              1 },
	{ XFLT, "VTOL__puffN",                              1 },
	{ XFLT, "VTOL__tail_with_coll",                     1 },
	{ XFLT, "VTOL__diff_coll_with_roll",                1 },
	{ XFLT, "VTOL__diff_coll_with_hdng",                1 },
	{ XFLT, "VTOL__diff_cycl_with_hdng",                1 },
	{ XINT, "VTOL__auto_rpm_with_tvec",                 1 },
	{ XFLT, "VTOL__rotor_trim_max_fwd",                 1 },
	{ XFLT, "VTOL__rotor_trim_max_aft",                 1 },
	{ XFLT, "ASTAB_AShiV",                              1 },
	{ XFLT, "ASTAB_ASloV",                              1 },
	{ XFLT, "ASTAB_Asmaxp_lo",                          1 },
	{ XFLT, "ASTAB_Asp_lo_rate",                        1 },
	{ XFLT, "ASTAB_Asmaxp_hi",                          1 },
	{ XFLT, "ASTAB_Asp_hi_pos",                         1 },
	{ XFLT, "ASTAB_Asmaxh_lo",                          1 },
	{ XFLT, "ASTAB_Ash_lo_rate",                        1 },
	{ XFLT, "ASTAB_Asmaxh_hi",                          1 },
	{ XFLT, "ASTAB_Ash_hi_pos",                         1 },
	{ XFLT, "ASTAB_Asmaxr_lo",                          1 },
	{ XFLT, "ASTAB_Asr_lo_rate",                        1 },
	{ XFLT, "ASTAB_Asmaxr_hi",                          1 },
	{ XFLT, "ASTAB_Asr_hi_rate",                        1 },
	{ XINT, "has_clutch",                               1 },
	{ XINT, "has_idlespeed",                            1 },
	{ XFLT, "element_len",                             57 },
	{ XFLT, "gear_door_size",                           1 },
	{ XFLT, "stab_delinc_to_Vne",                       1 },
	{ XFLT, "Vmca",                                     1 },
	{ XFLT, "Vyse",                                     1 },
	{ XFLT, "flap_arm",                                 1 },
	{ XFLT, "tank_xyz12",                               6 },
	{ XFLT, "cgZ_fwd",                                  1 },
	{ XFLT, "cgZ_aft",                                  1 },
	{ XFLT, "gear_cyc_time",                            5 },
	{ XFLT, "refuel_X",                                 1 },
	{ XFLT, "refuel_Y",                                 1 },
	{ XFLT, "refuel_Z",                                 1 },
	{ XCHR, "gear_steers",                             57 },
	{ XCHR, "hybrid_gear",                              1 },
	{ XCHR, "chr_overflow",                             2 },
	{ XINT, "vardihedEQ",                              57 },
	{ XFLT, "dihed2",                                  57 },
	{ XFLT, "dihednow",                                57 },
	{ XFLT, "jett_xyz",                                 3 },
	{ XFLT, "puffX",                                    1 },
	{ XFLT, "puffY",                                    1 },
	{ XFLT, "puffZ",                                    1 },
	{ XFLT, "Vle",                                      1 },
	{ XFLT, "ASp_hi_rate",                              1 },
	{ XFLT, "ASh_hi_rate",                              1 },
	{ XFLT, "spooltime_prop",                           1 },
	{ XFLT, "elevflaps",                                1 },
	{ XFLT, "tank_xyz3",                                3 },
	{ XFLT, "tank_rat",                                 3 },
	{ XFLT, "stall_warn_alpha",                         1 },
	{ XFLT, "mass_shift",                               1 },
	{ XFLT, "mass_shift_dx",                            1 },
	{ XFLT, "mass_shift_dz",                            1 },
	{ XFLT, "feathered_pitch",                          1 },
	{ XFLT, "ASmaxg_hi",                                1 },
	{ XFLT, "ASg_hi_pos",                               1 },
	{ XFLT, "ASg_hi_rate",                              1 },
	{ XFLT, "wing_tilt_ptch",                           1 },
	{ XFLT, "wing_tilt_roll",                           1 },
	{ XFLT, "max_press_diff",                           1 },
	{ XFLT, "diff_coll_with_ptch",                      1 },
	{ XFLT, "flap_roll",                                1 },
	{ XFLT, "flap_ptch",                                1 },
	{ XFLT, "lift_fan_rat",                             1 },
	{ XFLT, "diff_cycl_with_hdng_lat",                  1 },
	{ XINT, "phase_tvect_out_at_90",                    1 },
	{ XFLT, "roll_co",                                  1 },
	{ XFLT, "brake_co",                                 1 },
	{ XINT, "OVER__drive_by_wire",                      1 },
	{ XINT, "is_glossy",                                1 },
	{ XINT, "num_tanks",                                1 },
	{ XINT, "has_refuel",                               1 },
	{ XINT, "draw_geo_frnt_views",                      1 },
	{ XINT, "draw_geo_side_views",                      1 },
	{ XINT, "jett_is_slung",                            1 },
	{ XFLT, "eng_mass",                                57 },
	{ XINT, "phase_tvect_out_at_00",                    1 },
	{ XINT, "auto_trimEQ",                              1 },
	{ XINT, "has_DC_fd",                                1 },
	{ XINT, "flaps_with_gearEQ",                        1 },
	{ XINT, "rev_on_touchdown",                         1 },
	{ XINT, "flaps_with_vecEQ",                         1 },
	{ XINT, "blow_all_controls",                        1 },
	{ XINT, "warn2EQ",                                  1 },
	{ XINT, "num_thrustpoints",                         1 },
	{ XINT, "props_linked",                             1 },
	{ XINT, "int_overflow",                            15 },
	{ XINT, "old_struct_last_data",                     1 },
	{ XCHR, "wpn_name",                              12000 },
	{ XFLT, "Xwpn_att",                                24 },
	{ XFLT, "Ywpn_att",                                24 },
	{ XFLT, "Zwpn_att",                                24 },
	{ XINT, "cus_rnd_use",                             50 },
	{ XFLT, "cus_rnd_lo_val",                          50 },
	{ XFLT, "cus_rnd_hi_val",                          50 },
	{ XFLT, "cus_rnd_lo_ang",                          50 },
	{ XFLT, "cus_rnd_hi_ang",                          50 },
	{ XINT, "has_nav",                                  6 },
	{ XINT, "has_radar",                                1 },
	{ XINT, "dummy_int",                               43 },
	{ XINT, "cus_rnd_mirror",                          50 },
	{ XINT, "cus_rnd_label",                           50 },
	{ XINT, "cus_dig_use",                             50 },
	{ XFLT, "cus_dig_offset",                          50 },
	{ XFLT, "cus_dig_scale",                           50 },
	{ XINT, "cus_dig_dig",                             50 },
	{ XINT, "cus_dig_dec",                             50 },
	{ XINT, "inc_ail",                                570 },
	{ XINT, "inc_vec",                                570 },
	{ XFLT, "tow_hook_Y",                               1 },
	{ XFLT, "tow_hook_Z",                               1 },
	{ XFLT, "win_hook_Y",                               1 },
	{ XFLT, "win_hook_Z",                               1 },
	{ XFLT, "nosewheel_k",                              1 },
	{ XFLT, "vectarmY",                                 1 },
	{ XINT, "hide_prop_at_90_vect",                     1 },
	{ XINT, "xint_overflow",                          204 },
	{ XCHR, "xchr_overflow",                         1000 },

	{ XEOF, NULL, 0 }
};

#endif /* _IMP_ACF_DEF_ACF651_H */