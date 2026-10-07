/*
 * file:     unit_021EE740_p11.c
 * unit:     yes
 * function: func_021EF538, func_021EF5B0, func_021EF5D0
 * address:  0x021EF538
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A223C 0x021A223C thumb ov021
 *   func_021A2390 0x021A2390 thumb ov021
 *   func_021A23B0 0x021A23B0 thumb ov021
 *   func_021A21BC 0x021A21BC thumb ov021
 *   func_021A244C 0x021A244C thumb ov021
 *   func_021A2564 0x021A2564 thumb ov021
 *   func_021A231C 0x021A231C thumb ov021
 *   func_021A2120 0x021A2120 thumb ov021
 *   func_021A2630 0x021A2630 thumb ov021
 *   func_021A2638 0x021A2638 thumb ov021
 *   func_021A2640 0x021A2640 thumb ov021
 *   func_021A21E0 0x021A21E0 thumb ov021
 *   _s32_div_f    0x0209C0A4 arm
 */
struct PtS;
typedef signed int     s32;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed short s16;

extern int *func_021A21B8(int *p);
extern int func_021A223C(unsigned char *o, int arg);
extern void func_021A2390(u32 *p, int a, int b, int c);
extern int func_021A23B0(u32 a);
extern int func_021A21BC(unsigned char *o);
extern void func_021A244C(u8 *o, s32 *outX, s32 *outY);
extern void func_021A2564(int, int, int);
extern void func_021A231C(u32 *, int);
extern void func_021A2120(u32 *, int);
extern unsigned char *func_021A2630(unsigned char *o);
extern unsigned int func_021A2638(unsigned char *o);
extern void func_021A2640(unsigned char *, struct PtS *);
extern void func_021A21E0(u32 *p);
int func_021EF538(int a, int b, int c);
int func_021EF5B0(u8 *a, int b);
void func_021EF5D0(int a);


int func_021EF538(int a, int b, int c)
{
    int *p;
    int t;
    int x;
    int y;
    int ok;

    p = func_021A21B8((int *)a);
    t = func_021A223C((unsigned char *)a, c);
    if (*p > 0) {
        *p = *p - 1;
        if (*p == 0) {
            func_021A2390((u32 *)a, 0x7FFF, 0x78, b);
        }
    } else {
        ok = (b != 0) ? func_021A23B0(a) : 1;
        if (ok != 0 && t != 0 && func_021A21BC((unsigned char *)a) == 0) {
            return 1;
        }
    }
    func_021A244C((u8 *)a, &x, &y);
    func_021A2564(a, x, y);
    return 0;
}


int func_021EF5B0(u8 *a, int b)
{
    func_021A21B8((int *)a);
    func_021A231C((u32 *)a, b);
    func_021A2120((u32 *)a, b);
    return 1;
}


void func_021EF5D0(int a)
{
    int *p;
    s16 v[2];

    p = (int *)func_021A2630((unsigned char *)a);
    func_021A2638((unsigned char *)a);
    func_021A2640((unsigned char *)a, (struct PtS *)v);
    *p = *p + 1;
    if (*p % p[4] == 0) {
        v[0] = v[0] + (s16)p[2];
    }
    if (*p % p[5] == 0) {
        v[1] = v[1] + (s16)p[3];
    }
    if (*p >= p[1]) {
        func_021A21E0((u32 *)a);
    }
}
