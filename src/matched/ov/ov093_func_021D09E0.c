/*
 * function: BTL_CLIENT_SortMonsByMovePower
 * address:  0x021D09E0
 * packet:   pkt_ov093_021D09E0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT*
 * pass 6 2026-10-06 P6L01: EXACT* (302 B code plus 2 B pad), also EXACT* under -lang c99. The
 * closing change is u16 type with BTL_CALC_GetTypeAffinityVsPair declared (int, u16). The callee
 * (ov093_func_021D799C.c) also matches EXACT with a u16 second parameter, so the prototype is consistent.
 * Why it closes (seen in a debugger capture of the post-RA scheduler of mwccarm): a word-sized spill of a
 * narrow variable gets the "narrow locals" alias set. With int type, the type store after the call
 * has its own alias, so the count home store has a height of 6 and 'adds r0,r3' (height 7) goes before
 * it. With u16 type (no int conversion, so no hoisted int temp), the type store is in the same set, the
 * count store gets an edge to it (height 7), and it issues second, as in the original. Passes 1 to 5
 * (all 5 B or more) tried every source shape of the entry block; none can change this edge.
 * symbols:
 *   WAZA_TOOL_IsDamaging 0x0201C314 thumb
 *   WAZA_TOOL_GetType 0x0201C1C8 thumb
 *   WAZA_TOOL_GetPower 0x0201C1D8 thumb
 *   BTL_POKEPARAM_GetTypePair 0x021D57FC thumb ov093
 *   BTL_SLOT_GetPokeParam 0x021B9C00 thumb ov093
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   BTL_POKEPARAM_GetMoveCount 0x021D5448 thumb ov093
 *   BTL_POKEPARAM_GetMovePPChecked 0x021D5584 thumb ov093
 *   BTL_POKEPARAM_GetMoveId 0x021D54C0 thumb ov093
 *   BTL_CALC_GetTypeAffinityVsPair 0x021D799C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 BTL_POKEPARAM_GetTypePair(void *);
struct QG;
struct S2;
struct UtilWork;
extern u8 *BTL_SLOT_GetPokeParam(struct S2 *p, u32 i);
extern int BTL_POKEPARAM_IsFainted(void *);
extern u8 BTL_POKEPARAM_GetMoveCount(struct QG *p);
extern u8 BTL_POKEPARAM_GetMovePPChecked(struct UtilWork *p, u32 i);
extern u16 BTL_POKEPARAM_GetMoveId(u8 *p, int i);
extern u32 WAZA_TOOL_IsDamaging(void *);
extern u8 WAZA_TOOL_GetType(void *);
extern u16 WAZA_TOOL_GetPower(void *);
extern int BTL_CALC_GetTypeAffinityVsPair(int, u16);
void BTL_CLIENT_SortMonsByMovePower(u8 *p, u8 *order, u8 count, void *target)
{
    u16 scores[6];
    u16 type;
    u8 i;
    u8 j;
    void *mon;
    u16 move;
    u16 power;
    u16 temp;
    u8 tempid;
    type = BTL_POKEPARAM_GetTypePair(target);
    for (i = 0; i < count; i++) {
        scores[i] = 0;
        mon = BTL_SLOT_GetPokeParam(*(void **)(p + 0x118), order[i]);
        if (!BTL_POKEPARAM_IsFainted(mon)) {
            u8 n;
            n = BTL_POKEPARAM_GetMoveCount(mon);
            for (j = 0; j < n; j++) {
                if (BTL_POKEPARAM_GetMovePPChecked(mon, j)) {
                    move = BTL_POKEPARAM_GetMoveId(mon, j);
                    if (WAZA_TOOL_IsDamaging((void *)(u32)move)) {
                        int kind;
                        kind = WAZA_TOOL_GetType((void *)(u32)move);
                        power = WAZA_TOOL_GetPower((void *)(u32)move);
                        if (power < 10) power = 60;
                        switch (BTL_CALC_GetTypeAffinityVsPair(kind, type)) {
                        case 5: power *= 4; break;
                        case 4: power *= 2; break;
                        case 2: power /= 2; break;
                        case 1: power /= 4; break;
                        case 0: power = 0; break;
                        case 3: break;
                        }
                        if (scores[i] < power) scores[i] = power;
                    }
                }
            }
        }
    }
    for (i = 0; i < count; i++) {
        for (j = i + 1; j < count; j++) {
            if (scores[i] < scores[j]) {
                temp = scores[i];
                scores[i] = scores[j];
                scores[j] = temp;
                tempid = order[i];
                order[i] = order[j];
                order[j] = tempid;
            }
        }
    }
}
