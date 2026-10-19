/*
 * function: BTL_CLIENT_ShouldSwitchWhileLocked
 * address: 0x021CFFAC
 * packet: pkt_ov093_021CFFAC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes at 0x021D00FE before BTL_CLIENT_FindSwitchFromHitHistory.
 * lever: hold the one-word aggregate accessor result before passing by value.
 * symbols:
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   BTL_POKEPARAM_GetSickContRaw 0x021D6314 thumb ov093
 *   BTL_SICKCONT_GetValue 0x021E8B80 thumb ov093
 *   BTL_POKEPARAM_GetTypePair 0x021D57FC thumb ov093
 *   BTL_CALC_GetTypeAffinityVsPair 0x021D799C thumb ov093
 *   BTL_CLIENT_AnyMemberHasMoveVsTarget 0x021D055C thumb ov093
 *   _ull_mul 0x0209C054 arm
 *   WAZA_TOOL_GetType  0x0201C1C8  thumb  arm9
 *   WAZA_TOOL_IsDamaging  0x0201C314  thumb  arm9
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
struct G { u8 pad[0xf4]; u64 seed; u64 mul; u64 add; };
typedef union { u32 v; } Word;
struct Unk021D62A8;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern Word BTL_POKEPARAM_GetSickContRaw(void *, int);
extern u16 BTL_SICKCONT_GetValue(Word);
extern u32 WAZA_TOOL_IsDamaging(void *p);
extern u8 WAZA_TOOL_GetType(void *p);
extern u16 BTL_POKEPARAM_GetTypePair(void *);
extern int BTL_CALC_GetTypeAffinityVsPair(int, int);
extern int BTL_CLIENT_AnyMemberHasMoveVsTarget(u8 *g, void *a, int b);
int BTL_CLIENT_ShouldSwitchWhileLocked(struct G *g, void *mon, void *target)
{
    u32 id;
    int valid;
    u32 kind;
    Word slot;
    if (BTL_POKEPARAM_HasSick(mon, 0x1b)) {
        slot = BTL_POKEPARAM_GetSickContRaw(mon, 0x1b);
        id = BTL_SICKCONT_GetValue(slot);
        if (id) {
            valid = WAZA_TOOL_IsDamaging((void *)id);
            kind = WAZA_TOOL_GetType((void *)id);
            if (BTL_CALC_GetTypeAffinityVsPair(kind, BTL_POKEPARAM_GetTypePair(target)) == 0 && valid) {
                if (BTL_CLIENT_AnyMemberHasMoveVsTarget((u8 *)g, target, 4)) {
                    g->seed = g->mul * g->seed + g->add;
                    return (u32)(((g->seed >> 32) * 3) >> 32) < 2;
                }
                if (BTL_CLIENT_AnyMemberHasMoveVsTarget((u8 *)g, target, 3)) {
                    g->seed = g->mul * g->seed + g->add;
                    return (u32)(((g->seed >> 32) * 2) >> 32) < 1;
                }
            }
            if (!valid) {
                g->seed = g->mul * g->seed + g->add;
                return (u32)(((g->seed >> 32) * 2) >> 32) < 1;
            }
        }
    }
    return 0;
}
