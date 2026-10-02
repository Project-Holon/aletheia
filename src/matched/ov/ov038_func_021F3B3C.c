/*
 * function: func_021F3B3C
 * address:  0x021F3B3C
 * packet:   pkt_ov038_021F3B3C
 * region:   ov038
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     enum-k spelling as ov038_func_021F3F40.  Case 1 keeps the pressed
 *           path in the if body (the release path, a task swap to
 *           func_021F3DFC, is the else) so case 0's two failed tests reuse
 *           its `b` to the shared tail; d = (u32)s[5] >> 1 gives the plain lsrs.
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_0203630C  0x0203630C  arm
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_0201235C  0x0201235C  thumb
 *   func_021F3DFC  0x021F3DFC  thumb  ov038
 *   func_02197DA0  0x02197DA0  thumb  ov021
 *   func_02197DAC  0x02197DAC  thumb  ov021
 *   func_021618A0  0x021618A0  thumb  ov010
 *   func_02012374  0x02012374  thumb
 *   func_02006210  0x02006210  thumb
 *   func_021BE6E8  0x021BE6E8  thumb  ov021
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 *   func_02197D3C  0x02197D3C  thumb  ov021
 *   d_021F45F8     0x021F45F8  data  a4
 *   d_021F4600     0x021F4600  data  a4
 *   d_021F4608     0x021F4608  data  a4
 *   d_021F4620     0x021F4620  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { K_0 } KType;

typedef struct {
    int x;
    int y;
    int z;
} V3;

extern u32 d_021F45F8[];
extern u32 d_021F4600[];
extern u32 d_021F4608[];
extern u32 d_021F4620[];

extern void *func_020124E4(int a0);
extern void *func_0201210C(void *w);
extern int func_02188D2C(void *p);
extern u8 *func_021897BC(void *p, int idx);
extern void *func_02188CB4(void *p);
extern u32 func_02188C80(void *p);
extern unsigned int func_020120F4(unsigned int);
extern unsigned int func_02012EC4(unsigned int);
extern int *func_0200B3A4(unsigned int, unsigned int);
extern void *func_021BE674(int base, int i, int j, int k);
extern void *func_021A3074(unsigned char *p);
extern int func_0216D454(void *t);
extern int func_0216D3CC(void *t);
extern void func_021A3038(void *q, V3 *v);
extern void func_021A3044(void *q, V3 *v);
extern void func_021BE4B4(int p, int i, int j, int v);
extern V3 *func_021BE480(int p, int i, int j);
extern void func_021BE700(int p, int i, int j, int k, int flag);
extern void func_021BE6CC(int p, int i, int j, int k, int flag);
extern void func_021BE6B0(void *s, int b);
extern int func_021BE6BC(void *p);
extern int func_021BE6E8(int p, int i, int j, int k);
extern unsigned int func_0203630C(void);
extern void func_020061E4(u32 se);
extern void func_02006210(void);
extern void *func_020122C0(void *a, u32 b, void *fn, u32 size);
extern void func_0201235C(int a0, void *t);
extern void func_02012374(int a0, void *t);
extern void *func_021618A0(void *w, void *sys, int a2, void *a3);
extern int func_02197DA0();
extern int func_02197DAC();
extern int func_02197D3C(void *t, void *p);
extern int func_021F3DFC(int a0, int *a1);

int func_021F3B3C(int a0, int *a1)
{
    void *w;
    void *sys;
    int h;
    u8 *s;
    void *q;
    u8 c;
    KType k;
    void *e;
    void *t;
    V3 *src;
    int mask;
    int dir;
    u32 d;
    V3 v;

    w = func_020124E4(a0);
    sys = func_0201210C(w);
    h = func_02188D2C(sys);
    s = func_021897BC(sys, 1);
    q = func_02188CB4(sys);
    func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(sys))), 6);
    k = 0;
    c = s[3] + 0x19;
    if (s[6] == 1)
        k = (u8)(k + 1);
    e = func_021BE674(h, 0, 0x22, k);
    switch (*a1) {
    case 0:
        t = func_021A3074((void *)q);
        if (func_0216D454(t) != 0 && func_0216D3CC(t) != 0) {
            *(int *)(s + 0x1c) = 1;
            func_021A3038(q, (V3 *)(s + 8));
            func_021BE4B4(h, 0, c, 1);
            func_021BE4B4(h, 0, 0x22, 0);
            src = func_021BE480(h, 0, c);
            *func_021BE480(h, 0, 0x22) = *src;
            func_021BE700(h, 0, 0x22, k, 1);
            func_021BE6CC(h, 0, 0x22, k, 0);
            func_021BE6B0(e, 1);
            *(int *)(s + 0x20) = 0;
            *a1 = *a1 + 1;
        }
        break;
    case 1:
        if (s[6] == 0) {
            mask = 0x40;
            dir = -1;
        } else {
            mask = 0x80;
            dir = 1;
        }
        if ((func_0203630C() & mask) != 0) {
            s[7]++;
            if (s[7] >= 2) {
                s[7] = 0;
                s[5]++;
                func_021A3038(q, &v);
                v.z += dir << 12;
                func_021A3044(q, &v);
                d = (u32)s[5] >> 1;
                if (*(int *)(s + 0x20) == 0 && d != 0) {
                    func_020061E4(0x6C2);
                    *(int *)(s + 0x20) = 1;
                }
                func_021BE6CC(h, 0, 0x22, k, d << 12);
                if (s[5] >= 0x20)
                    *a1 = *a1 + 1;
            }
        } else {
            func_0201235C(a0, func_020122C0(w, 0, func_021F3DFC, 0));
            return 0;
        }
        break;
    case 2:
        if (*(int *)(s + 0x14) != 0) {
            if (func_02197DA0(*(int *)(s + 0x14)) == 1) {
                func_02197DAC(*(int *)(s + 0x14));
                *(int *)(s + 0x14) = 0;
                *(int *)(s + 0x18) = 1;
                *a1 = *a1 + 1;
            }
        } else {
            *(int *)(s + 0x18) = 1;
            *a1 = *a1 + 1;
        }
        if (*(int *)(s + 0x18) != 0) {
            func_021BE6B0(e, 0);
            func_02012374(a0, func_021618A0(w, sys, 0xff, s[6] == 0 ? d_021F4608 : d_021F4600));
            func_02006210();
            func_020061E4(0x6C3);
        }
        break;
    case 3:
        func_021BE6E8(h, 0, 0x22, k);
        if (func_021BE6BC(e)) {
            func_021BE700(h, 0, 0x22, k, 0);
            func_021BE4B4(h, 0, 0x22, 1);
            func_021BE4B4(h, 0, c, 0);
            return 1;
        }
        break;
    }
    if (*(int *)(s + 0x1c) != 0 && *(int *)(s + 0x18) == 0) {
        t = func_021A3074((void *)q);
        if (*(int *)(s + 0x14) == 0) {
            *(int *)(s + 0x14) = func_02197D3C(t, s[6] == 0 ? d_021F4620 : d_021F45F8);
        } else if (func_02197DA0(*(int *)(s + 0x14)) == 1) {
            func_02197DAC(*(int *)(s + 0x14));
            *(int *)(s + 0x14) = 0;
        }
    }
    return 0;
}
