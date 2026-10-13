/*
 * unit:     yes
 * function: HAND_WAZA_FuryCutterOnWazaPower, HAND_WAZA_AddAssurance
 * address:  0x021E2E28
 * packet:   pkt_ov093_021E2E28
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetLastUsedMoveId  0x021D67A8  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTL_POKEPARAM_GetMoveStreak  0x021D679C  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   gAssuranceHandlers     0x021F25AC  data  ov093  a4
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
struct QL;
struct QQ;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern u16 BTL_POKEPARAM_GetLastUsedMoveId(struct QL *p);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern u16 BTL_POKEPARAM_GetMoveStreak(u8 *p);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern u8 gAssuranceHandlers[];

void HAND_WAZA_FuryCutterOnWazaPower(int u, void *p, int k)
{
    void *q;
    u32 t;
    u32 n;
    u32 i;
    if (k == BTL_EVENT_GetVar(3)) {
        q = BTL_SERVER_FLOW_GetPokeParam(p, k);
        if (BTL_POKEPARAM_GetLastUsedMoveId(q) == BTL_EVENT_GetFactorKey((void *)u)) {
            t = BTL_EVENT_GetVar(0x30);
            n = BTL_POKEPARAM_GetMoveStreak(q);
            for (i = 0; i < n; i++) {
                t <<= 1;
                if (t > 0xa0) {
                    t = 0xa0;
                    break;
                }
            }
            BTL_EVENT_OverwriteVar(0x30, t);
        }
    }
}

u8 *HAND_WAZA_AddAssurance(int *p)
{
    *p = 1;
    return gAssuranceHandlers;
}
