/*
 * function: func_021BBC5C
 * address: 0x021BBC5C
 * packet: pkt_ov110_021BBC5C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021C3C58 0x021C3C58 data a1
 *   func_021BF6D4 0x021BF6D4 thumb ov110
 *   func_020457B0 0x020457B0 arm
 *   func_02045B38 0x02045B38 arm
 *   BMP_CURSOR_Create 0x02020D18 thumb
 *   BGWINFRM_Create 0x0202C9B4 thumb
 */
#include "../include/Obj01392.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct WinMgr;
extern void *func_02030734(unsigned, unsigned, int, const char *, u16);
extern const char d_021C3C58[];
extern u8 *func_021BF6D4(u8 *);
struct MsgBank;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *BMP_CURSOR_Create(unsigned);
extern struct WinMgr *BGWINFRM_Create(u32 a0, u32 a1, u32 heap);
u8 *func_021BBC5C(void *a, u8 *b, void *c)
{
    u8 *p;
    p = func_02030734(42, 444, 1, d_021C3C58, 211);
    ((struct Obj01392 *)p)->f0 = a;
    *(u8 * *)&((struct Obj01392 *)p)->f4 = b;
    ((struct Obj01392 *)p)->f8 = c;
    *(u8 * *)&((struct Obj01392 *)p)->f1A0 = func_021BF6D4(b);
    ((struct Obj01392 *)p)->f14 = 0;
    ((struct Obj01392 *)p)->f18 = 0;
    ((struct Obj01392 *)p)->f1A4 = 0;
    ((struct Obj01392 *)p)->f30 = func_020457B0(128, 42);
    ((struct Obj01392 *)p)->f2C = func_02045B38(0, 2, 146, 42);
    ((struct Obj01392 *)p)->f34 = BMP_CURSOR_Create(42);
    ((struct Obj01392 *)p)->f198 = 0;
    ((struct Obj01392 *)p)->f19A = 0;
    ((struct Obj01392 *)p)->f1A8 = 0;
    ((struct Obj01392 *)p)->f1AC = 0;
    ((struct Obj01392 *)p)->f1B0 = 0;
    ((struct Obj01392 *)p)->f1B4 = BGWINFRM_Create(1, 1, 42);
    return p;
}
