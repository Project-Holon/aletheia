/*
 * file:     fldmmdl_p33.c
 * unit:     yes
 * function: func_0216E114, func_0216E160
 * address:  0x0216E114
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D948  0x0216D948  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_02164010  0x02164010  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216DAA0  0x0216DAA0  thumb  ov010
 *   func_0216D744  0x0216D744  thumb  ov010
 *   func_0216DA88  0x0216DA88  thumb  ov010
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_0216E40C  0x0216E40C  thumb  ov010
 */
#include "../../matched/include/Obj17853.h"
#include "../../matched/include/Obj17854.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void *func_0216D67C(void *a0);
extern int func_0216D948(int a0);
extern u32 func_0216D57C(void *p, u32 v);
extern int func_02164010(int a);
extern int func_0216D674();
extern int func_0216DAA0(void *a0);
extern int func_0216D744();
extern int func_0216DA88();
extern void *func_0216E3C4(void *p);
extern u32 func_0216E40C(int i);
int func_0216E114(int a0);
int func_0216E160(int a0);


/*
 * blocked:  listing 76 compiled 74
 */
int func_0216E114(int a0)
{
    int a1;
    int t4;

t4 = a0 + 0;
    a0 = (int)func_0216D67C((void *)a0);
loc_0216E11C:
    a0 = func_0216D948(a0);
loc_0216E120:
    if (a0 == 0) goto loc_0216E15C;
loc_0216E124:
a1 = 1;
a0 = t4 + 0;
a1 = a1 << 0xc;
    a0 = func_0216D57C((void *)a0, a1);
loc_0216E12E:
    if (a0 == 0) goto loc_0216E138;
loc_0216E132:
a0 = t4 + 0;
    a0 = func_02164010(a0);
loc_0216E138:
a0 = t4 + 0;
a1 = 0;
    a0 = func_0216D674(a0, a1);
loc_0216E140:
a0 = t4 + 0;
    a0 = func_0216DAA0((void *)a0);
loc_0216E146:
    if (a0 != 0) goto loc_0216E15C;
loc_0216E14A:
a0 = t4 + 0;
    a0 = func_0216E160(a0);
loc_0216E150:
a0 = t4 + 0;
    a0 = func_0216D744(a0);
loc_0216E156:
a0 = t4 + 0;
    a0 = func_0216DA88(a0);
loc_0216E15C:
    return a0;}


int func_0216E160(int a0)
{
    int t4;
    void *p;

t4 = a0 + 0;
    p = func_0216E3C4((void *)a0);
loc_0216E168:
a0 = ((struct Obj17854 *)p)->f3;
    a0 = func_0216E40C(a0);
loc_0216E16E:
t4 = t4 + 0x90;
((struct Obj17853 *)((char *)t4))->f0 = a0;
    return a0;}
