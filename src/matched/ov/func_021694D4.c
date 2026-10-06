/*
 * function: func_021694D4
 * address:  0x021694D4
 * packet:   pkt_021694D4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02169998  0x02169998  thumb  ov010
 *   func_02169550  0x02169550  thumb  ov010
 *   func_02169568  0x02169568  thumb  ov010
 *   func_0216959C  0x0216959C  thumb  ov010
 *   func_0216990C  0x0216990C  thumb  ov010
 */
#include "../include/Obj00306.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02169998(int a0, int a1);
extern int func_02169550();
extern int func_02169568();
extern int func_0216959C();
extern int func_0216990C();

void func_021694D4(int a0, int a1)
{
    int t4;

t4 = a0 + 0;
a0 = *(int *)&((struct Obj00306 *)t4)->f2C;
    a0 = func_02169998(a0, a1);
loc_021694DE:
a0 = t4 + 0;
    a0 = func_02169550(a0);
loc_021694E4:
a0 = t4 + 0;
    a0 = func_02169568(a0);
loc_021694EA:
a0 = t4 + 0;
    a0 = func_0216959C(a0);
loc_021694F0:
a0 = t4 + 0;
    a0 = func_0216990C(a0);
loc_021694F6:
    return;}
