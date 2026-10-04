/*
 * function: func_021F5744
 * address:  0x021F5744
 * packet:   pkt_ov077_021F5744
 * region:   ov077
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02189A08  0x02189A08  thumb  ov021
 *   func_021CF560  0x021CF560  thumb  ov021
 *   func_021F5798  0x021F5798  thumb  ov077
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj20795.h"

typedef unsigned char u8;
typedef unsigned int u32;

typedef signed int     s32;
struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02189A08(unsigned char *p);
extern u32 func_021CF560(u32 *p);
extern int func_021F5798(u8 *p);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);

int func_021F5744(void *task, int *st)
{
    u8 *w;

    w = (u8 *)func_021CF560((u32 *)func_02189A08((unsigned char *)((int)func_0201210C(func_020124E4(task)))));
    switch (*st) {
    case 0:
        if (func_021F5798(w) == 0)
            break;
        func_0204E720(((struct Obj20795 *)w)->f3074, 0, 0x10, 0);
        (*st)++;
        break;
    case 1:
        if (func_0204E804() == 0)
            return 1;
        break;
    }
    return 0;
}
