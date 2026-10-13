/*
 * function: func_021CACD0
 * address:  0x021CACD0
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * Thunk: MI_CpuFill8(a, 0, 20).
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void MI_CpuFill8(int, int, int);

void func_021CACD0(int a)
{
    MI_CpuFill8(a, 0, 0x14);
}
