/*
 * function: BTL_SERVER_FLOW_RunMoveDamageGroupEvent
 * address: 0x021C1B5C
 * packet: pkt_ov093_021C1B5C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C1C48 0x021C1C48 thumb ov093
 *   func_021C1C58 0x021C1C58 thumb ov093
 *   func_021C1C68 0x021C1C68 thumb ov093
 *   func_021C1C78 0x021C1C78 thumb ov093
 *   BTL_EVENT_PushVarFrame 0x021D74F8 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_EVENT_SetVarReadOnly 0x021D75EC thumb ov093
 *   BTL_EVENT_SetVarOnce 0x021D7630 thumb ov093
 *   BTL_EVENT_DispatchEventChecked 0x021D70F0 thumb ov093
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_PopVarFrame 0x021D7540 thumb ov093
 */
#include "../include/Obj13325.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_021C1C48(u8 *);
extern u8 *func_021C1C58(u8 *, u32);
extern int func_021C1C68(u8 *, u8 *, u32 *);
extern int func_021C1C78(u8 *, u8 *, u32 *);
extern void BTL_EVENT_PushVarFrame(int);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVarReadOnly(int, u32);
extern void BTL_EVENT_SetVarOnce(int, u32);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern int BTL_EVENT_GetVar(int);
extern void BTL_EVENT_PopVarFrame(int);
void BTL_SERVER_FLOW_RunMoveDamageGroupEvent(u8 *p, u8 *a, u8 *b, u8 *c, u32 d, u8 e, int f)
{
    u32 sum;
    u32 n;
    u32 got;
    u32 i;
    u32 v;
    u8 *x;
    int ok;
    n = func_021C1C48(b);
    sum = 0;
    got = 0;
    BTL_EVENT_PushVarFrame(0x1b2b);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(0x4d, d);
    BTL_EVENT_SetVarReadOnly(0x12, ((struct Obj13325 *)c)->f0);
    BTL_EVENT_SetVarReadOnly(0x16, c[6]);
    for (i = 0; i < n; i++) {
        x = func_021C1C58(b, i);
        if (e) ok = func_021C1C68(b, x, &v);
        else ok = func_021C1C78(b, x, &v);
        if (ok) {
            sum += v;
            BTL_EVENT_SetVarReadOnly(got + 6, BTL_POKEPARAM_GetPokeId(x));
            got++;
        }
    }
    if (got) {
        BTL_EVENT_SetVarReadOnly(5, got);
        BTL_EVENT_SetVarOnce(0x47, 0);
        BTL_EVENT_SetVarOnce(0x48, 0);
        BTL_EVENT_SetVarReadOnly(0x32, sum);
        BTL_EVENT_DispatchEventChecked(p, 0x82);
        if (!BTL_EVENT_GetVar(0x48)) BTL_EVENT_DispatchEventChecked(p, f);
    }
    BTL_EVENT_PopVarFrame(0x1b52);
}
