/*
 * file:     worldtrade_adapter_p41.c
 * unit:     yes
 * function: func_02202000, func_02202038, func_02202054
 * address:  0x02202000
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02201F18 0x02201F18 thumb ov135
 *   func_021F4E98 0x021F4E98 thumb ov135
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_021F4FC4 0x021F4FC4 thumb ov135
 *   func_021FFBC8 0x021FFBC8 thumb ov135
 *   func_0220251C  0x0220251C  thumb  ov135
 */
#include "../../matched/include/Obj00018.h"
#include "../../matched/include/Obj09248.h"

struct Ctx;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

extern u32 func_02201F18(u8 *p);
extern void func_021F4E98(u8 *,u32,u32),func_021F4EC0(u8 *,u32,u32),func_021F4FC4(u8 *),func_021FFBC8(u8 *);
extern void func_021F4E98(u8 *p, u32 a, u32 b);
extern void func_0220251C(u8 *p, u16 a, u16 b);
extern void *func_020120F4(const struct Ctx *p);
extern int func_02012DAC(int a0);
extern u32 func_020056EC(u32 v);
int func_02202000(u8 *p);
int func_02202038(u8 *p);
int func_02202054(u8 *p);

int func_02202000(u8 *p) { func_02201F18(p); func_021F4E98(p,41,40); func_021F4EC0(p,1,0); func_021F4FC4(p); if(((struct Obj00018 *)p)->fD0>0) func_021FFBC8(p); return 2; }


/*
 * Publish the 0x29/0x22 then the 0x25/0x28 pair and report 2.
 */
int func_02202038(u8 *p)
{
    func_021F4E98(p, 0x29, 0x22);
    func_0220251C(p, 0x25, 0x28);
    return 2;
}


/*
 * Latch state 0x23 and publish the +2 tick of the 0x3c query into +0xdfc.
 */
int func_02202054(u8 *p)
{
    func_02012DAC((int)func_020120F4((const struct Ctx *)(*(u32 *)(((struct Obj09248 *)p)->f0 + 0x40))));
    ((struct Obj09248 *)p)->f28 = 0x23;
    ((struct Obj09248 *)p)->fDFC = func_020056EC(0x3c) + 2;
    return 2;
}
