/*
 * function: func_021B9A08
 * address: 0x021B9A08
 * packet: pkt_ov225_021B9A08
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9B38 0x021B9B38 thumb ov225
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_021B9B38(const u32 *);
u32 func_021B9A08(const u8 *p) { return func_021B9B38((const u32 *)(p+4)); }
