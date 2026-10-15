/*
 * function: B_PLIST_DRAW_FormatRowWord
 * address: 0x0220E1D4
 * packet: pkt_ov198_0220E1D4
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the row pointer p + 4 + idx * 0x4c is one statement before the
 *   func_02045EC0 allocation, so p + 4 (r6) and idx * 0x4c (r7) stay live
 *   across it and the allocation result spills to [sp]; computing the row
 *   address only at its use (the earlier note's base + i) left t in r7 and
 *   rematerialised p + 4 after the call (DIFF 16).
 * symbols:
 *   B_PLIST_MAIN_GetOrderIndex 0x022110D4 thumb ov198
 *   func_02045EC0 0x02045EC0 arm
 *   WORDSET_SetSlotMonSpecies 0x0201EEF4 thumb
 *   WORDSET_SetSlotFromMsgCB 0x0201EF34 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct WordSet;
struct MsgBank;
struct U16Vec;
extern int B_PLIST_MAIN_GetOrderIndex(u8 *p, int i);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void WORDSET_SetSlotMonSpecies(struct WordSet *p, u32 i, void *mon);
extern void WORDSET_SetSlotFromMsgCB(struct WordSet *p, u32 i, u32 v);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
void B_PLIST_DRAW_FormatRowWord(u8 *p)
{
    u8 *row;
    void *t;
    row = p + 4 + B_PLIST_MAIN_GetOrderIndex(p, (*(u8 **)p)[32]) * 0x4c;
    t = func_02045EC0(*(struct MsgBank **)(p + 0x1ea0), 105);
    WORDSET_SetSlotMonSpecies(*(struct WordSet **)(p + 0x1ea4), 0, *(void **)row);
    WORDSET_SetSlotFromMsgCB(*(struct WordSet **)(p + 0x1ea4), 1, 373);
    WORDSET_CopyTaggedText(*(struct WordSet **)(p + 0x1ea4), *(void **)(p + 0x1ea8), t);
    STRBUF_Delete(t);
}
