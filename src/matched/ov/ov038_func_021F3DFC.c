/*
 * function: func_021F3DFC
 * address:  0x021F3DFC
 * packet:   pkt_ov038_021F3DFC
 * region:   ov038
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     same enum-k spelling as ov038_func_021F3F40 (k = (u8)(k + 1)
 *           on an enum local, int fourth parameter on the 0x021BE6xx calls).
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_02006210  0x02006210  thumb
 *   func_02197DA0  0x02197DA0  thumb  ov021
 *   func_02197DAC  0x02197DAC  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
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

extern void *func_020124E4(void *p);
extern void *func_0201210C(void *p);
extern int func_02188D2C(void *p);
extern u8 *func_021897BC(void *p, int idx);
extern void *func_02188CB4(void *p);
extern void func_021BE4B4(int p, int i, int j, int v);
extern void func_021BE700(int p, int i, int j, int k, int flag);
extern void func_021BE6CC(int p, int i, int j, int k, int flag);
extern void func_020061E4(u32 se);
extern void func_02006210(void);
extern int func_02197DA0();
extern int func_02197DAC();
extern void func_021A3038(void *q, V3 *v);
extern void func_021A3044(void *q, V3 *v);

int func_021F3DFC(int a0, int *a1)
{
    void *sys;
    int h;
    u8 *s;
    void *q;
    u8 c;
    KType k;
    int done;
    int d;
    V3 v;

    sys = func_0201210C(func_020124E4((void *)a0));
    h = func_02188D2C(sys);
    s = func_021897BC(sys, 1);
    q = func_02188CB4(sys);
    k = 0;
    c = s[3] + 0x19;
    if (s[6] == 1)
        k = (u8)(k + 1);
    switch (*a1) {
    case 0:
        func_02006210();
        *a1 = *a1 + 1;
    case 1:
        if (*(int *)(s + 0x14) != 0) {
            if (func_02197DA0(*(int *)(s + 0x14)) == 1) {
                func_02197DAC(*(int *)(s + 0x14));
                *(int *)(s + 0x14) = 0;
                s[5] = 0;
                *a1 = *a1 + 1;
            }
        } else {
            s[5] = 0;
            *a1 = *a1 + 1;
        }
        if (*a1 == 2)
            *(int *)(s + 0x20) = 0;
        break;
    case 2:
        func_021A3038(q, &v);
        done = 0;
        s[5]++;
        if (s[6] == 0) {
            v.z += s[5] << 12;
            if (v.z >= *(int *)(s + 0x10)) {
                v.z = *(int *)(s + 0x10);
                done = 1;
            }
            d = (*(int *)(s + 0x10) - v.z) / 2;
        } else {
            v.z += -s[5] << 12;
            if (v.z <= *(int *)(s + 0x10)) {
                v.z = *(int *)(s + 0x10);
                done = 1;
            }
            d = (v.z - *(int *)(s + 0x10)) / 2;
        }
        if (*(int *)(s + 0x20) == 0 && d != 0) {
            func_020061E4(0x6C4);
            *(int *)(s + 0x20) = 1;
        }
        func_021BE6CC(h, 0, 0x22, k, d);
        func_021A3044(q, &v);
        if (done) {
            func_021BE700(h, 0, 0x22, k, 0);
            func_021BE4B4(h, 0, 0x22, 1);
            func_021BE4B4(h, 0, c, 0);
            return 1;
        }
        break;
    }
    return 0;
}
