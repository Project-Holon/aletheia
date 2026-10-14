/*
 * function: MB_SEQ_StateExit
 * address: 0x021C6A5C
 * packet: pkt_ov136_021C6A5C
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_020306F0 0x020306F0 arm
 *   MB_SEQ_DeleteMenuEntries 0x021C5AA8 thumb ov136
 *   MB_SEQ_DeleteMessageResources 0x021C5954 thumb ov136
 *   MB_SEQ_DeleteTouchSelect 0x021C76A8 thumb ov136
 *   MB_SEQ_DeletePmsDraw 0x021C5E30 thumb ov136
 *   MB_SEQ_DeleteActors 0x021C657C thumb ov136
 *   MB_SEQ_DeleteFrames 0x021C5918 thumb ov136
 *   MB_SEQ_DeleteWindows 0x021C5F44 thumb ov136
 *   MB_SEQ_FreeBgs 0x021C5714 thumb ov136
 *   MB_SEQ_FreeMails 0x021C5BE0 thumb ov136
 */
#include "../include/Obj04536.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Node;
extern void func_02030EAC(struct Node *n);
extern void MB_SEQ_DeleteMenuEntries(u8 *);
extern void MB_SEQ_DeleteMessageResources(u8 *p);
extern void MB_SEQ_DeleteTouchSelect(u8 *p);
extern void MB_SEQ_DeletePmsDraw(u8 *p);
extern void MB_SEQ_DeleteActors(u8 *);
extern void MB_SEQ_DeleteFrames(u8 *p);
extern void MB_SEQ_DeleteWindows(u8 *p);
extern void MB_SEQ_FreeBgs(void *);
extern void MB_SEQ_FreeMails(u8 *p);
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern u32 func_020307B0(void *p);
extern void func_020306F0(u32);
u32 MB_SEQ_StateExit(u8 *p)
{
    if (((struct Obj04536 *)p)->f2C != 0) {
        func_02030EAC(((struct Obj04536 *)p)->f2C);
        ((struct Obj04536 *)p)->f2C = 0;
    }
    MB_SEQ_DeleteMenuEntries(p);
    MB_SEQ_DeleteMessageResources(((struct Obj04536 *)p)->f8);
    MB_SEQ_DeleteTouchSelect(p);
    MB_SEQ_DeletePmsDraw(p);
    MB_SEQ_DeleteActors(p);
    MB_SEQ_DeleteFrames(p);
    MB_SEQ_DeleteWindows(p);
    MB_SEQ_FreeBgs(p);
    MB_SEQ_FreeMails(p);
    *(u16 *)0x04000050 = 0;
    *(u16 *)0x04001050 = 0;
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    func_020307B0(((struct Obj04536 *)p)->f8);
    ((struct Obj04536 *)p)->f8 = 0;
    func_020306F0(102);
    return ((struct Obj04536 *)p)->f28;
}
