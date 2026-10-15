/*
 * function: SAVE_EVENT_WriteMode
 * address:  0x0202F1B4
 * packet:   pkt_0202F1B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     time_icon.c seven-way mode switch around a POKE_TOOL_DecodeBoxParam /
 *           POKE_TOOL_EncodeBoxParam bracket.  Closed in wave 16: the 129-byte residue
 *           of docs/notes/SAVE_EVENT_WriteMode.c.txt was NOT an allocator tie but
 *           the source's gotos.  Every case is written out in full (no
 *           shared labels) and case 2's guard carries the call run in BOTH
 *           arms; 1.1p1's own cross-jumping then produces the image's
 *           `b` into case 0's SAVE_EVENT_CopyDoneFlag/SAVE_EVENT_SetDoneFlag tail, the kept
 *           `bne; b` pair in case 2, and the head that spills the selector
 *           and holds the fifth parameter in r7.  The call at +0x58 is
 *           attested by src/matched/SAVE_EVENT_SetDoneFlag.c (same shard).
 *           0x7532 is a plain constant.
 * symbols:
 *   POKE_TOOL_DecodeBoxParam  0x02017DBC  thumb
 *   POKE_TOOL_EncodeBoxParam  0x02017DE4  thumb
 *   POKE_TOOL_IsBoxOwnedByPlayer  0x02018488  thumb
 *   SAVE_EVENT_ClearVariant  0x0202F2F4  thumb
 *   SAVE_EVENT_WriteEventIdWithDate  0x0202F30C  thumb
 *   SAVE_EVENT_CopyVariant  0x0202F3AC  thumb
 *   SAVE_EVENT_StoreRecord  0x0202F41C  thumb
 *   SAVE_EVENT_CopyDoneFlag  0x0202F464  thumb
 *   SAVE_EVENT_SetDoneFlag  0x0202F47C  thumb
 */
typedef unsigned int u32;
struct Sav;
extern u32 POKE_TOOL_DecodeBoxParam(struct Sav *p);
extern u32 POKE_TOOL_EncodeBoxParam(struct Sav *p, u32 f);
extern u32 POKE_TOOL_IsBoxOwnedByPlayer(void *p, void *mail);
extern void SAVE_EVENT_ClearVariant(void *a0, u32 a1);
extern void SAVE_EVENT_WriteEventIdWithDate(void *a0, u32 a1, u32 a2);
extern void SAVE_EVENT_CopyVariant(void *a0, u32 a1);
extern int SAVE_EVENT_StoreRecord(int a0, int a1, int a2);
extern int SAVE_EVENT_CopyDoneFlag(int a0);
extern void SAVE_EVENT_SetDoneFlag(void *p);
void SAVE_EVENT_WriteMode(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    u32 h = POKE_TOOL_DecodeBoxParam((struct Sav *)a);

    switch (b) {
    case 0:
        SAVE_EVENT_ClearVariant((void *)a, 0);
        SAVE_EVENT_WriteEventIdWithDate((void *)a, d, 1);
        SAVE_EVENT_StoreRecord(a, c, e);
        SAVE_EVENT_CopyDoneFlag(a);
        SAVE_EVENT_SetDoneFlag((void *)a);
        break;
    case 1:
        SAVE_EVENT_WriteEventIdWithDate((void *)a, 0x7532, 1);
        SAVE_EVENT_CopyDoneFlag(a);
        SAVE_EVENT_SetDoneFlag((void *)a);
        break;
    case 2:
        if (POKE_TOOL_IsBoxOwnedByPlayer((void *)a, (void *)c) == 1) {
            SAVE_EVENT_WriteEventIdWithDate((void *)a, d, 1);
            SAVE_EVENT_StoreRecord(a, c, e);
        } else {
            SAVE_EVENT_CopyVariant((void *)a, 1);
            SAVE_EVENT_WriteEventIdWithDate((void *)a, d, 1);
            SAVE_EVENT_StoreRecord(a, c, e);
        }
        SAVE_EVENT_SetDoneFlag((void *)a);
        break;
    case 3:
    case 4:
        break;
    case 5:
        SAVE_EVENT_WriteEventIdWithDate((void *)a, d, 0);
        SAVE_EVENT_StoreRecord(a, c, e);
        SAVE_EVENT_SetDoneFlag((void *)a);
        break;
    case 6:
        SAVE_EVENT_WriteEventIdWithDate((void *)a, d, 1);
        break;
    }
    POKE_TOOL_EncodeBoxParam((struct Sav *)a, h);
}
