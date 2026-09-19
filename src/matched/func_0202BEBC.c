/*
 * function: func_0202BEBC
 * address:  0x0202BEBC
 * packet:   pkt_0202BEBC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls func_0202BFF0 when the object's +0 word is set.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202BEBC.c \
 *       --func func_0202BEBC --addr 0x0202BEBC --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_0202BFF0(u8 *p);

void func_0202BEBC(u8 *p)
{
    if (*(u32 *)p != 0) {
        func_0202BFF0(p);
    }
}
