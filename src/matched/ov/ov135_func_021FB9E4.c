/*
 * function: func_021FB9E4
 * address: 0x021FB9E4
 * packet: pkt_ov135_021FB9E4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Tail: two zero bytes of alignment padding after the return.
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B898 0x0204B898 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B98C 0x0204B98C arm
 *   func_021F9660 0x021F9660 thumb ov135
 */
#include "../include/Obj00098.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed char s8;
struct WinMgr;
struct Actor;
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int on);
extern u16 func_0204B898(struct Obj *p);
extern void func_0204B878(struct Obj *p, u16 value);
extern u32 func_0204B98C(struct Actor *a);
extern void func_021F9660(void *p, u32 mode);
extern void func_0202CD64(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
extern void func_0202CAE4(struct WinMgr *mgr, u32 idx, u32 arc, u32 member, u32 alloc);
int func_021FB9E4(u8 *p)
{
    if (func_0204B98C(((struct Obj00098 *)p)->f8) != 0) return -1;
    func_0204B3DC((struct Obj *)*(u32 *)&((struct Obj00098 *)p)->f8, 0);
    func_021F9660(p, 5);
    if (((struct Obj00098 *)p)->f3A < 0) {
        ((struct Obj00098 *)p)->f48 = 21;
    } else {
            func_0202CD64(((struct Obj00098 *)p)->f18, 0, -4, 0, 3);
            if (((struct Obj00098 *)p)->f14 != 0) func_0204B3DC((struct Obj *)((struct Obj00098 *)p)->f14, 0);
            func_0204B878((struct Obj *)(*(u32 *)&((struct Obj00098 *)p)->f8), 7);
            ((struct Obj00098 *)p)->f48 = 2;
            func_0202CAE4(((struct Obj00098 *)p)->f18, 0, 0x60, 0x18, 1);
            ((struct Obj00098 *)p)->f4C = 26;
    }
    return -1;
}
