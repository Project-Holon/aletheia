/*
 * function: FLDMMDL_MOVE_FaceDirTurnPlayerDir
 * address:  0x0219C080
 * packet:   pkt_0219C080
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysSearchPlayer  0x0216DEE0  thumb  ov010
 *   FLDMMDL_GetDirMove  0x0216D608  thumb  ov010
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb  ov021
 *   FLDMMDL_SetLocalAcmd  0x0216D438  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17964.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void FLDMMDL_SetLocalAcmd(char *a0, int a1);
extern u16 FLDMMDL_GetDirMove(void *p);
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern void *FLDMMDL_SysSearchPlayer(void *a0);
extern int FLDMMDL_ACMD_ConvertCodeByDir(int a, int b);

int FLDMMDL_MOVE_FaceDirTurnPlayerDir(char *a, u32 b, u32 c, u32 d)
{
FLDMMDL_SetLocalAcmd(a, (((u32)FLDMMDL_ACMD_ConvertCodeByDir((u32)FLDMMDL_GetDirMove(FLDMMDL_SysSearchPlayer((void *)FLDMMDL_GetMmdlSys((void *)a))), (u32)0) << 16) >> 16));
((struct Obj17964 *)((u8 *)(b)))->f0 = 4;
return 1;
}

