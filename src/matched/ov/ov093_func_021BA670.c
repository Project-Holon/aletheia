/*
 * function: func_021BA670
 * address: 0x021BA670
 * packet: pkt_ov093_021BA670
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA710 0x021BA710 thumb ov093
 *   MYSTATUS_Copy  0x02008494  thumb  arm9
 */
#include "../include/Obj13287.h"

typedef unsigned char u8;
extern u8 func_021BA710(int, int);
extern void MYSTATUS_Copy(void *src, void *dst);
void func_021BA670(char *p, u8 k, void *dst)
{
 int i;
 void *q;
 i = func_021BA710(((struct Obj13287 *)p)->f46C, k);
 q = *(void **)(*(char * *)&((struct Obj13287 *)p)->f0 + i * 4 + 0x34);
 if (q != 0) MYSTATUS_Copy((void *)dst, q);
}
