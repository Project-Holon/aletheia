/*
 * function: HAND_TOKUSEI_AnticipationFoeIsThreat
 * address:  0x021DA5BC
 * packet:   pkt_ov093_021DA5BC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_POKEPARAM_GetTypePair   0x021D57FC  thumb ov093
 *   BTL_POKEPARAM_GetMoveCount   0x021D5448  thumb ov093
 *   BTL_POKEPARAM_GetMoveId   0x021D54C0  thumb ov093
 *   WAZA_TOOL_GetCategory    0x0201C1BC  thumb
 *   WAZA_TOOL_IsDamaging   0x0201C314  thumb
 *   WAZA_TOOL_GetType    0x0201C1C8  thumb
 *   BTL_CALC_GetTypeAffinityVsPair   0x021D799C  thumb ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern u16 BTL_POKEPARAM_GetTypePair(void *p);
struct QG;
extern u8 BTL_POKEPARAM_GetMoveCount(struct QG *p);
extern u16 BTL_POKEPARAM_GetMoveId(u8 *p, int i);
extern u32 WAZA_TOOL_GetCategory(u16 move);
extern u32 WAZA_TOOL_IsDamaging(void *p);
extern u8 WAZA_TOOL_GetType(void *p);
extern int BTL_CALC_GetTypeAffinityVsPair(int a, int b);

int HAND_TOKUSEI_AnticipationFoeIsThreat(void *a, void *b)
{
    u16 s;
    u8 n;
    u8 i;
    u16 t;

    s = BTL_POKEPARAM_GetTypePair(a);
    n = BTL_POKEPARAM_GetMoveCount(b);
    for (i = 0; i < n; i++) {
        t = BTL_POKEPARAM_GetMoveId(b, i);
        if (WAZA_TOOL_GetCategory(t) == 9)
            return 1;
        if (WAZA_TOOL_IsDamaging((void *)t) != 0) {
            if (BTL_CALC_GetTypeAffinityVsPair(WAZA_TOOL_GetType((void *)t), s) > 3)
                return 1;
        }
    }
    return 0;
}
