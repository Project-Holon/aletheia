/*
 * function: BTL_SERVER_FLOW_ProcDamageTargets
 * address: 0x021C0D90
 * packet: pkt_ov093_021C0D90
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C0EC4 0x021C0EC4 thumb ov093
 *   func_021C0ED4 0x021C0ED4 thumb ov093
 *   func_021C0EE4 0x021C0EE4 thumb ov093
 *   func_021C0EF4 0x021C0EF4 thumb ov093
 *   BTL_SERVER_FLOW_BuildDamageList 0x021C0A4C thumb ov093
 *   BTL_SERVER_CMD_Reserve 0x021CD4FC thumb ov093
 *   func_021C0F04 0x021C0F04 thumb ov093
 *   BTL_SERVER_FLOW_ProcDamageRecordIfAny 0x021C11A4 thumb ov093
 *   BTL_SERVER_FLOW_IsPlayerSidePoke 0x021BEC08 thumb ov093
 *   BTL_MAIN_TrainerRecordAdd 0x021BA1B4 thumb ov093
 *   PMS_SELECT_GRAPHIC_UpdateInput 0x021C0F14 thumb ov093
 */
#include "../include/Obj01373.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Flags { u32 a:1; u32 b:1; } Flags;
extern u32 func_021C0EC4(u8 *);
extern u32 func_021C0ED4(u8 *);
extern void func_021C0EE4(u8 *, u8 *, u8 *);
extern void func_021C0EF4(u8 *, u8 *, u8 *);
extern void BTL_SERVER_FLOW_BuildDamageList(u8 *, u8 *, u8 *, u8 *, u32, u32, u8 *);
extern u32 BTL_SERVER_CMD_Reserve(u8 *, u32);
extern u32 func_021C0F04(u8 *);
extern u32 BTL_SERVER_FLOW_ProcDamageRecordIfAny(u8 *, u8 *, u8 *, u8 *, u8 *, u8 *, u32, Flags);
extern int BTL_SERVER_FLOW_IsPlayerSidePoke(u8 *p, u8 *a);
extern void BTL_MAIN_TrainerRecordAdd(char **p, int i);
extern u32 PMS_SELECT_GRAPHIC_UpdateInput(u8 *);
u32 BTL_SERVER_FLOW_ProcDamageTargets(u8 *p, u8 *q, u8 *a, u8 *b, u32 c, u32 *out, u32 d)
{
    u32 k;
    u32 result;
    Flags f;
    if (func_021C0EC4(b) == 1) k = 0x1000;
    else k = 0xc00;
    result = 0;
    f.a = func_021C0ED4(b) > 1;
    f.b = d;
    func_021C0EE4(b, a, *(u8 * *)&((struct Obj01373 *)p)->f858);
    func_021C0EF4(b, a, *(u8 * *)&((struct Obj01373 *)p)->f85C);
    BTL_SERVER_FLOW_BuildDamageList(p, a, *(u8 * *)&((struct Obj01373 *)p)->f858, q, c, k, *(u8 * *)&((struct Obj01373 *)p)->f86C);
    BTL_SERVER_FLOW_BuildDamageList(p, a, *(u8 * *)&((struct Obj01373 *)p)->f85C, q, c, k, *(u8 * *)&((struct Obj01373 *)p)->f870);
    *out = BTL_SERVER_CMD_Reserve(*(u8 * *)&((struct Obj01373 *)p)->fC, 0x30);
    if (func_021C0F04(*(u8 * *)&((struct Obj01373 *)p)->f858) != 0) {
        result += BTL_SERVER_FLOW_ProcDamageRecordIfAny(p, q, a, *(u8 * *)&((struct Obj01373 *)p)->f858, *(u8 * *)&((struct Obj01373 *)p)->f86C, *(u8 * *)&((struct Obj01373 *)p)->f4B4, k, f);
        if (result != 0 && BTL_SERVER_FLOW_IsPlayerSidePoke(p, a) != 0)
            BTL_MAIN_TrainerRecordAdd((char **)(*(u8 * *)&((struct Obj01373 *)p)->f4), 0x4d);
    }
    if (PMS_SELECT_GRAPHIC_UpdateInput(*(u8 * *)&((struct Obj01373 *)p)->f85C) != 0)
        result += BTL_SERVER_FLOW_ProcDamageRecordIfAny(p, q, a, *(u8 * *)&((struct Obj01373 *)p)->f85C, *(u8 * *)&((struct Obj01373 *)p)->f870, *(u8 * *)&((struct Obj01373 *)p)->f4B4, k, f);
    return result;
}
