/*
 * file:     fld3d_ci_p06.c
 * unit:     yes
 * function: func_021C3490, func_021C34B4, func_021C34C4, func_021C34F8, func_021C3510, func_021C3530, func_021C360C
 * address:  0x021C3490
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
 *   func_0200BC2C  0x0200BC2C  thumb
 *   func_021C341C  0x021C341C  thumb  ov021
 *   func_0200BCB8  0x0200BCB8  thumb
 *   func_021C36EC  0x021C36EC  thumb  ov021
 *   func_0200BCA8  0x0200BCA8  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_02018584  0x02018584  thumb
 *   func_020185C4  0x020185C4  thumb
 *   func_0201ADD0  0x0201ADD0  thumb
 *   func_021C3670  0x021C3670  thumb  ov021
 *   func_020181F4  0x020181F4  thumb
 *   func_020180F4  0x020180F4  thumb
 *   d_021DA8C8     0x021DA8C8  data  ov021  a4
 */
#include "../../matched/include/Obj04896.h"

typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed char    s8;

typedef unsigned long long u64;

typedef struct { u16 x, y; } P;

typedef struct { u32 v[4]; } T4;

extern void *func_0200BC2C(void *e, int i);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern int func_021C341C(u32 *p, u32 b);
extern int func_0200BCB8(void *e);
extern int func_021C36EC(u32 a, u32 b);
extern u32 func_0200BCA8(void *e, u32 i);
extern void func_02017E40(void *mon, u32 id, u32 v);
extern u32 func_02018584(u16 a, u16 b, u16 c);
extern void func_020185C4(void *mon);
extern void func_0201ADD0(unsigned int a, int b, void *buf);
extern int func_021C3670(void *, u32);
extern void func_020181F4(void *p, u16 move, u32 slot);
extern void func_020180F4(void *p, int move);
int func_021C3490(void **p, int i);
int func_021C34B4(void **a, int b);
u8 func_021C34C4(void **p);
void *func_021C34F8(void *a, u32 b);
u32 func_021C3510(u32 a, u32 b);
void func_021C3530(void *mon, u32 b);
void func_021C360C(void *a, u32 b);
extern const T4 d_021DA8C8;



/*
 * Levels gained by the slot-i day-care Pokemon (EXACT*: pad).
 */
int func_021C3490(void **p, int i)
{
    int lv = func_02017E1C(func_0200BC2C(p[2], i), 0x9E, 0);

    return func_021C341C((u32 *)p, i) - lv;
}



/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C34B4(void **a, int b)
{
return ((func_021C3490((void **)a, b) + 1) * 100);
}



/*
 * Compatibility of the two deposited Pokemon, 0 when fewer than two (EXACT*: pad).
 */
u8 func_021C34C4(void **p)
{
    void *a;

    if (func_0200BCB8(p[2]) < 2)
        return 0;
    a = func_0200BC2C(p[2], 0);
    return func_021C36EC((u32)a, (u32)func_0200BC2C(p[2], 1));
}



void *func_021C34F8(void *a, u32 b)
{
func_0200BCA8(((struct Obj04896 *)a)->f8, b);
return func_0200BC2C(((struct Obj04896 *)a)->f8, b);
}



/*
 * Saturating 32-bit add (EXACT*: pad).
 */
u32 func_021C3510(u32 a, u32 b)
{
    u64 s = (u64)a + b;

    if (s > 0xFFFFFFFF)
        return 0xFFFFFFFF;
    return s;
}



/*
 * Learnset walk as in func_021C4084. Load-bearing: lv is read from the
 * first entry copy right after it is made (the value stays in the
 * register), mv from the second copy, and mv is u32/int (u16 sinks its
 * load to the call).
 */
void func_021C3530(void *mon, u32 b)
{
    P buf[26];
    P e, d, c, a;
    u32 species;
    u32 form;
    u32 max;
    int oldlv;
    int newlv;
    u32 exp;
    int i;
    int end;
    int lv;
    u32 mv;

    species = func_02017E1C(mon, 5, 0);
    form = func_02017E1C(mon, 0x6f, 0);
    max = func_02018584(species, form, 100);
    oldlv = func_02017E1C(mon, 0x9e, 0);
    exp = func_021C3510(func_02017E1C(mon, 8, 0), b);
    if (max < exp)
        exp = max;
    func_02017E40(mon, 8, exp);
    func_020185C4(mon);
    i = 0;
    newlv = func_02017E1C(mon, 0x9e, 0);
    func_0201ADD0((u16)species, (u16)form, buf);
    goto test;
body:
    e = a;
    lv = e.y;
    d = a;
    mv = d.x;
    if (newlv < lv)
        return;
    if (oldlv < lv)
        func_021C360C(mon, mv);
    i++;
test:
    a = buf[i];
    c = a;
    end = 0;
    if (c.x == 0xffff && c.y == 0xffff)
        end = 1;
    if (!end)
        goto body;
}



/*
 * Addresses are Black-image addresses.
 */
void func_021C360C(void *a, u32 b)
{
    T4 t = d_021DA8C8;
    int i;

    if (b != 0 && func_021C3670(a, b) == 0) {
        for (i = 0; i < 4; i++) {
            if (func_02017E1C(a, t.v[i], 0) == 0) {
                func_020181F4(a, b, (u8)i);
                return;
            }
        }
        func_020180F4(a, (u16)b);
    }
}
