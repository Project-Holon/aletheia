/*
 * function: POKETRADE_3D_CreateIcaStreamsEnding
 * address: 0x021E2EFC
 * packet: pkt_ov119_021E2EFC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 46-byte body followed by 2-byte alignment padding.
 * symbols:
 *   ICA_ANIME_CreateStream 0x02011510 thumb
 */
#include "../include/Obj08067.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern void *ICA_ANIME_CreateStream(u32,u32,u32,u32);
void POKETRADE_3D_CreateIcaStreamsEnding(char *p)
{
    ((struct Obj08067 *)p)->f90=ICA_ANIME_CreateStream(((struct Obj08067 *)p)->fBA,0x68,0xb,10);
    ((struct Obj08067 *)p)->f94=ICA_ANIME_CreateStream(((struct Obj08067 *)p)->fBA,0x68,0xc,10);
}
