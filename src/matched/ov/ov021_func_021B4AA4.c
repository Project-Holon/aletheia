/*
 * function: SCRCMD_PROC_FLD_StepQuantitySelect
 * address:  0x021B4AA4
 * packet:   pkt_ov021_021B4AA4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203633C 0x0203633C arm
 *   func_020362DC 0x020362DC arm
 *   SCRCMD_PROC_FLD_AdjustQuantity 0x021B49EC thumb ov021
 *   func_020061E4 0x020061E4 thumb
 *   SCRCMD_PROC_FLD_PrintQuantityWindow 0x021B42D0 thumb ov021
 *   SCRCMD_PROC_FLD_ShowConfirmMessage 0x021B4804 thumb ov021
 */
#include "../include/Obj00030.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern unsigned int func_0203633C(void);
extern u32 func_020362DC(void);
extern int SCRCMD_PROC_FLD_AdjustQuantity(s16 *p, int max, int key);
extern void func_020061E4(u32 se);
extern void SCRCMD_PROC_FLD_PrintQuantityWindow(char *w, u32 a, u32 b);
extern void SCRCMD_PROC_FLD_ShowConfirmMessage(char *w, u32 b);

int SCRCMD_PROC_FLD_StepQuantitySelect(char *w)
{
    if (func_0203633C() & 0x40) {
        if (SCRCMD_PROC_FLD_AdjustQuantity((s16 *)(w + 0x208), (u16)((struct Obj00030 *)w)->f204, 1) != 0) {
            func_020061E4(0x548);
            SCRCMD_PROC_FLD_PrintQuantityWindow(w, ((struct Obj00030 *)w)->f208, ((struct Obj00030 *)w)->f200);
        }
    } else if (func_0203633C() & 0x80) {
        if (SCRCMD_PROC_FLD_AdjustQuantity((s16 *)(w + 0x208), (u16)((struct Obj00030 *)w)->f204, -1) != 0) {
            func_020061E4(0x548);
            SCRCMD_PROC_FLD_PrintQuantityWindow(w, ((struct Obj00030 *)w)->f208, ((struct Obj00030 *)w)->f200);
        }
    } else if (func_0203633C() & 0x20) {
        if (SCRCMD_PROC_FLD_AdjustQuantity((s16 *)(w + 0x208), (u16)((struct Obj00030 *)w)->f204, -10) != 0) {
            func_020061E4(0x548);
            SCRCMD_PROC_FLD_PrintQuantityWindow(w, ((struct Obj00030 *)w)->f208, ((struct Obj00030 *)w)->f200);
        }
    } else if (func_0203633C() & 0x10) {
        if (SCRCMD_PROC_FLD_AdjustQuantity((s16 *)(w + 0x208), (u16)((struct Obj00030 *)w)->f204, 10) != 0) {
            func_020061E4(0x548);
            SCRCMD_PROC_FLD_PrintQuantityWindow(w, ((struct Obj00030 *)w)->f208, ((struct Obj00030 *)w)->f200);
        }
    }
    if (func_020362DC() & 1) {
        func_020061E4(0x54C);
        SCRCMD_PROC_FLD_ShowConfirmMessage(w, ((struct Obj00030 *)w)->f162);
        *(u8 *)&((struct Obj00030 *)w)->f1 = 6;
        return 10;
    }
    if (func_020362DC() & 2) {
        func_020061E4(0x551);
        return 4;
    }
    return 3;
}
