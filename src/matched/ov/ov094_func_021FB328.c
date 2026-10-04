/*
 * function: func_021FB328
 * address:  0x021FB328
 * packet:   pkt_ov094_021FB328
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_021F84D0  0x021F84D0  thumb  ov094
 *   func_021F8694  0x021F8694  thumb  ov094
 *   func_021FF4C0  0x021FF4C0  thumb  ov094
 */
extern int func_0201134C(int a);
extern int func_021F84D0(int a);
extern int func_021F8694(void);
extern void func_021FF4C0(void *obj, int a, int b, int *c, int d, int e, int f);

int func_021FB328(int a, char *b)
{
    int arr[3];
    int t1;
    int t0;
    int t5, t6, t7;

    t0 = func_021F84D0(func_0201134C(a));
    t1 = func_0201134C(a);
    arr[0] = func_0201134C(a);
    arr[1] = func_0201134C(a);
    arr[2] = func_0201134C(a);
    t5 = func_0201134C(a);
    t6 = func_0201134C(a);
    t7 = func_0201134C(a);
    func_021FF4C0((void *)func_021F8694(), t0, t1, arr, t5, t6, t7);
    return *(int *)(b + 0x23c);
}
