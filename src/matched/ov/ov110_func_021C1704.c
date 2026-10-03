/*
 * function: func_021C1704
 * address: 0x021C1704
 * packet: pkt_ov110_021C1704
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021C1838 0x021C1838 thumb ov110
 *   func_021C17D0 0x021C17D0 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021C1838(void *);
extern void func_021C17D0(void *);
void func_021C1704(u8 *p) { func_021C1838(p+4); func_021C17D0(p); }
