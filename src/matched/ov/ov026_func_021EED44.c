/*
 * function: func_021EED44
 * address:  0x021EED44
 * packet:   pkt_ov026_021EED44
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EED44 0x021EED44 thumb ov026
 *   func_021EEF0C 0x021EEF0C thumb ov026
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A223C 0x021A223C thumb ov021
 *   func_021A2390 0x021A2390 thumb ov021
 *   func_021A23B0 0x021A23B0 thumb ov021
 *   func_021A21BC 0x021A21BC thumb ov021
 */

typedef signed short s16;

typedef unsigned int   u32;
extern int *func_021A21B8(int *p);
extern int func_021A223C(unsigned char *o, int arg);
extern void func_021A2390(u32 *p, int a, int b, int c);
extern int func_021A23B0(int);
extern int func_021A21BC(unsigned char *o);
extern void func_021EEF0C(int, s16 *);

int func_021EED44(int a, int b, int c)
{
    s16 *p;
    int t;
    int ok;

    p = (s16 *)func_021A21B8((int *)a);
    t = func_021A223C((unsigned char *)a, c);
    if (p[1] > 0) {
        p[1] = p[1] - 1;
        if (p[1] == 0) {
            func_021A2390((u32 *)a, 0x7FDF, 0x32, b);
        }
    } else {
        if (b != 0) {
            ok = func_021A23B0(a);
        } else {
            ok = 1;
        }
        if (ok != 0 && t != 0 && func_021A21BC((unsigned char *)a) == 0) {
            return 1;
        }
    }
    func_021EEF0C(a, p);
    return 0;
}
