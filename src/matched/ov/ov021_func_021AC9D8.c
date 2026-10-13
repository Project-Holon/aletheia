/*
 * function: FLDEFF_GRASS_IsModelOnTile
 * address:  0x021AC9D8
 * packet:   pkt_ov021_021AC9D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_GetDirMove  0x0216D608  thumb  ov010
 *   FLDMMDL_GetGridOldX  0x0216D804  thumb  ov010
 *   FLDMMDL_GetGridOldZ  0x0216D81C  thumb  ov010
 *   sGrassEndsOnLeave     0x021D90C0  data
 * Addresses are Black-image addresses.
 */
#include "../include/Obj05039.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FLDMMDL_GetGridNowX(void *p);
extern int FLDMMDL_GetGridNowZ(void *p);
extern u16 FLDMMDL_GetDirMove(void *p);
extern int FLDMMDL_GetGridOldX(void *p);
extern int FLDMMDL_GetGridOldZ(void *p);
extern u8 sGrassEndsOnLeave[];

int FLDEFF_GRASS_IsModelOnTile(u8 *p)
{
    u32 a = ((struct Obj05039 *)p)->f8;
    u32 x = FLDMMDL_GetGridNowX((void *)a);
    u32 y = FLDMMDL_GetGridNowZ((void *)a);
    u32 f = sGrassEndsOnLeave[((struct Obj05039 *)p)->f24];
    if (((struct Obj05039 *)p)->fC == x && ((struct Obj05039 *)p)->f10 == y)
        goto yes;
    if (f == 0 && FLDMMDL_GetDirMove((void *)a) == 0) {
        x = FLDMMDL_GetGridOldX((void *)a);
        y = FLDMMDL_GetGridOldZ((void *)a);
        if (((struct Obj05039 *)p)->fC == x && ((struct Obj05039 *)p)->f10 == y)
            return 1;
    }
    return 0;
yes:
    return 1;
}
