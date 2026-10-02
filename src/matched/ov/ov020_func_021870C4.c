/*
 * function: func_021870C4
 * address:  0x021870C4
 * packet:   pkt_ov020_021870C4
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02158434  0x02158434  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_021871F8  0x021871F8  thumb  ov020
 *   func_020124E8  0x020124E8  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045B38  0x02045B38  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_020127D0  0x020127D0  thumb
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_0218DC70  0x0218DC70  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_020127F0  0x020127F0  thumb
 *   func_021A3460  0x021A3460  thumb  ov021
 *   func_0216DDC0  0x0216DDC0  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02186090  0x02186090  thumb  ov020
 *   func_0219390C  0x0219390C  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;

int func_02188C84(void *a);
int func_02188C54(void *a);
void *func_020120F4(void *a);
void *func_02012138(void *a);
void *func_02158344(void *a);
void *func_02158434(void *a);
void *func_020122C0(void *a, int b, void (*f)(void), int size);
char *func_020124E8(void *a);
void func_021871F8(void);
int func_020457B0(int a, int b);
int func_02045B38(int a, int b, int c, int d);
int func_0201EC64(int a);
int func_020127D0(void *a, int b);
int func_02188C98(void *a);
int func_0218DC70(int a);
int func_02188CB4(void *a);
int func_02188C7C(void *a);
void func_020127F0(void *a);
void func_021A3460(int a, s16 *x, s16 *y, s16 *z);
int func_0216DDC0(int a, int b, int c, int d);
void func_0216D88C(int a, void *b);
int func_02186090(void *p);
int func_0219390C(int a, int b);

void *func_021870C4(void *a0, void *a1)
{
    int n;
    int c54;
    void *h;
    void *w;
    void *ret;
    int b;
    s16 v[3];
    char *o;
    int a;
    int c;
    int d;
    int e;
    int x;

    n = func_02188C84(a1);
    c54 = func_02188C54(a1);
    h = func_020120F4(a0);
    w = func_02158344(func_02012138(a0));
    if (w == 0)
        return 0;
    w = func_02158434(w);
    ret = func_020122C0(a0, 0, func_021871F8, 0x58);
    o = func_020124E8(ret);
    *(void **)(o + 0) = a0;
    *(void **)(o + 4) = a1;
    *(int *)(o + 0x20) = func_020457B0(0x100, n);
    *(int *)(o + 0x24) = func_020457B0(0x100, n);
    *(int *)(o + 0x18) = func_02045B38(0, 3, 0x142, n);
    *(int *)(o + 0x1c) = func_0201EC64(n);
    *(int *)(o + 0xc) = c54;
    *(void **)(o + 0x40) = w;
    *(u8 *)(o + 0x56) = 1;
    *(u16 *)(o + 8) = (n & 0x7FFF) | 0x8000;
    *(int *)(o + 0x44) = func_020127D0(h, 1);
    *(int *)(o + 0x48) = func_020127D0(h, 0);
    a = func_0218DC70(func_02188C98(a1));
    b = func_02188CB4(a1);
    c = func_02188C7C(a1);
    func_020127F0(func_020120F4(a0));
    func_021A3460(b, &v[2], &v[1], &v[0]);
    d = func_0216DDC0(c, v[2], v[0], 0);
    func_0216D88C(d, o + 0x34);
    e = func_02186090((void *)d);
    x = func_0219390C(a, e);
    *(int *)(o + 0x28) = a;
    *(int *)(o + 0x2c) = x;
    *(int *)(o + 0x30) = d;
    *(u16 *)(o + 0x4c) = e;
    return ret;
}
