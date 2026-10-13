/*
 * function: BTL_SERVER_FLOW_ClampDamageToHp
 * address: 0x021C15D4
 * packet: pkt_ov093_021C15D4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D59B4 0x021D59B4 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D59B4(u8 *p, int k);

u32 BTL_SERVER_FLOW_ClampDamageToHp(void *p, u32 n)
{
    u32 v = func_021D59B4(p, 13);
    if (n > v) n = v;
    return n;
}
