/*
 * function: BTL_CLIENT_ShouldSwitchNoEffectiveMove
 * address: 0x021CFE98
 * packet: pkt_ov093_021CFE98
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes at 0x021CFFAA, followed by labelled BTL_CLIENT_ShouldSwitchWhileLocked.
 * symbols:
 *   BTL_POKEPARAM_GetTypePair 0x021D57FC thumb ov093
 *   BTL_POKEPARAM_GetMoveCount 0x021D5448 thumb ov093
 *   BTL_POKEPARAM_GetMoveId 0x021D54C0 thumb ov093
 *   WAZA_TOOL_IsDamaging 0x0201C314 thumb
 *   WAZA_TOOL_GetType 0x0201C1C8 thumb
 *   BTL_CALC_GetTypeAffinityVsPair 0x021D799C thumb ov093
 *   BTL_CLIENT_AnyMemberHasMoveVsTarget 0x021D055C thumb ov093
 *   _ull_mul 0x0209C054 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
struct G { u8 pad[0xf4]; u64 seed; u64 mul; u64 add; };
extern u16 BTL_POKEPARAM_GetTypePair(void *);
struct QG;
extern u8 BTL_POKEPARAM_GetMoveCount(struct QG *p);
extern u16 BTL_POKEPARAM_GetMoveId(u8 *p, int i);
extern u32 WAZA_TOOL_IsDamaging(void *p);
extern u8 WAZA_TOOL_GetType(void *p);
extern int BTL_CALC_GetTypeAffinityVsPair(int, int);
extern int BTL_CLIENT_AnyMemberHasMoveVsTarget(u8 *g, void *a, int b);
int BTL_CLIENT_ShouldSwitchNoEffectiveMove(struct G *g, void *a, void *b)
{
    u8 n;
    int k;
    u32 c;
    u32 i;
    u32 v;
    k = BTL_POKEPARAM_GetTypePair(b);
    n = BTL_POKEPARAM_GetMoveCount(a);
    c = 0;
    for (i = 0; i < n; i++) {
        v = (u32)BTL_POKEPARAM_GetMoveId(a, (u8)i);
        if (WAZA_TOOL_IsDamaging((void *)v)) {
            if (BTL_CALC_GetTypeAffinityVsPair(WAZA_TOOL_GetType((void *)v), k))
                return 0;
            c++;
        }
    }
    if (c >= 2) {
        if (BTL_CLIENT_AnyMemberHasMoveVsTarget((u8 *)g, b, 4)) {
            g->seed = g->mul * g->seed + g->add;
            return (u32)(((g->seed >> 32) * 3) >> 32) < 2;
        }
        if (BTL_CLIENT_AnyMemberHasMoveVsTarget((u8 *)g, b, 3)) {
            g->seed = g->mul * g->seed + g->add;
            return (u32)(((g->seed >> 32) * 2) >> 32) < 1;
        }
    }
    return 0;
}
