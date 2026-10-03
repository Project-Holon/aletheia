/*
 * function: func_021B80BC
 * address: 0x021B80BC
 * packet: pkt_ov106_021B80BC
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B7F74 0x021B7F74 thumb ov106
 *   func_021B7FEC 0x021B7FEC thumb ov106
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
/* Both callback callees ignore entry arguments, but the original explicitly supplies them. */
extern void func_021B7F74(u8 *);
extern void func_021B7FEC(u8 *);
void func_021B80BC(void *a,u8 *p) { func_021B7F74(p); func_021B7FEC(p+16); }
