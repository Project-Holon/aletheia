/*
 * function: PMSIV_EDIT_IsSubScreenLayer
 * address: 0x021BC6D0
 * packet: pkt_ov110_021BC6D0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:

 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

u32 PMSIV_EDIT_IsSubScreenLayer(u32 n)
{
    if (n >= 4) return 1;
    return 0;
}
