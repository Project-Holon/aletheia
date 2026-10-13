/*
 * function: DWCi_Ndi_memclr
 * address:  0x021C7A30
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * Thunk: MI_CpuFill8(a, 0, b).
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void MI_CpuFill8(int, int, int);

void DWCi_Ndi_memclr(int a, int b)
{
    MI_CpuFill8(a, 0, b);
}
