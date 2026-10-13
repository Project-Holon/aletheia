/*
 * function: func_021F44F8
 * address: 0x021F44F8
 * packet: pkt_ov112_021F44F8
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * ABI: 0204B294 returns an Obj pointer, which the original stores at +88.
 * symbols:
 *   func_021F4684 0x021F4684 thumb ov112
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_020413B0 0x020413B0 arm
 *   func_020409B4 0x020409B4 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_02027624 0x02027624 thumb
 *   func_02027628 0x02027628 thumb
 *   func_0202762C 0x0202762C thumb
 *   func_02027614 0x02027614 thumb
 *   func_02027618 0x02027618 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   d_021F8298 0x021F8298 data a4
 *   d_021F82B8 0x021F82B8 data a4
 *   d_021F82D8 0x021F82D8 data a4
 */
#include "../include/Obj00721.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 x,y,z; u8 a,b; } Desc;
extern const u32 d_021F8298[],d_021F82B8[],d_021F82D8[];
extern void func_021F4684(const void *,u32,u32);
struct Bank;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void BG_SYS_SetSubPlaneVisible(u32,u32);
extern void *func_020490F4(u32 id, u32 heap);
typedef signed int     s32;
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_TOOL_DeleteHandle(void *);
extern u32 func_020275E4(void);
extern u32 func_02027624(void);
extern u32 func_02027628(void);
extern u32 func_0202762C(void);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u32);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern u32 func_02027614(void);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *,u32,u32,u32,const void *,u16,u16);
void func_021F44F8(u8 *p)
{
    Desc d;
    void *t;
    u32 v;
    u32 w;
    func_021F4684(d_021F8298,4,0);
    func_021F4684(d_021F82B8,6,0);
    func_021F4684(d_021F82D8,7,0);
    ((struct Obj00721 *)p)->f48=CLACT_CreateUnit(8,0,((struct Obj00721 *)p)->f0);
    CLACT_SetUnitDefaultRenderer(((struct Obj00721 *)p)->f48);
    BG_SYS_SetSubPlaneVisible(16,1);
    t=func_020490F4((unsigned int)46,((struct Obj00721 *)p)->f0);
    func_02049B68((void *)((u32)t),4,4,0,0,((struct Obj00721 *)p)->f0);
    func_02049658((void *)((u32)t),7,7,0,0,0,((struct Obj00721 *)p)->f0);
    func_020498F4((void *)((u32)t),12,7,0,0,0,((struct Obj00721 *)p)->f0);
    ARC_TOOL_DeleteHandle(t);
    if (((struct Obj00721 *)p)->fC==0) {
        t=func_020490F4((unsigned int)func_020275E4(),((struct Obj00721 *)p)->f0);
        func_02049B68((void *)((u32)t),func_02027624(),4,288,32,((struct Obj00721 *)p)->f0);
        func_02049658((void *)((u32)t),func_02027628(),6,0,0,0,((struct Obj00721 *)p)->f0);
        func_020498F4((void *)((u32)t),func_0202762C(),6,0,0,0,((struct Obj00721 *)p)->f0);
        func_020413B0(6,0,21,32,3,9);
        func_020409B4(6);
        ((struct Obj00721 *)p)->f4C=CLACT_RegisterPaletteEx((void *)((u32)t),func_02027614(),1,0,0,3,((struct Obj00721 *)p)->f0);
        ((struct Obj00721 *)p)->f50=CLACT_RegisterCharacter((void *)((u32)t),func_02027618(),0,1,((struct Obj00721 *)p)->f0);
        v=func_0202761C(0);
        w=func_02027620(0);
        ((struct Obj00721 *)p)->f54=CLACT_RegisterCellAnim((void *)((u32)t),v,w,((struct Obj00721 *)p)->f0);
        ARC_TOOL_DeleteHandle(t);
        d.x=232;
        d.y=168;
        d.z=1;
        d.b=0;
        d.a=0;
        ((struct Obj00721 *)p)->f58=CLACT_CreateActor((void *)*(u32 *)&((struct Obj00721 *)p)->f48,((struct Obj00721 *)p)->f50,((struct Obj00721 *)p)->f4C,((struct Obj00721 *)p)->f54,&d,1,((struct Obj00721 *)p)->f0);
    }
}
