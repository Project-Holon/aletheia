/*
 * function: func_021BA71C
 * address: 0x021BA71C
 * packet: pkt_ov213_021BA71C
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BAC94 0x021BAC94 thumb ov213
 *   func_021B629C 0x021B629C thumb ov067
 */
#include "../include/Obj14696.h"
typedef unsigned int   u32;
extern u32 func_021BAC94(char *p);extern void *func_021B629C(void *,int,unsigned char,unsigned char,unsigned char,unsigned short);
void *func_021BA71C(char *p,int a,int b,unsigned short c){return func_021B629C(p+8,func_021BAC94(((struct Obj14696 *)p)->f0),a,b,c,((struct Obj14696 *)p)->f4);}
