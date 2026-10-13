/*
 * function: func_0200E370
 * address:  0x0200E370
 * packet:   pkt_0200E024
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Zeroes 0x284 bytes and sets the three trailing descriptor bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200E370.c \
 *       --func func_0200E370 --addr 0x0200E370 --thumb --cc 1.1p1
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void MI_CpuFill8(void *p, u32 v, u32 size);

void func_0200E370(u8 *p)
{
    MI_CpuFill8(p, 0, 0x284);
    p[0x280] = 0;
    p[0x281] = 8;
    p[0x282] = 0x1d;
}
