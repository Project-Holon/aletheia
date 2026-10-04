/*
 * unit:     yes
 * function: func_021ED318, func_021ED374
 * address:  0x021ED318
 * packet:   pkt_ov093_021ED318
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F80E4  0x021F80E4  thumb  ov094
 *   func_021F7F04  0x021F7F04  thumb  ov094
 *   func_020311B8  0x020311B8  arm
 *   func_02031290  0x02031290  arm
 *   func_021ED384  0x021ED384  thumb  ov093
 */
#include "../include/Obj05231.h"
#include "../include/Obj12172.h"
#include "../include/Obj21591.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void func_021F80E4(u32 a);
struct S02030FB4;
extern void func_021F7F04(int a);
extern void *func_020311B8(u32 a, void *fn, u32 sz, u32 a3);
extern void *func_02031290(struct S02030FB4 *p);
extern void func_021ED384(u32 a, u8 *t);

void func_021ED318(char *p, u16 k, u16 a, int flag)
{
    u8 *t;

    if (flag != 0 || a == 0) {
        func_021F80E4(k);
        func_021F7F04(k);
        return;
    }
    t = func_02031290(func_020311B8(((struct Obj21591 *)p)->f2C, (void *)func_021ED384, 0x10, 1));
    ((struct Obj05231 *)t)->f6 = k;
    *(char * *)&((struct Obj05231 *)t)->f0 = p + 0x48 + k * 0xc;
    *(char * *)&((struct Obj05231 *)t)->fC = p + 0x42;
    if (a == 0)
        a = 0x26c;
    ((struct Obj05231 *)t)->f8 = a;
    ((struct Obj05231 *)t)->f4 = 0;
    (**(u8 * *)&((struct Obj05231 *)t)->fC)++;
}

int func_021ED374(char *p)
{
    if (((struct Obj12172 *)p)->f42 == 0)
        return 1;
    return 0;
}
