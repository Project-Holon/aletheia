/*
 * unit:     yes
 * function: func_021E2A38, func_021E2A74
 * address:  0x021E2A38
 * packet:   pkt_ov093_021E2A38
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetHpRatioFixed  0x021D5C44  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   d_021F244C     0x021F244C  data   ov093  a4
 */

typedef unsigned char u8;

extern int BTL_EVENT_GetVar(int key);
struct Rat;
extern void *func_021C7CF4(int *p, int i);
extern int BTL_POKEPARAM_GetHpRatioFixed(struct Rat *p);
extern void BTL_EVENT_MultiplyVar(int a, int b);
extern int d_021F244C[];

void func_021E2A38(int a, void *b, int c)
{
    if (c == BTL_EVENT_GetVar(3)) {
        if (BTL_POKEPARAM_GetHpRatioFixed(func_021C7CF4(b, (u8)BTL_EVENT_GetVar(4))) <= 0x32 << 12)
            BTL_EVENT_MultiplyVar(0x31, 4 << 11);
    }
}

int *func_021E2A74(int *p)
{
    *p = 1;
    return d_021F244C;
}
