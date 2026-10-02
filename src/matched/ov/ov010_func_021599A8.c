/*
 * function: func_021599A8
 * address:  0x021599A8
 * packet:   pkt_ov010_021599A8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CCC  0x02188CCC  thumb
 *   func_02012E40  0x02012E40  thumb
 *   func_02012DD0  0x02012DD0  thumb
 *   func_021A0F90  0x021A0F90  thumb  ov021
 *   func_021A153C  0x021A153C  thumb  ov021
 *   func_021A1548  0x021A1548  thumb  ov021
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_021590FC  0x021590FC  thumb  ov010
 *   func_021D11D8  0x021D11D8  thumb
 *   func_021D1194  0x021D1194  thumb
 *   func_021590F4  0x021590F4  thumb  ov010
 */

typedef unsigned short u16;

extern void *func_0215A5E4(void *a0);
extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(void *p);
extern int func_02188CCC(void *);
extern int func_02012E40(void *);
extern int func_02012DD0(void *);
extern int func_021A0F90(int);
extern int func_021A153C(int);
extern void func_021A1548(int);
extern u16 *func_02159AE8(void *a0, void *a1);
extern int func_021590FC(void *);
extern void func_021D11D8(int);
extern void func_021D1194(int);
extern void func_021590F4(void *, int);

int func_021599A8(int a, int b)
{
    void *s4 = func_0215A5E4((void *)b);
    void *s0 = func_0215A5F4((void *)b);
    int h;
    int ret;
    h = func_02188CCC(func_0201210C(func_0215A5DC((void *)b)));
    if (func_02012E40(s4) == 0) {
        ret = 1;
        if (func_021A0F90(h) == 7) {
            if (func_021A153C(h) == 0)
                ret = 0;
        }
    } else {
        switch (func_02012DD0(s4)) {
        case 0:
        case 1:
            ret = 0;
            break;
        case 2:
            *func_02159AE8((void *)a, (void *)b) = 1;
            ret = 0;
            break;
        case 3:
            *func_02159AE8((void *)a, (void *)b) = 0;
            ret = 1;
            if (func_021A0F90(h) == 7)
                func_021A1548(h);
            break;
        }
    }
    if (ret == 1) {
        int t = func_021590FC(s0);
        func_021D11D8(t);
        func_021D1194(t);
        func_021590F4(s0, 0);
    }
    return ret;
}
