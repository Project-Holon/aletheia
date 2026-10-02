/*
 * function: func_021F56E4
 * address: 0x021F56E4
 * packet: pkt_ov082_021F56E4
 * region: ov082
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204047C 0x0204047C arm
 */
typedef unsigned char u8;
extern void func_0204047C(u8 layer, unsigned short value);
void func_021F56E4(u8 *p) { int i; for(i=0;i<4;i++) func_0204047C(i,p[i]); }
