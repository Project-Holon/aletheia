/*
 * function: func_021B86FC
 * address: 0x021B86FC
 * packet: pkt_ov102_021B86FC
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: 2026-10-05 wave P27: u16 field at +0x34 tested for non-zero. 14 B compiled, 2 B trailing pad. Twin shape in ov068 021BA6B8 area (ldrh #0x34 callers).
 * symbols:
 */
typedef unsigned char u8;
typedef unsigned short u16;
int func_021B86FC(u8 *p)
{
    return *(u16 *)(p + 0x34) != 0;
}
