/*
 * file:     script_work_p03.c
 * unit:     yes
 * function: func_02158FE0, func_0215901C, func_02159030, func_02159058, func_0215909C
 * address:  0x02158FE0
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
 *   func_0201296C 0x0201296C thumb
 *   func_020143CC 0x020143CC thumb
 *   func_02158FD0 0x02158FD0 thumb ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02082A60 0x02082A60 arm
 *   func_02030734 0x02030734 arm
 *   d_0217289C 0x0217289C data a1
 */
#include "../../matched/include/Obj00020.h"
#include "../../matched/include/Obj18755.h"

struct BigObj;
struct Ctx;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

extern u32 func_0201296C(const struct BigObj *p);
extern unsigned int func_020143CC(unsigned int, unsigned int);
extern u16 *func_02158FD0(void *, unsigned int);
extern void *func_020120F4(const struct Ctx *p);
extern void func_02082A60(const void *, void *, unsigned int);
extern void *func_02030734(unsigned int, unsigned int, int, const char *, u16);
u16 *func_02158FE0(void *a, void *b, unsigned int id);
/* * extent: two-byte zero alignment padding follows the 18-byte function. * Return stays full-width: the fallback id has no halfword truncation. */ unsigned int func_0215901C(void *a, void *b, unsigned int id);
int func_02159030(int a0, int a1, int a2);
int func_02159058(int a, int b, int c, int d, u16 e);
void *func_0215909C(u8 *a);
extern const char d_0217289C[];


u16 *func_02158FE0(void *a, void *b, unsigned int id)
{
    void *p = (void *)func_0201296C(b);
    if (id < 0x4000) return 0;
    if (id < 0x8000) return (u16 *)func_020143CC((unsigned int)p, id);
    if (id < 0xc000) return func_02158FD0(a, id);
    return 0;
}



/*
 * extent: two-byte zero alignment padding follows the 18-byte function.
 * Return stays full-width: the fallback id has no halfword truncation.
 */
unsigned int func_0215901C(void *a, void *b, unsigned int id)
{
    u16 *p = func_02158FE0(a, b, id);
    if (p) id = *p;
    return id;
}




int func_02159030(int a0, int a1, int a2)
{
    int t4;
    int t5;
    int t6;
    void *p;
    u16 *q;

t5 = a0 + 0;
a0 = *(int *)&((struct Obj00020 *)t5)->f10;
t6 = a1 + 0;
t4 = a2 + 0;
    p = func_020120F4((const struct Ctx *)a0);
loc_0215903E:
    q = func_02158FE0((void *)t5, p, t6);
loc_02159048:
    if (q != 0) goto loc_02159050;
loc_0215904C:
a0 = 0;
    return a0;
loc_02159050:
*q = t4;
a0 = 1;
    return a0;}



int func_02159058(int a, int b, int c, int d, u16 e)
{
    func_02159030(a, 0x8000, b);
    func_02159030(a, 0x8001, c);
    func_02159030(a, 0x8002, d);
    return func_02159030(a, 0x8003, e);
}


void *func_0215909C(u8 *a)
{
    void *p = func_02030734(((struct Obj18755 *)a)->fC, 0x7e, 1, d_0217289C, 0x21b);
    func_02082A60(func_02158FD0(a, 0x8020), p, 0x7e);
    return p;
}
