/*
 * function: func_021FB6F4
 * address:  0x021FB6F4
 * packet:   pkt_ov094_021FB6F4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * (pt is 3 words: the third is unused padding that sets the 0x30 frame)
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_021FCF2C  0x021FCF2C  thumb  ov094
 *   func_021F8694  0x021F8694  thumb  ov094
 *   func_021FF3F4  0x021FF3F4  thumb  ov094
 *   func_021F86F0  0x021F86F0  thumb  ov094
 *   func_02201AF8  0x02201AF8  thumb  ov094
 *   func_0206DF3C  0x0206DF3C  arm
 */
typedef short s16;

extern int func_0201134C(int a);
extern int func_021FCF2C(int a, int b);
extern void *func_021F8694(void);
extern void func_021FF3F4(void *obj, int *out, int idx);
extern int func_021F86F0(void);
extern int func_02201AF8(int a, int b, int c, s16 d, s16 e, int f, int g);
extern void func_0206DF3C(int *p, int *q, int *r);

int func_021FB6F4(int a, char *b)
{
    int pt[3];
    int o1, o2;
    int t0, t1, t2, t3, t4, t5, t6;

    t0 = func_0201134C(a);
    t1 = func_0201134C(a);
    t2 = func_021FCF2C(a, func_0201134C(a));
    t3 = func_0201134C(a);
    t4 = func_0201134C(a);
    t5 = func_0201134C(a);
    t6 = func_0201134C(a);
    func_021FF3F4(func_021F8694(), pt, t2);
    pt[0] += t3;
    pt[1] += t4;
    func_0206DF3C(pt, &o1, &o2);
    *(int *)(b + t0 * 4 + 0xcc) =
        func_02201AF8(func_021F86F0(), 0x5f, t1, o1, o2, t5, t6);
    return *(int *)(b + 0x23c);
}
