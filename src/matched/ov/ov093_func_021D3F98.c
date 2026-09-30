/*
 * function: func_021D3F98
 * address: 0x021D3F98
 * packet: pkt_ov093_021D3F98
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
int func_021D3F98(u8 *p)
{
    if (*(u16 *)(p+0xc) == *(u16 *)(p+8)) return 1;
    return 0;
}
