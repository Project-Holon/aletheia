/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0201ED04
 * packet:   pkt_0201E4C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: WORDSET_DeleteStrbufED04, WORDSET_Init, WORDSET_ResetSlot, WORDSET_SetSlotText,
 *           WORDSET_SetSlotFromMessage, WORDSET_SetSlotTag, WORDSET_Callback, WORDSET_SetSlotMonName,
 *           WORDSET_SetSlotMonNameAlt, WORDSET_Callback_EEC4, WORDSET_SetSlotMonNameEx, WORDSET_SetSlotMonSpecies,
 *           WORDSET_SetSlotMonSpeciesAlt, WORDSET_SetSlotFromMsgCB, WORDSET_Callback_EF40, WORDSET_Callback_EF4C,
 *           WORDSET_SetSlotFromMsg118, WORDSET_SetSlotFromBank, WORDSET_SetSlotFromMsgB6, WORDSET_SetSlotFromMsg18,
 *           WORDSET_SetSlotNumber, WORDSET_SetSlotPmsWord
 *
 * symbols:
 *   gSpeciesNameBank   0x020A7370  data
 *   PMSI_PARAM_ValidateWord  0x020246C8  thumb
 *   PMSI_PARAM_ValidateDecoValue  0x0202473C  thumb
 *   PMS_WORD_LoadString  0x02024838  thumb
 *   STRBUF_Clear  0x0204581C  arm
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   STRBUF_Copy  0x02045838  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   WORDSET_FormatNumber  0x0201F35C  thumb
 *
 * 760 bytes, 0x0201ED04..0x0201EFFC, 22 functions, the body of wordset.c.
 * The file name is attested at the constructor 0x0201EC74, which is just
 * before this range and is a near miss; see src/matched/unit_0201EC64.c.
 *
 * The object is a small table of substitution slots:
 *
 *     struct WordSet { u32 count; u32 heap; struct Entry *entries;
 *                      void *buf; };
 *     struct Entry   { struct Tag tag; void *str; };     // 12 bytes
 *
 * and every setter in the file ends the same way, by handing a rendered
 * string to WORDSET_SetSlotText, which copies the caller's five-byte Tag into the
 * slot (or clears it when the caller passes NULL) and then copies the string
 * itself.  The five-byte tag is not a scalar: the byte at +3 is two
 * bitfields, a seven-bit value and a one-bit flag, which is what the
 * `ldrb`/`bics #0x7F`/`orrs` and `ldrb`/`bics #0x80`/`lsls #0x1F` pairs in
 * WORDSET_SetSlotTag are.  Writing that byte as a plain u8 with masks costs a pool
 * word and an `ands` for each of the two fields
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md is the same
 * effect on the reading side).
 *
 * WORDSET_Init is the tag clear and takes a `struct Tag *`, not a
 * `struct Entry *`: WORDSET_SetSlotTag calls it on a bare stack local, which is
 * what fixes the parameter type.  The two are the same address for an entry,
 * so the distinction is only visible at that one call site.
 *
 * WORDSET_Callback reaches a file-scope pointer at 0x020A7370.  Exactly two
 * literal pools in the image hold that address, this function's and
 * WORDSET_LoadSpeciesNameBank's in src/matched/unit_0201F0F8.c, so each file is the other's
 * `literal` witness and the two may not be merged into one range.
 *
 * WORDSET_SetSlotFromBank is three separate early returns rather than one conjunction:
 * each `bl` is followed by its own `pop`, which is the shape
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md
 * records for a chain the compiler does not tail-merge.
 *
 * Addresses are Black-image addresses.  func_02017E1C and func_02017E88 are
 * the pair of species-keyed getters this file reads names through; they are
 * not resolved here and nothing in this range reads a version flag or an
 * exclusive-species table directly, but any renaming of those two should be
 * checked against Pokemon White.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ED04.c  *       --addr 0x0201ED04 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *gSpeciesNameBank;

extern void  MI_CpuFill8(void *dest, u8 data, u32 size);
extern u32 func_020307B0(void *p);
extern u32   func_02017E1C(void *p, u32 id, u32 v);
extern u32 func_02017E88(void *p, u32 id, u32 v);
typedef signed int     s32;
struct MsgBank;
struct Rec;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void STRBUF_Clear(struct U16Vec *vec);
extern void STRBUF_Copy(struct U16Vec *dst, struct U16Vec *src);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 PMSI_PARAM_ValidateWord(u16 *p, u32 mode, u32 flag);
extern u32 PMSI_PARAM_ValidateDecoValue(u32 *p, u32 a);
extern void PMS_WORD_LoadString(u32 id, void *dest, u32 heap);
extern void WORDSET_FormatNumber(void *ctx, s32 n, u32 kind, u32 mode, u32 flag);

struct Tag {
    u8 unk00;
    u8 unk01;
    u8 unk02;
    u8 unk03 : 7;
    u8 unk03b : 1;
    u8 unk04;
};

struct Entry {
    struct Tag tag;
    void *str;
};

struct WordSet {
    u32 count;
    u32 heap;
    struct Entry *entries;
    void *buf;
};

extern void WORDSET_Init(struct Tag *t);
extern void WORDSET_SetSlotText(struct WordSet *p, u32 i, const void *src,
                          const struct Tag *tag);
extern void WORDSET_SetSlotFromMessage(struct WordSet *p, u32 i, u32 id, u32 v);
extern void WORDSET_Callback(struct WordSet *p, u32 i, u16 v);
extern void WORDSET_Callback_EEC4(struct WordSet *p, u32 i, u32 v);
extern void WORDSET_Callback_EF40(struct WordSet *p, u32 i, u32 v);
extern void WORDSET_Callback_EF4C(struct WordSet *p, u32 i, u32 v);
extern void WORDSET_SetSlotFromMsg118(struct WordSet *p, u32 i, u32 v);

u32 WORDSET_DeleteStrbufED04(struct WordSet *p)
{
    u32 i;

    if (p->entries != 0) {
        for (i = 0; i < p->count; i++) {
            if (p->entries[i].str == 0) {
                break;
            }
            STRBUF_Delete(p->entries[i].str);
        }
        func_020307B0(p->entries);
    }
    if (p->buf != 0) {
        STRBUF_Delete(p->buf);
    }
    p->count = 0;
    return func_020307B0(p);
}

void WORDSET_Init(struct Tag *t)
{
    MI_CpuFill8(t, 0, 5);
    t->unk04 = 0;
}

void WORDSET_ResetSlot(struct WordSet *p, u32 i)
{
    WORDSET_Init(&p->entries[i].tag);
    STRBUF_Clear(p->entries[i].str);
}

void WORDSET_SetSlotText(struct WordSet *p, u32 i, const void *src,
                   const struct Tag *tag)
{
    if (i < p->count) {
        if (tag != 0) {
            p->entries[i].tag = *tag;
        } else {
            WORDSET_Init(&p->entries[i].tag);
        }
        STRBUF_Copy(p->entries[i].str, (struct U16Vec *)src);
    }
}

void WORDSET_SetSlotFromMessage(struct WordSet *p, u32 i, u32 id, u32 v)
{
    void *s = func_02045B38(0, 2, (u16)id, (u16)p->heap);

    if (s != 0) {
        func_02045CAC(s, v, p->buf);
        WORDSET_SetSlotText(p, i, p->buf, 0);
        MSGDATA_Delete(s);
    }
}

void WORDSET_SetSlotTag(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c)
{
    struct Tag tag;

    WORDSET_Init(&tag);
    tag.unk03 = n;
    tag.unk03b = (f == 0);
    WORDSET_SetSlotText(p, i, src, &tag);
}

void WORDSET_Callback(struct WordSet *p, u32 i, u16 v)
{
    func_02045CAC(gSpeciesNameBank, v, p->buf);
    WORDSET_SetSlotText(p, i, p->buf, 0);
}

void WORDSET_SetSlotMonName(struct WordSet *p, u32 i, void *mon)
{
    WORDSET_Callback(p, i, func_02017E1C(mon, 5, 0));
}

void WORDSET_SetSlotMonNameAlt(struct WordSet *p, u32 i, void *mon)
{
    WORDSET_Callback(p, i, func_02017E88(mon, 5, 0));
}

void WORDSET_Callback_EEC4(struct WordSet *p, u32 i, u32 v)
{
    WORDSET_SetSlotFromMessage(p, i, 0x119, v);
}

void WORDSET_SetSlotMonNameEx(struct WordSet *p, u32 i, void *mon)
{
    WORDSET_Callback_EEC4(p, i, (u16)func_02017E1C(mon, 5, 0));
}

void WORDSET_SetSlotMonSpecies(struct WordSet *p, u32 i, void *mon)
{
    func_02017E1C(mon, 0x73, (u32)p->buf);
    WORDSET_SetSlotText(p, i, p->buf, 0);
}

void WORDSET_SetSlotMonSpeciesAlt(struct WordSet *p, u32 i, void *mon)
{
    func_02017E88(mon, 0x73, (u32)p->buf);
    WORDSET_SetSlotText(p, i, p->buf, 0);
}

void WORDSET_SetSlotFromMsgCB(struct WordSet *p, u32 i, u32 v)
{
    WORDSET_SetSlotFromMessage(p, i, 0xCB, v);
}

void WORDSET_Callback_EF40(struct WordSet *p, u32 i, u32 v)
{
    WORDSET_SetSlotFromMessage(p, i, 0x36, v);
}

void WORDSET_Callback_EF4C(struct WordSet *p, u32 i, u32 v)
{
    WORDSET_SetSlotFromMessage(p, i, 0x117, v);
}

void WORDSET_SetSlotFromMsg118(struct WordSet *p, u32 i, u32 v)
{
    WORDSET_SetSlotFromMessage(p, i, 0x118, v);
}

void WORDSET_SetSlotFromBank(struct WordSet *p, u32 i, u32 v, u32 a, u32 b)
{
    if (a != 0) {
        WORDSET_SetSlotFromMsg118(p, i, v);
        return;
    }
    if (b != 0) {
        WORDSET_Callback_EF4C(p, i, v);
        return;
    }
    WORDSET_Callback_EF40(p, i, v);
}

void WORDSET_SetSlotFromMsgB6(struct WordSet *p, u32 i, u32 v)
{
    WORDSET_SetSlotFromMessage(p, i, 0xB6, v);
}

void WORDSET_SetSlotFromMsg18(struct WordSet *p, u32 i, u32 v)
{
    WORDSET_SetSlotFromMessage(p, i, 0x18, v);
}

void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d)
{
    WORDSET_FormatNumber(p->buf, a, b, c, d);
    WORDSET_SetSlotText(p, i, p->buf, 0);
}

void WORDSET_SetSlotPmsWord(struct WordSet *p, u32 i, u32 v)
{
    u16 x = v;

    PMSI_PARAM_ValidateWord(&x, 0, 0);
    PMS_WORD_LoadString((u16)x, p->buf, (u16)p->heap);
    WORDSET_SetSlotText(p, i, p->buf, 0);
}

