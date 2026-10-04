/*
 * function: func_021F75DC
 * address: 0x021F75DC
 * packet: pkt_ov112_021F75DC
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:

 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void func_021F75DC(u8 *p, u16 v)
{
    u8 i;
    *(u16 *)(p + 0x434) = v;
    for (i = 0; i < 9; i++) {
        u8 *e = p + i * 0x108;
        if (*(u32 *)(e + 0x14) == 1) *(u32 *)(e + 0x18) = 1;
    }
}
