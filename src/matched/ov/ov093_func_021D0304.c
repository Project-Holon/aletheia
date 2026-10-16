/*
 * function: BTL_CLIENT_FindSwitchByTypeMatchup
 * address: 0x021D0304
 * packet: pkt_ov093_021D0304
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_CLIENT_HasMoveWithAffinityVsTarget 0x021D0644 thumb ov093
 *   BTL_POKEPARAM_GetValue 0x021D59B4 thumb ov093
 *   BTL_POKEPARAM_GetHitRecord 0x021D6940 thumb ov093
 *   BTL_SLOT_GetCount 0x021B9B94 thumb ov093
 *   BTL_MAIN_GetRule 0x021B8588 thumb ov093
 *   BTL_CALC_GetScanStartIndex 0x021D7F2C thumb ov093
 *   BTL_CLIENT_HasSlotInOrder 0x021CFBBC thumb ov093
 *   BTL_SLOT_GetPokeParam 0x021B9C00 thumb ov093
 *   BTL_POKEPARAM_GetTypePair 0x021D57FC thumb ov093
 *   BTL_CALC_GetTypeAffinityVsPair 0x021D799C thumb ov093
 *   _ull_mul 0x0209C054 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
struct G { void *p0; u8 pad[0xf0]; u64 seed; u64 mul; u64 add; u8 pad2[0xc]; void *list; u8 start; };
extern int BTL_CLIENT_HasMoveWithAffinityVsTarget(void *, void *, void *, int);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
struct Q1;
struct S2;
extern int BTL_POKEPARAM_GetHitRecord(const u8 *p, int i, u32 j, u16 *out);
extern u8 BTL_SLOT_GetCount(struct Q1 *p);
extern u32 BTL_MAIN_GetRule(void **p);
extern u8 BTL_CALC_GetScanStartIndex(u32 a, u8 b);
typedef signed char    s8;
extern int BTL_CLIENT_HasSlotInOrder(s8 *p, int v);
extern u8 *BTL_SLOT_GetPokeParam(struct S2 *p, u32 i);
extern u16 BTL_POKEPARAM_GetTypePair(void *);
extern int BTL_CALC_GetTypeAffinityVsPair(int, int);
int BTL_CLIENT_FindSwitchByTypeMatchup(struct G *g, void *mon, void *target, u8 *out)
{
    u16 hist[4];
    u32 sum;
    u32 i;
    u32 n;
    u8 *other;
    int affinity;
    if (BTL_CLIENT_HasMoveWithAffinityVsTarget(g, mon, target, 4)) {
        g->seed = g->mul * g->seed + g->add;
        if ((u32)(((g->seed >> 32) * 10) >> 32) != 0) return 0;
    }
    sum = 0;
    for (i = 1; i <= 7; i++) sum += BTL_POKEPARAM_GetValue(mon, i);
    if (sum >= 4) return 0;
    if (BTL_POKEPARAM_GetHitRecord(mon, 1, 0, hist)) {
        n = BTL_SLOT_GetCount(g->list);
        i = BTL_CALC_GetScanStartIndex(BTL_MAIN_GetRule(g->p0), g->start);
        for (; i < n; i++) {
            if (!BTL_CLIENT_HasSlotInOrder((s8 *)g, (u8)i)) {
                other = BTL_SLOT_GetPokeParam(g->list, (u8)i);
                if (BTL_CLIENT_HasMoveWithAffinityVsTarget(g, other, target, 4)) {
                    affinity = BTL_CALC_GetTypeAffinityVsPair(((u8 *)hist)[4], BTL_POKEPARAM_GetTypePair(other));
                    if (affinity == 0) {
                        g->seed = g->mul * g->seed + g->add;
                        if ((u32)(((g->seed >> 32) * 2) >> 32) == 0) {
                            *out = i;
                            return 1;
                        }
                    } else if (affinity < 3) {
                        g->seed = g->mul * g->seed + g->add;
                        if ((u32)(((g->seed >> 32) * 3) >> 32) == 0) {
                            *out = i;
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
