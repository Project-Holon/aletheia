/*
 * function: func_021BA858
 * address: 0x021BA858
 * packet: pkt_ov099_021BA858
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201FEBC 0x0201FEBC thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_0201FEBC(u8 *);
u32 func_021BA858(char *p)
{
    u32 r = func_0201FEBC(*(u8 **)(p + 0x108));
    if (r != 0xFFFFFFFF)
        *(u32 *)(p + 0x108) = 0;
    return r;
}
