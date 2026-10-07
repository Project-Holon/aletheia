/*
 * file:     fldeff_ripple_p08.c
 * unit:     yes
 * function: func_021C40F8, func_021C4160, func_021C4238, func_021C42BC, func_021C42F4, func_021C4340, func_021C447C, func_021C4504
 * address:  0x021C40F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02048F60  0x02048F60  arm
 *   func_02017E1C  0x02017E1C  thumb
 *   func_020307B0  0x020307B0  arm
 *   d_021DA908     0x021DA908  data  ov021  a4
 *   func_0201ADD0  0x0201ADD0  thumb
 *   d_021DA8F8     0x021DA8F8  data  ov021  a4
 *   func_020212B0  0x020212B0  thumb
 *   d_021DA8E8     0x021DA8E8  data  ov021  a4
 *   func_02017588  0x02017588  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_02018A00  0x02018A00  thumb
 *   func_02008510  0x02008510  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0202F190  0x0202F190  thumb
 *   func_02018198  0x02018198  thumb
 *   func_020185C4  0x020185C4  thumb
 *   func_0201B9F0  0x0201B9F0  thumb
 *   g_020A7370     0x020A7370  data
 *   d_021DA948     0x021DA948  data  ov021  a4
 *   func_02021288  0x02021288  thumb
 *   func_0201ADE4  0x0201ADE4  thumb
 *   func_0202130C  0x0202130C  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 *   func_0201AE14  0x0201AE14  thumb
 */
#include "../../matched/include/Obj02093.h"

struct Mon;
struct MsgBank;
struct U16Vec;
struct Personal;
typedef unsigned int u32;

typedef unsigned short u16;

typedef struct { u32 v[4]; } T;

typedef struct { u16 x, y; } P;

typedef struct { u32 v[4]; } T4;

typedef unsigned long long u64;

typedef struct { u32 v[6]; } T6;

typedef struct {
    u32 species;
    u32 form;
    u32 level;
    u32 f0C;
    u32 f10;
    u32 f14;
    u32 iv[6];
    u32 f30;
    u32 f34;
    u32 f38;
    u32 mv[4];
    u32 f4C;
    u32 f50;
    u32 f54;
    u32 a[6];
    u32 b[6];
    u32 n;
} S;

extern void *func_02048F60(u32 archive, u32 member, u32 heap);
extern u32 func_02017E1C(void *a, u32 b, u32 c);
extern u32 func_020307B0(void *p);
extern void func_0201ADD0(unsigned int a, int b, void *buf);
extern u16 func_020212B0(u16 id);
extern void func_02017588(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void func_02017E40(void *mon, u32 id, u32 v);
extern void func_02018A00(void *mon, u32 species, u32 form);
extern void *func_02008510(void *a, int tag);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0202F190(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_02018198(void *mon);
extern void func_020185C4(void *mon);
extern void func_0201B9F0(void *mon);
extern u32 func_02021288(u32 a);
extern void *func_0201ADE4(u32 species, int form, u32 heap);
extern u32 func_0202130C(u32 a);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *p);
extern void func_02048F74(void *dst, u32 archive_id, u32 member, u32 mode, u32 *size_out);
void func_021C40F8(u32 *p, u32 *q, u32 heap);
void func_021C4160(u32 *p, u32 *q);
void func_021C4238(u32 *a, u32 *b, u32 *c);
void func_021C42BC(void **p, u32 *q);
void func_021C42F4(u32 *p, u32 v);
void func_021C4340(void *mon, const S *q, void *my, u32 y, u16 heap);
int func_021C447C(u32 a, u32 b, u32 c, u32 d);
u16 func_021C4504(u16 sp);
extern T d_021DA908;
extern const T4 d_021DA8F8;
extern T d_021DA8E8;
extern void *g_020A7370;
extern const T6 d_021DA948;


/*
 * r2 is never touched before the func_02048F60 call: the function takes a
 * third parameter and forwards it as the heap argument. With two
 * parameters the table copy takes r3/r2 instead of r4/r3 (7 bytes).
 * Addresses are Black-image addresses.
 */
void func_021C40F8(u32 *p, u32 *q, u32 heap)
{
    T t = d_021DA908;
    u32 *pt = t.v;
    u16 *buf = func_02048F60(0x7b, q[0], heap);
    int n = buf[0];
    int i;

    for (i = 0; i < 4; i++) {
        u32 v = func_02017E1C((void *)p[0], pt[i], 0);
        int j;

        for (j = 1; j <= n; j++) {
            if (v == buf[j]) {
                func_021C42F4(q, v);
                break;
            }
        }
    }
    func_020307B0(buf);
}


/*
 * Twin of func_021C4084 (same goto-rotated learnset walk). The call
 * result must be a named local (v == mv gives cmp r0, r5), and end = 0
 * goes after the entry copies, as in the twin.
 */
void func_021C4160(u32 *p, u32 *q)
{
    P buf[26];
    T4 t = d_021DA8F8;
    P d, b, a;
    int i;
    int fa;
    int fb;
    int end;
    int k;
    u32 mv;
    u32 v;

    func_0201ADD0((u16)q[0], (u16)q[1], buf);
    i = 0;
    goto test;
body:
    d = a;
    mv = d.x;
    fa = 0;
    fb = 0;
    for (k = 0; k < 4; k++) {
        v = func_02017E1C((void *)p[0], t.v[k], 0);
        if (v == mv) {
            fa = 1;
            break;
        }
    }
    for (k = 0; k < 4; k++) {
        v = func_02017E1C((void *)p[1], t.v[k], 0);
        if (v == mv) {
            fb = 1;
            break;
        }
    }
    if (fa && fb)
        func_021C42F4(q, mv);
    i++;
test:
    a = buf[i];
    b = a;
    end = 0;
    if (b.x == 0xffff && b.y == 0xffff)
        end = 1;
    if (!end)
        goto body;
}


void func_021C4238(u32 *a, u32 *b, u32 *c)
{
    T t = d_021DA8E8;
    int i;

    for (i = 0; i < 4; i++) {
        u32 v = func_02017E1C((void *)a[0], t.v[i], 0);
        int k;

        for (k = 0x148; k <= 0x272; k++) {
            if (v == func_020212B0(k)) {
                if (func_021C447C((u32)c, (u16)b[0], (u16)b[1], (u16)k)) {
                    func_021C42F4(b, v);
                    break;
                }
            }
        }
    }
}


/*
 * Pikachu offspring learns move 0x158 when a parent holds item 0xEC.
 */
void func_021C42BC(void **p, u32 *q)
{
    if (q[0] == 0xAC) {
        if (func_02017E1C(p[0], 6, 0) == 0xEC || func_02017E1C(p[1], 6, 0) == 0xEC)
            func_021C42F4(q, 0x158);
    }
}


void func_021C42F4(u32 *p, u32 v)
{
    int i;
    u32 n;

    if (v == 0)
        return;
    n = ((struct Obj02093 *)p)->f38;
    for (i = 0; i < n; i++) {
        if (v == *(u32 *)((char *)p + i * 4 + 0x3c))
            return;
    }
    if (n < 4) {
        *(u32 *)((char *)p + n * 4 + 0x3c) = v;
        ((struct Obj02093 *)p)->f38 = ((struct Obj02093 *)p)->f38 + 1;
        return;
    }
    for (i = 0; i < 3; i++)
        *(u32 *)((char *)p + i * 4 + 0x3c) = *(u32 *)((char *)p + i * 4 + 0x40);
    *(u32 *)((char *)p + i * 4 + 0x3c) = v;
}


/*
 * Builds the day-care egg/offspring Pokemon from the 0x8C-byte work
 * record q (the struct func_021C38F4 fills on its stack). The bl to the
 * Thumb tail-call stub func_02018198 is witnessed by
 * src/matched/arm9/func_02018198.c.
 *
 * Load-bearing: const S *q (the species/level loads rise above the zero
 * stack-argument stores), and heap u16 at both callees (func_02008510,
 * func_0202F190) so it is re-read from its stack slot per call.
 */
void func_021C4340(void *mon, const S *q, void *my, u32 y, u16 heap)
{
    T6 t = d_021DA948;
    int i;
    u32 s;

    func_02017588(mon, q->species, q->level, q->f30, -1, q->f34);
    func_02017E40(mon, 0x6f, q->form);
    func_02017E40(mon, 0x70, q->f0C);
    func_02017E40(mon, 9, q->f14);
    if (q->f4C == 2)
        func_02018A00(mon, q->species, q->form);
    else
        func_02017E40(mon, 0xb2, q->f10);
    for (i = 0; i < 6; i++) {
        if (q->a[i] != 0 || q->b[i] != 0)
            func_02017E40(mon, t.v[i], q->iv[i]);
    }
    func_02017E40(mon, 0x36, q->mv[0]);
    func_02017E40(mon, 0x37, q->mv[1]);
    func_02017E40(mon, 0x38, q->mv[2]);
    func_02017E40(mon, 0x39, q->mv[3]);
    s = (u32)func_02008510(my, heap);
    func_02017E40(mon, 0x8d, s);
    func_02045808((struct U16Vec *)s);
    s = (u32)func_02045EC0(g_020A7370, 0x28a);
    func_02017E40(mon, 0x73, s);
    func_02045808((struct U16Vec *)s);
    func_0202F190(mon, 5, (u32)my, y, heap);
    func_02017E40(mon, 0x4c, 1);
    func_02018198(mon);
    func_020185C4(mon);
    func_0201B9F0(mon);
}


int func_021C447C(u32 a, u32 b, u32 c, u32 d)
{
    u32 y, x, v;

    if (b >= 0x289)
        return 0;
    if (func_02021288(d) == 0)
        return 0;
    x = (u32)func_0201ADE4(b, c, a);
    y = func_0202130C(d);
    if (y < 0x20) {
        v = func_0201AE1C((const struct Personal *)x, 0x27);
    } else if (y < 0x40) {
        v = func_0201AE1C((const struct Personal *)x, 0x28);
        y -= 0x20;
    } else if (y < 0x60) {
        v = func_0201AE1C((const struct Personal *)x, 0x29);
        y -= 0x40;
    } else {
        v = func_0201AE1C((const struct Personal *)x, 0x2a);
        y -= 0x60;
    }
    func_0201AE14((void *)x);
    return v & (1 << y);
}


/*
 * Maps a species to its base form via the evolution table (species below
 * 0x289).
 */
u16 func_021C4504(u16 sp)
{
    u16 v;

    if (sp >= 0x289)
        return sp;
    func_02048F74(&v, 0x14, sp, 0, (u32 *)2);
    return v;
}
