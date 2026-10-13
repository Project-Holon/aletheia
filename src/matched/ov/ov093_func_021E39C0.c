/*
 * unit:     yes
 * function: func_021E39C0, func_021E39F8
 * address:  0x021E39C0
 * packet:   pkt_ov093_021E39C0
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
 *   BTL_POKEPARAM_TestContFlag  0x021D5BDC  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   d_021F2804     0x021F2804  data   a4
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int);
extern void *func_021C7CF4(int *p, int i);
struct UtilWork;
extern int BTL_POKEPARAM_TestContFlag(struct UtilWork *p, u32 n);
extern void BTL_EVENT_MultiplyVar(int a, int b);
extern int d_021F2804[];

void func_021E39C0(int u, void *a, int c)
{
    int n;

    if (c == BTL_EVENT_GetVar(3)) {
        n = 4;
        if (BTL_POKEPARAM_TestContFlag(func_021C7CF4(a, (u8)BTL_EVENT_GetVar(4)), 4) != 0)
            BTL_EVENT_MultiplyVar(0x35, n << 11);
    }
}

int *func_021E39F8(int *p)
{
    *p = 1;
    return d_021F2804;
}
