/*
 * function: func_0202ED90
 * address:  0x0202ED90
 * packet:   pkt_0202ECB0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0202EC24   0x0202EC24  thumb
 *
 * Stores the record at `b` into slot index func_0202EC24(a), after setting
 * the bit-3 mark from `c` and the bit-4 occupied flag.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202ED90.c \
 *       --func func_0202ED90 --addr 0x0202ED90 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Body {
    u32 w[10];
};

struct Slot {
    u8  pad[0x26];
    u8      : 3;
    u8 mark : 1;
    u8 flag : 1;
    u8      : 3;
    u8  pad2;
};

extern u32 func_0202EC24(u8 *p);

void func_0202ED90(u8 *a, struct Slot *b, u32 c)
{
    u32 i = func_0202EC24(a);

    if (i >= 0x14)
        return;

    if (c != 0)
        b->mark = 1;
    else
        b->mark = 0;

    b->flag = 1;

    *(struct Body *)(a + i * 0x28) = *(struct Body *)b;
}
