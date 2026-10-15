/*
 * function: BTL_SERVER_FLOW_ProcAccuracyCheck
 * address:  0x021BF3D8
 * packet:   pkt_ov093_021BF3D8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_ResetSlotTable  0x021CC8A0  thumb  ov093
 *   BTL_SERVER_FLOW_SetSlotTableEntry  0x021CC8B0  thumb  ov093
 *   func_021BF46C  0x021BF46C  thumb  ov093
 *   RESEARCH_GRAPH_SetTriangleActorVisible  0x021BF47C  thumb  ov093
 *   func_021BF48C  0x021BF48C  thumb  ov093
 *   func_021BF49C  0x021BF49C  thumb  ov093
 *   BTL_SERVER_FLOW_CalcTypeEffectiveness  0x021C6E3C  thumb  ov093
 *   BTL_SERVER_FLOW_RecordEffectivenessHit  0x021C7C24  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_MAIN_PokeIdToClientIdThunk  0x021B8DDC  thumb  ov093
 *   BTL_MAIN_GetOwnClientId  0x021B8FF4  thumb  ov093
 *   BTL_MAIN_TrainerRecordAdd  0x021BA1B4  thumb  ov093
 */
#include "../include/Obj13315.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void BTL_SERVER_FLOW_ResetSlotTable(u32 *p);
extern void BTL_SERVER_FLOW_SetSlotTableEntry(u32 *p, u32 i, u32 b);
extern void func_021BF46C(int d);
extern u8 *RESEARCH_GRAPH_SetTriangleActorVisible(int d);
extern void func_021BF48C(int d, u8 *x);
extern u8 *func_021BF49C(int d);
extern int BTL_SERVER_FLOW_CalcTypeEffectiveness(u8 *p, u8 *a, u8 *b, u8 *q, int flag);
extern void BTL_SERVER_FLOW_RecordEffectivenessHit(u16 *p, int unused, u8 *b, u8 *c, int e);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern u8 BTL_MAIN_PokeIdToClientIdThunk(u32 x);
extern u8 BTL_MAIN_GetOwnClientId(u8 *p);
extern void BTL_MAIN_TrainerRecordAdd(char **p, int i);

void BTL_SERVER_FLOW_ProcAccuracyCheck(u8 *p, int b, u8 *a, int d, void *arr)
{
    u8 *x;
    int r;
    int e;
    BTL_SERVER_FLOW_ResetSlotTable(arr);
    func_021BF46C(d);
    x = RESEARCH_GRAPH_SetTriangleActorVisible(d);
    while (x != 0) {
        r = BTL_SERVER_FLOW_CalcTypeEffectiveness(p, a, x, (u8 *)b, 1);
        BTL_SERVER_FLOW_SetSlotTableEntry(arr, BTL_POKEPARAM_GetPokeId(x), r);
        if (r == 0) {
            func_021BF48C(d, x);
            BTL_SERVER_FLOW_RecordEffectivenessHit((u16 *)(p + 0x1f7c), (int)p, a, x, 0);
            e = BTL_MAIN_PokeIdToClientIdThunk(BTL_POKEPARAM_GetPokeId(a));
            if (e == BTL_MAIN_GetOwnClientId(*(u8 * *)&((struct Obj13315 *)p)->f4))
                BTL_MAIN_TrainerRecordAdd((char **)(*(u8 * *)&((struct Obj13315 *)p)->f4), 0x4b);
        }
        x = func_021BF49C(d);
    }
}
