/*
 * file:     mb_seq_p08.c
 * unit:     yes
 * function: func_021C76D0, func_021C770C
 * address:  0x021C76D0
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0202616C  0x0202616C  thumb
 *   func_021C66A0 0x021C66A0 thumb
 *   func_021C66CC 0x021C66CC thumb
 *   func_02035C08  0x02035C08  arm
 *   func_020362DC                0x020362DC  arm
 *   d_021C7E14 0x021C7E14 data a4
 */
#include "../../matched/include/Obj01066.h"
#include "../../matched/include/Obj23663.h"

typedef unsigned char u8;

typedef unsigned int u32;

extern void *func_0202616C(void **obj, u32 idx);
extern void func_021C66CC(u8 *, int, int, int);
extern void func_021C66A0(u8 *p, int i, u32 v);
extern int func_02035C08(const void *);
extern u32 func_020362DC(void);
void func_021C76D0(u8 *p, u32 v);
int func_021C770C(u8 *a0);
extern const u8 d_021C7E14[];

void func_021C76D0(u8 *p, u32 v)
{
    u8 *q = func_0202616C(((struct Obj23663 *)(*(u8 * *)&((struct Obj01066 *)p)->f8))->f294, v);
    func_021C66CC(*(u8 * *)&((struct Obj01066 *)p)->f8, 2, q[0], q[1]);
    if (v == 10) {
        func_021C66A0(*(u8 * *)&((struct Obj01066 *)p)->f8, 2, 4);
    } else {
        func_021C66A0(*(u8 * *)&((struct Obj01066 *)p)->f8, 2, 5);
    }
}

int func_021C770C(u8 *a0)
{
    if (func_02035C08(d_021C7E14) != -1) {
        return 1;
    }
    if ((func_020362DC() & 3) != 0) {
        return 1;
    }
    return 0;
}
