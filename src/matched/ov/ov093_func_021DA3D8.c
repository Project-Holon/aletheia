/*
 * unit: yes
 * function: HAND_TOKUSEI_ForewarnOnMemberIn, HAND_TOKUSEI_AddForewarn
 * address: 0x021DA3D8
 * packet: pkt_ov093_021DA3D8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   func_021C7D54 0x021C7D54 thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021C8120 0x021C8120 thumb ov093
 *   BTL_POKEPARAM_GetMoveCount 0x021D5448 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_POKEPARAM_GetMoveId 0x021D54C0 thumb ov093
 *   BTL_CALC_Random 0x021D78AC thumb ov093
 *   func_021C88B4 0x021C88B4 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   WAZA_TOOL_GetDamageType 0x0201C1E8 thumb
 *   WAZA_TOOL_GetPower 0x0201C1D8 thumb
 *   WAZA_TOOL_GetCategory 0x0201C1BC thumb
 *   d_021F0980 0x021F0980 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 id, pad; u16 move; } Entry;
extern int BTL_EVENT_GetVar(int);
extern u8 func_021C7D54(u8 *p, u8 *k, u8 *out);
struct QG;
extern void *func_021C7CF4(int *p, int i);
extern u8 *func_021C8120(u8 *p, int b);
extern u8 BTL_POKEPARAM_GetMoveCount(struct QG *p);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern u16 BTL_POKEPARAM_GetMoveId(u8 *p, int i);
extern int WAZA_TOOL_GetDamageType(int a);
extern u16 WAZA_TOOL_GetPower(void *p);
extern u32 WAZA_TOOL_GetCategory(u16);
extern u32 BTL_CALC_Random(u32);
extern void func_021C88B4(void *, int, int);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *, int, int);
struct S;
extern void func_021C8860(struct S *p, u32 val);
extern void func_021C88C8(void *, void *);
static inline u32 score(u16 move)
{
    u32 value;
    if (WAZA_TOOL_GetDamageType(move)) {
        value = (u8)WAZA_TOOL_GetPower((void *)move);
        if (value == 1) {
            if (WAZA_TOOL_GetCategory(move) == 9) value = 150;
            else if (move == 68 || move == 243 || move == 368) value = 120;
            else value = 80;
        }
    } else {
        value = 1;
    }
    return value;
}
void HAND_TOKUSEI_ForewarnOnMemberIn(int a, void *b, int c)
{
    u8 buf[4];
    void *q;
    Entry *entries;
    u8 n, m, i;
    u16 move;
    u8 count, j, choice;
    u32 best, value;
    u8 *p;
    if (c != BTL_EVENT_GetVar(2)) return;
    n = func_021C7D54(b, (u8 *)c, buf);
    best = 0;
    count = 0;
    entries = (Entry *)func_021C8120(b, 12);
    for (i = 0; i < n; i++) {
        q = func_021C7CF4(b, buf[i]);
        m = BTL_POKEPARAM_GetMoveCount(q);
        for (j = 0; j < m; j++) {
            move = BTL_POKEPARAM_GetMoveId(q, j);
            value = score(move);
            if (value >= best) {
                if (value > best) { best = value; count = 0; }
                entries[count].id = BTL_POKEPARAM_GetPokeId(q);
                entries[count].move = move;
                count++;
            }
        }
    }
    if (count == 0) return;
    choice = BTL_CALC_Random(count);
    func_021C88B4(b, 2, c);
    p = func_021C88A4(b, 4, c);
    func_021C8838(p + 4, 2, 0x1b1);
    func_021C8860((struct S *)(p + 4), entries[choice].id);
    func_021C8860((struct S *)(p + 4), entries[choice].move);
    func_021C88C8(b, p);
    func_021C88B4(b, 3, c);
}
extern int d_021F0980;
int *HAND_TOKUSEI_AddForewarn(int *p) { *p = 2; return &d_021F0980; }
