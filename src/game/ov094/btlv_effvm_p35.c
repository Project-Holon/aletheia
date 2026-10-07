/*
 * file:     btlv_effvm_p35.c
 * unit:     yes
 * function: func_021FA758, func_021FA794, func_021FA884, func_021FA988, func_021FAB0C, func_021FAC94, func_021FACA0, func_021FACAC
 * address:  0x021FA758
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
 *   func_021FE38C 0x021FE38C thumb ov094
 *   func_021FD1A8 0x021FD1A8 thumb ov094
 *   func_021FDB08 0x021FDB08 thumb ov094
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   func_020515CC 0x020515CC arm
 *   func_021FD1CC 0x021FD1CC thumb ov094
 *   d_0220AE68 0x0220AE68 data ov094 a1
 *   func_02051648 0x02051648 arm
 *   func_02051788 0x02051788 arm
 *   d_02209DC0 0x02209DC0 data ov094 a4
 *   d_02209D84 0x02209D84 data ov094 a4
 *   d_02209DA8 0x02209DA8 data ov094 a4
 *   d_02209D9C 0x02209D9C data ov094 a4
 *   func_021FDFA0 0x021FDFA0 thumb ov094
 *   func_021FCA04  0x021FCA04  thumb  ov094
 *   func_021F8694  0x021F8694  thumb  ov094
 *   func_021FF4C0  0x021FF4C0  thumb  ov094
 */
#include "../../matched/include/Obj00325.h"

struct Cursor;
typedef unsigned int   u32;

typedef unsigned short u16;

typedef struct { int x, y, z; } Vec;

typedef struct { u32 v[8]; } Desc;

typedef struct {
    char pad[0x23C];
    int f23c;
} State;

extern u32 func_0201134C(struct Cursor *p);
extern unsigned int func_021FE38C(char *, unsigned int);
extern int func_021FD1A8(char *p, int v);
extern void func_021FDB08(void *);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern u32 func_020307B0(void *p);
extern int func_020515CC(int *p, int a, int b, int c);
extern void func_021FD1CC(void *p);
extern void func_02051648(void *, Desc *, u16, Vec *, Vec *, Vec *, u16);
extern int func_02051788(char *p);
extern int func_021FDFA0(void *a, char *s, int mode);
extern int func_021FCA04(State *s, int id, int *out);
extern int func_021F8694(void);
extern void func_021FF4C0(void *w, int a, int b, int *c, int d, int e, int f);
int func_021FA758(void *a, char *s);
int func_021FA794(void *a, char *s);
int func_021FA884(void *a, char *s);
int func_021FA988(void *a, char *s);
int func_021FAB0C(void *a, char *s);
void func_021FAC94(void *a, void *b);
void func_021FACA0(void *a, void *b);
int func_021FACAC(void *a, State *s);
extern char d_0220AE68[];
extern const Vec d_02209DC0, d_02209D84;
extern const Vec d_02209DA8, d_02209D9C;


int func_021FA758(void *a, char *s)
{
    int slot = func_021FD1A8(s, func_021FE38C(s, func_0201134C(a)));

    if (slot != 16) {
        void **e = (void **)(s + 0xc) + slot;
        func_021FDB08(*e);
        *e = 0;
        ((int *)(s + 0x4c))[slot] = -1;
    }
    return ((struct Obj00325 *)s)->f23C;
}


int func_021FA794(void *a, char *s)
{
    int *p;
    int slot;
    int arg;

    p = func_02030734((u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x868);
    slot = func_021FD1A8(s, func_021FE38C(s, func_0201134C(a)));
    arg = func_0201134C(a);
    p[0] = (int)a;
    p[8] = func_0201134C(a);
    p[1] = func_0201134C(a);
    p[2] = func_0201134C(a);
    p[3] = 0;
    p[4] = func_0201134C(a);
    p[5] = 0;
    p[9] = func_0201134C(a);
    p[7] = func_0201134C(a);
    p[17] = 0x1000;
    p[18] = func_0201134C(a);
    p[19] = 0x1000;
    p[20] = func_0201134C(a);
    p[21] = func_0201134C(a);
    if (p[21] == 0)
        p[21] = 1;
    if (slot != 16) {
        if (func_020515CC(*(int **)(s + 12 + slot * 4), arg, (int)func_021FD1CC, (int)p) == -1)
            func_020307B0(p);
    } else {
        func_020307B0(p);
    }
    return ((struct Obj00325 *)s)->f23C;
}

int func_021FA884(void *a, char *s)
{
    int *p;
    int idx;
    int x;
    p = func_02030734((u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x8a2);
    idx = func_021FD1A8(s, func_021FE38C(s, func_0201134C(a)));
    x = func_0201134C(a);
    p[0] = (int)a;
    p[8] = func_0201134C(a);
    p[1] = 8;
    p[10] = func_0201134C(a);
    p[11] = func_0201134C(a);
    p[12] = func_0201134C(a);
    p[2] = func_0201134C(a);
    p[3] = 0;
    p[4] = func_0201134C(a);
    p[5] = 0;
    p[9] = func_0201134C(a);
    p[7] = func_0201134C(a);
    p[17] = 0x1000;
    p[18] = func_0201134C(a);
    p[19] = 0x1000;
    p[20] = func_0201134C(a);
    p[21] = func_0201134C(a);
    if (p[21] == 0) p[21] = 1;
    if (idx != 16) {
        if (func_020515CC(*(int **)(s + 0xc + idx * 4), x, (int)func_021FD1CC, (int)p) == -1) {
            func_020307B0(p);
        }
    } else {
        func_020307B0(p);
    }
    return ((struct Obj00325 *)s)->f23C;
}

/*
 * witness: arm9 func_02051788 filed as src/matched/arm9/func_02051788.c.
 */
int func_021FA988(void *a, char *s)
{
    Desc desc;
    int *p;
    int idx;
    int x;
    p = func_02030734((u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x8e0);
    idx = func_021FD1A8(s, func_021FE38C(s, func_0201134C(a)));
    x = func_0201134C(a);
    p[0] = (int)a;
    p[8] = func_0201134C(a);
    p[1] = func_0201134C(a);
    p[2] = func_0201134C(a);
    p[3] = 0;
    p[4] = func_0201134C(a);
    p[5] = 0;
    p[9] = func_0201134C(a);
    p[7] = func_0201134C(a);
    p[17] = 0xc00;
    p[18] = func_0201134C(a);
    p[19] = 0xc00;
    p[20] = func_0201134C(a);
    p[21] = func_0201134C(a);
    p[16] = 3;
    if (p[21] == 0) p[21] = 1;
    if (idx != 16) {
        Vec zero = {0, 0, 0};
        Vec v1;
        Vec v2;
        v1 = d_02209DC0;
        v2 = d_02209D84;
        desc.v[0] = 2;
        desc.v[1] = 0x3000;
        desc.v[2] = 0xffffd000;
        desc.v[3] = 0xffffc000;
        desc.v[4] = 0x4000;
        desc.v[5] = 0x1000;
        desc.v[6] = 0x200000;
        desc.v[7] = 0x1000;
        if (func_02051788(*(void **)(s + 0xc + idx * 4)) == 0)
            func_02051648(*(void **)(s + 0xc + idx * 4), &desc, 0x2000, &zero, &v1, &v2, (((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000);
        if (func_020515CC(*(int **)(s + 0xc + idx * 4), x, (int)func_021FD1CC, (int)p) == -1) {
            func_020307B0(p);
        }
    } else {
        func_020307B0(p);
    }
    return ((struct Obj00325 *)s)->f23C;
}

/*
 * witness: arm9 func_02051788 filed as src/matched/arm9/func_02051788.c.
 * trailing: 021FAC94 and 021FACA0 are tail-call stubs; not filed while ARM9 blocks.
 */
int func_021FAB0C(void *a, char *s)
{
    Desc desc;
    int *p;
    int idx;
    int x;
    p = func_02030734((u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x92d);
    idx = func_021FD1A8(s, func_021FE38C(s, func_0201134C(a)));
    x = func_0201134C(a);
    p[0] = (int)a;
    p[8] = func_0201134C(a);
    p[1] = 8;
    p[10] = func_0201134C(a);
    p[11] = func_0201134C(a);
    p[12] = func_0201134C(a);
    p[2] = func_0201134C(a);
    p[3] = 0;
    p[4] = func_0201134C(a);
    p[5] = 0;
    p[9] = func_0201134C(a);
    p[7] = func_0201134C(a);
    p[17] = 0x1000;
    p[18] = func_0201134C(a);
    p[20] = func_0201134C(a);
    p[19] = func_0201134C(a);
    p[16] = 3;
    if (idx != 16) {
        Vec zero = {0, 0, 0};
        Vec v1;
        Vec v2;
        v1 = d_02209DA8;
        v2 = d_02209D9C;
        desc.v[0] = 2;
        desc.v[1] = 0x3000;
        desc.v[2] = 0xffffd000;
        desc.v[3] = 0xffffc000;
        desc.v[4] = 0x4000;
        desc.v[5] = 0x1000;
        desc.v[6] = 0x200000;
        desc.v[7] = 0x1000;
        if (func_02051788(*(void **)(s + 0xc + idx * 4)) == 0)
            func_02051648(*(void **)(s + 0xc + idx * 4), &desc, 0x2000, &zero, &v1, &v2, (((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000);
        if (func_020515CC(*(int **)(s + 0xc + idx * 4), x, (int)func_021FD1CC, (int)p) == -1) {
            func_020307B0(p);
        }
    } else {
        func_020307B0(p);
    }
    return ((struct Obj00325 *)s)->f23C;
}


/*
 * Tail call to func_021FDFA0 with mode 0.
 */
void func_021FAC94(void *a, void *b)
{
    func_021FDFA0(a, b, 0);
}


/*
 * Tail call to func_021FDFA0 with mode 1.
 */
void func_021FACA0(void *a, void *b)
{
    func_021FDFA0(a, b, 1);
}


int func_021FACAC(void *a, State *s)
{
    int buf[8];
    int t[3];
    int n;
    int x;
    int r;
    int u;
    int v;
    int i;

    n = func_021FCA04(s, func_0201134C(a), buf);
    x = func_0201134C(a);
    t[0] = func_0201134C(a);
    t[1] = func_0201134C(a);
    i = 0;
    t[2] = 0;
    r = func_0201134C(a);
    u = func_0201134C(a);
    v = func_0201134C(a);
    if (n != 0) {
        for (; i < n; i++)
            func_021FF4C0((void *)func_021F8694(), buf[i], x, t, r, u, v);
    }
    return s->f23c;
}
