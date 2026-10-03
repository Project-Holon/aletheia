/*
 * function: func_021C0E98
 * address:  0x021C0E98
 * packet:   pkt_ov021_021C0E98
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_021A5408  0x021A5408  thumb  ov021
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_020061E4  0x020061E4  thumb
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216DB4C  0x0216DB4C  thumb  ov010
 *   func_0216DAE0  0x0216DAE0  thumb  ov010
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_0216D8E0  0x0216D8E0  thumb  ov010
 *   func_0216E014  0x0216E014  thumb  ov010
 *   func_0216E57C  0x0216E57C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } Vec3;

extern int func_0216D3CC(int a0);
extern int func_021A5408(u32 a);
extern int func_02197E7C(int a, int b);
extern void func_0216D410(u32 o, u32 a);
extern void func_020061E4(u32 se);
extern int func_0216D454(u32 o);
extern void func_0216D88C(u32 o, Vec3 *v);
extern int func_02163E58(u32 o, Vec3 *v, int *out);
extern u16 func_0216D598(u32 o);
extern void func_0216DB4C(u32 o, u32 b);
extern void func_0216DAE0(u32 o, int v);
extern void func_0216D89C(u32 o, Vec3 *v);
extern void func_0216D8E0(u32 o, void *p);
extern void func_0216E014(u32 o, void *v, u32 c);
extern void func_0216E57C(u32 o);

int func_021C0E98(u32 unused, int *st, u8 *p)
{
    Vec3 a;
    Vec3 b;
    Vec3 c;

    switch (*st) {
    case 0:
        if (func_0216D3CC(*(u32 *)(p + 0x1c)) == 0)
            break;
        if (func_0216D3CC(*(u32 *)(p + 0x20)) == 0 && func_021A5408(*(u32 *)p) == 0)
            break;
        func_0216D410(*(u32 *)(p + 0x1c), func_02197E7C(*(u16 *)(p + 4), 8));
        func_0216D410(*(u32 *)(p + 0x20), func_02197E7C(*(u16 *)(p + 4), 0x20));
        func_020061E4(0x674);
        (*st)++;
        break;
    case 1:
        if (func_0216D454(*(u32 *)(p + 0x1c)) == 0)
            break;
        if (func_0216D454(*(u32 *)(p + 0x20)) == 0)
            break;
        if (*(u16 *)(p + 6) == 0) {
            *st = 4;
            break;
        }
        func_0216D88C(*(u32 *)(p + 0x1c), &a);
        func_02163E58(*(u32 *)(p + 0x1c), &a, (int *)(p + 0xc));
        if (func_0216D598(*(u32 *)(p + 0x1c)) == 0x6d)
            *(int *)(p + 0xc) -= 14 << 12;
        else
            *(int *)(p + 0xc) -= 26 << 12;
        func_0216DB4C(*(u32 *)(p + 0x1c), 1);
        func_0216DAE0(*(u32 *)(p + 0x1c), 0);
        func_020061E4(0x675);
        (*st)++;
        break;
    case 2:
        func_0216D88C(*(u32 *)(p + 0x1c), &b);
        if (*(int *)(p + 0xc) < b.y) {
            b.y -= 0x4000;
            if (*(int *)(p + 0xc) > b.y)
                b.y = *(int *)(p + 0xc);
        } else if (*(int *)(p + 0xc) > b.y) {
            b.y += 0x4000;
            if (*(int *)(p + 0xc) < b.y)
                b.y = *(int *)(p + 0xc);
        }
        func_0216D89C(*(u32 *)(p + 0x1c), &b);
        if (*(int *)(p + 0xc) == b.y) {
            *(int *)(p + 0x14) = 0x2000;
            (*st)++;
        }
        break;
    case 3:
        func_0216D8E0(*(u32 *)(p + 0x1c), p + 0x10);
        *(int *)(p + 0x14) = -*(int *)(p + 0x14);
        *(s16 *)(p + 8) = *(s16 *)(p + 8) + 1;
        if (*(s16 *)(p + 8) & 4) {
            if (*(int *)(p + 0x14) < 0)
                *(int *)(p + 0x14) += 0x1000;
            else if (*(int *)(p + 0x14) > 0)
                *(int *)(p + 0x14) -= 0x1000;
        }
        if (*(int *)(p + 0x14) == 0) {
            func_0216D88C(*(u32 *)(p + 0x1c), &c);
            func_0216E014(*(u32 *)(p + 0x1c), &c, *(u16 *)(p + 4));
            func_0216D8E0(*(u32 *)(p + 0x1c), p + 0x10);
            func_0216E57C(*(u32 *)(p + 0x1c));
            (*st)++;
        }
        break;
    case 4:
        return 1;
    }
    return 0;
}
