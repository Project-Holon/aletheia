/*
 * file:     union_comm_p01.c
 * unit:     yes
 * function: func_02172BC0, func_02172C1C
 * address:  0x02172BC0
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203064C  0x0203064C  arm
 *   func_02030734  0x02030734  arm
 *   func_021734E0  0x021734E0  thumb  ov012
 *   func_0217365C  0x0217365C  thumb  ov012
 *   func_0200ADF0  0x0200ADF0  thumb
 *   str_02175600   0x02175600  data  ov012  a1
 *   func_020307B0 0x020307B0 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02173420 0x02173420 thumb ov012
 */
#include "../../matched/include/Obj00033.h"

struct Work;
struct Reg;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef struct {
    u32 field0;
    u8  pad004[0x282a - 4];
    u8  f282a;
    u8  pad282b[0x283e - 0x282b];
    u8  f283e;
    u8  pad283f[0x30e0 - 0x283f];
    u8  f30e0[0x352c - 0x30e0];
    u32 f352c;
    u8  pad3530[0x3570 - 0x3530];
} Work;

typedef unsigned short u16;

extern void func_0203064C(u32 a, u32 b, u32 c);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021734E0(struct Work *w);
extern void func_0217365C(u8 *p);
extern struct Reg *func_0200ADF0(u32 heap);
extern u32 func_020307B0(void *p);
extern void func_020306F0(unsigned int heap);
extern void func_02173420(void *p);
Work *func_02172BC0(u32 a);
void func_02172C1C(void *p, u8 *q);
extern char str_02175600[];


Work *func_02172BC0(u32 a)
{
    Work *w;

    func_0203064C(4, 0x41, 0x8a00);
    w = func_02030734(0x41, sizeof(Work), 1, str_02175600, 0x89);
    w->field0 = a;
    func_021734E0((struct Work *)w);
    w->f283e = 1;
    func_0217365C(w->f30e0);
    w->f352c = (u32)func_0200ADF0(0x41);
    w->f282a = 1;
    return w;
}

void func_02172C1C(void *p, u8 *q)
{
    if (((struct Obj00033 *)q)->f352C != 0) func_020307B0(((struct Obj00033 *)q)->f352C);
    func_02173420(q);
    func_020307B0(q);
    func_020306F0(0x41);
    func_020307B0(p);
}
