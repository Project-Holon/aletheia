/*
 * function: func_021CD9F4
 * address: 0x021CD9F4
 * packet: pkt_ov093_021CD9F4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * u8 step preserves the low-byte result for every incoming word; no
 * signed int addition overflow. Wide step emits an extra narrowing pair.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void func_021CD9F4(u8 *p,u8 n) { p[0x1ab]+=n; if(p[0x1ab]>14) p[0x1ab]=14; }
