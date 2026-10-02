/*
 * function: func_021D84F8
 * address: 0x021D84F8
 * packet: pkt_ov093_021D84F8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
int func_021D84F8(u32 *p) { u16 n = *p >> 16; if (n == 0) n = 5; *p &= 65535; return n; }
