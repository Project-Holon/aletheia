/*
 * function: func_020519C4
 * address:  0x020519C4
 * packet:   pkt_02051838
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Copies a 12-byte record into the slot func_020518AC hands back for class 2.
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020519C4.c \
 *       --func func_020519C4 --addr 0x020519C4 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct S12 {
    u32 a;
    u32 b;
    u32 c;
};

extern void *func_020518AC(void *obj, int kind);

void func_020519C4(void *p, struct S12 *q)
{
    struct S12 *r = func_020518AC(p, 2);

    if (r != 0)
        *r = *q;
}
