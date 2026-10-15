/*
 * function: BTL_SERVER_FLOW_LoadFrame
 * address: 0x021C85D4
 * packet: pkt_ov093_021C85D4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C87A0 0x021C87A0 thumb ov093
 *   Wf2dmapFriend_ShowEntryActor 0x021C87B0 thumb ov093
 *   func_021C87C0 0x021C87C0 thumb ov093
 *   func_021C87D0 0x021C87D0 thumb ov093
 *   PLEASURE_BOAT_GetTimeEvent 0x021C87E0 thumb ov093
 *   func_021C87F0 0x021C87F0 thumb ov093
 *   func_021C8800 0x021C8800 thumb ov093
 *   BTL_SERVER_FLOW_InitTurnState 0x021BD1E0 thumb ov093
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj00294.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Flags { u8 low : 3; u8 a : 1; u8 b : 1; u8 high : 3; };
struct Unk021BD1E0 {
    u16 f0; u8 f2; u8 f3; u8 f4;
    u8 b0 : 1; u8 b1 : 1; u8 rest : 6;
};
extern void func_021C87A0(void *);
extern void Wf2dmapFriend_ShowEntryActor(void *);
extern void func_021C87C0(void *);
extern void func_021C87D0(void *);
extern void PLEASURE_BOAT_GetTimeEvent(void *);
extern void func_021C87F0(void *);
extern void func_021C8800(void *);
extern void BTL_SERVER_FLOW_InitTurnState(struct Unk021BD1E0 *);
extern void MI_CpuFill8(void *, int, u32);

void BTL_SERVER_FLOW_LoadFrame(u8 *p, int index, int clear)
{
    u8 *q = p + 0x874 + index * 0x290;
    *(u8 * *)&((struct Obj00294 *)p)->f850 = q;
    *(u8 * *)&((struct Obj00294 *)p)->f854 = q + 0x48;
    *(u8 * *)&((struct Obj00294 *)p)->f858 = q + 0x90;
    *(u8 * *)&((struct Obj00294 *)p)->f85C = q + 0xd8;
    *(u8 * *)&((struct Obj00294 *)p)->f860 = q + 0x120;
    *(u8 * *)&((struct Obj00294 *)p)->f864 = q + 0x168;
    *(u8 * *)&((struct Obj00294 *)p)->f868 = q + 0x1b0;
    *(u8 * *)&((struct Obj00294 *)p)->f4A8 = q + 0x1f8;
    *(u8 * *)&((struct Obj00294 *)p)->f1AB0 = q + 0x200;
    *(u8 * *)&((struct Obj00294 *)p)->f1AB4 = q + 0x214;
    *(u8 * *)&((struct Obj00294 *)p)->f4B4 = q + 0x228;
    *(u8 * *)&((struct Obj00294 *)p)->f4AC = q + 0x22e;
    *(u8 * *)&((struct Obj00294 *)p)->f4B0 = q + 0x241;
    *(u8 * *)&((struct Obj00294 *)p)->f86C = q + 0x254;
    *(u8 * *)&((struct Obj00294 *)p)->f870 = q + 0x270;
    p[0x77f] = q[0x28c];
    ((struct Flags *)(p + 0x78a))->a = q[0x28d];
    ((struct Flags *)(p + 0x78a))->b = q[0x28e];
    if (clear) {
        func_021C87A0(q);
        Wf2dmapFriend_ShowEntryActor(((struct Obj00294 *)p)->f854);
        func_021C87C0(((struct Obj00294 *)p)->f858);
        func_021C87D0(((struct Obj00294 *)p)->f85C);
        PLEASURE_BOAT_GetTimeEvent(((struct Obj00294 *)p)->f860);
        func_021C87F0(((struct Obj00294 *)p)->f864);
        func_021C8800(((struct Obj00294 *)p)->f868);
        BTL_SERVER_FLOW_InitTurnState(*(struct Unk021BD1E0 * *)&((struct Obj00294 *)p)->f4A8);
        MI_CpuFill8(((struct Obj00294 *)p)->f1AB0, 0, 0x14);
        MI_CpuFill8(((struct Obj00294 *)p)->f1AB4, 0, 0x14);
        MI_CpuFill8(((struct Obj00294 *)p)->f4B4, 0, 6);
        MI_CpuFill8(((struct Obj00294 *)p)->f4AC, 0, 0x13);
        MI_CpuFill8(((struct Obj00294 *)p)->f4B0, 0, 0x13);
        MI_CpuFill8(((struct Obj00294 *)p)->f86C, 0, 0x1c);
        MI_CpuFill8(((struct Obj00294 *)p)->f870, 0, 0x1c);
        p[0x77f] = 6;
        ((struct Flags *)(p + 0x78a))->a = 0;
        ((struct Flags *)(p + 0x78a))->b = 0;
    }
}
