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
 *   func_0201C314  0x0201C314  thumb
 *   func_021CF5B0  0x021CF5B0  thumb  ov093
 *   func_0201C1C8  0x0201C1C8  thumb
 *   func_021D799C  0x021D799C  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D5B68(int m);
extern u16 func_021D57FC(int a);
extern u8 func_021D5448(int m);
extern u16 func_021D54C0(int m, u8 i);
extern u8 func_021D5584(int m, u8 i);
extern int func_0201C314(u32 c);
extern int func_021CF5B0(void *g, int m, u32 q, int k);
extern int func_0201C1C8(u32 c);
extern int func_021D799C(int a, int b);

int func_021D0644(void *g, int m, int a, int b)
{
    int x;
    u8 n;
    u32 i;
    u32 q;

    if (func_021D5B68(m) == 0) {
        x = func_021D57FC(a);
        n = func_021D5448(m);
        for (i = 0; i < n; i++) {
            q = func_021D54C0(m, i);
            if (func_021D5584(m, i) && func_0201C314(q)
                && func_021CF5B0(g, m, q, 0) == 0) {
                if (func_021D799C(func_0201C1C8(q), x) >= b)
                    return 1;
            }
        }
    }
    return 0;
}
