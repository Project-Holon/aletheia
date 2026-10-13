/*
 * function: func_021BA13C
 * address:  0x021BA13C
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * ov114 tail-call thunk: g(a, 0, b) via `ldr ip,pool; bx ip`.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void MI_CpuFill8(int, int, int);

void func_021BA13C(int a, int b)
{
    MI_CpuFill8(a, 0, b);
}
