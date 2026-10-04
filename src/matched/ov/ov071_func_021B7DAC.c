/*
 * function: func_021B7DAC
 * address: 0x021B7DAC
 * packet: pkt_ov071_021B7DAC
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020498F4 0x020498F4 arm
 *   func_021B7234 0x021B7234 thumb ov071
 *   func_020409B4 0x020409B4 arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_021B7234(void *,int,int);
extern void func_020409B4(unsigned);
void func_021B7DAC(void *a,unsigned *b) { func_020498F4((void *)b[12],11,2,0,0,1,0x61); func_021B7234(a,0,2); func_020409B4(2); }
