/*
 * file:     eventdata_system_p05.c
 * unit:     yes
 * function: func_02161FEC, func_02161FF0, func_02162008, func_02162024, func_0216202C
 * address:  0x02161FEC
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
 *   func_0216210C  0x0216210C  thumb  ov010
 *   func_0216220C  0x0216220C  thumb  ov010
 *   func_02162230  0x02162230  thumb  ov010
 *   func_021622AC 0x021622AC thumb ov010
 *   func_021622D8 0x021622D8 thumb ov010
 */
#include "../../matched/include/Obj18948.h"
#include "../../matched/include/Obj18949.h"

typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int u32;

extern int func_0216210C(int a0);
extern int func_0216220C();
extern int func_02162230();
extern int func_021622AC(char *, int, void *);
extern int func_021622D8(char *, void *);
void func_02161FEC(char *p, u16 v);
void func_02161FF0(int a0, int a1);
void func_02162008(int a0, int a1, int a2);
int func_02162024(char *p, int index, void *out);
int func_0216202C(char *p, void *out, u8 *index);


/*
 * Unlabelled leaf, four bytes: strh r1, [r0, #4]; bx lr.
 */
void func_02161FEC(char *p, u16 v)
{
    ((struct Obj18948 *)p)->f4 = v;
}


void func_02161FF0(int a0, int a1)
{
    int t4;
    int t5;

t5 = a0 + 0;
t4 = a1 + 0;
    a0 = func_0216210C(a0);
loc_02161FFA:
    if (a0 != 0) goto loc_02162006;
loc_02161FFE:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_0216220C(a0, a1);
loc_02162006:
    return;}


void func_02162008(int a0, int a1, int a2)
{
    int t4;
    int t5;
    int t6;

t5 = a0 + 0;
t4 = a1 + 0;
t6 = a2 + 0;
    a0 = func_0216210C(a0);
loc_02162014:
    if (a0 != 0) goto loc_02162022;
loc_02162018:
a0 = t5 + 0;
a1 = t4 + 0;
a2 = t6 + 0;
    a0 = func_02162230(a0, a1, a2);
loc_02162022:
    return;}

int func_02162024(char *p, int index, void *out)
{
    return func_021622AC(p, index, out);
}

int func_0216202C(char *p, void *out, u8 *index)
{
    *index = ((struct Obj18949 *)p)->f4;
    return func_021622D8(p, out);
}
