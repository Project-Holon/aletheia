/*
 * file:     event_field_proclink_p10.c
 * unit:     yes
 * function: func_021616A4, func_021616F0
 * address:  0x021616A4
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
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_02169AB8  0x02169AB8  thumb  ov010
 */
#include "../../matched/include/Obj04884.h"
#include "../../matched/include/Obj00029.h"
#include "../../matched/include/Obj00654.h"

struct Desc;
struct Obj;
struct Big;
struct Ctx;
struct Work;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
void *func_020120F4(const struct Ctx *p);
void *func_02012EBC(struct Big *p);
void func_02082BCC(void *p, int v, int n);
extern int func_02169AB8(struct Work *w, u32 *state);
void *func_021616A4(void *p, int a1, int a2, int a3, int a4);
int func_021616F0(int a0, int a1, int a2);


/*
 * Allocator with callback, zero-fills the node, then fills link fields.
 */
void *func_021616A4(void *p, int a1, int a2, int a3, int a4)
{
    void *r0v = func_020122C0(p, 0, func_021616F0, 0x1C);
    char *r4 = func_020124E8(r0v);

    func_02082BCC(r4, 0, 0x1C);
    ((struct Obj04884 *)r4)->fC = a3;
    ((struct Obj04884 *)r4)->f10 = a2;
    ((struct Obj04884 *)r4)->f4 = (int)p;
    ((struct Obj04884 *)r4)->f8 = a1;
    ((struct Obj04884 *)r4)->f0 = (int)func_02012EBC(func_020120F4(p));
    ((struct Obj04884 *)r4)->f14 = a4;
    return r0v;
}


int func_021616F0(int a0, int a1, int a2)
{
    int t4;

t4 = a2 + 0;
a0 = t4 + 0;
    a0 = func_02169AB8((struct Work *)a0, (u32 *)a1);
loc_021616FA:
    if (a0 == 0) goto loc_02161704;
loc_021616FE:
    if (a0 == 1) goto loc_0216170C;
loc_02161702:
    goto loc_02161716;
loc_02161704:
a1 = ((struct Obj00029 *)t4)->f14;
a0 = 1;
*(int *)&((struct Obj00654 *)((char *)a1))->f0 = a0;
    return a0;
loc_0216170C:
a0 = ((struct Obj00029 *)t4)->f14;
a1 = 0;
*(int *)&((struct Obj00029 *)((char *)a0))->f0 = a1;
a0 = 1;
    return a0;
loc_02161716:
a0 = 0;
    return a0;}
