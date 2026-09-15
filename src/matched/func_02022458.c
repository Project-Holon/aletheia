/*
 * function: func_02022458
 * address:  0x02022458
 * packet:   pkt_02022174
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Resets the 24-byte two-entry callback block at +0x74 of the dual-screen
 * text object (the buffer func_0202208C hands to both screen builders):
 * three parallel two-element arrays, the context pointers at +0x00, the
 * handlers at +0x08 and the user words at +0x10.  Both handler slots are
 * armed with the do-nothing func_020225F0 rather than a null, so the
 * dispatcher never has to test them.
 *
 * symbols:
 *   func_020225F0  0x020225F0  thumb
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022458.c \
 *       --func func_02022458 --addr 0x02022458 --cc 1.1p1 --thumb
 */
typedef unsigned int u32;

typedef void (*Handler)(void);

struct Slots {
    void   *ctx[2];
    Handler fn[2];
    u32     arg[2];
};

extern void func_020225F0(void);

void func_02022458(struct Slots *p)
{
    int i;

    for (i = 0; i < 2; i++) {
        p->ctx[i] = 0;
        p->fn[i] = func_020225F0;
        p->arg[i] = 0;
    }
}
