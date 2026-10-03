/*
 * function: func_0217ECD0
 * address: 0x0217ECD0
 * packet: pkt_ov019_0217ECD0
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02008550 0x02008550 thumb
 *   d_02180324 0x02180324 data a2
 */
typedef unsigned short u16;
typedef unsigned char  u8;
struct Sub0200852CObj;
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern const u16 d_02180324[];
u16 func_0217ECD0(void ***ctx)
{
    return d_02180324[func_02008550(**ctx)];
}
