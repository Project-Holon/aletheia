/*
 * function: COMM_HISTORY_InsertOrReplace
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
 *           no longer merges the two COMM_HISTORY_RemoveAt calls, and the a/b/v
 *           register rotation of docs/notes/pkt_0202EB9C.c.txt resolves
 *           with it.  `mark` is the +0x26 bit-3 field of
 *           docs/families/blink_palanm.h.
 * symbols:
 *   func_0200974C  0x0200974C  thumb
 *   func_0200856C  0x0200856C  thumb
 *   COMM_HISTORY_FindByKeys  0x0202ECB0  thumb
 *   COMM_HISTORY_RemoveAt  0x0202ED00  thumb
 *   COMM_HISTORY_StoreAndNotify  0x0202ED60  thumb
 *   COMM_HISTORY_CountByKey  0x0202EC44  thumb
 *   COMM_HISTORY_CountLeadingOccupied  0x0202EC24  thumb
 *   COMM_HISTORY_FindByKey  0x0202EC7C  thumb
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
extern s32  COMM_HISTORY_FindByKeys(struct Slot *t, void *b);
extern void COMM_HISTORY_RemoveAt(struct Slot *t, u32 n);
extern void COMM_HISTORY_StoreAndNotify(u32 a, void *b, u32 c);
extern u32  COMM_HISTORY_CountByKey(struct Slot *t, u32 a);
struct Ent0202EC24;
extern u32 COMM_HISTORY_CountLeadingOccupied(const struct Ent0202EC24 *p);
extern s32 COMM_HISTORY_FindByKey(struct Slot *a0, u32 a1);

u32 COMM_HISTORY_InsertOrReplace(u32 a, void *b)
{
    struct Slot *t;
    u32 n;
    u32 v;

    t = func_0200974C(a);
    n = COMM_HISTORY_FindByKeys(t, b);

    if (n != 0x14) {
        if (t[n].mark)
            v = 1;
        else
            v = 0;
        COMM_HISTORY_RemoveAt(t, n);
        COMM_HISTORY_StoreAndNotify(a, b, v);
        return 1;
    }

    v = func_0200856C(b);
    if (COMM_HISTORY_CountByKey(t, v) < 5) {
        if (COMM_HISTORY_CountLeadingOccupied((const struct Ent0202EC24 *)t) >= 0x14)
            COMM_HISTORY_RemoveAt(t, 0);
        COMM_HISTORY_StoreAndNotify(a, b, 0);
    } else {
        COMM_HISTORY_RemoveAt(t, COMM_HISTORY_FindByKey(t, v));
        COMM_HISTORY_StoreAndNotify(a, b, 0);
    }
    return 2;
}
