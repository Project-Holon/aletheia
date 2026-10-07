/*
 * file:     fldmmdl_p26.c
 * unit:     yes
 * function: func_0216D900, func_0216D910, func_0216D91C, func_0216D924, func_0216D92C, func_0216D948, func_0216D95C, func_0216D974, func_0216D98C
 * address:  0x0216D900
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
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0216D4D4  0x0216D4D4  thumb  ov010
 *   func_0216D4DC 0x0216D4DC thumb ov010
 *   func_0216D4E4 0x0216D4E4 thumb ov010
 */
#include "../../matched/include/Obj17850.h"
#include "../../matched/include/Obj17851.h"
#include "../../matched/include/Obj09334.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef struct { u32 a, b, c; } Triple;

typedef signed char    s8;

typedef signed int     s32;

extern void *func_0216D67C(void *a0);
extern u32 func_0216D520(void *p);
extern int func_0216D4D4(int a0, int a1);
extern int func_0216D4DC(int a0, int a1, int a2);
extern u32 *func_0216D4E4(u32 *p, u32 v);
void func_0216D900(void *p, const Triple *q);
int func_0216D910(int a0);
u8 func_0216D91C(int a0);
u8 func_0216D924(int a0);
void func_0216D92C(u8 *p, s32 *q);
int func_0216D948(int a0);
void func_0216D95C(unsigned int *p, unsigned int v, int a2);
void func_0216D974(unsigned int *p, unsigned int v, int a2);
int func_0216D98C(int a0);


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Twelve-byte struct copy between an interior member of the
 * object and a caller-supplied 3-word record: the compiler
 * emits ldm/stm plus the odd word.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D900.c \
 *       --func func_0216D900 --addr 0x0216D900 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D900(void *p, const Triple *q)
{
    *(Triple *)((char *)p + 104) = *q;
}


int func_0216D910(int a0)
{

    a0 = (int)func_0216D67C((void *)a0);
loc_0216D916:
    a0 = func_0216D520((void *)a0);
loc_0216D91A:
    return a0;}




u8 func_0216D91C(int a0)
{

a0 = a0 + 0x7c;
a0 = ((struct Obj17850 *)((char *)a0))->f0;
    return a0;}




u8 func_0216D924(int a0)
{

a0 = a0 + 0x7d;
a0 = ((struct Obj17851 *)((char *)a0))->f0;
    return a0;}


/*
 * Unlabelled leaf: widens three signed bytes at p + 0x7e..0x80 to fixed
 * point (<< 12) and stores them into q[0..2].
 *
 * Addresses are Black-image addresses.
 */
void func_0216D92C(u8 *p, s32 *q)
{
    q[0] = ((struct Obj09334 *)p)->f7E << 12;
    q[1] = ((struct Obj09334 *)p)->f7F << 12;
    q[2] = ((struct Obj09334 *)p)->f80 << 12;
}


int func_0216D948(int a0)
{
    int a1;
    int t4;

a1 = 1;
t4 = 1;
    a0 = func_0216D4D4(a0, a1);
loc_0216D952:
    if (a0 != 0) goto loc_0216D958;
loc_0216D956:
t4 = 0;
loc_0216D958:
a0 = t4 + 0;
    return a0;}

void func_0216D95C(unsigned int *p, unsigned int v, int a2)
{
    if (v == 1) func_0216D4DC((int)p, 1, a2);
    else func_0216D4E4(p, 1);
}

void func_0216D974(unsigned int *p, unsigned int v, int a2)
{
    if (v == 0) func_0216D4DC((int)p, 8, a2);
    else func_0216D4E4(p, 8);
}


int func_0216D98C(int a0)
{
    int a1;
a1 = 8;
    a0 = func_0216D4D4(a0, a1);
loc_0216D994:
    if (a0 != 0) goto loc_0216D99C;
loc_0216D998:
a0 = 1;
    return a0;
loc_0216D99C:
a0 = 0;
    return a0;}
