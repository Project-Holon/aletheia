/*
 * file:     script_work_p13.c
 * unit:     yes
 * function: func_02158F94, func_02158FB4, func_02158FB8, func_02158FBC
 * address:  0x02158F94
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
 *   func_02158FD0 0x02158FD0 thumb ov010
 *   func_0216D588 0x0216D588 thumb ov010
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj17637.h"
#include "../../matched/include/Obj00005.h"

typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed short   s16;

extern int func_02158FD0(int a0, u32 a1, int a2);
extern u16 func_0216D588(void *);
extern int func_020307B0();
void func_02158F94(void *p, void *q, int a2);
void *func_02158FB4(void *p);
u32 func_02158FB8(void *p);
void func_02158FBC(int a0);

void func_02158F94(void *p, void *q, int a2)
{
    *(void **)((char *)p + 8) = q;
    if (q != 0) {
        u16 *r = (u16 *)func_02158FD0((int)p, 0x8011, a2);
        *r = func_0216D588(q);
    }
}


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Returns the address of an interior member (field address), pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02158FB4.c \
 *       --func func_02158FB4 --addr 0x02158FB4 --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_02158FB4(void *p) { return (char *)p + 60; }


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02158FB8.c \
 *       --func func_02158FB8 --addr 0x02158FB8 --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_02158FB8(void *p) { return ((struct Obj17637 *)p)->f3C; }


void func_02158FBC(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj00005 *)t4)->f3C;
    if (a0 == 0) goto loc_02158FCE;
loc_02158FC6:
    a0 = func_020307B0(a0);
loc_02158FCA:
a0 = 0;
((struct Obj00005 *)t4)->f3C = a0;
loc_02158FCE:
    return;}
