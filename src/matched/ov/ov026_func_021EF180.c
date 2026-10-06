/*
 * function: func_021EF180
 * address:  0x021EF180
 * packet:   pkt_ov026_021EF180
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A223C  0x021A223C  thumb  ov021
 *   func_021A23B0  0x021A23B0  thumb  ov021
 *   func_021A21BC  0x021A21BC  thumb  ov021
 *   func_021EF664  0x021EF664  thumb  ov026
 *   func_021EF830  0x021EF830  thumb  ov026
 */

typedef signed short   s16;
extern int *func_021A21B8(int *p);
extern int func_021A223C(unsigned char *o, int arg);
typedef unsigned int   u32;
extern int func_021A23B0(u32 a);
extern int func_021A21BC(unsigned char *o);
extern void func_021EF664(int a, s16 *p, int b, int d);
extern void func_021EF830(int a, s16 *p);

int func_021EF180(int a, int b, int c)
{
    int x;
    int y;
    int t;

    x = (int)func_021A21B8((int *)a);
    y = func_021A223C((unsigned char *)a, c);
    t = (b != 0) ? func_021A23B0(a) : 1;
    if (t != 0 && y != 0 && func_021A21BC((unsigned char *)a) == 0) {
        return 1;
    }
    func_021EF664(a, (s16 *)x, b, 1);
    func_021EF830(a, (s16 *)x);
    return 0;
}
