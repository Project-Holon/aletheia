/*
 * function: func_021B8080
 * address: 0x021B8080
 * packet: pkt_ov070_021B8080
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020061E4 0x020061E4 thumb
 *   func_0204B878 0x0204B878 arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
extern void func_020061E4(unsigned int id);
extern void func_0204B878(void *p, u16 v);
void func_021B8080(u8 *p) { func_020061E4(0x663); func_0204B878(*(void **)(p+0x72C),2); }
