/*
 * function: FLDMMDL_MOVE_HasPlayerMoved
 * address:  0x0219B9D8
 * packet:   pkt_ov021_0219B9D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysSearchPlayer  0x0216DEE0  thumb  ov010
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 */
#include "../include/Obj05998.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern void *FLDMMDL_SysSearchPlayer(void *a0);
extern int FLDMMDL_GetGridNowX(void *p);
extern int FLDMMDL_GetGridNowZ(void *p);

int FLDMMDL_MOVE_HasPlayerMoved(u32 a, u8 *s)
{
    u32 o = (u32)FLDMMDL_SysSearchPlayer(FLDMMDL_GetMmdlSys((void *)a));
    int x;
    int y;
    if (o != 0) {
        x = FLDMMDL_GetGridNowX((void *)o);
        y = FLDMMDL_GetGridNowZ((void *)o);
        if (x != *(s16 *)&((struct Obj05998 *)s)->f2 || y != *(s16 *)&((struct Obj05998 *)s)->f4) {
            return 1;
        }
    }
    return 0;
}
