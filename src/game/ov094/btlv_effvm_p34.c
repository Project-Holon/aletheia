/*
 * file:     btlv_effvm_p34.c
 * unit:     yes
 * function: func_021FA09C, func_021FA108, func_021FA12C, func_021FA288, func_021FA358, func_021FA458, func_021FA5D0
 * address:  0x021FA09C
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
 *   func_0201134C  0x0201134C  thumb
 *   func_021FCA04  0x021FCA04  thumb  ov094
 *   func_021F8694  0x021F8694  thumb  ov094
 *   func_021FDB20  0x021FDB20  thumb  ov094
 *   func_021FF228  0x021FF228  thumb  ov094
 *   func_021FF1F4  0x021FF1F4  thumb  ov094
 *   func_021F8684 0x021F8684 thumb ov094
 *   func_021F70F0 0x021F70F0 thumb ov094
 *   func_020113D0 0x020113D0 thumb
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0205121C 0x0205121C arm
 *   func_02050C30 0x02050C30 arm
 *   func_02051380 0x02051380 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021FE38C 0x021FE38C thumb ov094
 *   func_021FD15C 0x021FD15C thumb ov094
 *   func_021FD19C 0x021FD19C thumb ov094
 *   func_021F896C 0x021F896C thumb ov094
 *   func_021FE9BC 0x021FE9BC thumb ov094
 *   func_021FC9F4 0x021FC9F4 thumb ov094
 *   d_0220AE68 0x0220AE68 data ov094 a1
 *   func_021FD1A8 0x021FD1A8 thumb ov094
 *   func_021FDD60 0x021FDD60 thumb ov094
 *   func_020515CC 0x020515CC arm
 *   func_021FD1CC 0x021FD1CC thumb ov094
 *   func_02051648 0x02051648 arm
 *   func_02051788 0x02051788 arm
 *   d_02209E1C 0x02209E1C data a4
 *   d_02209D90 0x02209D90 data a4
 *   func_021FD1C0 0x021FD1C0 thumb ov094
 *   d_02209D78 0x02209D78 data a4
 *   d_02209E04 0x02209E04 data a4
 */
#include "../../matched/include/Obj12208.h"
#include "../../matched/include/Obj00325.h"

struct Cursor;
struct Dst648;
struct Src648;
typedef struct {
    char pad[0x23C];
    int f23c;
    char pad2[4];
    int f244;
} State;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef struct { char *state; void *emitter; void *resource; } Callback;

typedef struct { int x, y, z; } Vec;

typedef struct { u32 v[8]; } Desc;

extern u32 func_0201134C(struct Cursor *p);
extern int func_021FCA04(State *s, int id, int *out);
extern int func_021F8694(void);
extern void func_021FDB20(State *s);
extern void func_021FF228(void *w, int a);
extern void func_021FF1F4(void *w, int a);
extern int  func_021F8684(void);
extern void func_021F70F0(void **p, void *b, int c);
extern void func_020113D0(char *p, int val);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern u32 func_020307B0(void *p);
extern int func_0205121C(u32 a, u32 b, u32 c);
extern void *func_02050C30(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 heap);
extern void func_02051380(void *, void *);
extern void *func_020056A0(void (*)(void), void *, int);
extern unsigned int func_021FE38C(char *, unsigned int);
extern int func_021FD15C(char *, unsigned int, int *);
extern void func_021FD19C(char *p, int i, char *q);
extern void func_021F896C(void *h, void (*cb)(void *), int arg);
extern void func_021FE9BC(void);
extern void func_021FC9F4(void);
extern int func_021FD1A8(char *p, int v);
extern void func_021FDD60(char *, int *, int, int);
extern int func_020515CC(int *p, int a, int b, int c);
extern void func_021FD1CC(void *p);
extern void func_02051648(struct Dst648 *this, struct Src648 *src, u16 a2, int *a3, int *a4, int *a5, u32 a6);
extern int func_02051788(char *p);
extern int func_021FD1C0(char *, int);
int func_021FA09C(void *a, State *s);
int func_021FA108(int a, char *b);
int func_021FA12C(void *a, char *s);
int func_021FA288(void *a, char *s);
int func_021FA358(void *a, char *s);
int func_021FA458(void *a, char *s);
int func_021FA5D0(void *a, char *s);
extern char d_0220AE68[];
extern const Vec d_02209E1C, d_02209D90;
extern const Vec d_02209D78, d_02209E04;


int func_021FA09C(void *a, State *s)
{
    int buf[8];
    int x;
    int n;
    int i;

    x = func_0201134C(a);
    if (func_0201134C(a) == 0) {
        s->f244 = x;
        func_021FDB20(s);
    } else {
        n = func_021FCA04(s, 14, buf);
        if (n != 0) {
            for (i = 0; i < n; i++) {
                if (x == 1)
                    func_021FF228((void *)func_021F8694(), buf[i]);
                else
                    func_021FF1F4((void *)func_021F8694(), buf[i]);
            }
        }
    }
    return s->f23c;
}


/*
 * lane O10 candidate
 */
int func_021FA108(int a, char *b)
{
    ((struct Obj12208 *)b)->f284 = 1;
    func_021F70F0((void **)func_021F8684(), b + 0x288, (int)(b + 0x294));
    return ((struct Obj12208 *)b)->f23C;
}


/*
 * witness: arm9 func_02051380 filed as src/matched/arm9/func_02051380.c.
 * witness: func_021FC9F4 filed as src/matched/ov/ov094_func_021FC9F4.c.
 */
int func_021FA12C(void *a, char *s)
{
    int slot;
    int key;
    void *buffer;
    void *resource;
    Callback *cb;
    int line;

    key = func_021FE38C(s, func_0201134C(a));
    if (func_021FD15C(s, key, &slot) == 1) {
        line = 0x715;
        buffer = func_02030734((u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000), 0x4800, 0, d_0220AE68, line);
        resource = (void *)func_0205121C(6, key, (u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000));
        if (buffer != 0 && resource != 0) {
            *(void **)(s + 12 + slot * 4) = func_02050C30((u32)buffer, 0x4800, 0, 5, 6, 0x36, (u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000));
            if (*(void **)(s + 12 + slot * 4) != 0) {
                func_02051380(*(void **)(s + 12 + slot * 4), resource);
                line += 10;
                cb = func_02030734((u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000), 12, 0, d_0220AE68, line);
                cb->state = s;
                cb->emitter = *(void **)(s + 12 + slot * 4);
                cb->resource = resource;
                ((struct Obj00325 *)s)->f0 |= 0x10000;
                func_021F896C(func_020056A0(func_021FE9BC, cb, 0), 0, 1);
                func_020113D0(a, (int)func_021FC9F4);
                func_021FD19C(s, slot, resource);
            }
        }
        if (*(void **)(s + 12 + slot * 4) == 0) {
            if (buffer != 0)
                func_020307B0(buffer);
            if (resource != 0)
                func_020307B0(resource);
            *(int *)(s + 0x4c + slot * 4) = -1;
        }
    }
    return 1;
}


int func_021FA288(void *a, char *s)
{
    int *p;
    int slot;
    int arg;

    p = func_02030734((u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x74a);
    slot = func_021FD1A8(s, func_021FE38C(s, func_0201134C(a)));
    arg = func_0201134C(a);
    p[0] = (int)a;
    p[1] = func_0201134C(a);
    p[2] = func_0201134C(a);
    p[3] = 0;
    p[4] = func_0201134C(a);
    p[5] = 0;
    p[6] = func_0201134C(a);
    func_0201134C(a);
    p[17] = func_0201134C(a);
    p[18] = func_0201134C(a);
    p[19] = func_0201134C(a);
    p[20] = func_0201134C(a);
    if (p[2] == 8)
        p[2] = p[1];
    if (slot != 16)
        func_021FDD60(s, p, slot, arg);
    func_020307B0(p);
    return ((struct Obj00325 *)s)->f23C;
}


int func_021FA358(void *a, char *s)
{
    int *p;
    int slot;
    int arg;
    int result;

    p = func_02030734((u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x77d);
    slot = func_021FD1A8(s, func_021FE38C(s, func_0201134C(a)));
    arg = func_0201134C(a);
    p[0] = (int)a;
    p[1] = 8;
    p[2] = 8;
    p[10] = func_0201134C(a);
    p[11] = func_0201134C(a);
    p[12] = func_0201134C(a);
    p[13] = func_0201134C(a);
    p[14] = func_0201134C(a);
    p[15] = func_0201134C(a);
    p[3] = 0;
    p[4] = func_0201134C(a);
    p[5] = 0;
    p[6] = func_0201134C(a);
    func_0201134C(a);
    p[17] = func_0201134C(a);
    p[18] = func_0201134C(a);
    p[19] = func_0201134C(a);
    p[20] = func_0201134C(a);
    if (slot != 16) {
        result = func_020515CC(*(int **)(s + 12 + slot * 4), arg, (int)func_021FD1CC, (int)p);
        if (result == -1)
            func_020307B0(p);
    } else {
        func_020307B0(p);
    }
    return ((struct Obj00325 *)s)->f23C;
}


/*
 * witness: arm9 func_02051788 filed as src/matched/arm9/func_02051788.c.
 */
int func_021FA458(void *a, char *s)
{
    Desc desc;
    int *p;
    int slot;
    int arg;

    p = func_02030734((u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x7b6);
    slot = func_021FD1A8(s, func_021FE38C(s, func_0201134C(a)));
    arg = func_0201134C(a);
    p[0] = (int)a;
    p[1] = func_0201134C(a);
    p[2] = func_0201134C(a);
    p[3] = func_0201134C(a);
    p[4] = func_0201134C(a);
    p[5] = func_0201134C(a);
    p[17] = func_0201134C(a);
    p[18] = func_0201134C(a);
    p[19] = func_0201134C(a);
    p[20] = func_0201134C(a);
    p[16] = 1;
    if (p[1] == 13) {
        p[1] = 9;
        p[16] = 2;
    }
    if (p[2] == 8)
        p[2] = p[1];
    if (slot != 16) {
        Vec zero = {0, 0, 0};
        Vec v1;
        Vec v2;
        v1 = d_02209E1C;
        v2 = d_02209D90;
        desc.v[0] = 2;
        desc.v[1] = 0x3000;
        desc.v[2] = 0xffffd000;
        desc.v[3] = 0xffffc000;
        desc.v[4] = 0x4000;
        desc.v[5] = 0x1000;
        desc.v[6] = 0x200000;
        desc.v[7] = 0x1000;
        if (func_02051788(*(void **)(s + 12 + slot * 4)) == 0)
            func_02051648(*(void **)(s + 12 + slot * 4), (struct Src648 *)(&desc), 0x2000, (int *)(&zero), (int *)(&v1), (int *)(&v2), (u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000));
        func_021FDD60(s, p, slot, arg);
    }
    func_020307B0(p);
    return ((struct Obj00325 *)s)->f23C;
}


int func_021FA5D0(void *a, char *s)
{
    Desc desc;
    int *p;
    int slot;
    int count;
    int arg;
    int i;

    p = func_02030734((u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x7ff);
    slot = func_021FD1A8(s, func_021FE38C(s, func_0201134C(a)));
    count = func_021FD1C0(s, slot);
    p[0] = (int)a;
    p[1] = func_0201134C(a);
    p[2] = func_0201134C(a);
    p[3] = 0;
    p[4] = func_0201134C(a);
    p[5] = 0;
    p[6] = func_0201134C(a);
    arg = func_0201134C(a);
    p[17] = func_0201134C(a);
    p[18] = func_0201134C(a);
    p[19] = func_0201134C(a);
    p[20] = func_0201134C(a);
    if (slot != 16) {
        if (arg != 0) {
            Vec zero = {0, 0, 0};
            Vec v1;
            Vec v2;
            v1 = d_02209D78;
            v2 = d_02209E04;
            desc.v[0] = 2;
            desc.v[1] = 0x3000;
            desc.v[2] = 0xffffd000;
            desc.v[3] = 0xffffc000;
            desc.v[4] = 0x4000;
            desc.v[5] = 0x1000;
            desc.v[6] = 0x200000;
            desc.v[7] = 0x1000;
            if (func_02051788(*(void **)(s + 12 + slot * 4)) == 0)
                func_02051648(*(void **)(s + 12 + slot * 4), (struct Src648 *)(&desc), 0x2000, (int *)(&zero), (int *)(&v1), (int *)(&v2), (u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000));
            p[16] = 2;
        }
        if (p[2] == 8)
            p[2] = p[1];
        for (i = 0; i < count; i++)
            func_021FDD60(s, p, slot, i);
    }
    func_020307B0(p);
    return ((struct Obj00325 *)s)->f23C;
}
