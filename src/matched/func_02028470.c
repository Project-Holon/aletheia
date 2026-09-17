/*
 * function: func_02028470
 * address:  0x02028470
 * packet:   pkt_02027FEC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02028470.c \\
 *       --func func_02028470 --addr 0x02028470 --thumb --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_02082BCC(void *p, u32 v, u32 size);

void func_02028470(u8 *p, u32 v)
{
    func_02082BCC(p, 0, 8);
    *(u32 *)(p + 4) = v;
}
