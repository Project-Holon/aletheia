/*
 * function: func_02029374
 * address:  0x02029374
 * packet:   pkt_02029354
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02029374.c \\
 *       --func func_02029374 --addr 0x02029374 --thumb --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02005DF8(u32 v);
extern void func_02005DE4(u32 v);

void func_02029374(u8 *p)
{
    if (*(u32 *)(p + 8) == 0) {
        return;
    }
    func_02005DF8(*(u16 *)(p + 0x18));
    func_02005DE4(0);
}
