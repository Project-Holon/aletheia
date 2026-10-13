/*
 * function: func_021DC818
 * address: 0x021DC818
 * packet: pkt_ov119_021DC818
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 */
#include "../include/Obj00001.h"
extern int GFL_USE_PopBgm(void);
typedef unsigned int   u32;
extern void GFL_USE_SetBgmPlayerParam(void *p);
extern void GFL_USE_FadeInBgmFull(u32 a);
void func_021DC818(char *p)
{
    switch (((struct Obj00001 *)p)->f11F8) {
    case 0:
        break;
    case 2:
        GFL_USE_PopBgm();
        GFL_USE_SetBgmPlayerParam(0);
    case 1:
        GFL_USE_PopBgm();
        GFL_USE_SetBgmPlayerParam(0);
        GFL_USE_FadeInBgmFull(30);
    }
    ((struct Obj00001 *)p)->f11F8 = 0;
}
