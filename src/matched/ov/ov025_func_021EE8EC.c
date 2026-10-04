/*
 * function: func_021EE8EC
 * address:  0x021EE8EC
 * packet:   pkt_ov025_021EE8EC
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021EE8EC  0x021EE8EC  thumb  ov025
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A223C  0x021A223C  thumb  ov021
 *   func_021A2390  0x021A2390  thumb  ov021
 *   func_021A23B0  0x021A23B0  thumb  ov021
 *   func_021A21BC  0x021A21BC  thumb  ov021
 *   func_021A244C  0x021A244C  thumb  ov021
 *   func_021A2564  0x021A2564  thumb  ov021
 */

typedef signed int     s32;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int *func_021A21B8(int *p);
extern int func_021A223C(unsigned char *o, int arg);
extern void func_021A2390(u32 *p, int a, int b, int c);
extern int func_021A23B0(int);
extern int func_021A21BC(unsigned char *o);
extern void func_021A244C(u8 *o, s32 *outX, s32 *outY);
extern void func_021A2564(int, int, int);

int func_021EE8EC(int a, int b, int c)
{
    int *p;
    int t;
    int ok;
    int x;
    int y;

    p = func_021A21B8((int *)a);
    t = func_021A223C((unsigned char *)a, c);
    if (*p > 0) {
        *p = *p - 1;
        if (*p == 0) {
            func_021A2390((u32 *)a, 0x7FDF, 0x5A, b);
        }
    } else {
        if (b != 0) {
            ok = func_021A23B0(a);
        } else {
            ok = 1;
        }
        if (ok != 0 && t != 0) {
            p[2] = 1;
            if (func_021A21BC((unsigned char *)a) == 0) {
                return 1;
            }
        }
    }
    func_021A244C((u8 *)a, &x, &y);
    func_021A2564(a, x, y);
    return 0;
}
