/*
 * function: func_021FB7F8
 * address:  0x021FB7F8
 * packet:   pkt_ov094_021FB7F8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_021F86F0  0x021F86F0  thumb  ov094
 *   func_02201D5C  0x02201D5C  thumb  ov094
 */
extern int func_0201134C(int a);
extern int func_021F86F0(void);
extern void func_02201D5C(int a, int b, int c, int *d, int e, int f, int g);

int func_021FB7F8(int a, char *b)
{
    int arr[3];
    int t0, t1, t3, t4, t5;

    t0 = func_0201134C(a);
    t1 = func_0201134C(a);
    arr[0] = func_0201134C(a);
    arr[1] = func_0201134C(a);
    arr[2] = 0x1000;
    t3 = func_0201134C(a);
    t4 = func_0201134C(a);
    t5 = func_0201134C(a);
    func_02201D5C(func_021F86F0(), *(int *)(b + t0 * 4 + 0xcc), t1, arr, t3, t4, t5);
    return *(int *)(b + 0x23c);
}
