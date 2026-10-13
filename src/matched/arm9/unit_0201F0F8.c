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
 * function: func_0201F0F8, func_0201F104, func_0201F124, func_0201F134,
 *           func_0201F140, func_0201F14C, func_0201F158, func_0201F164,
 *           func_0201F184, func_0201F198, func_0201F1B0, func_0201F1C8,
 *           func_0201F1E0, func_0201F230
 *
 * The second half of the wordset.c setter run, 0x0201F0F8..0x0201F250.
 * Every one of these is the same shape: clamp or range-check the caller's
 * value, then render one message id through func_0201EDD0.  The constants are
 * message ids and the ones above 255 (0x116, 0x11B, 0x1CD) arrive from the
 * function's own literal pool because Thumb's `movs` immediate stops at 255;
 * they are plain numbers, not relocations, which is the negative case of
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 *
 * func_0201F184 clamps with a signed `blt`, so its value parameter is `s32`
 * while every other clamp in the file is an unsigned `bls`/`bhi`.
 *
 * func_0201F1E0 clears the slot unconditionally before the range check and
 * only overwrites it when the id is in range, so a caller with an
 * out-of-range id leaks the rendered string; that is what the bytes say and
 * it is reproduced here rather than tidied.
 *
 * The calls to func_0201ED64 are carried by the `matched` class through
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
extern u32   func_02025B94(u32 a);
extern u32 func_0202A230(void *a, u32 idx);
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

extern void func_0201ED64(struct WordSet *p, u32 i);
extern void func_0201ED84(struct WordSet *p, u32 i, const void *src,
                          const struct Tag *tag);
extern void func_0201EDD0(struct WordSet *p, u32 i, u32 id, u32 v);
extern void func_0201F0F8(struct WordSet *p, u32 i, u32 v);

void func_0201F0F8(struct WordSet *p, u32 i, u32 v)
{
    func_0201EDD0(p, i, 0xBF, v);
}

void func_0201F104(struct WordSet *p, u32 i, u32 a)
{
    func_0201F0F8(p, i, (u8)func_0202A230((void *)a, 1));
}

void func_0201F124(struct WordSet *p, u32 i, u32 v)
{
    func_0201EDD0(p, i, 0x11B, v);
}

void func_0201F134(struct WordSet *p, u32 i, u32 v)
{
    func_0201EDD0(p, i, 0xBE, v);
}

void func_0201F140(struct WordSet *p, u32 i, u32 v)
{
    func_0201EDD0(p, i, 0xB4, v);
}

void func_0201F14C(struct WordSet *p, u32 i, u32 v)
{
    func_0201EDD0(p, i, 0x37, v);
}

void func_0201F158(struct WordSet *p, u32 i, u32 v)
{
    func_0201EDD0(p, i, 0x59, v);
}

void func_0201F164(struct WordSet *p, u32 i, u32 a, u32 b)
{
    func_0200785C((void *)a, b, p->buf);
    func_0201ED84(p, i, p->buf, 0);
}

void func_0201F184(struct WordSet *p, u32 i, s32 v)
{
    if (v >= 0x30) {
        v = 0;
    }
    func_0201EDD0(p, i, 0xA0, v);
}

void func_0201F198(struct WordSet *p, u32 i, u32 v)
{
    if (v > 8) {
        func_0201ED64(p, i);
        return;
    }
    func_0201EDD0(p, i, 0x2B, v);
}

void func_0201F1B0(struct WordSet *p, u32 i, u8 v)
{
    if (v > 0x91) {
        func_0201ED64(p, i);
        return;
    }
    func_0201EDD0(p, i, 0, v);
}

void func_0201F1C8(struct WordSet *p, u32 i, u32 v)
{
    if (v > 8) {
        func_0201ED64(p, i);
        return;
    }
    func_0201EDD0(p, i, 0x38, v);
}

void func_0201F1E0(struct WordSet *p, u32 i, u32 v)
{
    void *s = func_02045B38(0, 3, (u16)0x1CD, (u16)p->heap);

    func_0201ED64(p, i);
    if (v <= 6 && s != 0) {
        MSGDATA_ReadString(s, v + 0x2B, p->buf);
        func_0201ED84(p, i, p->buf, 0);
        MSGDATA_Delete(s);
    }
}

void func_0201F230(struct WordSet *p, u32 i, u32 v)
{
    if (v < 1) {
        v = 1;
    } else if (v > 0xC) {
        v = 0xC;
    }
    func_0201EDD0(p, i, 0x116, v - 1);
}
