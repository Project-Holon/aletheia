/*
 * function: SCRCMD_FLDMMDL_CheckPlayerAnimeDone
 * address:  0x021B1CFC
 * packet:   pkt_021B1CFC
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
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_StepFormChange  0x021A2F54  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18096.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern int FIELD_PLAYER_StepFormChange(u8 *p);

int SCRCMD_FLDMMDL_CheckPlayerAnimeDone(u32 a, u32 b, u32 c, u32 d)
{
if (FIELD_PLAYER_StepFormChange(FIELDMAP_GetFieldPlayer(((struct Obj18096 *)((u8 *)(SCRIPT_WORK_ResetFieldParam((int)SCRCMD_WORK_GetScriptWork((void *)b)))))->f4)) == 1) {
    return 1;
}
return 0;
}

