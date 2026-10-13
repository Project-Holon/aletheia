/*
 * unit:     yes
 * function: func_021E2908, func_021E293C
 * address:  0x021E2908
 * packet:   pkt_ov093_021E2908
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
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   d_021F2444     0x021F2444  data   ov093  a4
 */

extern int BTL_EVENT_GetVar(int key);
struct Unk021D62A8;
extern void *func_021C7CF4(int *p, int i);
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct Unk021D62A8 *p);
extern void BTL_EVENT_MultiplyVar(int a, int b);
extern int d_021F2444[];

void func_021E2908(int a, void *b, int c)
{
    int k;

    if (c == BTL_EVENT_GetVar(3)) {
        k = BTL_POKEPARAM_GetMajorStatusIndex(func_021C7CF4(b, c));
        if (k == 5 || k == 1 || k == 4)
            BTL_EVENT_MultiplyVar(0x31, 2 << 12);
    }
}

int *func_021E293C(int *p)
{
    *p = 1;
    return d_021F2444;
}
