/*
 * function: func_02010DF4
 * address:  0x02010DF4
 * packet:   pkt_02010DB4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_02146228        0x02146228  data
 *   func_02010F50     0x02010F50  thumb
 *
 * The per-entry initialiser of the table func_02010DB4 clears and
 * func_02010DCC counts down: 13 calls to func_02010F50(i), then the count
 * itself is written as a byte at +0x1C of the object at 0x02146228.
 *
 * The loop is rotated the short way - `i = 0; if (i >= 13) goto tail;` then
 * body, `i++`, back edge - which is what a plain `for` over a constant bound
 * compiles to here.
 *
 * The two references to the table are the only relocations; the pool word
 * for 0x02146228 is `literal`-attested from outside this range.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010DF4.c \
 *       --func func_02010DF4 --addr 0x02010DF4 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub02014628 {
    u8 pad0[0x1C];
    u8 f1c;         /* +0x1C */
};

extern struct Sub02014628 g_02146228;
extern void func_02010F50(int i);

void func_02010DF4(void)
{
    int i;

    for (i = 0; i < 13; i++)
        func_02010F50(i);
    g_02146228.f1c = 13;
}
