/*
 * function: func_021F03EC
 * address:  0x021F03EC
 * packet:   pkt_ov032_021F03EC
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F05E8  0x021F05E8  thumb  ov032
 *   func_021F029C  0x021F029C  thumb  ov032
 *   func_021F1A08  0x021F1A08  thumb  ov032
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_021F05E8(u8 *p, int a, u32 b);
extern void func_021F029C(u8 *p, int a);
extern void func_021F1A08(u8 *p);

int func_021F03EC(u8 *p)
{
    int s = *(int *)(p + 0x6c);

    switch (s) {
    case 0:
        func_021F05E8(p, 0, 1);
        func_021F029C(p, 1);
        func_021F1A08(p);
        *(int *)(p + 0x6c) = *(int *)(p + 0x6c) + 1;
        break;
    case 1:
        if (*(int *)(p + 0xa8) == 0) {
            func_021F029C(p, 0);
            *(int *)(p + 0x6c) = 0;
            return 1;
        }
        break;
    }
    return 0;
}
