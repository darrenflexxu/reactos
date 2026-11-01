
set(LWIP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lwip)
set(LWIP_INCLUDE_DIRS
    ${LWIP_DIR}/src/include
    ${LWIP_DIR}/src/include/ipv4
    ${CMAKE_CURRENT_SOURCE_DIR}/include/lwip
)
include(${LWIP_DIR}/src/Filelists.cmake)
add_dependencies(lwipcore xdk)

add_definitions(
    -DNDIS51
    -D_NTDRIVER_)

spec2def(tcpip.sys tcpip.spec)

list(APPEND SOURCE
    address.c
    entities.c
    information.c
    interface.c
    main.c
    memory.c
    ndis_lwip.c
    sys_arch.c
    tcp.c
    stubs.c
    precomp.h
)

add_library(tcpip SHARED
    ${SOURCE}
    tcpip.rc
    ${CMAKE_CURRENT_BINARY_DIR}/tcpip.def)

target_include_directories(tcpip BEFORE
    PRIVATE ${LWIP_INCLUDE_DIRS}
    PRIVATE include)

target_link_libraries(tcpip lwipcore ${PSEH_LIB} libcntpr)
set_module_type(tcpip kernelmodedriver)
add_importlibs(tcpip ndis ntoskrnl hal)
add_pch(tcpip precomp.h SOURCE)
add_cd_file(TARGET tcpip DESTINATION reactos/system32/drivers FOR all)
