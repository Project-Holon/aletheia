/*
 * function: func_021BAA94
 * address: 0x021BAA94
 * packet: pkt_ov093_021BAA94
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
#include "../include/Obj21023.h"

typedef unsigned char u8;
extern char *func_021B9AEC(char *, int);
extern void func_021BB840(char *, int, int, int);
extern void func_021BB848(char *, char *, u8);
void func_021BAA94(char *p, int b, int c, u8 d)
{
 char *x;
 unsigned int q;
 unsigned int off;
 x = func_021B9AEC(*(char * *)&((struct Obj21023 *)p)->f10, c);
 q = (unsigned int)p + 0x14U;
 off = (unsigned int)c * 12U;
 func_021BB840((char *)(q + off), c, b, 1);
 func_021BB848((char *)(q + off), x, d);
}
