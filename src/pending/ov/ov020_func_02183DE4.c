/*
 * function: func_02183DE4
 * address:  0x02183DE4
 * packet:   pkt_ov020_02183DE4
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Byte-correct at 376 of 376 bytes.  Four wildcarded call sites, all of
 * them unlabelled tail-call leaves with no witness outside this range.
 * Each leaf's C below was verified EXACT with `match.py one` in a scratch
 * file; none is filed, because the arm9 one belongs to Ilias:
 *   +0xD4  func_02029DF4 (arm9, Ilias's): ldr r3,=func_02029EB4+1; bx r3
 *          int func_02029DF4(int a, int b, int c)
 *          { return func_02029EB4(a, b, c); }
 *   +0x96  func_02164474 (ov010): void f(int a, int b) { func_0215E364(a, b); }
 *   +0xB6  func_0216E29C (ov010): void f(u8 *p, int n)
 *          { func_02048F4C(*(int *)(p + 0x44), 0x3a, n); }   (02048F4C arm)
 *   +0xBC  func_0216CCCC (ov010): void f(u8 *p)
 *          { func_02082BCC(*(int *)(p + 0x44), 0, 0x310); }  (02082BCC arm)
 * Filing the three ov010 leaves (region hint ov010: ov009 overlaps them)
 * and the arm9 leaf makes this file EXACT unchanged.  This is the callback
 * func_02183F5C registers through func_020122C0.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_0201445C  0x0201445C  thumb
 *   func_02012894  0x02012894  thumb
 *   func_02185B70  0x02185B70  thumb  ov020
 *   func_02185A68  0x02185A68  thumb  ov020
 *   func_0218601C  0x0218601C  thumb  ov020
 *   func_021857C0  0x021857C0  thumb  ov020
 *   func_0202735C  0x0202735C  thumb
 *   func_02168EEC  0x02168EEC  thumb  ov010
 *   func_02164474  0x02164474  thumb  ov010
 *   func_0202C860  0x0202C860  thumb
 *   func_0201405C  0x0201405C  thumb
 *   func_02012964  0x02012964  thumb
 *   func_0216E29C  0x0216E29C  thumb  ov010
 *   func_0216CCCC  0x0216CCCC  thumb  ov010
 *   func_02012984  0x02012984  thumb
 *   func_02029DF4  0x02029DF4  thumb
 *   func_020298A0  0x020298A0  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020145FC  0x020145FC  thumb
 *   func_020143CC  0x020143CC  thumb
 *   func_02158780  0x02158780  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_021BC578  0x021BC578  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short s16;

extern int func_020120F4(int a);
extern int func_0201296C(int a);
extern int func_02012B38(int a);
extern void func_0201445C(int a, int b);
extern u8 *func_02012894(int a);
extern void func_02185B70(int a);
extern void func_02185A68(int a, int b);
extern void func_0218601C(int a);
extern void func_021857C0(int a, u8 *b);
extern void func_0202735C(int a, int b);
extern void func_02168EEC(int a);
extern void func_02164474(int a, int b);
extern void func_0202C860(int a, int b);
extern int func_0201405C(int a);
extern int func_02012964(int a);
extern void func_0216E29C(int a, int b);
extern void func_0216CCCC(int a);
extern int func_02012984(int a);
extern int func_02029DF4(int a, int b, int c);
extern int func_020298A0(int a, int b, int c, int d);
extern void func_02012374(int a, int b);
extern int func_020145FC(int a);
extern u16 *func_020143CC(int a, int b);
extern void func_02158780(int a, int b, int c, int d, int e);
extern int func_0201210C(int a);
extern int func_021BE92C(int a, int b, int c, int d, int e, int f, int g);
extern int func_02188D20(int a);
extern void func_021BC578(int a, int b);

int func_02183DE4(int ctx, int *state, u8 *p)
{
    int a;
    int s;
    int m;
    u8 *q;
    int n;
    int t;

    a = *(int *)(p + 0);
    s = func_020120F4(a);
    m = func_0201296C(s);

    switch (*state) {
    case 0:
        func_0201445C(func_02012B38(s), 1);
        if (*(int *)(p + 0xc) != 0) {
            q = func_02012894(s);
            *(s16 *)(p + 8) = *(s16 *)(q + 4);
            func_02185B70(a);
            func_02185A68(a, *(u16 *)(p + 8));
            func_0218601C(s);
            func_021857C0(a, q);
            func_0202735C(*(u16 *)(q + 4), s);
        } else {
            func_02185A68(a, *(u16 *)(p + 8));
            func_0218601C(s);
            func_02168EEC(s);
            func_02164474(s, *(u16 *)(p + 8));
            func_0202C860(s, *(u16 *)(p + 8));
            n = func_0201405C(*(u16 *)(p + 8));
            t = func_02012964(s);
            if (n < 16) {
                func_0216E29C(t, n);
            } else {
                func_0216CCCC(t);
            }
        }
        (*state)++;
        break;
    case 1:
        func_02012374(ctx, func_020298A0(a, func_02029DF4(s, *(u16 *)(p + 8), func_02012984(s)), 0, 0x3c));
        (*state)++;
        break;
    case 2:
        func_02012374(ctx, func_020145FC(a));
        (*state)++;
        break;
    case 3:
        if (*(int *)(p + 0xc) != 0 && *func_020143CC(m, 0x4041) != 0) {
            func_02158780(ctx, 0x83b, 0, 0, 0x15);
        } else {
            n = func_02012984(s);
            func_02012374(ctx, func_021BE92C(a, func_0201210C(a), 3, 0, 0, n, n));
        }
        (*state)++;
        break;
    case 4:
        t = func_0201210C(a);
        if (func_02188D20(t) != 0) {
            func_021BC578(func_02188D20(t), *(u16 *)(p + 8));
        }
        return 1;
    }
    return 0;
}
