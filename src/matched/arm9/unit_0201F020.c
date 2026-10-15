/*
 * unit:     yes
 * address:  0x0201F020
 * packet:   pkt_0201F020
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: WORDSET_SetSlotFromMsgC7, WORDSET_SetSlotMyStatus, WORDSET_SetSlotFromMsgE7
 *
 * Three of the wordset.c setters, cut off at 0x0201F094 because the function
 * there is the only caller of 0x02025B94 anywhere in the image and so cannot
 * be attested; see src/pending/sub_0201F094.c.  The rest of the run continues
 * in src/matched/unit_0201F0F8.c.
 *
 * WORDSET_SetSlotFromMsgE7 renders message 0xE7 with an argument and falls back to
 * clearing the slot when the argument is out of the message's own range; the
 * `bhs` is the unsigned compare against func_02045F50's result, and the
 * fall-through arm is the in-range one
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * The call to WORDSET_ResetSlot is carried by the `matched` class: its only six
 * callers in the image are all inside this packet, so no cut reaches it, but
 * src/matched/unit_0201ED04.c is an EXACT entry covering that address.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F020.c  *       --addr 0x0201F020 --thumb
 *
 * symbols:
 *   MYSTATUS_NameToStrbuf  0x02008500  thumb
 *   MSGDATA_Delete  0x02045C04  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   WORDSET_Set  0x0201F0F8  thumb
 *   BMP_OAM_Get  0x02025B94  thumb
 *   TPOKE_DATA_GetRecordField  0x0202A230  thumb
 *   WORDSET_ResetSlot  0x0201ED64  thumb
 *   WORDSET_SetSlotText  0x0201ED84  thumb
 *   WORDSET_SetSlotFromMessage  0x0201EDD0  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct MsgBank;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
struct MsgBank;
struct Obj;
struct Rec;
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern u16 func_02045F50(const struct Obj *o);
extern void  MYSTATUS_NameToStrbuf(void *a, void *b);
extern u32   BMP_OAM_Get(u32 a);
extern u32 TPOKE_DATA_GetRecordField(void *a, u32 idx);
extern void func_0200785C(void *save, u32 box, void *dest);

struct Tag;

struct Entry {
    u8 tag[5];
    void *str;
};

struct WordSet {
    u32 count;
    u32 heap;
    struct Entry *entries;
    void *buf;
};

extern void WORDSET_ResetSlot(struct WordSet *p, u32 i);
extern void WORDSET_SetSlotText(struct WordSet *p, u32 i, const void *src,
                          const struct Tag *tag);
extern void WORDSET_SetSlotFromMessage(struct WordSet *p, u32 i, u32 id, u32 v);
extern void WORDSET_Set(struct WordSet *p, u32 i, u32 v);

void WORDSET_SetSlotFromMsgC7(struct WordSet *p, u32 i, u32 v)
{
    WORDSET_SetSlotFromMessage(p, i, 0xC7, v);
}

void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a)
{
    MYSTATUS_NameToStrbuf(a, p->buf);
    WORDSET_SetSlotText(p, i, p->buf, 0);
}

void WORDSET_SetSlotFromMsgE7(struct WordSet *p, u32 i, u32 n)
{
    void *s = func_02045B38(0, 2, (u16)0xE7, (u16)p->heap);

    if (s != 0) {
        if (n < func_02045F50(s)) {
            MSGDATA_ReadString(s, n, p->buf);
            WORDSET_SetSlotText(p, i, p->buf, 0);
        } else {
            WORDSET_ResetSlot(p, i);
        }
        MSGDATA_Delete(s);
    }
}
