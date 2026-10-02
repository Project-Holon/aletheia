/*
 * function: func_021CD924
 * address: 0x021CD924
 * packet: pkt_ov093_021CD924
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021EE63C 0x021EE63C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 *func_021EE63C(u16 *, u32 *);
u16 *func_021CD924(u8 *p, u32 *out) { if (*(u16 **)(p+0x10)) return func_021EE63C(*(u16 **)(p+0x10),out); return 0; }
