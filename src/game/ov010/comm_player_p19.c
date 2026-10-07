/*
 * file:     comm_player_p19.c
 * unit:     yes
 * function: func_0216932C, func_02169354, func_0216937C, func_021693A0
 * address:  0x0216932C
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
 *   func_02169308  0x02169308  thumb  ov010
 *   func_02169520  0x02169520  thumb  ov010
 *   func_0216968C  0x0216968C  thumb  ov010
 *   func_02169710  0x02169710  thumb  ov010
 *   func_0216990C 0x0216990C thumb ov010
 *   func_020490F4 0x020490F4 arm
 *   func_02049238  0x02049238  arm
 */
#include "../../matched/include/Obj04162.h"
#include "../../matched/include/Obj03541.h"
#include "../../matched/include/Obj00306.h"
#include "../../matched/include/Obj19036.h"
#include "../../matched/include/Obj12053.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_02169308();
extern int func_02169520(int a0, int a1);
extern int func_0216968C(u8 *p);
extern int func_02169710();
extern void func_0216990C(u8 *);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049238(void *arc);
int func_0216932C(int a0);
int func_02169354(int a0, int a1);
void func_0216937C(u8 *p,int a,int b);
void func_021693A0(int a0);


int func_0216932C(int a0)
{
    int a1;
    int v0;
    int t4;
    int t5;
t5 = a0 + 0;
a0 = 1;
((struct Obj04162 *)t5)->f2 = a0;
t4 = (int)&v0;
loc_02169336:
a0 = t5 + 0;
    a0 = func_02169308(a0);
loc_0216933C:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02169520(a0, a1);
loc_02169344:
    a0 = v0;
a0 = ((struct Obj04162 *)((char *)a0))->f0;
    if (a0 != 0) goto loc_02169336;
loc_0216934C:
a0 = 0;
((struct Obj04162 *)t5)->f2 = a0;
    return a0;
}


int func_02169354(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t5 = a0 + 0;
t6 = a1 + 0;
t4 = 0;
    a0 = func_0216968C((u8 *)a0);
loc_02169360:
    if (a0 != 1) goto loc_02169378;
loc_02169364:
a0 = t5 + 0;
a0 = a0 + 0x98;
a0 = ((struct Obj03541 *)((char *)a0))->f0;
    if (a0 == 0) goto loc_02169376;
loc_0216936E:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02169710(a0, a1);
loc_02169376:
t4 = 1;
loc_02169378:
a0 = t4 + 0;
    return a0;}

void func_0216937C(u8 *p,int a,int b) { func_0216990C(p); func_021693A0((int)p); ((struct Obj19036 *)(*(u8 * *)&((struct Obj00306 *)p)->f2C))->f4=0; ((struct Obj00306 *)p)->f10=func_020490F4(a,b); }


void func_021693A0(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj12053 *)t4)->f10;
    if (a0 == 0) goto loc_021693B2;
loc_021693AA:
    func_02049238((void *)a0);
loc_021693AE:
a0 = 0;
((struct Obj12053 *)t4)->f10 = a0;
loc_021693B2:
    return;}
