/*
 * file:     btl_server_p102.c
 * unit:     yes
 * function: func_021CA248, func_021CA270, func_021CA2E8, func_021CA318, func_021CA370, func_021CA394, func_021CA3AC, func_021CA3D0, func_021CA47C, func_021CA570
 * address:  0x021CA248
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021C1D60 0x021C1D60 thumb ov093
 *   func_021D5FA4  0x021D5FA4  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021C99A0  0x021C99A0  thumb  ov093
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021B8DDC  0x021B8DDC  thumb  ov093
 *   func_021B8DEC  0x021B8DEC  thumb  ov093
 *   func_021BD9D4  0x021BD9D4  thumb  ov093
 *   func_021BDA00  0x021BDA00  thumb  ov093
 *   func_021D67D8 0x021D67D8 thumb ov093
 *   func_021C3810  0x021C3810  thumb  ov093
 *   func_021BD148 0x021BD148 thumb ov093
 *   func_021BD170 0x021BD170 thumb ov093
 *   func_021BD1B0 0x021BD1B0 thumb ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021B9AEC  0x021B9AEC  thumb  ov093
 *   func_021B9C98  0x021B9C98  thumb  ov093
 *   func_021BD43C  0x021BD43C  thumb  ov093
 *   func_021BD4E4  0x021BD4E4  thumb  ov093
 *   func_021D6C24 0x021D6C24 thumb ov093
 *   func_021D5C30 0x021D5C30 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021D6C50 0x021D6C50 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021C5A1C 0x021C5A1C thumb ov093
 *   func_021E0434 0x021E0434 thumb ov093
 *   func_021D8510 0x021D8510 thumb ov093
 *   func_021D8484 0x021D8484 thumb ov093
 *   func_021C5A34 0x021C5A34 thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021C7B7C 0x021C7B7C thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021CA5BC  0x021CA5BC  thumb  ov093
 *   func_021D6C2C  0x021D6C2C  thumb  ov093
 */
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj21127.h"

struct Unk021D5FA4;
struct Msg;
struct R4;
struct UtilWork;
struct Unk021D6C50;
struct Unk021D6C2C;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Cmd_021CA248 {
    u32 pad;
    u8 b4;
    u8 b5;
    u16 h6;
};

struct Q {
    u32 a : 8;
    u32 b : 5;
    u32 c : 19;
    u16 e;
    u8 f;
    u8 lo : 4;
    u8 hi : 4;
};

struct Cmd_021CA2E8 { u32 a:8; u32 id:5; u32 b:10; u32 flag:1; u32 c:8; u8 target; };

extern u8 *func_021B9934(char *p, int i);
extern int func_021C1D60(u8 *, u8 *, u32);
extern void func_021D5FA4(struct Unk021D5FA4 *p, u16 n);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern int func_021C99A0(void *w, const struct Msg *m);
extern int func_021B8D8C(void *p, void *a, u32 b);
extern u8 func_021B8DDC(u32 x);
extern int func_021B8DEC(void *p, int s);
extern void func_021BD9D4(void *w, int a, int b, int c, int d);
extern int func_021BDA00(u8 *p);
extern void func_021D67D8(u8 *, u32);
extern int func_021C3810(u8 *p, u8 *a, u8 *b, int force, int *out, u16 move, int ignore, const struct Msg *msg);
extern int func_021BD148(void *, u8);
extern int func_021BD170(u8 *, u8 *);
extern int func_021BD1B0(void *, u8);
extern int func_021D5B68(void *p);
extern char *func_021B9AEC(char *p, int i);
extern int func_021B9C98(u8 *p, u32 v);
extern void func_021BD43C(u8 *p, int i, u8 a, u8 b, int c);
extern void func_021BD4E4(u8 *p, int i, u8 a, u8 b);
extern int func_021D6C24(struct R4 *p);
extern int func_021D5C30(struct UtilWork *p);
extern int func_021D59B4(u8 *p, int k);
extern int func_021D6C50(struct Unk021D6C50 *a, struct Unk021D6C50 *b);
extern u8 func_021D5440(u8 *p);
extern void func_021C5A1C(u8 *p, u8 *a);
extern void func_021E0434(u8 *);
extern void func_021D8510(void *p);
extern void *func_021D8484(void *);
extern void func_021C5A34(u8 *p, u8 *a);
extern u32 func_021CC8D8(void *, int);
extern void func_021C7B7C(u8 *p, unsigned int i);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern int func_021CA5BC(u8 *p, int k);
extern void func_021D6C2C(struct Unk021D6C2C *p);
u8 func_021CA248(u8 *p, const u8 *q);
int func_021CA270(u8 *w, const struct Cmd_021CA248 *c);
int func_021CA2E8(u8 *p, const u8 *q);
u8 func_021CA318(u8 *p, const struct Q *q);
int func_021CA370(u8 *p, const u8 *q);
u8 func_021CA394(u8 *p, const u8 *q);
int func_021CA3AC(u8 *p, const u8 *q);
int func_021CA3D0(u8 *p, u8 *q);
int func_021CA47C(u8 *p, struct Cmd_021CA2E8 *q);
int func_021CA570(u8 *p, u8 *q);


u8 func_021CA248(u8 *p, const u8 *q)
{
    u8 r;
    if (func_021C1D60(p, func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[4]), q[5])) r = 1;
    else r = 0;
    return r;
}



int func_021CA270(u8 *w, const struct Cmd_021CA248 *c)
{
    int s;
    int a;
    int b;
    func_021D5FA4((struct Unk021D5FA4 *)func_021B9934(*(char * *)&((struct Obj00003 *)w)->f8, c->b4), c->h6);
    func_021CD4B0(((struct Obj00003 *)w)->fC, 2, c->b4, c->h6);
    *(u8 *)(w + c->b4 + 0x7A9) = 0;
    func_021C99A0(w, (const struct Msg *)((u8 *)c + 8));
    s = func_021B8D8C(((struct Obj00003 *)w)->f4, ((struct Obj00003 *)w)->f8, c->b4);
    if (s != 6) {
        a = func_021B8DDC(c->b4);
        b = func_021B8DEC(((struct Obj00003 *)w)->f4, s);
        func_021BD9D4(w, a, b, b, 1);
        func_021BDA00(w);
    }
    return 1;
}


/*
 * extent: two zero bytes at 021CA316 are alignment padding.
 */
int func_021CA2E8(u8 *p, const u8 *q)
{
    func_021D67D8(func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[4]), *(const u16 *)(q + 6));
    func_021CD4B0(((struct Obj00003 *)p)->fC, 20, q[4], *(const u16 *)(q + 6));
    func_021C99A0(p, (const struct Msg *)(q + 8));
    return 1;
}



u8 func_021CA318(u8 *p, const struct Q *q)
{
    int out[1];
    u8 *a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q->f);
    u8 *b = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, (u8)q->b);
    if (func_021C3810(p, b, a, q->lo, out, q->e, q->hi, (const struct Msg *)((u8 *)q + 8))) return 1;
    return 0;
}


/*
 * extent: two zero bytes at 021CA392 are alignment padding.
 */
int func_021CA370(u8 *p, const u8 *q)
{
    if (func_021BD148(p, q[4])) {
        func_021C99A0(p, (const struct Msg *)(q + 8));
        return 1;
    }
    return 0;
}


/*
 * interface: r1 is the halfword loaded at 021CA396; cast preserves the
 * original payload while retaining the callee's pointer prototype.
 */
u8 func_021CA394(u8 *p, const u8 *q)
{
    u8 r;
    if (func_021BD170(p, (u8 *)(u32)*(const u16 *)&((struct Obj21127 *)q)->f4)) r = 1;
    else r = 0;
    return r;
}


/*
 * extent: two zero bytes at 021CA3CE are alignment padding.
 */
int func_021CA3AC(u8 *p, const u8 *q)
{
    if (func_021BD1B0(p, q[4])) {
        func_021C99A0(p, (const struct Msg *)(q + 8));
        return 1;
    }
    return 0;
}



int func_021CA3D0(u8 *p, u8 *q)
{
    int a, b;
    u8 *m1, *m2;
    char *o;
    s16 i, j;
    if (q[4] != q[5]) {
        a = func_021B8DDC(q[4]);
        b = func_021B8DDC(q[5]);
        if (a == b) {
            m1 = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[4]);
            m2 = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[5]);
            if (!func_021D5B68(m1) && !func_021D5B68(m2)) {
                o = func_021B9AEC(*(char * *)&((struct Obj00003 *)p)->f8, a);
                i = func_021B9C98((u8 *)o, (u32)m1);
                j = func_021B9C98((u8 *)o, (u32)m2);
                if (i >= 0 && j >= 0) {
                    func_021BD43C(p, a, i, j, 0);
                    func_021C99A0(p, (const struct Msg *)(q + 8));
                    func_021BD4E4(p, a, i, j);
                    return 1;
                }
            }
        }
    }
    return 0;
}


int func_021CA47C(u8 *p, struct Cmd_021CA2E8 *q)
{
    u8 *a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, (u8)q->id);
    u8 *b = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, (u8)q->target);
    u16 k;
    int x, y;
    u32 lock;
    if (!func_021D6C24((struct R4 *)a) && !func_021D6C24((struct R4 *)b) && !func_021D5C30((struct UtilWork *)a)) {
        k = func_021D59B4(a, 16);
        if (func_021D6C50((struct Unk021D6C50 *)a, (struct Unk021D6C50 *)b)) {
            x = func_021D5440(a);
            y = func_021D5440(b);
            if (q->flag) func_021C5A1C(p, a);
            func_021E0434(a);
            func_021D8510(a);
            func_021D8484(a);
            func_021CD4B0(((struct Obj00003 *)p)->fC, 0x53, x, y);
            func_021C99A0(p, (const struct Msg *)((u8 *)q + 8));
            if (q->flag) func_021C5A34(p, a);
            if (k != func_021D59B4(a, 17)) {
                lock = func_021CC8D8(p + 0x1d74, 0x3f0a);
                func_021C7B7C(p, x);
                func_021CC95C((u32 *)(p + 0x1d74), lock, 0x3f0c);
            }
            return 1;
        }
    }
    return 0;
}



int func_021CA570(u8 *p, u8 *q)
{
    u8 *m;
    if (func_021CA5BC(p + 0x1AB8, q[4])) {
        m = func_021B9934(((struct Obj00003 *)p)->f8, q[4]);
        if (func_021D6C24((struct R4 *)m)) {
            func_021D6C2C((struct Unk021D6C2C *)m);
            func_021CD4B0(((struct Obj00003 *)p)->fC, 0x4b, q[4]);
            func_021C99A0(p, (const struct Msg *)(q + 8));
            return 1;
        }
    }
    return 0;
}
