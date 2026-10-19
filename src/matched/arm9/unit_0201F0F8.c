/*
 * unit:     yes
 * address:  0x0201F0F8
 * packet:   pkt_0201F020
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: WORDSET_SetSlotFromMsgBF, WORDSET_SetSlotPokeData, WORDSET_SetSlotFromMsg11B, WORDSET_SetSlotFromMsgBE,
 *           WORDSET_SetSlotFromMsgB4, WORDSET_SetSlotFromMsg37, WORDSET_SetSlotFromMsg59, WORDSET_SetSlotBoxName,
 *           WORDSET_SetSlotFromMsgA0, WORDSET_SetSlotFromMsg2B, WORDSET_SetSlotFromMsg00, WORDSET_SetSlotFromMsg38,
 *           WORDSET_SetSlotWeekday, WORDSET_SetSlotMonth
 *
 * The second half of the wordset.c setter run, 0x0201F0F8..0x0201F250.
 * Every one of these is the same shape: clamp or range-check the caller's
 * value, then render one message id through WORDSET_SetSlotFromMessage.  The constants are
 * message ids and the ones above 255 (0x116, 0x11B, 0x1CD) arrive from the
 * function's own literal pool because Thumb's `movs` immediate stops at 255;
 * they are plain numbers, not relocations, which is the negative case of
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 *
 * WORDSET_SetSlotFromMsgA0 clamps with a signed `blt`, so its value parameter is `s32`
 * while every other clamp in the file is an unsigned `bls`/`bhi`.
 *
 * WORDSET_SetSlotWeekday clears the slot unconditionally before the range check and
 * only overwrites it when the id is in range, so a caller with an
 * out-of-range id leaks the rendered string; that is what the bytes say and
 * it is reproduced here rather than tidied.
 *
 * The calls to WORDSET_ResetSlot are carried by the `matched` class through
 * src/matched/unit_0201ED04.c; all six of its callers are inside this packet.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F0F8.c  *       --addr 0x0201F0F8 --thumb
 *
 * symbols:
 *   MYSTATUS_NameToStrbuf  0x02008500  thumb
 *   MSGDATA_Delete  0x02045C04  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   NATION_AREA_GetAreaMsgBank  0x02025B94  thumb
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
extern u32   NATION_AREA_GetAreaMsgBank(u32 a);
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
extern void WORDSET_SetSlotFromMsgBF(struct WordSet *p, u32 i, u32 v);

void WORDSET_SetSlotFromMsgBF(struct WordSet *p, u32 i, u32 v)
{
    WORDSET_SetSlotFromMessage(p, i, 0xBF, v);
}

void WORDSET_SetSlotPokeData(struct WordSet *p, u32 i, u32 a)
{
    WORDSET_SetSlotFromMsgBF(p, i, (u8)TPOKE_DATA_GetRecordField((void *)a, 1));
}

void WORDSET_SetSlotFromMsg11B(struct WordSet *p, u32 i, u32 v)
{
    WORDSET_SetSlotFromMessage(p, i, 0x11B, v);
}

void WORDSET_SetSlotFromMsgBE(struct WordSet *p, u32 i, u32 v)
{
    WORDSET_SetSlotFromMessage(p, i, 0xBE, v);
}

void WORDSET_SetSlotFromMsgB4(struct WordSet *p, u32 i, u32 v)
{
    WORDSET_SetSlotFromMessage(p, i, 0xB4, v);
}

void WORDSET_SetSlotFromMsg37(struct WordSet *p, u32 i, u32 v)
{
    WORDSET_SetSlotFromMessage(p, i, 0x37, v);
}

void WORDSET_SetSlotFromMsg59(struct WordSet *p, u32 i, u32 v)
{
    WORDSET_SetSlotFromMessage(p, i, 0x59, v);
}

void WORDSET_SetSlotBoxName(struct WordSet *p, u32 i, u32 a, u32 b)
{
    func_0200785C((void *)a, b, p->buf);
    WORDSET_SetSlotText(p, i, p->buf, 0);
}

void WORDSET_SetSlotFromMsgA0(struct WordSet *p, u32 i, s32 v)
{
    if (v >= 0x30) {
        v = 0;
    }
    WORDSET_SetSlotFromMessage(p, i, 0xA0, v);
}

void WORDSET_SetSlotFromMsg2B(struct WordSet *p, u32 i, u32 v)
{
    if (v > 8) {
        WORDSET_ResetSlot(p, i);
        return;
    }
    WORDSET_SetSlotFromMessage(p, i, 0x2B, v);
}

void WORDSET_SetSlotFromMsg00(struct WordSet *p, u32 i, u8 v)
{
    if (v > 0x91) {
        WORDSET_ResetSlot(p, i);
        return;
    }
    WORDSET_SetSlotFromMessage(p, i, 0, v);
}

void WORDSET_SetSlotFromMsg38(struct WordSet *p, u32 i, u32 v)
{
    if (v > 8) {
        WORDSET_ResetSlot(p, i);
        return;
    }
    WORDSET_SetSlotFromMessage(p, i, 0x38, v);
}

void WORDSET_SetSlotWeekday(struct WordSet *p, u32 i, u32 v)
{
    void *s = func_02045B38(0, 3, (u16)0x1CD, (u16)p->heap);

    WORDSET_ResetSlot(p, i);
    if (v <= 6 && s != 0) {
        MSGDATA_ReadString(s, v + 0x2B, p->buf);
        WORDSET_SetSlotText(p, i, p->buf, 0);
        MSGDATA_Delete(s);
    }
}

void WORDSET_SetSlotMonth(struct WordSet *p, u32 i, u32 v)
{
    if (v < 1) {
        v = 1;
    } else if (v > 0xC) {
        v = 0xC;
    }
    WORDSET_SetSlotFromMessage(p, i, 0x116, v - 1);
}
