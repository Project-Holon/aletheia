/*
 * function: func_021DCF58
 * address: 0x021DCF58
 * packet: pkt_ov137_021DCF58
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02039338 0x02039338 arm
 *   func_021DCBC4 0x021DCBC4 thumb ov137
 */
#include "../include/Obj23705.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
typedef unsigned short u16;
extern u16 func_02039338(void);
extern void func_021DCBC4(void *p, u32 a, const void *b, u32 c);
void func_021DCF58(int a,int b,u8 *p) {u8 v;if(func_02039338()==0) {v=a;func_021DCBC4(((struct Obj23705 *)p)->f10,10240,&v,1);}}
