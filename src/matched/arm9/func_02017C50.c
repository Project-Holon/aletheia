/*
 * function: func_02017C50
 * address:  0x02017C50
 * packet:   pkt_020179B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Picks one of three record types and writes selector 0xa.  `mask` is a
 * bit test against the byte returned by selector 0, and which bit it is
 * depends on selector 0x77: below 0x14 the mask is bit 0, at or above it the
 * mask is bit 16.  The comparison against 0x14 is *unsigned* in the original
 * (`bhs`, not `bge`), so func_02017E88 must be declared returning an unsigned
 * type - an `int` declaration emits `bge` and costs four bytes.
 *
 * Declaration order is load bearing: `r6` (the 0x1a/0x1b/0x1c selector) is
 * declared first and takes the higher register, `mask` second and takes the
 * lower one.  Reversing them keeps the same instruction count but swaps r4
 * and r6 in nine places.
 *
 * EXACT*: the extent runs into the follower's four-byte pad.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02017C50.c \
 *       --func func_02017C50 --addr 0x02017C50 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

struct Personal;
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern void *func_02019C54(u32 a, u32 b);
extern u32 func_02019C7C(void *h);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_02017E64(void *p, u32 id, u32 v);

void func_02017C50(int a0, int a1)
{
    int v = (int)func_02019C54(a1, (unsigned short)func_02017E88((void *)a0, 0x6f, 0));
    int r7 = func_02017E88((void *)a0, 0, 0);
    int r6 = 0x1a;
    u32 mask = 1 << 16;

    if (func_02017E88((void *)a0, 0x77, 0) < 0x14) {
        mask = 1;
    }
    if (func_02017E88((void *)a0, 0x71, 0) != 0) {
        r6 = 0x1c;
    } else if (func_02019C7C((void *)v) == 2 && (r7 & mask) != 0) {
        r6 = 0x1b;
    }
    func_02017E64((void *)a0, 0xa, func_0201AE1C((const struct Personal *)v, r6));
}
