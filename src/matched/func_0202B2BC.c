/*
 * function: func_0202B2BC
 * address:  0x0202B2BC
 * packet:   pkt_0202B1F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-calls func_02005F24(0x300, value).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B2BC.c \
 *       --func func_0202B2BC --addr 0x0202B2BC --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_02005F24(u32 a, u32 b);

void func_0202B2BC(u8 *p)
{
    func_02005F24(0x300, *(u32 *)(p + 4));
}
