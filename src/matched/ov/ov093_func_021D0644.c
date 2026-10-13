/*
 * function: BTL_CLIENT_HasMoveWithAffinityVsTarget
 * address:  0x021D0644
 * packet:   pkt_ov093_021D0644
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_POKEPARAM_GetTypePair  0x021D57FC  thumb  ov093
 *   BTL_POKEPARAM_GetMoveCount  0x021D5448  thumb  ov093
 *   BTL_POKEPARAM_GetMoveId  0x021D54C0  thumb  ov093
 *   BTL_POKEPARAM_GetMovePPChecked  0x021D5584  thumb  ov093
 *   WAZA_TOOL_IsDamaging  0x0201C314  thumb
 *   BTL_CLIENT_IsMoveSelectionBlocked  0x021CF5B0  thumb  ov093
 *   WAZA_TOOL_GetType  0x0201C1C8  thumb
 *   BTL_CALC_GetTypeAffinityVsPair  0x021D799C  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_POKEPARAM_IsFainted(void *m);
extern u16 BTL_POKEPARAM_GetTypePair(void *m);
struct QG;
extern u8 BTL_POKEPARAM_GetMoveCount(struct QG *p);
struct UtilWork;
extern u16 BTL_POKEPARAM_GetMoveId(u8 *p, int i);
extern u8 BTL_POKEPARAM_GetMovePPChecked(struct UtilWork *p, u32 i);
extern u32 WAZA_TOOL_IsDamaging(void *p);
extern int BTL_CLIENT_IsMoveSelectionBlocked(u8 *g, void *m, u32 move, void *out);
extern u8 WAZA_TOOL_GetType(void *p);
extern int BTL_CALC_GetTypeAffinityVsPair(int a, int b);

int BTL_CLIENT_HasMoveWithAffinityVsTarget(void *g, void *m, void *a, int b)
{
    int x;
    u8 n;
    u32 i;
    u32 q;

    if (BTL_POKEPARAM_IsFainted(m) == 0) {
        x = BTL_POKEPARAM_GetTypePair(a);
        n = BTL_POKEPARAM_GetMoveCount(m);
        for (i = 0; i < n; i++) {
            q = BTL_POKEPARAM_GetMoveId(m, (u8)i);
            if (BTL_POKEPARAM_GetMovePPChecked(m, (u8)i) && WAZA_TOOL_IsDamaging((void *)q)
                && BTL_CLIENT_IsMoveSelectionBlocked(g, m, q, 0) == 0) {
                if (BTL_CALC_GetTypeAffinityVsPair(WAZA_TOOL_GetType((void *)q), x) >= b)
                    return 1;
            }
        }
    }
    return 0;
}
