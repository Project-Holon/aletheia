/*
 * file:     eventdata_system_p23.c
 * unit:     yes
 * function: func_02163580, func_02163618, func_02163650
 * address:  0x02163580
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
 *   func_021AB3D4  0x021AB3D4  thumb
 *   func_021AB3E0  0x021AB3E0  thumb
 *   func_021AB334  0x021AB334  thumb
 *   func_021AB328  0x021AB328  thumb
 *   func_021AB41C  0x021AB41C  thumb
 *   func_021BBDD4  0x021BBDD4  thumb
 *   func_021AB304  0x021AB304  thumb
 *   func_0216DBE8  0x0216DBE8  thumb  ov010
 *   func_021C4BE0  0x021C4BE0  thumb
 *   func_0216DBCC  0x0216DBCC  thumb  ov010
 *   func_021AB364  0x021AB364  thumb
 *   func_021C4A10  0x021C4A10  thumb
 */
#include "../../matched/include/Obj00110.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021AB3D4();
extern int func_021AB3E0();
extern int func_021AB334();
extern int func_021AB328();
extern int func_021AB41C();
extern int func_021BBDD4();
extern int func_021AB304();
extern int func_0216DBE8(void *a0);
extern int func_021C4BE0();
extern int func_0216DBCC();
extern int func_021AB364();
extern int func_021C4A10();
void func_02163580(int a0, int a1, int a2);
int func_02163618(int a0, int a1);
int func_02163650(int a0, int a1);


void func_02163580(int a0, int a1, int a2)
{
    int t4;
    int t5;
    int t6;

t5 = a1 + 0;
a1 = ((struct Obj00110 *)t5)->fC;
t6 = a0 + 0;
a0 = 8;
    if ((a0 & a1) == 0) goto loc_02163616;
loc_0216358E:
a0 = ((struct Obj00110 *)t5)->f8;
t4 = 5;
    a0 = func_021AB3D4(a0);
loc_02163596:
    if (a0 == 0) goto loc_021635AE;
loc_0216359A:
a0 = ((struct Obj00110 *)t5)->f18;
    if (a0 != 3) goto loc_02163608;
loc_021635A0:
a0 = *(int *)&((struct Obj00110 *)t5)->f10;
t4 = 2;
a0 = ((struct Obj00110 *)a0)->f5;
    if (a0 != 2) goto loc_02163608;
loc_021635AA:
t4 = 3;
    goto loc_02163608;
loc_021635AE:
a0 = ((struct Obj00110 *)t5)->f8;
    a0 = func_021AB3E0(a0);
loc_021635B4:
    if (a0 == 0) goto loc_021635CE;
loc_021635B8:
a0 = ((struct Obj00110 *)t5)->f18;
    if (a0 == 0) goto loc_021635C2;
loc_021635BE:
    if (a0 != 3) goto loc_02163608;
loc_021635C2:
a0 = *(int *)&((struct Obj00110 *)t5)->f10;
t4 = 2;
a0 = ((struct Obj00110 *)a0)->f5;
    if (a0 != 2) goto loc_02163608;
loc_021635CC:
    goto loc_021635AA;
loc_021635CE:
a0 = ((struct Obj00110 *)t5)->f8;
    a0 = func_021AB334(a0);
loc_021635D4:
    if (a0 == 1) goto loc_021635E2;
loc_021635D8:
a0 = ((struct Obj00110 *)t5)->f8;
    a0 = func_021AB328(a0);
loc_021635DE:
    if (a0 != 1) goto loc_021635EE;
loc_021635E2:
a0 = *(int *)&((struct Obj00110 *)t5)->f10;
t4 = 2;
a0 = ((struct Obj00110 *)a0)->f5;
    if (a0 != 2) goto loc_02163608;
loc_021635EC:
    goto loc_021635AA;
loc_021635EE:
a0 = ((struct Obj00110 *)t5)->f8;
    a0 = func_021AB41C(a0);
loc_021635F4:
    if (a0 != 1) goto loc_021635FC;
loc_021635F8:
t4 = 4;
    goto loc_02163608;
loc_021635FC:
a0 = *(int *)&((struct Obj00110 *)t5)->f10;
t4 = 0;
a0 = ((struct Obj00110 *)a0)->f5;
    if (a0 != 2) goto loc_02163608;
loc_02163606:
t4 = 1;
loc_02163608:
    if (t4 == 5) goto loc_02163616;
loc_0216360C:
a1 = ((struct Obj00110 *)t5)->f14;
a0 = t6 + 0;
a2 = t4 + 0;
    a0 = func_021BBDD4(a0, a1, a2);
loc_02163616:
    return;}


int func_02163618(int a0, int a1)
{
    int t4;
    int t5;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = ((struct Obj00110 *)t4)->fA;
    a0 = func_021AB304(a0);
loc_02163624:
    if (a0 != 1) goto loc_02163644;
loc_02163628:
a0 = t5 + 0;
    a0 = func_0216DBE8((void *)a0);
loc_0216362E:
    if (a0 != 0) goto loc_0216364C;
loc_02163632:
a0 = ((struct Obj00110 *)t4)->f14;
a1 = t5 + 0;
    a0 = func_021C4BE0(a0, a1);
loc_0216363A:
a0 = t5 + 0;
a1 = 1;
    a0 = func_0216DBCC(a0, a1);
loc_02163642:
    return a0;
loc_02163644:
a0 = t5 + 0;
a1 = 0;
    a0 = func_0216DBCC(a0, a1);
loc_0216364C:
    return a0;}


int func_02163650(int a0, int a1)
{
    int t4;
    int t5;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = ((struct Obj00110 *)t4)->fA;
    a0 = func_021AB304(a0);
loc_0216365C:
    if (a0 != 1) goto loc_0216367C;
loc_02163660:
a0 = t5 + 0;
    a0 = func_0216DBE8((void *)a0);
loc_02163666:
    if (a0 != 0) goto loc_02163698;
loc_0216366A:
a0 = ((struct Obj00110 *)t4)->f14;
a1 = t5 + 0;
    a0 = func_021C4BE0(a0, a1);
loc_02163672:
a0 = t5 + 0;
a1 = 1;
    a0 = func_0216DBCC(a0, a1);
loc_0216367A:
    return a0;
loc_0216367C:
a0 = ((struct Obj00110 *)t4)->fA;
    a0 = func_021AB364(a0);
loc_02163682:
    if (a0 != 1) goto loc_02163690;
loc_02163686:
a0 = ((struct Obj00110 *)t4)->f14;
a1 = t5 + 0;
    a0 = func_021C4A10(a0, a1);
loc_0216368E:
    return a0;
loc_02163690:
a0 = t5 + 0;
a1 = 0;
    a0 = func_0216DBCC(a0, a1);
loc_02163698:
    return a0;}
