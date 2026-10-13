/*
 * function: BTL_SERVER_FLOW_InitState
 * address: 0x021BB9D8
 * packet: pkt_ov093_021BB9D8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Lever: the four flag clears are typed bitfield assignments, emitting bics.
 * BTL_SERVER_FLOW_ClearPendingCounter leaves its input in r0 for the following func_021BBB38.
 * symbols:
 *   BTL_EVENT_InitFactorList 0x021D6EAC thumb ov093
 *   BTL_FIELD_ResetStatic 0x021EF874 thumb ov093
 *   func_021BBB08 0x021BBB08 thumb ov093
 *   func_021BBB18 0x021BBB18 thumb ov093
 *   BTL_MAIN_GetRule 0x021B8588 thumb ov093
 *   func_021BBB28 0x021BBB28 thumb ov093
 *   MI_CpuFill8 0x02082BCC arm
 *   BTL_SERVER_FLOW_ClearEffectivenessRecord 0x021C7C18 thumb ov093
 *   BTL_SERVER_FLOW_ResetFrameStack 0x021C8588 thumb ov093
 *   BTL_CLIENT_SET_Clear 0x021D8230 thumb ov093
 *   BTL_SERVER_FLOW_ResetHandExBuffer 0x021CC8C8 thumb ov093
 *   BTL_SERVER_FLOW_ClearPendingCounter 0x021C5474 thumb ov093
 *   func_021BBB38 0x021BBB38 thumb ov093
 */
#include "../include/Obj02133.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 a:1; u8 b:1; u8 c:1; u8 pad:3; u8 d:1; u8 rest:1; } Flags;
extern void BTL_EVENT_InitFactorList(void);
extern int BTL_FIELD_ResetStatic(int a);
extern void func_021BBB08(void *);
extern void func_021BBB18(void *);
extern u32 BTL_MAIN_GetRule(void **p);
extern void func_021BBB28(void *, void *, void *, u32);
extern void MI_CpuFill8(void *, int, u32);
extern void BTL_SERVER_FLOW_ClearEffectivenessRecord(void *);
extern void BTL_SERVER_FLOW_ResetFrameStack(unsigned char *p);
extern void BTL_CLIENT_SET_Clear(u8 *p);
extern void BTL_SERVER_FLOW_ResetHandExBuffer(u32 *p);
extern void *BTL_SERVER_FLOW_ClearPendingCounter(char *p);
extern void func_021BBB38(void *);
void BTL_SERVER_FLOW_InitState(u8 *p)
{
    BTL_EVENT_InitFactorList();
    BTL_FIELD_ResetStatic(0);
    func_021BBB08(p + 0x1c);
    func_021BBB18(p + 0x3e0);
    func_021BBB28(p + 0x1ab8, ((struct Obj02133 *)p)->f4, ((struct Obj02133 *)p)->f8, BTL_MAIN_GetRule(((struct Obj02133 *)p)->f4));
    MI_CpuFill8(p + 0x7a9, 0, 0x18);
    MI_CpuFill8(p + 0x7c1, 0, 0x18);
    MI_CpuFill8(p + 0x7d9, 0, 4);
    MI_CpuFill8(p + 0x4d4, 0, 0x2a0);
    BTL_SERVER_FLOW_ClearEffectivenessRecord(p + 0x1f7c);
    BTL_SERVER_FLOW_ResetFrameStack(p);
    BTL_CLIENT_SET_Clear(p + 0x4b8);
    BTL_SERVER_FLOW_ResetHandExBuffer((u32 *)(p + 0x1d74));
    func_021BBB38(BTL_SERVER_FLOW_ClearPendingCounter((char *)(p + 0x1b50)));
    p[0x786] = 0;
    p[0x787] = 0;
    ((Flags *)(p + 0x78a))->a = 0;
    ((Flags *)(p + 0x78a))->b = 0;
    ((Flags *)(p + 0x78a))->c = 0;
    p[0x77c] = 0;
    p[0x789] = 31;
    ((struct Obj02133 *)p)->f1F74 = 0;
    p[0x784] = 6;
    ((struct Obj02133 *)p)->f774 = 0;
    p[0x77e] = 0;
    ((struct Obj02133 *)p)->f778 = 0;
    ((Flags *)(p + 0x78a))->d = 0;
}
