/*
 * function: func_021C59B8
 * address: 0x021C59B8
 * packet: pkt_ov136_021C59B8
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: use the prepared Pair pointer's t->a as the archive index and t->b after the call;
 *   its live address keeps r7 and frees the far-offset constants into the original stack slots.
 * retry: wave77 R24 recovered in 3 scratch runs; own callee prototypes copied before matching.
 * symbols:
 *   func_021C59B8 0x021C59B8 thumb
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   g_78C0 0x021C78C0 data
 *   g_78B0 0x021C78B0 data
 */
#include "../include/Obj02494.h"
#include "../include/Obj23515.h"
#include "../include/Obj23516.h"
#include "../include/Obj23517.h"
#include "../include/Obj23518.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Pair { u32 a; u32 b; };
extern const struct Pair g_78C0[];
extern const struct Pair g_78B0[];
struct R;
extern struct R *APP_TASKMENU_RES_Create(u16, u16, u32, u32, u16);
struct MsgBank;
extern void *func_02045EC0(struct MsgBank *, u32);

void func_021C59B8(u8 *p)
{
    u16 i;
    const struct Pair *t;
    ((struct Obj23516 *)(*(u8 * *)&((struct Obj02494 *)p)->f8))->f30C = APP_TASKMENU_RES_Create(0, 5, ((struct Obj02494 *)p)->f18, ((struct Obj23515 *)(*(u8 * *)&((struct Obj02494 *)p)->f8))->f1C4, 0x66);
    for (i = 0; i < 4; i++) {
        t = &g_78C0[i];
        *(u32 *)(*(u8 * *)&((struct Obj02494 *)p)->f8 + i * 12 + 0x314) = (u32)func_02045EC0(((struct Obj23517 *)(*(u8 * *)&((struct Obj02494 *)p)->f8))->f1D0, t->a);
        *(u16 *)(*(u8 * *)&((struct Obj02494 *)p)->f8 + i * 12 + 0x318) = 0x39E3;
        *(u32 *)(*(u8 * *)&((struct Obj02494 *)p)->f8 + i * 12 + 0x31C) = t->b;
    }
    for (i = 0; i < 2; i++) {
        t = &g_78B0[i];
        *(u32 *)(*(u8 * *)&((struct Obj02494 *)p)->f8 + i * 12 + 0x344) = (u32)func_02045EC0(((struct Obj23518 *)(*(u8 * *)&((struct Obj02494 *)p)->f8))->f1D0, t->a);
        *(u16 *)(*(u8 * *)&((struct Obj02494 *)p)->f8 + i * 12 + 0x348) = 0x39E3;
        *(u32 *)(*(u8 * *)&((struct Obj02494 *)p)->f8 + i * 12 + 0x34C) = t->b;
    }
}
