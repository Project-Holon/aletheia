/*
 * unit:     yes
 * function: HAND_WAZA_TechnoBlastOnWazaTypeCheck, HAND_WAZA_AddHiddenPower
 * address:  0x021E324C
 * packet:   pkt_ov093_021E324C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_CanUseHeldItem  0x021C824C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_SERVER_FLOW_SetCurTurnStateFlag  0x021C83DC  thumb  ov093
 *   gHiddenPowerHandlers  0x021F2A78  data   a4
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_SERVER_FLOW_CanUseHeldItem(u8 *p, int v);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct QI;
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern void BTL_SERVER_FLOW_SetCurTurnStateFlag(char *p, int x);
extern u8 gHiddenPowerHandlers[];

void HAND_WAZA_TechnoBlastOnWazaTypeCheck(int u, void *p, int key)
{
    int two = 2;
    if (key == BTL_EVENT_GetVar(two)) {
        if (BTL_SERVER_FLOW_CanUseHeldItem(p, key) != 0) {
            u16 x = (u16)(int)BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(p, key));
            int v = 0;
            int r = 0;
            switch (x) {
            case 0x74: v = 10; r = 1; break;
            case 0x75: v = 12; r = two; break;
            case 0x76: v = 9; r = 3; break;
            case 0x77: v = 14; r = 4; break;
            }
            BTL_EVENT_OverwriteVar(0x16, v);
            BTL_SERVER_FLOW_SetCurTurnStateFlag(p, r);
        }
    }
}

u8 *HAND_WAZA_AddHiddenPower(u32 *out)
{
    *out = 2;
    return gHiddenPowerHandlers;
}
