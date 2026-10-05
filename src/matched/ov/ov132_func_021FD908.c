/*
 * function: func_021FD908
 * address: 0x021FD908
 * packet: pkt_ov132_021FD908
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 * Getter: returns the word at offset 0x158.
 */
typedef unsigned char u8;
typedef unsigned int u32;
u32 func_021FD908(u8 *p)
{
 return *(u32 *)(p+0x158);
}
