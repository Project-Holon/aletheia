/*
 * function: func_02019E54
 * address:  0x02019E54
 * packet:   pkt_02019D58
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201A5FC   0x0201A5FC  thumb
 *
 * Maps a flag word to a small code: the four bits 2, 4, 0x20 and 0x40 all
 * answer 5 (one disjunction, so they share a single exit), then 8, 0x10,
 * 0x100, 0x80 and 1 each answer their own code and zero answers 0.  The
 * query is answered through two stack words whose addresses are passed to
 * func_0201A5FC, and the caller's second and third registers are forwarded
 * unchanged, so the query takes five arguments.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02019E54.c \
 *       --func func_02019E54 --addr 0x02019E54 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;
typedef unsigned long long u64;

typedef unsigned char  u8;
extern int func_0201A5FC(void *a0, void *a1, u8 *a2, char *a3, u32 *a4);

int func_02019E54(u32 a0, u32 a1, u32 a2)
{
    u64 q;
    u32 r;

    if (a0 == 0)
        return 0;

    func_0201A5FC((void *)a0, (void *)a1, (u8 *)a2, (char *)(&q), &r);
    if (r == 0)
        return 0;

    if ((r & 2) || (r & 4) || (r & 0x20) || (r & 0x40))
        return 5;
    if (r & 8)
        return 2;
    if (r & 0x10)
        return 3;
    if (r & 0x100)
        return 1;
    if (r & 0x80)
        return 7;
    if (r & 1)
        return 4;
    return 0;
}
