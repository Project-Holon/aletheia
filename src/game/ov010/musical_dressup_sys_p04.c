/*
 * file:     musical_dressup_sys_p04.c
 * unit:     yes
 * function: func_02155F4C, func_02155F9C
 * address:  0x02155F4C
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
 *   func_02156CD8  0x02156CD8  thumb  ov010
 *   func_02156F98  0x02156F98  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   func_021F6888  0x021F6888  thumb
 *   func_0215716C  0x0215716C  thumb  ov010
 *   func_02156CAC  0x02156CAC  thumb  ov010
 */
#include "../../matched/include/Obj02657.h"
#include "../../matched/include/Obj07201.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Obj { int f00; int f04; int f08; } Obj;

extern int func_02156CD8();
extern int func_02156F98();
extern int func_020307B0();
extern int func_021F6888();
extern int func_0215716C();
extern Obj *func_02156CAC(int a, int b, int c);
int func_02155F4C(int a0);
Obj *func_02155F9C(int a0);


int func_02155F4C(int a0)
{
    int a1;
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj02657 *)t4)->f2C;
    if (a0 == 0) goto loc_02155F5A;
loc_02155F56:
    a0 = func_02156CD8(a0);
loc_02155F5A:
a0 = ((struct Obj02657 *)t4)->f30;
    if (a0 == 0) goto loc_02155F64;
loc_02155F60:
    a0 = func_02156F98(a0);
loc_02155F64:
a0 = ((struct Obj02657 *)t4)->f34;
    if (a0 == 0) goto loc_02155F76;
loc_02155F6A:
a0 = ((struct Obj02657 *)a0)->f8;
    a0 = func_020307B0(a0);
loc_02155F70:
a0 = ((struct Obj02657 *)t4)->f34;
    a0 = func_020307B0(a0);
loc_02155F76:
a0 = ((struct Obj02657 *)t4)->f24;
    if (a0 == 0) goto loc_02155F80;
loc_02155F7C:
    a0 = func_021F6888(a0);
loc_02155F80:
a0 = ((struct Obj02657 *)t4)->f3C;
    if (a0 == 0) goto loc_02155F8A;
loc_02155F86:
    a0 = func_020307B0(a0);
loc_02155F8A:
a0 = ((struct Obj02657 *)t4)->f38;
    if (a0 == 0) goto loc_02155F94;
loc_02155F90:
    a0 = func_0215716C(a0);
loc_02155F94:
a0 = ((struct Obj02657 *)t4)->f8;
a1 = 0;
((struct Obj02657 *)((char *)a0))->f0 = a1;
    return a0;}


Obj *func_02155F9C(int a0)
{
    int a1;
    int a2;
    int t4;
    Obj *p;

t4 = a0 + 0;
a1 = ((struct Obj07201 *)t4)->f3C;
a2 = ((struct Obj07201 *)t4)->f1C;
a0 = 4;
    p = func_02156CAC(a0, a1, a2);
loc_02155FAA:
a1 = ((struct Obj07201 *)t4)->f28;
*(Obj * *)&((struct Obj07201 *)t4)->f2C = p;
p->f00 = a1;
    return p;}
