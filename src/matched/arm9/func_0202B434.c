/*
 * function: func_0202B434
 * address:  0x0202B434
 * packet:   pkt_0202B1F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns the object's +0xc word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B434.c \
 *       --func func_0202B434 --addr 0x0202B434 --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

u32 func_0202B434(u8 *p)
{
    return *(u32 *)(p + 0xc);
}
