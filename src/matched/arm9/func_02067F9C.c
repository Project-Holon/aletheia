/*
 * function: func_02067F9C
 * address:  0x02067F9C
 * packet:   pkt_02067F78
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Range lookup over a singly linked list of key records: walk the chain hung
 * off (*a0)->f10 and hand the first record whose [lo, hi] halfword pair
 * contains `key` to func_02067EB0, which returns the mapped word.  No record
 * holds the key: return the pooled 0xFFFF sentinel.  The record's link is at
 * +0x04 (used by the twin at 0x02067FE4) while the chain head here is the
 * +0x10 field of the object the caller's pointer points at.
 *
 * The half-open test is ONE conjunction (`key >= lo && key <= hi`): the
 * original's `ldrhls`/`cmpls` pair is the second comparison issued
 * conditionally on the first, which is a `&&`, not two nested guards.
 *
 * symbols:
 *   func_02067EB0  0x02067EB0  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec {
    u16  lo;    /* 0x00 */
    u16  hi;    /* 0x02 */
    u8   pad_04[4];
    struct Rec *next;   /* 0x08 */
};

struct Obj {
    u8          pad_00[0x10];
    struct Rec *chain;  /* 0x10 */
};

extern u32 func_02067EB0(struct Rec *r, u32 key);

u32 func_02067F9C(struct Obj **a0, u32 key)
{
    struct Rec *r = (*a0)->chain;

    while (r != 0) {
        if (r->lo <= key && key <= r->hi) {
            return func_02067EB0(r, key);
        }
        r = r->next;
    }

    return 0xffff;
}
