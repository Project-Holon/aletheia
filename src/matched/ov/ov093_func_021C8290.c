/*
 * function: func_021C8290
 * address: 0x021C8290
 * packet: pkt_ov093_021C8290
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two bytes alignment padding follow.
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021BFA00 0x021BFA00 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
extern u8 *func_021B9934(char *p, int i);
extern int func_021BFA00(u8 *, u8 *, u8 *, void *);
int func_021C8290(u8 *p, int a, int b, void *item) { u8 *x; x=func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8,a); return func_021BFA00(p,x,func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8,b),item); }
