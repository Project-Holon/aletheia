/*
 * unit: yes
 * function: func_02177150, func_0217715C, func_02177160
 * address: 0x02177150
 * packet: pkt_ov014_02177150
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02177E20 0x02177E20 thumb ov014
 *   func_021776C4 0x021776C4 thumb ov014
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern int func_02177E20(u32,u8 *,u32,u32);
int func_02177150(u32 a,u8 *b,u32 c,u32 d,u32 e) { return func_02177E20(a,b,c,e); }
extern int func_021776C4(void);
int func_0217715C(void) { return 0; }
int func_02177160(void) { return func_021776C4(); }
