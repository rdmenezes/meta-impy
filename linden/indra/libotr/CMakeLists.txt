# -*- cmake -*-

project(otr)

include(00-Common)
include(libgpg-error)
include(libgcrypt)
include(Linking)

if (WINDOWS)
    include_directories(
        ../gpg.vs/inc.vs
        ../gpg.vs/libgpg-error-1.1.vs/custom
        ../gpg.vs/libgcrypt-1.2.2.vs/custom
        ../libgpg-error/libgpg-error-1.0/src
        ../libgcrypt/libgcrypt-1.2.2/src
        )
else (WINDOWS)
    include_directories(
        ${LIBGPG-ERROR_INCLUDE_DIRS}
        ${LIBGCRYPT_INCLUDE_DIRS}
        )
endif (WINDOWS)

set(otr_SOURCE_FILES
    libotr-3.2.0/src/auth.c
    libotr-3.2.0/src/b64.c
    libotr-3.2.0/src/context.c
    libotr-3.2.0/src/dh.c
    libotr-3.2.0/src/mem.c
    libotr-3.2.0/src/message.c
    libotr-3.2.0/src/privkey.c
    libotr-3.2.0/src/proto.c
    libotr-3.2.0/src/sm.c
    libotr-3.2.0/src/tlv.c
    libotr-3.2.0/src/userstate.c
    )

set(otr_HEADER_FILES
    CMakeLists.txt

    libotr-3.2.0/src/auth.h
    libotr-3.2.0/src/b64.h
    libotr-3.2.0/src/context.h
    libotr-3.2.0/src/dh.h
    libotr-3.2.0/src/mem.h
    libotr-3.2.0/src/message.h
    libotr-3.2.0/src/privkey-t.h
    libotr-3.2.0/src/privkey.h
    libotr-3.2.0/src/proto.h
    libotr-3.2.0/src/serial.h
    libotr-3.2.0/src/sm.h
    libotr-3.2.0/src/tlv.h
    libotr-3.2.0/src/userstate.h
    libotr-3.2.0/src/version.h
    )

set_source_files_properties(${otr_HEADER_FILES}
                            PROPERTIES HEADER_FILE_ONLY TRUE)

list(APPEND libotr_SOURCE_FILES ${otr_HEADER_FILES})

add_library (otr ${otr_SOURCE_FILES})
target_link_libraries(otr
    ${LIBGCRYPT_LIBRARIES}
    ${LIBGPG-ERROR_LIBRARIES}
    )

add_dependencies(otr gcrypt)

