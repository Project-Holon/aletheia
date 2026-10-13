/*
 * function: func_021BFC50
 * address:  0x021BFC50
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) (u32)(a0 + 56), 0, 640 to MI_CpuFill8.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void MI_CpuFill8(u32, u32, u32);

void func_021BFC50(u8 *a0)
{
    MI_CpuFill8((u32)(a0 + 56), 0, 640);
}

