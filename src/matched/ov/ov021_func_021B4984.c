/*
 * function: SCRCMD_PROC_FLD_ShowTmBuyConfirm
 * address:  0x021B4984
 * packet:   pkt_ov021_021B4984
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_PROC_FLD_PrepareMessageWindow 0x021B4878 thumb ov021
 *   SCRCMD_PROC_FLD_ShowMessage 0x021B4894 thumb ov021
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   FILE_UTIL_Get_12B0 0x020212B0 thumb
 *   WORDSET_SetSlotFromMsgCB 0x0201EF34 thumb
 */
#include "../include/Obj01121.h"

typedef unsigned short u16;
typedef unsigned int u32;

extern int SCRCMD_PROC_FLD_PrepareMessageWindow(u32 a);
struct WordSet;
extern void SCRCMD_PROC_FLD_ShowMessage(char *w, u32 b);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern int FILE_UTIL_Get_12B0(u32 a);
extern void WORDSET_SetSlotFromMsgCB(struct WordSet *p, u32 i, u32 v);

void SCRCMD_PROC_FLD_ShowTmBuyConfirm(char *w, u32 a, u32 b, u32 c)
{
    SCRCMD_PROC_FLD_PrepareMessageWindow(((struct Obj01121 *)w)->f17C);
    WORDSET_SetSlotNumber((struct WordSet *)(((struct Obj01121 *)w)->f190), 0, b - 327, 2, 2, 1);
    WORDSET_SetSlotFromMsgCB((struct WordSet *)(((struct Obj01121 *)w)->f190), 1, FILE_UTIL_Get_12B0(b));
    WORDSET_SetSlotNumber((struct WordSet *)(((struct Obj01121 *)w)->f190), 2, c, 5, 0, 1);
    SCRCMD_PROC_FLD_ShowMessage((char *)((u32)w), a);
}
