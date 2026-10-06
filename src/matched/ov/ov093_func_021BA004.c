/*
 * function: func_021BA004
 * address: 0x021BA004
 * packet: pkt_ov093_021BA004
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9F70 0x021B9F70 thumb ov093
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char  u8;
extern int func_021B9F70(u8 *p, int i);
u16 func_021BA004(char *p, int i)
{
    if (func_021B9F70((u8 *)p, i)) return *(u16 *)((u32)p + (u32)i * 0x28 + 0x2a);
    return 0;
}
