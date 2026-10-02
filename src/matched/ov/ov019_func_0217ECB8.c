/*
 * function: func_0217ECB8
 * address: 0x0217ECB8
 * packet: pkt_ov019_0217ECB8
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02008550 0x02008550 thumb
 *   d_02180328 0x02180328 data a2
 */
typedef unsigned short u16;
extern int func_02008550(void *p);
extern const u16 d_02180328[];
u16 func_0217ECB8(void ***ctx)
{
    return d_02180328[func_02008550(**ctx)];
}
