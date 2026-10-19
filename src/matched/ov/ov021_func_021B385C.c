/*
 * function: SCRCMD_PROC_FLD_SetItemSlot
 * address:  0x021B385C
 * packet:   pkt_ov021_021B385C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_PROC_FLD_SetItemSlot 0x021B385C thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   FILE_UTIL_GetMachineMove 0x020212B0 thumb
 *   WORDSET_SetSlotFromMsgCB 0x0201EF34 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   BMP_MENUWORK_AddStrItem 0x0201F898 thumb
 *   BMP_MENUWORK_AddMsgItem 0x0201F878 thumb
 */
#include "../include/Obj00037.h"

typedef unsigned short u16;

typedef unsigned int   u32;
struct WordSet;
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u16 FILE_UTIL_GetMachineMove(u16 id);
extern void WORDSET_SetSlotFromMsgCB(struct WordSet *p, u32 i, u32 v);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
struct Slot;
extern void BMP_MENUWORK_AddStrItem(struct Slot *table, u32 a, u32 b, u32 tag);
extern void BMP_MENUWORK_AddMsgItem(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);

void SCRCMD_PROC_FLD_SetItemSlot(char *p, int idx, int mode, int val, int arg)
{
    if (mode == 1) {
        WORDSET_SetSlotNumber(((struct Obj00037 *)p)->f190, 0, val - 327, 2, 2, 1);
        WORDSET_SetSlotFromMsgCB(((struct Obj00037 *)p)->f190, 1, FILE_UTIL_GetMachineMove(val));
        WORDSET_CopyTaggedText(((struct Obj00037 *)p)->f190, ((struct Obj00037 *)p)->f198, ((struct Obj00037 *)p)->f19C);
        BMP_MENUWORK_AddStrItem((struct Slot *)(*(char * *)&((struct Obj00037 *)p)->f180 + idx * 8), (u32)(((struct Obj00037 *)p)->f198), idx, ((struct Obj00037 *)p)->f4);
    } else {
        BMP_MENUWORK_AddMsgItem((struct Slot *)(*(char * *)&((struct Obj00037 *)p)->f180 + idx * 8), arg, val, idx, ((struct Obj00037 *)p)->f4);
    }
}
