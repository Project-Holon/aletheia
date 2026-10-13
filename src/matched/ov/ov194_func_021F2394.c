/*
 * function: func_021F2394
 * address: 0x021F2394
 * packet: pkt_ov194_021F2394
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   func_021F233C 0x021F233C thumb ov194
 */
#include "../include/Obj03897.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 STRBUF_GetEosChar(void);
extern void func_021F233C(char *);
void func_021F2394(u8 *p) {if(((struct Obj03897 *)p)->f1E) {((struct Obj03897 *)p)->f1E=0;*(u16 *)(p+((struct Obj03897 *)p)->f1E*2)=STRBUF_GetEosChar();((struct Obj03897 *)p)->f28=1;}func_021F233C((char *)p);}
