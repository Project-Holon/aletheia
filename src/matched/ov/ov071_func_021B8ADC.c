/*
 * function: func_021B8ADC
 * address: 0x021B8ADC
 * packet: pkt_ov071_021B8ADC
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020498F4 0x020498F4 arm
 *   func_020409B4 0x020409B4 arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020409B4(unsigned int);
void func_021B8ADC(char *p) { func_020498F4((void *)(*(unsigned int *)(p+0x30)),5,6,0,0,1,0x61); func_020409B4(6); func_020409B4(4); }
