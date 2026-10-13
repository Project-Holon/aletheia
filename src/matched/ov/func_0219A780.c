/*
 * function: FLDMMDL_MOVECODE_SwingStepTurn
 * address:  0x0219A780
 * packet:   pkt_0219A780
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb  ov021
 *   FLDMMDL_SetLocalAcmd  0x0216D438  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17955.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void FLDMMDL_SetLocalAcmd(char *a0, int a1);
extern u16 FLDMMDL_GetDirDisp(void *p);
extern int FLDMMDL_ACMD_ConvertCodeByDir(int a, int b);

int FLDMMDL_MOVECODE_SwingStepTurn(char *a, u32 b, u32 c, u32 d)
{
FLDMMDL_SetLocalAcmd(a, (((u32)FLDMMDL_ACMD_ConvertCodeByDir((u32)(((u32)FLDMMDL_GetDirDisp((void *)a) << 16) >> 16), (u32)0) << 16) >> 16));
((struct Obj17955 *)((u8 *)(b)))->f2 = 1;
return 1;
}

