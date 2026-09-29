/*
 * function: func_02185360
 * address:  0x02185360
 * packet:   pkt_ov020_02185360
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02012894  0x02012894  thumb
 *   func_02012870  0x02012870  thumb
 *   func_02013E7C  0x02013E7C  thumb
 *   func_020128C0  0x020128C0  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_0201447C  0x0201447C  thumb
 *   func_02162694  0x02162694  thumb  ov010
 *   func_021625E8  0x021625E8  thumb  ov010
 *   func_021626E8  0x021626E8  thumb  ov010
 *   func_02184388  0x02184388  thumb  ov020
 *   func_02184CEC  0x02184CEC  thumb  ov020
 *   func_02185EB0  0x02185EB0  thumb  ov020
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int f[7]; } S7;

void *func_020122C0(void *p, int a, void (*cb)(void), int n);
void *func_020124E8(void *p);
void *func_020120F4(void *p);
S7 *func_02012894(void *p);
u16 *func_02012870(void *p);
int func_02013E7C(int x);
void func_020128C0(void *a, void *b);
void *func_02012B38(void *p);
void func_0201447C(void *p, int a);
int func_021625E8(int a0);
int func_02162694(int a0, int a1, int a2);
int func_021626E8(int a0);
void func_02184388(void);
void func_02184CEC(void *obj, void *p);
void func_02185EB0(void *a, void *b);

void *func_02185360(void *p, int u, int a, int b)
{
    char *r4;
    void *r5 = func_020120F4(p);
    void *r0v = func_020122C0(p, 0, func_02184388, 0x9c);
    u16 *r6;

    r4 = func_020124E8(r0v);
    func_02184CEC(r4, p);
    *(int *)(r4 + 0x40) = 1;
    if (func_021625E8(a) != 0) {
        *(S7 *)(r4 + 0x10) = *func_02012894(r5);
    } else {
        func_02162694(a, (int)(r4 + 0x10), b);
    }
    *(int *)(r4 + 0x2c) = func_021626E8(a);
    r6 = func_02012870(r5);
    if (func_02013E7C(r6[2]) == 1 && func_02013E7C(*(u16 *)(r4 + 0x14)) == 0) {
        func_020128C0(r5, r6);
    }
    func_02185EB0(r5, r4 + 0x10);
    func_0201447C(func_02012B38(r5), 2);
    return r0v;
}
