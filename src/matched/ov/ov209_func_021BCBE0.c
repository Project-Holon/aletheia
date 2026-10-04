/*
 * function: func_021BCBE0
 * address: 0x021BCBE0
 * packet: pkt_ov209_021BCBE0
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9398 0x021B9398 thumb ov067
 *   func_021B93B8 0x021B93B8 thumb ov067
 *   func_021BDD7C 0x021BDD7C thumb ov209
 *   func_021BE51C 0x021BE51C thumb ov209
 */
#include "../include/Obj14667.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_021B9398(char *p, int index);
extern int func_021B93B8(char *);
extern void func_021BDD7C(char *, u16);
extern void func_021BE51C(char *, int);
void func_021BCBE0(char *p, int index)
{
    u32 v;
    v = func_021B9398(((struct Obj14667 *)p)->fC2C, index);
    if ((v & 0xF0000000) >> 28) func_021BDD7C(p, v & 0x0FFFFFFF);
    else func_021BDD7C(p, 0);
    func_021BE51C(p, index - func_021B93B8(*(char * *)&((struct Obj14667 *)p)->fC2C));
}
