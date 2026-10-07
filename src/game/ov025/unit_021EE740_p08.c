/*
 * file:     unit_021EE740_p08.c
 * unit:     yes
 * function: func_021EF12C, func_021EF1A4, func_021EF1C4
 * address:  0x021EF12C
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
 *   func_021A2630  0x021A2630  thumb  ov021
 *   func_021A2638  0x021A2638  thumb  ov021
 *   func_021A2640  0x021A2640  thumb  ov021
 *   func_021A2654  0x021A2654  thumb  ov021
 *   func_021A26C4  0x021A26C4  thumb  ov021
 *   func_021A21E0  0x021A21E0  thumb  ov021
 *   func_0204B908  0x0204B908  arm
 *   func_0204B918  0x0204B918  arm
 */
struct PtS;
struct Obj;
typedef signed int     s32;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef struct {
    s16 x;
    s16 y;
} Pt;

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
extern void func_021A2654(int obj, unsigned short *src);
extern int func_021A26C4(u32 a, u32 b);
extern void func_021A21E0(u32 *p);
extern void func_0204B908(int a0, int a1);
extern u16 func_0204B918(struct Obj *p);
int func_021EF12C(int a, int b, int c);
int func_021EF1A4(u8 *a, int b);
void func_021EF1C4(int a);


int func_021EF12C(int a, int b, int c)
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
            func_021A2390((u32 *)a, 0x7FDF, 0x3C, b);
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


int func_021EF1A4(u8 *a, int b)
{
    func_021A21B8((int *)a);
    func_021A231C((u32 *)a, b);
    func_021A2120((u32 *)a, b);
    return 1;
}


void func_021EF1C4(int a)
{
    int *p;
    int h;
    Pt pt;

    p = (int *)func_021A2630((unsigned char *)a);
    h = func_021A2638((unsigned char *)a);
    func_021A2640((unsigned char *)a, (struct PtS *)&pt);
    switch (p[3]) {
    case 0:
        if (++p[0] > p[1]) {
            p[3] = 1;
            p[0] = (p[6] % 4) * 2 + 8;
            p[4] = 2;
            p[2] = 2;
            func_0204B908(h, (u16)(func_0204B918((struct Obj *)h) + 3));
            return;
        }
        pt.x = pt.x + (s16)p[4];
        pt.y = pt.y + (s16)p[2];
        func_021A2654(a, (short unsigned int *)(&pt));
        break;
    case 1:
        pt.x = pt.x + (s16)p[4];
        if (p[0] % 2 == 0) {
            pt.y = pt.y + (s16)p[2];
        } else {
            pt.y = pt.y - (s16)p[2];
        }
        if (p[0] % 4 == 0) {
            if (p[2] - 1 >= 0) {
                p[2] = p[2] - 1;
            }
            if (p[4] - 1 >= 0) {
                p[4] = p[4] - 1;
            }
        }
        func_021A26C4(a, (u32)(&pt));
        if (p[0]-- <= 0) {
            p[3] = 2;
        }
        break;
    case 2:
        func_021A21E0((u32 *)a);
        break;
    }
}
