/*
 * file:     event_field_proclink_p01.c
 * unit:     yes
 * function: func_0215EC54, func_0215EC6C, func_0215EC80, func_0215EC94
 * address:  0x0215EC54
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
 *   func_02165534  0x02165534  thumb  ov010
 *   func_021C8268  0x021C8268  thumb
 *   func_0215F104 0x0215F104 thumb ov010
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_0215F0E8 0x0215F0E8 thumb ov010
 *   func_0215ECBC 0x0215ECBC thumb ov010
 */
#include "../../matched/include/Obj12043.h"
#include "../../matched/include/Obj17699.h"
#include "../../matched/include/Obj02057.h"

struct Arg;
struct Desc;
struct Obj;
struct Pair;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef enum { B_FALSE, B_TRUE } Bool;

extern int func_02165534();
extern int func_021C8268();
extern int func_0215F104(int a0, int a1);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_0215F0E8(u32 *out, const struct Pair *in, u32 *ctx);
extern int func_0215ECBC(void *a0, int *state, struct Arg *arg);
int func_0215EC54(int a0, int a1, int a2);
int func_0215EC6C(void *p);
int func_0215EC80(void *p);
void *func_0215EC94(void *a, void *b);


int func_0215EC54(int a0, int a1, int a2)
{
    int t4;
    int t5;

t5 = a0 + 0;
t4 = a1 + 0;
a0 = 0x13;
    a0 = func_02165534(a0);
loc_0215EC60:
a0 = ((struct Obj12043 *)t4)->f8;
a1 = ((struct Obj12043 *)t4)->f10;
a2 = ((struct Obj17699 *)t5)->f4;
    a0 = func_021C8268(a0, a1, a2);
loc_0215EC6A:
    return a0;}

int func_0215EC6C(void *p)
{
    return func_0215F104((int)p, 4) != 0 ? B_FALSE : B_TRUE;
}

int func_0215EC80(void *p)
{
    return func_0215F104((int)p, 5) != 0 ? B_FALSE : B_TRUE;
}

void *func_0215EC94(void *a, void *b)
{
    void *task;
    task = func_020122C0(((struct Obj02057 *)b)->f8, 0, (void *)func_0215ECBC, 20);
    func_0215F0E8(func_020124E8(task), a, b);
    return task;
}
