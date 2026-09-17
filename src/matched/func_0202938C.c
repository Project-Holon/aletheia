/*
 * function: func_0202938C
 * address:  0x0202938C
 * packet:   pkt_02029354
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202938C.c \\
 *       --func func_0202938C --addr 0x0202938C --thumb --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02005E30(u32 v);

void func_0202938C(u8 *p)
{
    if (*(u32 *)(p + 8) != 0) {
        func_02005E30(*(u16 *)(p + 0x1a));
    }
}
