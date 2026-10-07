/*
 * function: func_021F55A0
 * address:  0x021F55A0
 * packet:   pkt_ov082_021F55A0
 * region:   ov082
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02189A60  0x02189A60  thumb  ov021
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_021F5648  0x021F5648  thumb  ov082
 */
#include "../../../matched/include/Obj05164.h"

typedef unsigned int u32;

typedef signed int     s32;
typedef unsigned char  u8;
struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern u8 *func_02189A60(u8 *p);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int  func_0204E804(void);
struct Node;
extern void func_02030EAC(struct Node *n);
extern void func_021F5648(void *a, void *p);

int func_021F55A0(void *a0, int *st)
{
    void *obj;
    char *w;
    int t;

    obj = func_0201210C(func_020124E4(a0));
    w = *(char **)func_02189A60(obj);
    switch (*st) {
    case 0:
        if (((struct Obj05164 *)w)->f70 != 0)
            func_0204E720(3, 0, 0x10, -8);
        else
            func_0204E720(1, 0, 0x10, 0);
        (*st)++;
        break;
    case 1:
        if (func_0204E804() != 0)
            break;
        func_02030EAC((struct Node *)(((struct Obj05164 *)w)->f14));
        (*st)++;
        break;
    case 2:
        if (((struct Obj05164 *)w)->f2C != 0)
            break;
        if (((struct Obj05164 *)w)->f50 != 0)
            break;
        func_02030EAC((struct Node *)(((struct Obj05164 *)w)->f18));
        t = ((struct Obj05164 *)w)->f70;
        func_021F5648(obj, w);
        if (t != 0)
            return 1;
        func_0204E720(1, 0x10, 0, 0);
        (*st)++;
        break;
    case 3:
        if (func_0204E804() == 0)
            return 1;
        break;
    }
    return 0;
}
