/*
 * function: func_021B9888
 * address: 0x021B9888
 * packet: pkt_ov069_021B9888
 * region: ov069
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020403F4 0x020403F4 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   d_021BA60C 0x021BA60C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_020403F4(u32 layer);
extern void func_0203F9B4(void);
extern const u32 d_021BA60C[];
void func_021B9888(void) { u32 i; for(i=0;i<5;i++) func_020403F4((u8)d_021BA60C[i]); func_0203F9B4(); }
