/*
 * function: func_0217B82C
 * address:  0x0217B82C
 * packet:   pkt_ov018_0217B82C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_021904B0  0x021904B0  thumb  ov021
 *   func_02190F64  0x02190F64  thumb  ov021
 *   func_02190E74  0x02190E74  thumb  ov021
 *   func_02190EF0  0x02190EF0  thumb  ov021
 *   func_02190E40  0x02190E40  thumb  ov021
 *   func_02045C04  0x02045C04  arm
 *   func_02188BE8  0x02188BE8  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3238  0x021A3238  thumb  ov021
 *   func_0217C658  0x0217C658  thumb  ov018
 *   func_0217C688  0x0217C688  thumb  ov018
 *   func_02185214  0x02185214  thumb
 *   func_02012374  0x02012374  thumb
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 */

typedef unsigned char u8;

typedef struct {
    int f0;
    int f4;
    u8 f8[1];
} Work;

extern int func_020124E4(void);
extern int func_0201210C(int);
extern int func_02012138(int);
extern int func_02188C7C(int);
extern void func_0216D9A0(int);
extern int func_02188C54(int);
extern int func_021904B0(int, int);
extern int func_02190F64(int, int);
extern void func_02190E74(int, int, int, int);
extern int func_02190EF0(int);
extern void func_02190E40(int);
extern void func_02045C04(int);
extern int func_02188BE8(int);
extern int func_02188CB4(int);
extern int func_021A3238(int);
extern void func_0217C658(void *, int, int, int, int, int);
extern int func_0217C688(void *, int);
extern int func_02185214(int);
extern void func_02012374(int, int);
extern void func_0216D9E4(int);

int func_0217B82C(int a0, int *state, Work *w)
{
    int sys;
    int obj;

    sys = func_020124E4();
    obj = func_0201210C(sys);
    func_02012138(sys);
    switch (*state) {
    case 0:
        func_0216D9A0(func_02188C7C(obj));
        obj = func_02188C54(obj);
        w->f0 = func_021904B0(obj, 0x2D);
        w->f4 = func_02190F64(obj, w->f0);
        func_02190E74(w->f4, 0, 0, 0x60);
        (*state)++;
        break;
    case 1:
        if (func_02190EF0(w->f4) == 1) {
            func_02190E40(w->f4);
            func_02045C04(w->f0);
            (*state)++;
        }
        break;
    case 2:
        obj = func_0201210C(sys);
        if (func_02188BE8(obj) == 1) {
            if (func_021A3238(func_02188CB4(obj)) == 0) {
                func_0217C658(w->f8, sys, obj, 0, 0, 0);
                (*state)++;
            } else {
                *state = 4;
            }
        }
        break;
    case 3:
        if (func_0217C688(w->f8, 0) == 1)
            (*state)++;
        break;
    case 4:
        func_02012374(a0, func_02185214(sys));
        (*state)++;
        break;
    case 5:
        if (obj != 0 && func_02188BE8(obj) == 1) {
            func_0216D9E4(func_02188C7C(obj));
            return 1;
        }
        break;
    }
    return 0;
}
