/*
 * file:     zknsearch_main_p06.c
 * unit:     yes
 * function: func_021BFA14, func_021BFA7C, func_021BFABC, func_021BFB24, func_021BFB8C, func_021BFBF8, func_021BFCE4, func_021BFE84, func_021BFEAC, func_021BFF18, func_021BFF30, func_021BFF68, func_021C003C, func_021C006C, func_021C0098, func_021C00B4, func_021C00D8, func_021C00FC, func_021C014C, func_021C01C0
 * address:  0x021BFA14
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BEDF0 0x021BEDF0 thumb ov210
 *   func_021BEE38 0x021BEE38 thumb ov210
 *   func_021B93B8 0x021B93B8 thumb ov067
 *   func_021BF7B0 0x021BF7B0 thumb ov210
 *   func_021BEE04 0x021BEE04 thumb ov210
 *   func_021BEE58 0x021BEE58 thumb ov210
 *   func_020355C4 0x020355C4 arm
 *   func_02025CD0 0x02025CD0 thumb
 *   func_02025D1C 0x02025D1C thumb
 *   d_021C0B60 0x021C0B60 data a4
 *   d_021C0B14 0x021C0B14 data a4
 *   func_02025D14 0x02025D14 thumb
 *   func_02025DE8 0x02025DE8 thumb
 *   func_020362DC 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   func_020260F4 0x020260F4 thumb
 *   func_020260E0 0x020260E0 thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_0202EB04 0x0202EB04 thumb
 *   func_02035C60 0x02035C60 arm
 *   func_02035C08 0x02035C08 arm
 *   func_021B940C 0x021B940C thumb ov067
 *   d_021C0B3C 0x021C0B3C data a4
 *   d_021C0B24 0x021C0B24 data a4
 */
#include "../../matched/include/Obj25630.h"
#include "../../matched/include/Obj25631.h"
#include "../../matched/include/Obj10923.h"
#include "../../matched/include/Obj00085.h"
#include "../../matched/include/Obj25635.h"

struct Struct_02025CD0;
struct Struct_02025D1C;
struct Sound;
struct CodeIn;
struct S;
typedef enum Y { YMin = -2147483647, YMax = 2147483647 } Y;

typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char  u8;

extern void func_021BEDF0(int p, int i, int v);
extern void func_021BEE38(char *p, int idx, int a, short b, unsigned short c);
extern int func_021B93B8(char *);
extern void func_021BF7B0(char *p, int idx, int y, int flag);
extern int func_021BEE04(int p, int i);
extern void func_021BEE58(char *p, int idx, short *outA, short *outB, unsigned short in);
extern unsigned char func_020355C4(void);
extern struct Struct_02025CD0 *func_02025CD0(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 heapId);
extern void func_02025D1C(struct Struct_02025D1C *obj);
extern void func_02025D14(void);
extern void *func_0202616C(void **obj, unsigned int idx);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(u32 bit);
extern int func_02025DE8(struct Sound *obj);
extern unsigned func_020362DC(void);
extern void func_020355D8(u8 v);
extern void func_020260F4(struct Struct_02025CD0 *obj, u32 state);
extern u8 func_020260E0(struct Sound *obj);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_0202EB04(struct CodeIn *p);
extern int func_02035C60(void);
extern int func_02035C08(const void *);
extern void func_021B940C(struct S *s);
void func_021BFA14(char *p, int y, int flag);
void func_021BFA7C(char *p, int i, int flag);
void func_021BFABC(char *ctx, int slot, int index);
void func_021BFB24(char *ctx);
void func_021BFB8C(char *ctx, unsigned long slot, Y y, int flag);
void func_021BFBF8(int p, int v);
void func_021BFCE4(char *p, int dx);
void func_021BFE84(int p, int n);
void func_021BFEAC(char *ctx, int index);
void func_021BFF18(int p);
void func_021BFF30(int p, unsigned int a, unsigned int b);
u32 func_021BFF68(int p);
void func_021C003C(int p, unsigned b);
void func_021C006C(int p, unsigned b);
void func_021C0098(int p, unsigned a, unsigned b);
void func_021C00B4(int p, unsigned a, unsigned b);
void func_021C00D8(int p, unsigned a, unsigned b);
int func_021C00FC(unsigned char *ctx);
int func_021C014C(char *ctx);
int func_021C01C0(char *ctx);
extern const unsigned d_021C0B60[], d_021C0B14[];
extern const unsigned d_021C0B3C[];
extern const unsigned d_021C0B24[];

void func_021BFA14(char *p, int y, int flag)
{
    int coord;
    if (flag == 1) {
        func_021BEDF0((int)p, 9, 1);
        coord = y + 20;
        func_021BEE38(p, 9, 0x8c, coord, 0);
    } else {
        func_021BEDF0((int)p, 11, 1);
        coord = y + 20;
        func_021BEE38(p, 11, 0x8c, coord, 1);
        func_021BEDF0((int)p, 13, 1);
        func_021BEE38(p, 13, 0x8c, coord, 1);
    }
}

/*
 * Caller sign-extends r3 to 16 bits before EE38; existing callee uses u16.
 */
void func_021BFA7C(char *p, int i, int flag)
{
    func_021BEDF0((int)p, 9, flag);
    func_021BEDF0((int)p, 11, 0);
    func_021BEDF0((int)p, 13, 0);
    if (flag == 1)
        func_021BEE38(p, 9, 0x8c, (short)(i * 40 + 20), 0);
}

void func_021BFABC(char *ctx, int slot, int index)
{
    unsigned center = func_021B93B8(*(char * *)&((struct Obj25630 *)ctx)->f1E0);
    signed short lower = center - 7;
    signed short upper = center + 7;
    if (lower < 0) lower = 0;
    if (index >= lower && index < center) {
        func_021BF7B0(ctx, slot, (signed short)(192 - (center - index) * 24), 0);
    } else if (index >= center && index < upper) {
        func_021BF7B0(ctx, slot, (signed short)((index - center) * 24), 1);
    }
}

void func_021BFB24(char *ctx)
{
    unsigned center = func_021B93B8(*(char * *)&((struct Obj25631 *)ctx)->f1E0);
    int index = (*(unsigned char ***)(ctx))[2][6];
    signed short lower = index - 4;
    signed short upper = index + 4;
    if (lower < 0) lower = 0;
    if (index >= lower && index < center) {
        func_021BFA14(ctx, (signed short)(192 - (center - index) * 40), 0);
    } else if (index >= center && index < upper) {
        func_021BFA14(ctx, (signed short)((index - center) * 40), 1);
    }
}

/*
 * lever: unsigned long slot keeps updates in its home; enum y keeps the wide updated value and repeats s16 call truncation. int/short variants sank or cached updates (110–118 B); check3b EXACT 108 B.
 */
void func_021BFB8C(char *ctx, unsigned long slot, Y y, int flag)
{
    unsigned long second;
    if (flag == 1) {
        slot += 15;
        func_021BEDF0((int)ctx, (unsigned)slot, (unsigned)1);
        y += 20;
        func_021BEE38(ctx, (unsigned)slot, (unsigned short)204, y, 0);
    } else {
        second = slot + 29;
        func_021BEDF0((int)ctx, (unsigned)second, (unsigned)1);
        y += 20;
        func_021BEE38(ctx, (unsigned)second, (unsigned short)204, y, 1);
        slot += 43;
        func_021BEDF0((int)ctx, (unsigned)slot, (unsigned)1);
        func_021BEE38(ctx, (unsigned)slot, (unsigned short)204, y, 1);
    }
}


/*
 * Addresses are Black-image addresses.
 */
void func_021BFBF8(int p, int v)
{
    unsigned i;
    short pos[2];

    for (i = 9; i <= 10; i++) {
        if (func_021BEE04(p, i) != 0) {
            int t;

            func_021BEE58((char *)p, i, &pos[1], &pos[0], 0);
            func_021BEE38((char *)p, i, (short)pos[1], (short)(pos[0] + v), (int)0);
            t = pos[0] + v;
            if (t <= -12 || t >= 0xcc)
                func_021BEDF0(p, i, 0);
        }
    }
    for (i = 11; i <= 12; i++) {
        if (func_021BEE04(p, i) != 0) {
            int t;

            func_021BEE58((char *)p, i, &pos[1], &pos[0], 1);
            func_021BEE38((char *)p, i, (short)pos[1], (short)(pos[0] + v), (int)1);
            func_021BEE38((char *)p, i + 2, (short)pos[1], (short)(pos[0] + v), (int)1);
            t = pos[0] + v;
            if (t <= -12 || t >= 0xcc) {
                func_021BEDF0(p, i, 0);
                func_021BEDF0(p, i + 2, 0);
            }
        }
    }
}


void func_021BFCE4(char *p, int dx)
{
    u32 i;
    struct { short x; short y; } pos;

    for (i = 0xF; i < 0x1D; i++) {
        if (func_021BEE04((int)p, i)) {
            func_021BEE58(p, i, &pos.y, &pos.x, 0);
            func_021BEE38(p, i, pos.y, (short)(pos.x + dx), 0);
            if (pos.x + dx <= -20 || pos.x + dx >= 0xDC) {
                func_021BEDF0((int)p, i, 0);
            }
        }
    }
    func_021BEE58(p, 9, &pos.y, &pos.x, 0);
    func_021BEE38(p, 9, pos.y, (short)(pos.x + dx), 0);
    if (pos.x + dx <= -20 || pos.x + dx >= 0xDC) {
        func_021BEDF0((int)p, 9, 0);
    }
    for (i = 0x1D; i < 0x2B; i++) {
        if (func_021BEE04((int)p, i)) {
            func_021BEE58(p, i, &pos.y, &pos.x, 1);
            func_021BEE38(p, i, pos.y, (short)(pos.x + dx), 1);
            func_021BEE38(p, i + 0xE, pos.y, (short)(pos.x + dx), 1);
            if (pos.x + dx <= -28 || pos.x + dx >= 0xD4) {
                func_021BEDF0((int)p, i, 0);
                func_021BEDF0((int)p, (int)i + 0xE, 0);
            }
        }
    }
    func_021BEE58(p, 0xB, &pos.y, &pos.x, 1);
    func_021BEE38(p, 0xB, pos.y, (short)(pos.x + dx), 1);
    func_021BEE38(p, 0xD, pos.y, (short)(pos.x + dx), 1);
    if (pos.x + dx <= -28 || pos.x + dx >= 0xD4) {
        func_021BEDF0((int)p, 0xB, 0);
        func_021BEDF0((int)p, 0xD, 0);
    }
}


void func_021BFE84(int p, int n)
{
    func_021BEDF0(p, 8, 1);
    func_021BEE38((char *)p, 8, (short)(n * 2 + 8), 0xa8, (int)0);
}

void func_021BFEAC(char *ctx, int index)
{
    if (func_020355C4() == 1) {
        ((struct Obj10923 *)ctx)->f2B0 = func_02025CD0((unsigned)d_021C0B60, (unsigned)d_021C0B14, (unsigned)ctx, 0, index, 123);
    } else {
        ((struct Obj10923 *)ctx)->f2B0 = func_02025CD0((unsigned)d_021C0B60, (unsigned)d_021C0B14, (unsigned)ctx, 1, index, 123);
        func_021BFF30((int)ctx, index, 3);
    }
    func_02025D1C(((struct Obj10923 *)ctx)->f2B0);
}


void func_021BFF18(int p)
{
    int *q = (int *)p;

    if (q[0xac] != 0) {
        func_02025D14();
        q[0xac] = 0;
    }
}


/*
 * note:     func_0202616C takes (record, a); passing a as the second argument keeps r1 live,
 *           so the 0x2B0 offset lands in r2.
 */
void func_021BFF30(int p, unsigned int a, unsigned int b)
{
    u8 *t;
    int *q = (int *)p;

    if (a > 6)
        return;
    t = (u8 *)func_0202616C((void **)q[0xac], a);
    func_020413B0(0, t[0], t[1], t[2], t[3], (u8)b);
    func_02041B6C(0);
}


u32 func_021BFF68(int p)
{
    int *q = (int *)p;
    int r = func_02025DE8((struct Sound *)q[0xac]);
    unsigned k;

    if (r != -1)
        return r;
    k = func_020362DC();
    if (k & 0x400) {
        func_020355D8(0);
        return 8;
    }
    k = func_020362DC();
    if (k & 0x800) {
        if (func_020355C4() == 1)
            func_020260F4((struct Struct_02025CD0 *)q[0xac], 1);
        func_020355D8(0);
        return 7;
    }
    k = func_020362DC();
    if (k & 8) {
        if (func_020355C4() == 1)
            func_020260F4((struct Struct_02025CD0 *)q[0xac], 1);
        func_020355D8(0);
        func_021C003C(p, 5);
        return 5;
    }
    k = func_020362DC();
    if (k & 4) {
        if (func_020355C4() == 1)
            func_020260F4((struct Struct_02025CD0 *)q[0xac], 1);
        func_020355D8(0);
        func_021C003C(p, 6);
        return 6;
    }
    if (func_020362DC() != 0 && func_020355C4() == 1) {
        func_020355D8(0);
        func_020260F4((struct Struct_02025CD0 *)q[0xac], 1);
        return -4;
    }
    return r;
}


void func_021C003C(int p, unsigned b)
{
    int *q = (int *)p;

    func_021BFF30(p, func_020260E0((struct Sound *)q[0xac]), 1);
    func_021BFF30(p, b, 3);
    func_020260E4((struct Sound *)q[0xac], (unsigned char)b);
}


void func_021C006C(int p, unsigned b)
{
    unsigned r = func_020362DC();

    if ((r & 2) && !(r & 0xf1))
        return;
    func_021BFF30(p, b, 3);
    func_0202EB04((struct CodeIn *)(((int *)p)[0xad]));
}


void func_021C0098(int p, unsigned a, unsigned b)
{
    func_021BFF30(p, b, 1);
    func_021BFF30(p, a, 1);
}


void func_021C00B4(int p, unsigned a, unsigned b)
{
    func_021BFF30(p, b, 1);
    func_021BFF30(p, a, 3);
    func_0202EB04((struct CodeIn *)(((int *)p)[0xad]));
}


void func_021C00D8(int p, unsigned a, unsigned b)
{
    func_021BFF30(p, b, 1);
    if (a == 7)
        func_020260E4((struct Sound *)(((int *)p)[0xac]), (unsigned char)b);
}

int func_021C00FC(unsigned char *ctx)
{
    if (ctx[0x2bb] == 90) {
        ctx[0x2bb] = 0;
        return 1;
    }
    ctx[0x2bb]++;
    if (func_02035C60()) {
        func_020355D8(1);
        ctx[0x2bb] = 0;
        return 1;
    }
    if (func_020362DC() & 3) {
        func_020355D8(0);
        ctx[0x2bb] = 0;
        return 1;
    }
    return 0;
}

int func_021C014C(char *ctx)
{
    int result = func_02035C08(d_021C0B3C);
    if (result != -1) {
        func_020355D8(1);
        return result;
    }
    if (func_020362DC() & 2) {
        func_020355D8(0);
        return 8;
    }
    if (func_020362DC() & 8) {
        func_020355D8(0);
        return 8;
    }
    if (func_020362DC() & 4) {
        if (func_020355C4() == 1) {
            func_020355D8(0);
            func_021B940C(((struct Obj00085 *)ctx)->f1E0);
        }
        return 9;
    }
    return result;
}

int func_021C01C0(char *ctx)
{
    int result = func_02035C08(d_021C0B24);
    if (result != -1) { func_020355D8(1); return result; }
    if (func_020362DC() & 2) { func_020355D8(0); return 8; }
    if (func_020362DC() & 8) { func_020355D8(0); return 8; }
    if (func_020362DC() & 4) {
        if (func_020355C4() == 1) {
            func_020355D8(0);
            func_021B940C(((struct Obj25635 *)ctx)->f1E0);
        }
        return 9;
    }
    return result;
}
