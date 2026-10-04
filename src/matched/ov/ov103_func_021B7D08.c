/*
 * function: func_021B7D08
 * address: 0x021B7D08
 * packet: pkt_ov103_021B7D08
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: Two-byte zero alignment padding follows the compiled body.
 * symbols:
 *   func_021B7EB8 0x021B7EB8 thumb ov103
 *   func_02048AC4 0x02048AC4 arm
 *   func_02046788 0x02046788 arm
 */
#include "../include/Obj22180.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021B7EB8(u8 *); extern void func_02048AC4(void *); extern void func_02046788(void);
void func_021B7D08(u8 *p) { int i; for(i=0;i<2;i++)func_021B7EB8(p+4+i*0x60); func_02048AC4(((struct Obj22180 *)p)->f0); func_02046788(); }
