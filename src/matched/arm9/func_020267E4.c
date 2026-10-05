/*
 * function: func_020267E4
 * address:  0x020267E4
 * packet:   pkt_020267E4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   MI_CpuCopy8    0x02082D44  arm
 *   d_02146940     0x02146940  data  a4
 */

typedef unsigned char u8;

extern void MI_CpuCopy8(const void *, void *, unsigned int);
extern u8 *d_02146940;

void func_020267E4(void *p)
{
    MI_CpuCopy8(d_02146940 + 4, p, 0x5C);
}
