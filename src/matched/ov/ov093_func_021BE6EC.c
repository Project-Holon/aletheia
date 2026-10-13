/*
 * function: BTL_SERVER_FLOW_ProcPledgeCombo
 * address: 0x021BE6EC
 * packet: pkt_ov093_021BE6EC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: shared fail label keeps one zero-return epilogue; id, chosen,
 * best declaration order fixes the spilled local slots.
 * symbols:
 *   gPledgeMoveIds 0x021EFDB8 data a2
 *   BTL_POKEPARAM_TestTurnFlag 0x021D5BB0 thumb ov093
 *   BTL_EVENT_HasClientReservedChoice 0x021D6E74 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_SERVER_FLOW_FindPendingMoveActionForPoke 0x021BCB14 thumb ov093
 *   BTL_SERVER_FLOW_GetActionIndex 0x021BCB68 thumb ov093
 *   BTL_POKEPARAM_SetTurnFlag 0x021D5FC0 thumb ov093
 *   BTL_EVENT_SetClientReservedChoice 0x021D6E40 thumb ov093
 *   BTL_SERVER_CMD_PushVariable 0x021CD64C thumb ov093
 *   BTL_SERVER_FLOW_PromoteActionOfPoke 0x021BD148 thumb ov093
 */
#include "../include/Obj21052.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 *a; u32 b, c; u8 d0, flag; u16 pad; } E;
extern const u16 gPledgeMoveIds[3];
struct UtilWork;
extern int BTL_POKEPARAM_TestTurnFlag(struct UtilWork *p, u32 n);
extern u32 BTL_EVENT_HasClientReservedChoice(u8 *p);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern E *BTL_SERVER_FLOW_FindPendingMoveActionForPoke(u8 *, u16, u8, u32);
extern u32 BTL_SERVER_FLOW_GetActionIndex(u8 *, E *);
extern void BTL_POKEPARAM_SetTurnFlag(struct UtilWork *p, u32 n);
extern void BTL_EVENT_SetClientReservedChoice(u8 *, u8, u16);
extern void BTL_SERVER_CMD_PushVariable(void *, u8, ...);
extern int BTL_SERVER_FLOW_PromoteActionOfPoke(void *p, u8 x);
int BTL_SERVER_FLOW_ProcPledgeCombo(u8 *p, u8 *a, u16 key, u32 x)
{
    u32 i;
    u32 n;
    u8 id;
    u8 *chosen;
    u32 best;
    u8 chosen_id;
    E *cur;
    E *found[2];
    u32 v;
    for (i = 0; i < 3; i++) {
        if (key == gPledgeMoveIds[i]) break;
    }
    if (i == 3) goto fail;
    if (BTL_POKEPARAM_TestTurnFlag((struct UtilWork *)a, 10) != 0) goto fail;
    if (BTL_EVENT_HasClientReservedChoice(a) != 0) goto fail;
    n = 0;
    id = BTL_POKEPARAM_GetPokeId(a);
    for (i = 0; i < 3; i++) {
        if (key != gPledgeMoveIds[i]) {
            found[n] = BTL_SERVER_FLOW_FindPendingMoveActionForPoke(p, gPledgeMoveIds[i], id, x);
            if (found[n] != 0) {
                n++;
                if (n >= 2) break;
            }
        }
    }
    if (n == 0) goto fail;
    best = 6;
    chosen = found[0]->a;
    for (i = 0; i < n; i++) {
        cur = found[i];
        v = BTL_SERVER_FLOW_GetActionIndex(p, cur);
        if (v < best) {
            best = v;
            chosen = cur->a;
        }
    }
    chosen_id = BTL_POKEPARAM_GetPokeId(chosen);
    BTL_POKEPARAM_SetTurnFlag((struct UtilWork *)a, 10);
    BTL_EVENT_SetClientReservedChoice(chosen, id, key);
    BTL_SERVER_CMD_PushVariable(((struct Obj21052 *)p)->fC, 91, 0x47a, id, chosen_id, 0xffff0000);
    BTL_SERVER_FLOW_PromoteActionOfPoke(p, chosen_id);
    return 1;
fail:
    return 0;
}
