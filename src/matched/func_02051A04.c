/*
 * function: func_02051A04
 * address:  0x02051A04
 * packet:   pkt_02051838
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Same 12-byte copy as func_020519C4, out of the class-5 slot.
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051A04.c \
 *       --func func_02051A04 --addr 0x02051A04 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct S12 {
    u32 a;
    u32 b;
    u32 c;
};

extern struct S12 *func_020518AC(void *p, int kind);

void func_02051A04(void *p, struct S12 *q)
{
    struct S12 *r = func_020518AC(p, 5);

    if (r != 0)
        *r = *q;
}
