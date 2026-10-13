/*
 * function: func_021D0644
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
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D57FC  0x021D57FC  thumb  ov093
 *   func_021D5448  0x021D5448  thumb  ov093
 *   func_021D54C0  0x021D54C0  thumb  ov093
 *   func_021D5584  0x021D5584  thumb  ov093
 *   WAZA_TOOL_IsDamaging  0x0201C314  thumb
 *   func_021CF5B0  0x021CF5B0  thumb  ov093
 *   WAZA_TOOL_GetType  0x0201C1C8  thumb
 *   func_021D799C  0x021D799C  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D5B68(void *m);
extern u16 func_021D57FC(void *m);
struct QG;
extern u8 func_021D5448(struct QG *p);
struct UtilWork;
extern u16 func_021D54C0(u8 *p, int i);
extern u8 func_021D5584(struct UtilWork *p, u32 i);
extern u32 WAZA_TOOL_IsDamaging(void *p);
extern int func_021CF5B0(u8 *g, void *m, u32 move, void *out);
extern u8 WAZA_TOOL_GetType(void *p);
extern int func_021D799C(int a, int b);

int func_021D0644(void *g, void *m, void *a, int b)
{
    int x;
    u8 n;
    u32 i;
    u32 q;

    if (func_021D5B68(m) == 0) {
        x = func_021D57FC(a);
        n = func_021D5448(m);
        for (i = 0; i < n; i++) {
            q = func_021D54C0(m, (u8)i);
            if (func_021D5584(m, (u8)i) && WAZA_TOOL_IsDamaging((void *)q)
                && func_021CF5B0(g, m, q, 0) == 0) {
                if (func_021D799C(WAZA_TOOL_GetType((void *)q), x) >= b)
                    return 1;
            }
        }
    }
    return 0;
}
