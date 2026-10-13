/*
 * function: BTL_SERVER_FLOW_ProcNoEffectChecks
 * address: 0x021BF4AC
 * packet: pkt_ov093_021BF4AC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Four separate veneer iterator loops; retain the explicit fourth C6668 argument.
 * symbols:
 *   EVENT_APPEAR_CreateSpinZoomAlt 0x021BF5E8 thumb ov093
 *   func_021BF5F8 0x021BF5F8 thumb ov093
 *   PMS_INPUT_SubHandleCancel 0x021BF608 thumb ov093
 *   func_021BF618 0x021BF618 thumb ov093
 *   func_021BF628 0x021BF628 thumb ov093
 *   func_021BF638 0x021BF638 thumb ov093
 *   func_021BF648 0x021BF648 thumb ov093
 *   func_021BF658 0x021BF658 thumb ov093
 *   func_021BF668 0x021BF668 thumb ov093
 *   func_021BF678 0x021BF678 thumb ov093
 *   func_021BF688 0x021BF688 thumb ov093
 *   func_021BF698 0x021BF698 thumb ov093
 *   func_021BF6A8 0x021BF6A8 thumb ov093
 *   func_021BF6B8 0x021BF6B8 thumb ov093
 *   func_021BF6C8 0x021BF6C8 thumb ov093
 *   PMS_INPUT_GetInputMode 0x021BF6D8 thumb ov093
 *   BTL_SERVER_FLOW_CheckNoGuardHit 0x021BF324 thumb ov093
 *   BTL_SERVER_FLOW_ProcNoEffectCheck 0x021BF6E8 thumb ov093
 *   BTL_POKEPARAM_TestTurnFlag 0x021D5BB0 thumb ov093
 *   BTL_SERVER_FLOW_QueryActionCancelEvent 0x021C6668 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_SERVER_CMD_PushVariable 0x021CD64C thumb ov093
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb  arm9
 */
#include "../include/Obj04358.h"
#include "../include/Obj13316.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void EVENT_APPEAR_CreateSpinZoomAlt(void *);
extern u8 *func_021BF5F8(void *);
extern void PMS_INPUT_SubHandleCancel(void *, u8 *);
extern u8 *func_021BF618(void *);
extern void func_021BF628(void *);
extern u8 *func_021BF638(void *);
extern void func_021BF648(void *, u8 *);
extern u8 *func_021BF658(void *);
extern void func_021BF668(void *);
extern u8 *func_021BF678(void *);
extern void func_021BF688(void *, u8 *);
extern u8 *func_021BF698(void *);
extern void func_021BF6A8(void *);
extern u8 *func_021BF6B8(void *);
extern void func_021BF6C8(void *, u8 *);
extern u8 *PMS_INPUT_GetInputMode(void *);
extern int BTL_SERVER_FLOW_CheckNoGuardHit(u8 *, u8 *, u8 *);
extern int BTL_SERVER_FLOW_ProcNoEffectCheck(u8 *, u8 *, u8 *, u8 *, void *, int);
extern u32 WAZA_TOOL_GetFlag(u16, u32);
struct UtilWork;
extern int BTL_POKEPARAM_TestTurnFlag(struct UtilWork *p, u32 n);
extern int BTL_SERVER_FLOW_QueryActionCancelEvent(u8 *, u8 *, u8 *, u16);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_SERVER_CMD_PushVariable(void *, u8, ...);
void BTL_SERVER_FLOW_ProcNoEffectChecks(u8 *p, u8 *b, u8 *a, void *d, void *e)
{
    u8 *q;
    EVENT_APPEAR_CreateSpinZoomAlt(d);
    q = func_021BF5F8(d);
    while (q) {
        if (BTL_SERVER_FLOW_CheckNoGuardHit(p, a, q) == 0 && BTL_SERVER_FLOW_ProcNoEffectCheck(p, b, a, q, e, 43))
            PMS_INPUT_SubHandleCancel(d, q);
        q = func_021BF618(d);
    }
    func_021BF628(d);
    q = func_021BF638(d);
    while (q) {
        if (BTL_SERVER_FLOW_ProcNoEffectCheck(p, b, a, q, e, 44)) func_021BF648(d, q);
        q = func_021BF658(d);
    }
    if (WAZA_TOOL_GetFlag(((struct Obj04358 *)b)->f0, 3)) {
        func_021BF668(d);
        q = func_021BF678(d);
        while (q) {
            if (BTL_POKEPARAM_TestTurnFlag((struct UtilWork *)q, 7) && BTL_SERVER_FLOW_QueryActionCancelEvent(p, a, q, ((struct Obj04358 *)b)->f0) == 0) {
                func_021BF688(d, q);
                BTL_SERVER_CMD_PushVariable(((struct Obj13316 *)p)->fC, 91, 523, BTL_POKEPARAM_GetPokeId(q), 0xffff0000);
            }
            q = func_021BF698(d);
        }
    }
    func_021BF6A8(d);
    q = func_021BF6B8(d);
    while (q) {
        if (BTL_SERVER_FLOW_ProcNoEffectCheck(p, b, a, q, e, 45)) func_021BF6C8(d, q);
        q = PMS_INPUT_GetInputMode(d);
    }
}
