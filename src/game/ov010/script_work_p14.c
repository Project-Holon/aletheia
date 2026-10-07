/*
 * file:     script_work_p14.c
 * unit:     yes
 * function: func_0215901C, func_02159030
 * address:  0x0215901C
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
 *   func_02158FE0 0x02158FE0 thumb ov010
 *   func_020120F4  0x020120F4  thumb
 */
#include "../../matched/include/Obj00020.h"

struct Ctx;
typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int u32;

extern u16 *func_02158FE0(void *, void *, unsigned int);
extern void *func_020120F4(const struct Ctx *p);
unsigned int func_0215901C(void *a, void *b, unsigned int id);
int func_02159030(int a0, int a1, int a2);

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
