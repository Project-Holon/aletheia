/*
 * function: func_021B7D00
 * address: 0x021B7D00
 * packet: pkt_ov071_021B7D00
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B6F04 0x021B6F04 thumb ov071
 *   func_021B7E3C 0x021B7E3C thumb ov071
 */
#include "../include/Obj13176.h"

typedef unsigned char  u8;
extern int func_021B6F04(void **p, u8 *q);
extern void func_021B7E3C(void **,void *);
int func_021B7D00(int a,int *p,char *c,void **d) { if((unsigned char)c[0x2d]==1) return 1; func_021B6F04(((struct Obj13176 *)c)->f4,(u8 *)d); func_021B7E3C(d,c); switch(*p) { case 0:return 0; default:return 0; } }
