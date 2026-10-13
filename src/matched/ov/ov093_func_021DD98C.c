/*
 * function: BTL_ITEM_RaiseRandomStatTwo
 * address:  0x021DD98C
 * packet:   pkt_ov093_021DD98C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021C8120  0x021C8120  thumb  ov093
 *   func_021D5D14  0x021D5D14  thumb  ov093
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 *   BTL_ITEM_RaiseStat  0x021DD9E8  thumb  ov093
 *   gBtlItemRaiseStatCandidates     0x021F1364  data  ov093  a1
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef signed char    s8;
extern void *func_021C7CF4(int *p, int i);
extern u8 *func_021C8120(u8 *p, int b);
extern int func_021D5D14(s8 *p, int i, int sign);
extern u32 BTL_CALC_Random(u32 range);
extern void BTL_ITEM_RaiseStat(void *a, int b, int c, int d);
extern u8 gBtlItemRaiseStatCandidates[5];

void BTL_ITEM_RaiseRandomStatTwo(int x, void *a, u8 b)
{
    void *m = func_021C7CF4(a, b);
    u8 *buf = func_021C8120(a, 5);
    u32 n;
    u32 i;
    u8 e;

    i = 0;
    n = 0;
    for (; i < 5; i++) {
        e = gBtlItemRaiseStatCandidates[i];
        if (func_021D5D14(m, e, 1) != 0)
            buf[n++] = e;
    }
    if (n != 0)
        BTL_ITEM_RaiseStat(a, b, buf[BTL_CALC_Random(n)], 2);
}
