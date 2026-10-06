/*
 * function: func_0202EB9C
 * address:  0x0202EB9C
 * packet:   pkt_0202EB9C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     the slot-table dispatcher of blink_palanm.c (look the record up;
 *           remove and notify, or insert by key under the count-capped
 *           policy).  Closed in wave 16 under 1.1p1, no pin: the notify
 *           call is written in BOTH arms of the count test.  1.1p1 then
 *           cross-jumps the two notify tails (the then-arm's `b` at
 *           0x0202EC04, reached by the inner `blo` as a jump to a jump) and
 *           no longer merges the two func_0202ED00 calls, and the a/b/v
 *           register rotation of docs/notes/pkt_0202EB9C.c.txt resolves
 *           with it.  `mark` is the +0x26 bit-3 field of
 *           docs/families/blink_palanm.h.
 * symbols:
 *   func_0200974C  0x0200974C  thumb
 *   func_0200856C  0x0200856C  thumb
 *   func_0202ECB0  0x0202ECB0  thumb
 *   func_0202ED00  0x0202ED00  thumb
 *   func_0202ED60  0x0202ED60  thumb
 *   func_0202EC44  0x0202EC44  thumb
 *   func_0202EC24  0x0202EC24  thumb
 *   func_0202EC7C  0x0202EC7C  thumb
 */
typedef unsigned char u8;
typedef unsigned int  u32;
typedef int           s32;

struct Slot {
    u8  pad[0x26];
    u8      : 3;
    u8 mark : 1;
    u8      : 4;
    u8  pad2;
};

extern struct Slot *func_0200974C(u32 a);
struct Sub0200852CObj;
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern s32  func_0202ECB0(struct Slot *t, void *b);
extern void func_0202ED00(struct Slot *t, u32 n);
extern void func_0202ED60(u32 a, void *b, u32 c);
extern u32  func_0202EC44(struct Slot *t, u32 a);
struct Ent0202EC24;
extern u32 func_0202EC24(const struct Ent0202EC24 *p);
extern s32 func_0202EC7C(struct Slot *a0, u32 a1);

u32 func_0202EB9C(u32 a, void *b)
{
    struct Slot *t;
    u32 n;
    u32 v;

    t = func_0200974C(a);
    n = func_0202ECB0(t, b);

    if (n != 0x14) {
        if (t[n].mark)
            v = 1;
        else
            v = 0;
        func_0202ED00(t, n);
        func_0202ED60(a, b, v);
        return 1;
    }

    v = func_0200856C(b);
    if (func_0202EC44(t, v) < 5) {
        if (func_0202EC24((const struct Ent0202EC24 *)t) >= 0x14)
            func_0202ED00(t, 0);
        func_0202ED60(a, b, 0);
    } else {
        func_0202ED00(t, func_0202EC7C(t, v));
        func_0202ED60(a, b, 0);
    }
    return 2;
}
