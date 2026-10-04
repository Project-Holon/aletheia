/*
 * function: func_021C899C
 * address: 0x021C899C
 * packet: pkt_ov128_021C899C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C8904 0x021C8904 thumb ov128
 *   func_021CA4B4 0x021CA4B4 thumb ov128
 */
#include "../include/Obj05381.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021C8904(char *,char *,void *,void *,int,char *,int,u16);
extern void func_021CA4B4(char *);
void func_021C899C(char *p,char *q,void *r,void *s,int t,char *table,int page,u16 heap) {func_021C8904(p,q,r,s,t,table,page,heap);func_021CA4B4(**(char ** *)&((struct Obj05381 *)p)->f8);}
