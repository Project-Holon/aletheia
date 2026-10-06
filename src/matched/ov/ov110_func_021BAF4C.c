/*
 * function: func_021BAF4C
 * address: 0x021BAF4C
 * packet: pkt_ov110_021BAF4C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021B6CCC 0x021B6CCC thumb ov067
 */
#include "../include/Obj13778.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Rec;
struct U16Vec;
extern void func_02045808(struct U16Vec *vec);
extern unsigned int func_02045C04(struct Rec *rec);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void func_021B6CCC(int *);
void func_021BAF4C(unsigned p) { int i; func_02045808(((struct Obj13778 *)p)->fAD0);func_021B6CCC(*(int * *)&((struct Obj13778 *)p)->f78);for(i=0;i<27;i++)func_02045C04(*(void **)(p+i*4+0xc));func_020307B0((void *)p); }
