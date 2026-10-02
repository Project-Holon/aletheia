/*
 * function: func_021B6154
 * address: 0x021B6154
 * packet: pkt_ov016_021B6154
 * region: ov016
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0200F17C 0x0200F17C thumb
 *   func_02034AC4 0x02034AC4 arm
 *   ov107_id 0x0000006B data a1
 */
typedef unsigned int u32;
extern void func_0203064C(u32, u32, u32);
extern int func_0200F17C(u32);
extern int func_02034AC4(int);
extern char ov107_id[];
int func_021B6154(void) { func_0203064C(1, 15, 0x40100); func_0200F17C(1); func_02034AC4((int)ov107_id); return 1; }
