/*
 * function: func_021C67D4
 * address: 0x021C67D4
 * packet: pkt_ov136_021C67D4
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021C6882 halfword is alignment padding.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_02027618 0x02027618 thumb
 *   func_02027614 0x02027614 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 */
#include "../include/Obj05422.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
extern u32 func_020275E4(void);
extern void *func_020490F4(u32 id, u32 heap);
extern int func_0204A6C8(void *, u32, u32, u32, u16);
extern int func_0204ABF0(void *, u32, u32, u32, u16);
extern int func_0204AF28(void *, u32, u32, u32);
extern void func_02049238(void *);
extern u32 func_02027618(void);
extern u32 func_02027614(void);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
void func_021C67D4(u8 *p)
{
    void *arc;
    u32 first;
    arc = func_020490F4(155, 102);
    ((struct Obj05422 *)p)->f21C = func_0204A6C8(arc, 44, 1, 0, 102);
    ((struct Obj05422 *)p)->f234 = func_0204ABF0(arc, 47, 0, 0, 102);
    ((struct Obj05422 *)p)->f254 = func_0204AF28(arc, 45, 46, 102);
    func_02049238(arc);
    arc = func_020490F4(func_020275E4(), 102);
    ((struct Obj05422 *)p)->f220 = func_0204A6C8(arc, func_02027618(), 0, 0, 102);
    ((struct Obj05422 *)p)->f238 = func_0204ABF0(arc, func_02027614(), 0, 128, 102);
    first = func_0202761C(0);
    ((struct Obj05422 *)p)->f258 = func_0204AF28(arc, first, func_02027620(0), 102);
    func_02049238(arc);
}
