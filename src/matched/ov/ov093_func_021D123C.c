/*
 * function: func_021D123C
 * address:  0x021D123C
 * packet:   pkt_ov093_021D123C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EEC20  0x021EEC20  thumb  ov093
 *   func_021EE608  0x021EE608  thumb  ov093
 *   func_021BB4E0  0x021BB4E0  thumb  ov093
 *   func_021EE638  0x021EE638  thumb  ov093
 */

extern int func_021EEC20(int, int *);
typedef unsigned char  u8;
extern void func_021EE608(u8 *p, const u8 *src, int n);
extern void func_021BB4E0(int, int, int);
extern u8 func_021EE638(u8 *p);

int func_021D123C(int a)
{
    int tmp;
    int r4 = func_021EEC20(*(int *)(a + 0x50), &tmp);
    if (*(int *)(a + 0x10) != 0)
        func_021EE608((u8 *)(*(int *)(a + 0x10)), (const u8 *)tmp, r4);
    if (*(int *)(a + 0xa0) != 0) {
        func_021BB4E0(*(int *)(a + 0xa0), tmp, r4);
        *(unsigned char *)(a + 0x1ae) = func_021EE638((u8 *)tmp);
    }
    return 1;
}
