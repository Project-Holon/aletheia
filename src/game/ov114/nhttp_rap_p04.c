/*
 * file:     nhttp_rap_p04.c
 * unit:     yes
 * function: func_021B98A0, func_021B98D8
 * address:  0x021B98A0
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B984C  0x021B984C  thumb  ov114
 */
#include "../../matched/include/Obj03250.h"
#include "../../matched/include/Obj10328.h"

typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

extern void *func_0203D7C8(unsigned int a, unsigned int size, const char *c, unsigned short d);
extern void func_02082BCC(int, int, int);
extern void func_021B984C(u8 *, int);
extern void func_02082D44(int, int, int);
void func_021B98A0(u8 *p, int a, int b, int c);
void func_021B98D8(u8 *p, int a, int n);


void func_021B98A0(u8 *p, int a, int b, int c)
{
    void *q;

    if (p == 0)
        return;
    q = func_0203D7C8(a, b + 0x130, (const char *)0x021CE310, 0x1f5);
    ((struct Obj03250 *)p)->f0 = (u32)q;
    func_02082BCC((int)q, 0, b + 0x130);
    func_021B984C(p, c);
}


/*
 * Appends `n` bytes at the write cursor and advances it.
 */
void func_021B98D8(u8 *p, int a, int n)
{
    if (p == 0)
        return;
    func_02082D44(a, ((struct Obj10328 *)p)->f0 + ((struct Obj10328 *)p)->f4, n);
    ((struct Obj10328 *)p)->f4 += n;
}
