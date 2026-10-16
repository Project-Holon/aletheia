/*
 * function: BTL_SERVER_FLOW_TryChangeStatStage
 * address: 0x021C3008
 * packet: pkt_ov093_021C3008
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: reassigning value to the transformed result keeps it in its incoming register.
 * symbols:
 *   BTL_SERVER_FLOW_QueryStatStageChangeEvent 0x021C312C thumb ov093
 *   BTL_POKEPARAM_CanChangeStatStage 0x021D5D14 thumb ov093
 *   BTL_SERVER_FLOW_PushSignedChangeMessage 0x021C5A4C thumb ov093
 *   BTL_POKEPARAM_HasSubstitute 0x021D6D7C thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_SERVER_CMD_PushVariable 0x021CD64C thumb ov093
 *   BTL_SERVER_FLOW_CheckStatStageChangeAllowedEvent 0x021C77B0 thumb ov093
 *   BTL_SERVER_FLOW_ChangeStatStage 0x021C5A8C thumb ov093
 *   BTL_SERVER_FLOW_BeginHandExScope 0x021CC8D8 thumb ov093
 *   BTL_SERVER_FLOW_NotifyStatStageChangedEvent 0x021C785C thumb ov093
 *   BTL_SERVER_FLOW_EndHandExScope 0x021CC95C thumb ov093
 *   BTL_SERVER_FLOW_NotifyStatStageChangeBlockedEvent 0x021C7820 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
enum Kind { K0, K1, K10 = 10 };
extern int BTL_SERVER_FLOW_QueryStatStageChangeEvent(u8 *, u8 *, enum Kind, u8, u16, int);
typedef signed char    s8;
extern int BTL_POKEPARAM_CanChangeStatStage(s8 *p, int i, int sign);
extern void BTL_SERVER_FLOW_PushSignedChangeMessage(u8 *p, u8 *a, int b, int c);
extern u32 BTL_POKEPARAM_HasSubstitute(u8 *p);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_SERVER_CMD_PushVariable(void *, u8, ...);
extern int BTL_SERVER_FLOW_CheckStatStageChangeAllowedEvent(u8 *, u8 *, u32, u32, u32, u32);
extern void BTL_SERVER_FLOW_ChangeStatStage(u8 *p, u8 *a, int c, int d, u16 msg, int flag);
extern u32 BTL_SERVER_FLOW_BeginHandExScope(void *, int);
extern void BTL_SERVER_FLOW_NotifyStatStageChangedEvent(u8 *, u32, u8 *, u32, u32);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);
extern void BTL_SERVER_FLOW_NotifyStatStageChangeBlockedEvent(u8 *, u8 *, u32);
int BTL_SERVER_FLOW_TryChangeStatStage(u8 *p, u8 b, u8 *a, enum Kind kind, int value, u8 f, u16 g, u32 h, int i, u32 j)
{
    int result;
    u32 lock;
    value = BTL_SERVER_FLOW_QueryStatStageChangeEvent(p, a, kind, f, g, value);
    if (!BTL_POKEPARAM_CanChangeStatStage((s8 *)a, kind, value)) {
        if (i) {
            BTL_SERVER_FLOW_PushSignedChangeMessage(p, a, kind, value);
            ((struct Obj00003 *)p)->f78A |= 0x10;
        }
        return 0;
    }
    if (BTL_POKEPARAM_HasSubstitute(a)) {
        u8 id;
        id = BTL_POKEPARAM_GetPokeId(a);
        if (b != id) {
            if (i) BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5b, 0xd2, id, 0xffff0000);
            return 0;
        }
    }
    result = 1;
    if (BTL_SERVER_FLOW_CheckStatStageChangeAllowedEvent(p, a, kind, b, value, h)) {
        BTL_SERVER_FLOW_ChangeStatStage(p, a, kind, value, g, j);
        lock = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1d74, 8349);
        BTL_SERVER_FLOW_NotifyStatStageChangedEvent(p, b, a, kind, value);
        BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1d74), lock, 8351);
    } else {
        if (i) {
            lock = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1d74, 8358);
            BTL_SERVER_FLOW_NotifyStatStageChangeBlockedEvent(p, a, h);
            BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1d74), lock, 8360);
        }
        result = 0;
    }
    return result;
}
