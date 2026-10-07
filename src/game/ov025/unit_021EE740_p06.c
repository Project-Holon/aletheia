/*
 * file:     unit_021EE740_p06.c
 * unit:     yes
 * function: func_021EEEE0, func_021EEF94, func_021EEFF0, func_021EF068
 * address:  0x021EEEE0
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
 *   func_021A244C 0x021A244C thumb ov021
 *   func_021A2564 0x021A2564 thumb ov021
 *   func_021A2190 0x021A2190 thumb ov021
 *   func_021A21A0 0x021A21A0 thumb ov021
 *   _s32_div_f    0x0209C0A4 arm
 *   _u32_div_f    0x0209C2B0 arm
 *   d_021EF765    0x021EF765 data a1
 *   d_021EF75C    0x021EF75C data ov025 a1
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A21F8 0x021A21F8 thumb ov021
 *   func_021A22E0 0x021A22E0 thumb ov021
 *   func_021A2424 0x021A2424 thumb ov021
 *   func_021A25BC 0x021A25BC thumb ov021
 *   func_021EF2D4 0x021EF2D4 thumb ov025
 *   func_021A223C 0x021A223C thumb ov021
 *   func_021A232C 0x021A232C thumb ov021
 *   func_021A2108 0x021A2108 thumb ov021
 *   func_021A23B0 0x021A23B0 thumb ov021
 *   func_02014A10 0x02014A10 thumb
 *   func_021A2254 0x021A2254 thumb ov021
 *   func_021A2114 0x021A2114 thumb ov021
 */
typedef signed char s8;

typedef signed int     s32;

typedef unsigned char  u8;

typedef unsigned int   u32;

typedef unsigned short u16;

extern void func_021A244C(u8 *o, s32 *outX, s32 *outY);
extern void func_021A2564(int, int, int);
extern void func_021A2190(unsigned char *o, unsigned int v, int i);
extern void func_021A21A0(unsigned char *o, unsigned int v, int i);
extern int *func_021A21B8(int *p);
extern void func_021A21F8(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
extern void func_021A22E0(u32 *p, int a, int b, int c);
extern void func_021A2424(u8 *p);
extern void func_021A25BC(unsigned char *o, int arg);
extern void func_021EF2D4(int a, int n, int idx);
extern int func_021A223C(unsigned char *o, int arg);
extern void func_021A232C(u8 *p, int a, int b, int c, int d);
extern int func_021A2108(unsigned int a, int b, int c);
extern int func_021A23B0(unsigned int a);
extern u16 func_02014A10(u32 i);
extern void func_021A2254(int, void *, int, int, int, int);
extern int func_021A2114(unsigned int a, int b, unsigned int c);
void func_021EEEE0(int a, int *s);
int func_021EEF94(int a, int b);
int func_021EEFF0(int a, int b, int c);
int func_021EF068(unsigned int *a, int b, int c);
extern const s8 d_021EF765[];
extern const s8 d_021EF75C[];


/*
 * The remainder goes back into t before the store (`t = (t+1) % 252u;
 * s[8] = t;`): storing the expression directly lets the compiler sink
 * `i = t / 28` below the _u32_div_f call. `const` on the two s8 tables
 * schedules the second table's pool load above the s[2] store.
 */
void func_021EEEE0(int a, int *s)
{
    int w;
    int h;
    int i;
    int t;

    func_021A244C((u8 *)a, &w, &h);
    func_021A2564(a, w, h);
    t = s[8];
    i = t / 28;
    t = (unsigned)(t + 1) % 252u;
    s[8] = t;
    s[2] = s[2] + d_021EF765[i] - w / 2;
    s[9] = s[9] + d_021EF75C[i] - h / 2;
    if (s[2] < 0) {
        s[2] = s[2] + 256;
    }
    if (s[9] < 0) {
        s[9] = s[9] + 256;
    }
    s[2] = s[2] % 256;
    s[9] = s[9] % 256;
    func_021A2190((unsigned char *)a, -s[2], 0);
    func_021A21A0((unsigned char *)a, -s[9], 0);
}


int func_021EEF94(int a, int b)
{
    int *p;

    p = func_021A21B8((int *)a);
    func_021A21F8((u8 *)a, 0, 8, 1, 1, -4, 2, 1, (int)((void *)func_021EF2D4));
    func_021A22E0((u32 *)a, 9, 0x7FDF, b);
    *p = 1;
    func_021A2424((u8 *)a);
    func_021A25BC((unsigned char *)a, 0x6E4);
    return 1;
}


int func_021EEFF0(int a, int b, int c)
{
    int *p;
    int t;
    int x;
    int y;

    p = func_021A21B8((int *)a);
    t = func_021A223C((unsigned char *)a, c);
    if (*p > 0) {
        *p = *p - 1;
        if (*p == 0) {
            func_021A232C((u8 *)a, 9, 0x7F80, 0x3C, b);
            func_021A2108(a, 0x3E, func_02014A10(5));
        }
    } else if (func_021A23B0(a) != 0 && t != 0) {
        return 1;
    }
    func_021A244C((u8 *)a, &x, &y);
    func_021A2564(a, x, y);
    return 0;
}


int func_021EF068(unsigned int *a, int b, int c)
{
    func_021A21B8((int *)a);
    func_021A21F8((u8 *)a, 1, 1, 1, 1, -4, 2, 1, (int)((void *)func_021EF2D4));
    func_021A22E0(a, 9, 0x7F80, b);
    func_021A2254((int)a, (void *)func_021EF2D4, 0x14, 10, 1, c);
    func_021A2114((unsigned int)a, 0x3E, func_02014A10(5));
    return 1;
}
