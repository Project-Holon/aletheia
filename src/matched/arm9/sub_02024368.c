/*
 * function: sub_02024368
 * address:  0x02024368
 * packet:   pkt_02024368
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Archived graphics-slot loader: opens the bank named by the id table at
 * 0x0209F724 for the requested stream, unpacks a scratch buffer out of
 * it, and walks the caller's two-halfword slot array telling the slot
 * manager what each entry is.
 *
 * A slot word of 0xffff means "empty" and is registered with the
 * fixed-size flag; otherwise bit 11 of the word says whether the value
 * carries a 0x7ff payload (registered masked) or is a plain size
 * (registered whole).  The two branches into the size-carrying
 * registration merge on one call site, so they are written as two
 * separate calls in the source and left to the compiler.
 *
 * The 0x100 buffer request is materialised as `movs r5, #2` followed by
 * `adds r5, #0xfe`: the 2 already sits in r5 from the previous call's
 * argument, and 2 + 0xfe is four bytes either way.
 *
 * symbols:
 *   Table_0209F724   0x0209F724  data
 *   WORDSET_CreateDefault    0x0201EC64  thumb
 *   WORDSET_DeleteStrbufED04    0x0201ED04  thumb
 *   WORDSET_SetSlotPmsWord    0x0201EFC8  thumb
 *   WORDSET_SetSlotMarkerFlag    0x0201EFFC  thumb
 *   WORDSET_CopyTaggedText    0x0201F250  thumb
 *   STRBUF_Create    0x020457B0  arm
 *   STRBUF_Delete    0x02045808  arm
 *   func_02045B38    0x02045B38  arm
 *   MSGDATA_Delete    0x02045C04  arm
 *   func_02045EC0    0x02045EC0  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 Table_0209F724[];

struct MsgBank;
struct Rec;
struct U16Vec;
struct WordSet;
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern void WORDSET_SetSlotPmsWord(struct WordSet *p, u32 i, u32 v);
extern void WORDSET_SetSlotMarkerFlag(struct WordSet *p, u32 i, u32 v);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void  *STRBUF_Create(u32 size, u16 heap);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void  *func_02045B38(int a, int b, u32 id, u16 heap);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);

void *sub_02024368(u16 *slots, u32 heap, int count)
{
    void *obj;
    void *buf;
    void *slot;
    void *k;
    int i;

    obj = WORDSET_CreateDefault((u16)heap);
    for (i = 0; i < count; i++) {
        u16 v = slots[i + 2];

        if (v != 0xffff) {
            if ((v >> 11) & 1) {
                WORDSET_SetSlotMarkerFlag(obj, i, v & 0x7ff);
            } else {
                WORDSET_SetSlotPmsWord(obj, i, v);
            }
        } else {
            WORDSET_SetSlotMarkerFlag(obj, i, 1);
        }
    }
    slot = func_02045B38(0, 2, Table_0209F724[slots[0]], (u16)heap);
    buf = STRBUF_Create(0x100, (u16)heap);
    k = func_02045EC0(slot, slots[1]);
    WORDSET_CopyTaggedText(obj, buf, k);
    STRBUF_Delete(k);
    MSGDATA_Delete(slot);
    WORDSET_DeleteStrbufED04(obj);
    return buf;
}
