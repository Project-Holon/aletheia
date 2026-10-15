/*
 * function: GPOWER_EVENT_PrintPowerRow
 * address:  0x021F556C
 * packet:   pkt_ov083_021F556C
 * region:   ov083
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WORDSET_SetSlotFromMsgA0  0x0201F184  thumb
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   FIELD_MSGBG_InfoMsgWinPrintStr  0x02190844  thumb  ov021
 */
#include "../include/Obj00815.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef signed int     s32;
struct Slot;
struct WordSet;
extern void WORDSET_SetSlotFromMsgA0(struct WordSet *p, u32 i, s32 v);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void FIELD_MSGBG_InfoMsgWinPrintStr(struct Slot **p, int x, int y, u32 z);

void GPOWER_EVENT_PrintPowerRow(char *p, u32 a1, u32 a2, int a3, u8 a4)
{
    WORDSET_SetSlotFromMsgA0((struct WordSet *)(((struct Obj00815 *)p)->f2C), 0, a2);
    WORDSET_SetSlotNumber((struct WordSet *)(((struct Obj00815 *)p)->f2C), 1, a3 / 60, 2, 1, 1);
    WORDSET_SetSlotNumber((struct WordSet *)(((struct Obj00815 *)p)->f2C), 2, a3 % 60, 2, 2, 1);
    WORDSET_CopyTaggedText((struct WordSet *)(((struct Obj00815 *)p)->f2C), (void *)(((struct Obj00815 *)p)->f38), (void *)a1);
    FIELD_MSGBG_InfoMsgWinPrintStr((struct Slot **)(((struct Obj00815 *)p)->f18), 8, (u16)(a4 << 4), ((struct Obj00815 *)p)->f38);
}
