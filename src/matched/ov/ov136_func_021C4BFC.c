/*
 * function: func_021C4BFC
 * address: 0x021C4BFC
 * packet: pkt_ov136_021C4BFC
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 0x021C4C9A..0x021C4C9C is a zero alignment halfword.
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   func_020457B0 0x020457B0 arm
 *   func_021C4DE4 0x021C4DE4 thumb ov136
 *   func_021C4EEC 0x021C4EEC thumb ov136
 *   func_021C515C 0x021C515C thumb ov136
 *   func_021C5420 0x021C5420 thumb ov136
 *   func_021C4D54 0x021C4D54 thumb ov136
 *   func_021C5360 0x021C5360 thumb ov136
 *   func_021C5268 0x021C5268 thumb ov136
 *   func_021C4C9C 0x021C4C9C thumb ov136
 */
#include "../include/Obj00160.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct MsgBank;
struct U16Vec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_021C4DE4(u8 *);
extern void func_021C4EEC(u8 *);
extern void func_021C515C(u8 *);
extern void func_021C5420(u8 *);
struct R;
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void func_021C4D54(u8 *);
extern void func_021C5360(u8 *);
extern void func_021C5268(u8 *);
extern void func_021C4C9C(u8 *);
int func_021C4BFC(u8 *p)
{
    switch (((struct Obj00160 *)p)->f8) {
    case 0:
        ((struct Obj00160 *)p)->f20 = func_02045B38(0, 2, 60, (u16)((struct Obj00160 *)p)->f0);
        ((struct Obj00160 *)p)->f34 = func_020457B0(128, (u16)((struct Obj00160 *)p)->f0);
        func_021C4DE4(p);
        break;
    case 1:
        func_021C4EEC(p);
        break;
    case 2:
        func_021C515C(p);
        break;
    case 3:
        func_021C5420(p);
        ((struct Obj00160 *)p)->f108 = func_02027F60(0, 8, (u32)(((struct Obj00160 *)p)->f24), (u32)(((struct Obj00160 *)p)->f98), (u16)((struct Obj00160 *)p)->f0);
        ((struct Obj00160 *)p)->f8 = 0;
        func_021C4D54(p);
        func_021C5360(p);
        func_021C5268(p);
        func_021C4C9C(p);
        return 1;
    }
    (((struct Obj00160 *)p)->f8)++;
    return 0;
}
