/*
 * function: func_02183B90
 * address:  0x02183B90
 * packet:   pkt_ov020_02183B90
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0208068C  0x0208068C  arm
 *   func_02082AC0  0x02082AC0  arm
 *   func_02080B98  0x02080B98  arm
 *   func_0202E888  0x0202E888  thumb
 *   sub_0202E8CC   0x0202E8CC  thumb
 *   func_02012984  0x02012984  thumb
 *   func_02187808  0x02187808  thumb  ov020
 *   func_02012374  0x02012374  thumb
 *   func_02161B90  0x02161B90  thumb  ov010
 *   func_02183D68  0x02183D68  thumb  ov020
 *   func_0201235C  0x0201235C  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_020120F4(int a);
extern void func_0208068C(int a);
extern void func_02082AC0(int v, u32 a, u32 b);
extern void func_02080B98(void);
extern int func_0202E888(void);
extern void sub_0202E8CC(int a, u16 b);
extern int func_02012984(int a);
extern int func_02187808(int a, int b, int c);
extern void func_02012374(int a, int b);
extern int func_02161B90(int a, int b, int c, int d, int e);
extern int func_02183D68(int a, int b);
extern void func_0201235C(int a, int b);

int func_02183B90(int a, int *state, int *p)
{
    int w = p[0];
    int s = func_020120F4(w);
    int r;
    int t;

    switch (*state) {
    case 0:
        func_0208068C(0x1ff);
        func_02082AC0(0, 0x1a << 22, 0x29 << 14);
        func_02080B98();
        (*state)++;
        break;
    case 1:
        sub_0202E8CC(s, func_0202E888());
        t = func_02012984(s);
        r = func_02187808(w, t, t);
        func_02012374(a, r);
        (*state)++;
        break;
    case 2:
        r = func_02161B90(w, a, 5, 0, 1);
        func_02012374(a, r);
        (*state)++;
        break;
    case 3:
        func_0201235C(a, func_02183D68(w, p[1]));
        break;
    }
    return 0;
}
