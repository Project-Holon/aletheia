/*
 * function: func_021C8030
 * address: 0x021C8030
 * packet: pkt_ov093_021C8030
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two bytes alignment padding follow.
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D80BC 0x021D80BC thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *func_021B9934(char *p, int i);
extern int func_021D80BC(void *, int, int, u16);
int func_021C8030(u8 *p, int v, u16 k) { return func_021D80BC(((struct Obj00003 *)p)->f4, *(int *)&((struct Obj00003 *)p)->f8, (int)func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8,v), k); }
