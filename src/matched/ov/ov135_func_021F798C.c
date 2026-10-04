/*
 * function: func_021F798C
 * address: 0x021F798C
 * packet: pkt_ov135_021F798C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02030734 0x02030734 arm
 *   func_02082AC0 0x02082AC0 arm
 *   func_021F8498 0x021F8498 thumb ov135
 *   func_021F84EC 0x021F84EC thumb ov135
 *   func_021F8990 0x021F8990 thumb ov135
 *   g_02203C00 0x02203C00 data a4
 */
#include "../include/Obj05412.h"
#include "../include/Obj23382.h"
#include "../include/Obj23383.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
extern const char g_02203C00[];
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082AC0(u32 value, void *dst, u32 size);
extern u16 *func_021F8498(u32 heap, u32 unused, u32 *count);
extern u8 *func_021F84EC(u32 id);
extern void func_021F8990(u8 *p);
void func_021F798C(u8 *p)
{
    ((struct Obj05412 *)p)->fB88 = func_020457B0(0xB4, 0x48);
    ((struct Obj05412 *)p)->fE00 = func_02030734(0x48, 0x30, 0, g_02203C00, 0x2B4);
    func_02082AC0(0, ((struct Obj05412 *)p)->fE00, 0x30);
    *(u16 * *)&((struct Obj23382 *)(*(u8 * *)&((struct Obj05412 *)p)->fE00))->f18 = func_021F8498(0x48, 0, (u32 *)(*(u8 * *)&((struct Obj05412 *)p)->fE00 + 0x1C));
    *(u8 * *)&((struct Obj23383 *)(*(u8 * *)&((struct Obj05412 *)p)->fE00))->f14 = func_021F84EC(0x48);
    func_021F8990(p + 0xEEC);
}
