/*
 * function: func_0202945C
 * address:  0x0202945C
 * packet:   pkt_02029354
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202945C.c \\
 *       --func func_0202945C --addr 0x0202945C --thumb --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02005D90(u32 a, u32 b);

void func_0202945C(u8 *p)
{
    if (*(u32 *)(p + 0xc) != 0) {
        func_02005D90(*(u32 *)(p + 0xc), 0xffff);
        *(u32 *)(p + 8) = *(u32 *)(p + 0xc);
        *(u32 *)(p + 0xc) = 0;
        *(u32 *)(p + 0x10) = 0;
    }
}
