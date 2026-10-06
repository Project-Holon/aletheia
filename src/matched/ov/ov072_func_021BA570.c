/*
 * function: func_021BA570
 * address: 0x021BA570
 * packet: pkt_ov072_021BA570
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BAF24 0x021BAF24 thumb ov072
 *   func_021BAA14 0x021BAA14 thumb ov072
 *   func_020307B0 0x020307B0 arm
 *   func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj09906.h"
typedef unsigned int u32;
extern void func_021BAF24(unsigned int *p);
extern void func_021BAA14(unsigned int *p);
extern u32 func_020307B0(void *p);
extern void func_02082BCC(void *p,int v,int n);
void func_021BA570(char *p) { u32 i; func_021BAF24((unsigned int *)(p+32)); for(i=0;i<((struct Obj09906 *)p)->fC;i++) func_021BAA14((void *)(*(u32 *)&((struct Obj09906 *)p)->f8+i*0x44)); func_020307B0(((struct Obj09906 *)p)->f8); func_02082BCC(p,0,40); }
