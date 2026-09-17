/*
 * function: func_0202C0D0
 * address:  0x0202C0D0
 * packet:   pkt_0202BE00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Resolves the object through func_0202C24C and, when found, forwards the
 * argument through func_0202C328.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202C0D0.c \
 *       --func func_0202C0D0 --addr 0x0202C0D0 --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32  func_0202C24C(u8 *p);
extern void func_0202C328(u32 r, u32 a);

void func_0202C0D0(u8 *p, u32 a)
{
    u32 r = func_0202C24C(p);

    if (r != 0) {
        func_0202C328(r, a);
    }
}
