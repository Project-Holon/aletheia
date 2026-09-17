/*
 * function: func_0202B224
 * address:  0x0202B224
 * packet:   pkt_0202B1F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clears the object's state word when it is set.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B224.c \
 *       --func func_0202B224 --addr 0x0202B224 --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

void func_0202B224(u8 *p)
{
    if (*(u32 *)p != 0) {
        *(u32 *)p = 0;
    }
}
