/*
 * function: func_021BAB10
 * address: 0x021BAB10
 * packet: pkt_ov093_021BAB10
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9AEC 0x021B9AEC thumb ov093
 *   func_021BB840 0x021BB840 thumb ov093
 *   func_021BB848 0x021BB848 thumb ov093
 */
#include "../include/Obj21024.h"

typedef unsigned char u8;
extern char *func_021B9AEC(char *, int);
struct Q4;
extern void func_021BB840(struct Q4 *p, int a, int b, int c);
extern void func_021BB848(u8 *p, void *q, u8 v);
void func_021BAB10(char *p, u8 c, u8 d)
{
 char *x;
 unsigned int q;
 unsigned int off;
 x = func_021B9AEC(*(char * *)&((struct Obj21024 *)p)->f10, c);
 q = (unsigned int)p + 0x14U;
 off = (unsigned int)c * 12U;
 func_021BB840((struct Q4 *)(q + off), c, 0, 0);
 func_021BB848((u8 *)(q + off), x, d);
}
