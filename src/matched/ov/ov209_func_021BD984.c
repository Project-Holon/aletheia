/*
 * function: func_021BD984
 * address: 0x021BD984
 * packet: pkt_ov209_021BD984
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021BE9D4 0x021BE9D4 data a4
 *   func_021BC380 0x021BC380 thumb ov209
 *   func_0204A48C 0x0204A48C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Template {u32 w[7];} Template;struct Cfg;extern const Template d_021BE9D4;extern void *func_021BC380(void);extern void func_0204A48C(const struct Cfg *,u32,u32);
void func_021BD984(char *p) {Template t;t=d_021BE9D4;func_0204A48C((const struct Cfg *)&t,(u32)func_021BC380(),107);}
