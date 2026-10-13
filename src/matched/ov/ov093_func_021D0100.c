/*
 * function: BTL_CLIENT_FindSwitchFromHitHistory
 * address: 0x021D0100
 * packet: pkt_ov093_021D0100
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_CLIENT_HasMoveWithAffinityVsTarget 0x021D0644 thumb ov093
 *   BTL_POKEPARAM_GetHitRecord 0x021D6940 thumb ov093
 *   BTL_CLIENT_FindMemberWithAbility 0x021D04E4 thumb ov093
 *   gBtlClientAiHitKindRows 0x021EFFC2 data ov093 a2
 *   _ull_mul 0x0209C054 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
struct G { u8 pad[0xf4]; u64 seed; u64 mul; u64 add; };
struct Row { u8 kind; u8 pad; u16 ids[4]; };
extern const struct Row gBtlClientAiHitKindRows[4];
extern int BTL_CLIENT_HasMoveWithAffinityVsTarget(void *, void *, void *, int);
extern int BTL_POKEPARAM_GetHitRecord(const u8 *p, int i, u32 j, u16 *out);
extern int BTL_CLIENT_FindMemberWithAbility(void *, int, u8 *);
int BTL_CLIENT_FindSwitchFromHitHistory(struct G *g, void *mon, void *target, u8 *out)
{
    u16 hist[5];
    u32 i;
    u8 pos;
    u32 j;
    const struct Row *row;
    pos = 0;
    if (BTL_CLIENT_HasMoveWithAffinityVsTarget(g, mon, target, 4)) {
        g->seed = g->mul * g->seed + g->add;
        if ((u32)(((g->seed >> 32) * 3) >> 32) == 0) return 0;
    }
    while (BTL_POKEPARAM_GetHitRecord(mon, 1, pos++, hist + 1)) {
        for (i = 0; i < 4; i++) {
            row = &gBtlClientAiHitKindRows[i];
            if (((u8 *)hist)[6] == row->kind) {
                for (j = 0; j < 4; j++) {
                    if (!row->ids[j]) break;
                    if (BTL_CLIENT_FindMemberWithAbility(g, row->ids[j], (u8 *)hist)) {
                        g->seed = g->mul * g->seed + g->add;
                        if ((u32)(((g->seed >> 32) * 2) >> 32) == 0) {
                            *out = ((u8 *)hist)[0];
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
