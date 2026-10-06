/*
 * function: func_021F56C0
 * address: 0x021F56C0
 * packet: pkt_ov082_021F56C0
 * region: ov082
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020416D4 0x020416D4 arm
 */
typedef unsigned char u8;
typedef unsigned int   u32;
extern u8 func_020416D4(u32 layer);
void func_021F56C0(u8 *p) { int i; for(i=0;i<4;i++) p[i]=func_020416D4((u8)i); }
