/*
 * function: func_021C87A0
 * address:  0x021C87A0
 * packet:   pkt_ov021_021C87A0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Unlabelled leaf in the 0x1C-byte record accessor run; called from ov010
 * func_02166734 case 5. 10 bytes plus 2 bytes of padding.
 * (ov128_func_021C87A0.c is a different overlay's function.)
 */
typedef unsigned char u8;
typedef unsigned int u32;

u32 func_021C87A0(void *p, u32 i)
{
    return *(u32 *)((u8 *)p + i * 0x1C + 0x18);
}
