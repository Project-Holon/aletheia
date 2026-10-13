/*
 * function: SCRCMD_PROC_FLD_ShowConfirmMessage
 * address:  0x021B4804
 * packet:   pkt_ov021_021B4804
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_PROC_FLD_ShowBuyConfirm 0x021B4918 thumb ov021
 *   SCRCMD_PROC_FLD_ShowTmBuyConfirm 0x021B4984 thumb ov021
 */
#include "../include/Obj00030.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void SCRCMD_PROC_FLD_ShowBuyConfirm(char *w, u32 a, u16 b, u32 c, u16 d);
extern void SCRCMD_PROC_FLD_ShowTmBuyConfirm(char *w, u32 a, u32 b, u32 c);

void SCRCMD_PROC_FLD_ShowConfirmMessage(char *w, u32 a)
{
    if (((struct Obj00030 *)w)->f162 == 1) {
        if (((struct Obj00030 *)w)->f163 == 1) {
            SCRCMD_PROC_FLD_ShowTmBuyConfirm(w, 8, ((struct Obj00030 *)w)->f1FC, ((struct Obj00030 *)w)->f200);
        } else {
            SCRCMD_PROC_FLD_ShowTmBuyConfirm(w, 7, ((struct Obj00030 *)w)->f1FC, ((struct Obj00030 *)w)->f200);
        }
    } else {
        if (((struct Obj00030 *)w)->f163 == 1) {
            SCRCMD_PROC_FLD_ShowBuyConfirm(w, 6, ((struct Obj00030 *)w)->f1FC, ((struct Obj00030 *)w)->f200, ((struct Obj00030 *)w)->f208);
        } else {
            SCRCMD_PROC_FLD_ShowBuyConfirm(w, 5, ((struct Obj00030 *)w)->f1FC, ((struct Obj00030 *)w)->f200, ((struct Obj00030 *)w)->f208);
        }
    }
}
