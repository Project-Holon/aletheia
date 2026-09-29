/*
 * function: func_021BBD0C
 * address:  0x021BBD0C
 * packet:   pkt_ov099_021BBD0C
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_0201BC3C  0x0201BC3C  thumb
 *   func_0204ACEC  0x0204ACEC  arm
 *   func_0201BC78  0x0201BC78  thumb
 *   func_0201BCB4  0x0201BCB4  thumb
 *   func_0204AF28  0x0204AF28  arm
 *   func_021BBC34  0x021BBC34  thumb  ov099
 *   func_021BBE50  0x021BBE50  thumb  ov099
 *   func_02049238  0x02049238  arm
 */

extern void *func_020490F4(int a, int b);
extern int func_0201BC3C(void);
extern void *func_0204ACEC(void *o, int a, int b, int c, int d);
extern int func_0201BC78(void);
extern int func_0201BCB4(void);
extern void *func_0204AF28(void *o, int a, int b, int c);
extern void func_021BBC34(void *p, int a, int b, void *o);
extern void func_021BBE50(void *p);
extern void func_02049238(void *o);

void func_021BBD0C(char *p, int a, int b)
{
    void *o;
    int t;

    o = func_020490F4(7, 0x21);
    *(void **)(p + 0x148) = func_0204ACEC(o, func_0201BC3C(), 0, 0x160, 0x21);
    t = func_0201BC78();
    *(void **)(p + 0x14C) = func_0204AF28(o, t, func_0201BCB4(), 0x21);
    func_021BBC34(p, a, 0, o);
    func_021BBC34(p, b, 6, o);
    func_021BBE50(p);
    func_02049238(o);
}
