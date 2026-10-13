/*
 * function: EVENT_TRAINER_EYE_StepApproach
 * address:  0x021AE604
 * packet:   pkt_021AE604
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
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb  ov021
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07222.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int FLDMMDL_CheckPossibleAcmd(int a0);
extern u32 FLDMMDL_SetAcmd(u32, u32);
extern int FLDMMDL_ACMD_ConvertCodeByDir(int a, int b);

int EVENT_TRAINER_EYE_StepApproach(u32 a)
{
if (FLDMMDL_CheckPossibleAcmd(((struct Obj07222 *)((u8 *)(a)))->f8) == 1) {
    FLDMMDL_SetAcmd(((struct Obj07222 *)((u8 *)(a)))->f8, FLDMMDL_ACMD_ConvertCodeByDir(((((struct Obj07222 *)((u8 *)(a)))->f10 << 16) >> 16), 12));
    ((struct Obj07222 *)((u8 *)(a)))->f0 = 12;
}
return 0;
}

