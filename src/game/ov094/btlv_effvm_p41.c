/*
 * file:     btlv_effvm_p41.c
 * unit:     yes
 * function: func_021FB8F4, func_021FB91C, func_021FBA64, func_021FBAD8, func_021FBAF8, func_021FBC78, func_021FBCEC, func_021FBD10
 * address:  0x021FB8F4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021F86F0 0x021F86F0 thumb ov094
 *   func_02201CA4 0x02201CA4 thumb ov094
 *   func_021F81B4  0x021F81B4  thumb  ov094
 *   func_021FCA04  0x021FCA04  thumb  ov094
 *   func_021F8198  0x021F8198  thumb  ov094
 *   func_021F7F1C  0x021F7F1C  thumb  ov094
 *   func_021F86B4  0x021F86B4  thumb  ov094
 *   func_022079C0  0x022079C0  thumb  ov094
 *   func_021F9858  0x021F9858  thumb  ov094
 *   func_02006210 0x02006210 thumb
 *   func_020061F8 0x020061F8 thumb
 *   func_02030734 0x02030734 arm
 *   func_021FCF2C 0x021FCF2C thumb ov094
 *   func_0207C768 0x0207C768 arm
 *   func_02030DA8 0x02030DA8 arm
 *   func_021F896C 0x021F896C thumb ov094
 *   func_021FE594 0x021FE594 thumb ov094
 *   func_021FE690 0x021FE690 thumb ov094
 *   d_0220AE68 0x0220AE68 data ov094 a1
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_021F9948  0x021F9948  thumb  ov094
 *   func_020113D0 0x020113D0 thumb
 *   func_021FC744 0x021FC744 thumb ov094
 *   func_021FC9D0 0x021FC9D0 thumb ov094
 */
#include "../../matched/include/Obj21671.h"
#include "../../matched/include/Obj21673.h"
#include "../../matched/include/Obj07880.h"
#include "../../matched/include/Obj13592.h"
#include "../../matched/include/Obj13593.h"

struct Cursor;
struct Res;
typedef unsigned int   u32;

typedef struct {
    char pad[0xdc];
    int fdc;            /* 0xdc */
    char pade0[0x23c - 0xe0];
    int ret;            /* 0x23c */
} State_021FB91C;

typedef struct { short x, y; } Pt;

typedef struct {
    char pad[0x23c];
    int f23c;
} State_021FBA64;

typedef unsigned short u16;

typedef struct {
    char pad[0x23c];
    int f23c;
} State_021FBC78;

extern u32 func_0201134C(struct Cursor *p);
extern int func_021F86F0(void);
extern void func_02201CA4(struct Res *r, int i);
extern void func_021F81B4(u32 a, u32 b);
extern int func_021FCA04(State_021FB91C *s, int id, int *out);
extern void func_021F8198(int a, int b);
extern int func_021F7F1C(int i);
extern int func_021F86B4(void);
extern void func_022079C0(char *p, int i, Pt *pt);
extern void func_021F9858(void *vm, u32 a, int b, u32 c, int e, u32 f, int g, int h, int d);
extern void func_02006210(void);
extern void func_020061F8(int i);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_021FCF2C(int, int);
extern u32 func_0207C768(u32 a, u32 b);
extern void *func_02030DA8(void *, void (*)(void *, int *), int *, int);
extern void func_021F896C(void *h, void (*cb)(void *), int arg);
extern void func_021FE594(void *, int *);
extern void func_021FE690(void *);
extern float _fflt(int);
extern float _fadd(float, float);
extern float _fsub(float, float);
extern int _ffix(float);
extern void func_021F9948(void *vm, u32 a, int mode, int c, int x, int dest, int e, int f, int g, int duration);
extern void func_020113D0(char *p, int val);
extern int func_021FC744(void *, void *);
extern int func_021FC9D0(void *a, char *s);
int func_021FB8F4(void *a, char *s);
int func_021FB91C(void *r, State_021FB91C *s);
int func_021FBA64(struct Cursor *a, State_021FBA64 *s);
int func_021FBAD8(void *a, char *s);
int func_021FBAF8(void *a, char *s);
int func_021FBC78(struct Cursor *a, State_021FBC78 *s);
int func_021FBCEC(void *a, char *s);
int func_021FBD10(void *a, char *s);
extern char d_0220AE68[];


/*
 * Script command: releases slot arg of the table at 0xcc and marks it free.
 */
int func_021FB8F4(void *a, char *s)
{
    int *tab = (int *)(s + 0xcc);
    int i = func_0201134C(a);

    func_02201CA4((struct Res *)func_021F86F0(), tab[i]);
    tab[i] = -1;
    return ((struct Obj21671 *)s)->f23C;
}


/*
 * The last loop reads the list through `((int *)ids)[i]`. The cast stops
 * the element address folding into sp-relative form, so the compiler hoists
 * `add r6, sp, #0x10` to function entry (ahead of the s spill) and reloads
 * the element after each call, while the case 4 call still takes a fresh
 * `add r2, sp, #0x10`. A `p = ids` pointer local instead CSEs that argument
 * into r6 and leaves 6 bytes out. `pt.x *= -1` and `Pt pt = {0, 0};` in the
 * loop block are required for the rest.
 */
int func_021FB91C(void *r, State_021FB91C *s)
{
    int ids2[8];
    int ids[8];
    u32 a;
    u32 b;
    int n;
    int i;

    a = func_0201134C(r);
    b = func_0201134C(r);
    if (a <= 1) {
        switch (b) {
        case 3:
            func_021F81B4(a, s->fdc);
            break;
        case 4:
            n = func_021FCA04(s, 0x10, ids2);
            if (n != 0) {
                for (i = 0; i < n; i++)
                    func_021F81B4(a, ids2[n]);
            }
            break;
        default:
            func_021F8198(a, b);
            break;
        }
    } else {
        n = 0;
        switch (b) {
        case 0:
            for (i = 0; i < 8; i += 2) {
                if (func_021F7F1C(i)) {
                    ids[n] = i;
                    n++;
                }
            }
            break;
        case 1:
            for (i = 1; i < 8; i += 2) {
                if (func_021F7F1C(i)) {
                    ids[n] = i;
                    n++;
                }
            }
            break;
        case 2:
            for (i = 0; i < 8; i++) {
                if (func_021F7F1C(i)) {
                    ids[n] = i;
                    n++;
                }
            }
            break;
        case 3:
            n = 1;
            ids[0] = s->fdc;
            break;
        case 4:
            n = func_021FCA04(s, 0x10, ids);
            break;
        }
        if (n != 0) {
            for (i = 0; i < n; i++) {
                Pt pt = {0, 0};

                pt.x = (a == 2) ? 0x80 : -0x10;
                if (((int *)ids)[i] & 1)
                    pt.x *= -1;
                func_022079C0((char *)func_021F86B4(), ((int *)ids)[i], &pt);
            }
        }
    }
    return s->ret;
}


int func_021FBA64(struct Cursor *a, State_021FBA64 *s)
{
    int v0 = func_0201134C(a);
    int v1 = func_0201134C(a);
    int v2 = func_0201134C(a);
    int v3 = func_0201134C(a);
    int v4 = func_0201134C(a);
    int v5 = func_0201134C(a);
    int v6 = func_0201134C(a);
    int v7 = func_0201134C(a);

    func_0201134C(a);
    func_021F9858((void *)a, v0, v1, v2, v4, v5, v6, v7, v3);
    return s->f23c;
}


/*
 * EXACT*: the listing extent includes two bytes of trailing alignment padding.
 *
 * Script command: mode 5 calls func_02006210, any other mode is passed to
 * func_020061F8.
 */
int func_021FBAD8(void *a, char *s)
{
    int r = func_0201134C(a);

    if (r == 5)
        func_02006210();
    else
        func_020061F8(r);
    return ((struct Obj21673 *)s)->f23C;
}

int func_021FBAF8(void *a, char *s)
{
    int *p;
    int x;
    int y;
    int diff;
    float f;
    float g;
    p = func_02030734((u16)((((struct Obj07880 *)s)->f238 & 0x7fff) | 0x8000), 0x38, 0, d_0220AE68, 0xf17);
    p[0] = (int)s;
    p[1] = func_0201134C(a);
    p[2] = func_0201134C(a);
    p[3] = 2;
    x = func_021FCF2C((int)a, func_0201134C(a));
    y = func_021FCF2C((int)a, func_0201134C(a));
    p[4] = (x & 1) ? 127 : -128;
    p[5] = (y & 1) ? 127 : -128;
    p[8] = func_0201134C(a);
    p[9] = func_0201134C(a);
    p[10] = p[9];
    p[11] = 0;
    p[12] = func_0201134C(a);
    p[13] = func_0201134C(a) * 2;
    if (p[2] == 1 && p[13] == 0) p[13] = 2;
    if (p[4] > 0) p[6] = _ffix(_fadd(0.5f, _fflt(p[4] << 12)));
    else p[6] = _ffix(_fsub(_fflt(p[4] << 12), 0.5f));
    if (p[9] > 0) f = _fadd(0.5f, _fflt(p[9] << 12));
    else f = _fsub(_fflt(p[9] << 12), 0.5f);
    diff = p[5] - p[4];
    if (diff > 0) g = _fadd(0.5f, _fflt(diff << 12));
    else g = _fsub(_fflt(diff << 12), 0.5f);
    x = _ffix(g);
    y = _ffix(f);
    p[7] = func_0207C768(x, y);
    func_021F896C(func_02030DA8(((struct Obj07880 *)s)->f8, func_021FE594, p, 0), func_021FE690, 1);
    ((struct Obj07880 *)s)->f0 |= 8;
    return ((struct Obj07880 *)s)->f23C;
}


int func_021FBC78(struct Cursor *a, State_021FBC78 *s)
{
    int v0 = func_0201134C(a);
    int v1 = func_0201134C(a);
    int v2 = func_0201134C(a);
    int v3 = func_0201134C(a);
    int v4 = func_0201134C(a);
    int v5 = func_0201134C(a);
    int v6 = func_0201134C(a);
    int v7 = func_0201134C(a);
    int v8 = func_0201134C(a);

    func_021F9948((void *)a, v0, v1, v2, v3, v4, v5, v6, v7, v8);
    return s->f23c;
}


/*
 * Script command: stores one argument at 0x240, waits on func_021FC744, and suspends.
 */
int func_021FBCEC(void *a, char *s)
{
    ((struct Obj13592 *)s)->f240 = func_0201134C(a);
    func_020113D0(a, (int)func_021FC744);
    ((struct Obj13592 *)s)->f23C = 1;
    return 1;
}


/*
 * Script command: stores one argument at 0x1e4, waits on func_021FC9D0, and suspends.
 */
int func_021FBD10(void *a, char *s)
{
    ((struct Obj13593 *)s)->f1E4 = func_0201134C(a);
    func_020113D0(a, (int)func_021FC9D0);
    ((struct Obj13593 *)s)->f23C = 1;
    return 1;
}
