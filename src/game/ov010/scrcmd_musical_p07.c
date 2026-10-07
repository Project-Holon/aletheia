/*
 * file:     scrcmd_musical_p07.c
 * unit:     yes
 * function: func_0215E334, func_0215E33C, func_0215E34C, func_0215E358
 * address:  0x0215E334
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
 *   func_020307B0  0x020307B0  arm
 *   func_02188CE8  0x02188CE8  thumb
 *   func_021AA7DC  0x021AA7DC  thumb
 *   func_02012A38  0x02012A38  thumb
 *   func_0215E740  0x0215E740  thumb
 */
#include "../../matched/include/Obj17696.h"
#include "../../matched/include/Obj17697.h"

struct BigObj;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

extern u32 func_020307B0(void *p);
extern int func_02188CE8();
extern int func_021AA7DC();
extern u32 func_02012A38(const struct BigObj *p);
void func_0215E740(int a, int b, int c, int d);
void func_0215E334(void *ptr);
int func_0215E33C(int a0);
int func_0215E34C(int a0);
void func_0215E358(int a, int b, int c);


void func_0215E334(void *ptr)
{
    func_020307B0(ptr);
}


int func_0215E33C(int a0)
{
    int a1;

    a0 = func_02188CE8(a0);
loc_0215E342:
a1 = ((struct Obj17696 *)a0)->f10;
    a0 = func_021AA7DC(a0, a1);
loc_0215E348:
    return a0;}


int func_0215E34C(int a0)
{
    int a1;

    a0 = func_02012A38((const struct BigObj *)a0);
loc_0215E352:
a1 = 0;
((struct Obj17697 *)a0)->fC = a1;
    return a0;}


void func_0215E358(int a, int b, int c)
{
    func_0215E740(a, b, c, 0xff);
}
