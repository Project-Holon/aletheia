/*
 * function: POKETRADE_2D_FreeMainResources
 * address: 0x021E4000
 * packet: pkt_ov119_021E4000
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_2D_FreeBoxScreenData 0x021E43DC thumb ov119
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 */
#include "../include/Obj00001.h"
extern void POKETRADE_2D_FreeBoxScreenData(char *);
typedef unsigned int   u32;
extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);
void POKETRADE_2D_FreeMainResources(char *p)
{
    POKETRADE_2D_FreeBoxScreenData(p);
    if (((struct Obj00001 *)p)->f870) {
        BG_SYS_DeleteHalf((int)5, (unsigned short)(((struct Obj00001 *)p)->f870), (unsigned short)(((struct Obj00001 *)p)->f870 >> 16));
        *(int *)&((struct Obj00001 *)p)->f870 = 0;
    }
    if (((struct Obj00001 *)p)->f874) {
        BG_SYS_DeleteHalf((int)7, (unsigned short)(((struct Obj00001 *)p)->f874), (unsigned short)(((struct Obj00001 *)p)->f874 >> 16));
        *(int *)&((struct Obj00001 *)p)->f874 = 0;
    }
    if (*(unsigned int *)&((struct Obj00001 *)p)->f644) {
        BG_SYS_DeleteHalf((int)6, (unsigned short)(*(unsigned int *)&((struct Obj00001 *)p)->f644), (unsigned short)(*(unsigned int *)&((struct Obj00001 *)p)->f644 >> 16));
        *(int *)&((struct Obj00001 *)p)->f644 = 0;
    }
}
