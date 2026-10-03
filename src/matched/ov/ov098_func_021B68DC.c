/*
 * function: func_021B68DC
 * address: 0x021B68DC
 * packet: pkt_ov098_021B68DC
 * region: ov098
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045808 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_020403F4 0x020403F4 arm
 *   func_02045C04 0x02045C04 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02045808(void *); extern void func_0201ED04(void *); extern void func_0201CE48(void *); extern void func_020403F4(int); extern void func_02045C04(void *); extern void func_020452E8(void *); extern void func_020307B0(void *);
void func_021B68DC(u8 *p) { func_02045808(*(void **)(p+44)); func_0201ED04(*(void **)(p+48)); if (*(void **)p) func_0201CE48(*(void **)p); func_020403F4(1); func_02045C04(*(void **)(p+32)); func_020452E8(*(void **)(p+28)); func_020307B0(p); }
