/*
 * file:     eventdata_system_p11.c
 * unit:     yes
 * function: func_02162370, func_0216237C, func_021623BC
 * address:  0x02162370
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
 *   func_02030734  0x02030734  arm
 *   func_020490F4  0x020490F4  arm
 *   d_0217299C     0x0217299C  data  ov010  a1
 *   func_02049238  0x02049238  arm
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj09161.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049238(void *arc);
extern int func_020307B0();
int func_02162370(int a);
int func_0216237C(int a);
int func_021623BC(int a0);
extern char d_0217299C[];

/*
 * Predicate: is the argument >= 7.
 *
 * Addresses are Black-image addresses.
 */
int func_02162370(int a)
{
return a >= 7;
}


int func_0216237C(int a)
{
    void **p = (void **)func_02030734(a, 0xAA8, 1, d_0217299C, 0xAF);
    p[1] = func_020490F4(0x7D, a);
    p[2] = func_020490F4(0x7E, a);
    p[3] = func_020490F4(0x39, a);
    return (int)p;
}


int func_021623BC(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj09161 *)t4)->f4;
    func_02049238((void *)a0);
loc_021623C6:
a0 = ((struct Obj09161 *)t4)->f8;
    func_02049238((void *)a0);
loc_021623CC:
a0 = ((struct Obj09161 *)t4)->fC;
    func_02049238((void *)a0);
loc_021623D2:
a0 = t4 + 0;
    a0 = func_020307B0(a0);
loc_021623D8:
    return a0;}
