/*
 * function: FLDMMDL_MOVE_SavePlayerGridPos
 * address:  0x0219BA0C
 * packet:   pkt_ov021_0219BA0C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
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

void FLDMMDL_MOVE_SavePlayerGridPos(u32 a, u8 *s)
{
    u32 o = (u32)FLDMMDL_SysSearchPlayer(FLDMMDL_GetMmdlSys((void *)a));
    ((struct Obj05998 *)s)->f2 = FLDMMDL_GetGridNowX((void *)o);
    ((struct Obj05998 *)s)->f4 = FLDMMDL_GetGridNowZ((void *)o);
}
