/*
 * function: func_021F5A18
 * address: 0x021F5A18
 * packet: pkt_ov135_021F5A18
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * precondition: entry mode at offset 0x20 must be 5 or 6; original
 *   leaves r4 unchanged for other modes at 021F5A32..021F5A38.
 * symbols:
 *   func_021F663C 0x021F663C thumb ov135
 *   func_021F4E98 0x021F4E98 thumb ov135
 *   func_020355C4 0x020355C4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   WIPE_SYS_EndCheck  0x020221A4  thumb  arm9
 */
#include "../include/Obj00018.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 WIPE_SYS_EndCheck(void);
extern void func_021F663C(u8 *, u32, u32, u32, u32, u32);
extern void func_021F4E98(u8 *, u32, u32);
extern u8 func_020355C4(void);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
int func_021F5A18(u8 *p)
{
    int index;
    if (WIPE_SYS_EndCheck()) {
        if (((struct Obj00018 *)p)->f20 == 5) {
            index = 0x15;
        } else if (((struct Obj00018 *)p)->f20 == 6) {
            index = 0x11;
        }
        func_021F663C(p, index, 1, 0, 0xf0f, 0);
        func_021F4E98(p, 3, 1);
        if (func_020355C4() == 1) {
            func_0204B3DC((struct Obj *)((struct Obj00018 *)p)->fBF4, 0);
        } else {
            func_0204B3DC((struct Obj *)((struct Obj00018 *)p)->fBF4, 1);
        }
    }
    return 2;
}
