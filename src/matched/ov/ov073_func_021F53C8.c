/*
 * function: func_021F53C8
 * address:  0x021F53C8
 * packet:   pkt_ov073_021F53C8
 * region:   ov073
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02189A08  0x02189A08  thumb  ov021
 *   func_021CF560  0x021CF560  thumb  ov021
 *   func_02189A00  0x02189A00  thumb  ov021
 *   func_021C1DCC  0x021C1DCC  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_02012374  0x02012374  thumb
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_021F5488  0x021F5488  thumb  ov073
 */
typedef unsigned char u8;
typedef unsigned int  u32;

extern void *func_020124E4(void *task);
extern void *func_0201210C(void *p);
extern int func_02189A08(int a);
extern u32 func_021CF560(u32 *p);
extern void *func_02189A00(u8 *p);
extern int func_021C1DCC(int a, char *b, int c, int d);
extern int func_020122C0(void *a, void *b, void *cb, int n);
extern void func_02012374(void *a, int b);
extern void func_0204E720(int a, int b, int c, int d);
extern int func_0204E804(void);
extern void func_021F5488(void);

int func_021F53C8(void *task, int *st)
{
    void *t;
    void *v;
    int *w;
    int r;

    t = func_020124E4(task);
    v = func_0201210C(t);
    w = (int *)func_021CF560((u32 *)func_02189A08((int)v));
    switch (*st) {
    case 0:
        func_0204E720(4, 0, 0x10, 0);
        *st = *st + 1;
    case 1:
        if (func_0204E804() == 0) {
            func_0204E720(4, 0x10, 0, 0);
            *st = *st + 1;
        }
        break;
    case 2:
        if (func_0204E804() == 0) {
            w[0] = w[0] + 1;
            if (w[0] < 2) {
                func_0204E720(4, 0, 0x10, 0);
                *st = 1;
            } else {
                r = func_021C1DCC((int)t, func_02189A00((u8 *)v), w[1], w[2]);
                if (r != 0) {
                    func_02012374(task, r);
                } else {
                    r = func_020122C0(t, task, (void *)func_021F5488, 0);
                    func_02012374(task, r);
                }
                *st = *st + 1;
            }
        }
        break;
    case 3:
        return 1;
    }
    return 0;
}
