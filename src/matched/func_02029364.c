/*
 * function: func_02029364
 * address:  0x02029364
 * packet:   pkt_02029354
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02029364.c \\
 *       --func func_02029364 --addr 0x02029364 --thumb --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02029348(u8 *p);

void func_02029364(u8 *p)
{
    if (*(u32 *)(p + 0x1c) != 0) {
        func_02029348(p);
    }
}
