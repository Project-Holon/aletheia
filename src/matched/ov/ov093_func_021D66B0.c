/*
 * function: func_021D66B0
 * address: 0x021D66B0
 * packet: pkt_ov093_021D66B0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021E8CFC 0x021E8CFC thumb ov093
 *   func_021E8D04 0x021E8D04 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 func_021E8CFC(int);
extern u8 func_021E8D04(int);
void func_021D66B0(u8 *p,int n) { p[0xf8]=func_021E8CFC(n); p[0xf9]=func_021E8D04(n); }
