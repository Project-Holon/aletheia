/*
 * file:     unit_0219B508_p15.c
 * unit:     yes
 * function: func_0219C180, func_0219C20C, func_0219C298, func_0219C2BC, func_0219C2E0, func_0219C314, func_0219C338
 * address:  0x0219C180
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
 *   func_02163E34  0x02163E34  thumb  ov010
 *   func_021AB11C  0x021AB11C  thumb  ov021
 *   d_021D53B4  0x021D53B4  data  a4
 *   d_021D53D4  0x021D53D4  data  a4
 *   d_021D5414  0x021D5414  data  a4
 *   d_021D5434  0x021D5434  data  a4
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   d_021D53F4  0x021D53F4  data  a4
 *   func_021639C0  0x021639C0  thumb  ov010
 *   d_021D5384     0x021D5384  data   a4
 *   d_021D5454     0x021D5454  data   ov021  a4
 *   func_0216D608  0x0216D608  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D438  0x0216D438  thumb  ov010
 *   func_0216DA44  0x0216DA44  thumb
 *   func_021642A4  0x021642A4  thumb  ov010
 */
struct Actor;
struct VecFx32;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { int x, y, z; } Vec;

extern int func_02163E34(u32, Vec *, u32 *);
extern int func_021AB11C(u32 attr);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *v);
extern int func_021639C0(u32 a, u16 v);
extern u16 func_0216D608(void *p);
extern int func_02197E7C(int a, int b);
extern void func_0216D438(char *a0, int a1);
extern void func_0216DA44(int a);
extern u16 func_021642A4(int i);
int func_0219C180(u32 a, Vec *p, int b, int c);
int func_0219C20C(u32 a, Vec *p, int b, int c);
int func_0219C298(u32 a, int b, int c);
int func_0219C2BC(u32 a, int b, int c);
int func_0219C2E0(u32 a, int b, int c);
int func_0219C314(int a, int *s, u32 c);
int func_0219C338(char *a, u32 *s, u32 c);
extern int d_021D53B4[][2];
extern int d_021D53D4[][2];
extern int d_021D5414[][2];
extern int d_021D5434[][2];
extern int d_021D53F4[][2];
extern u32 d_021D5384[];
extern u32 d_021D5454[][2];


/*
 * r = 0 is the first statement: its early live range pushes a to a stack
 * spill and leaves ip for &t.
 */
int func_0219C180(u32 a, Vec *p, int b, int c)
{
    int r;
    s16 x;
    s16 z;
    Vec t;
    u32 out;

    r = 0;
    t = *p;
    x = (p->x >> 4) / 4096;
    z = (p->z >> 4) / 4096;
    x += (s16)d_021D53B4[b][c];
    z += (s16)d_021D53D4[b][c];
    t.x = x << 16;
    t.z = z << 16;
    if (func_02163E34(a, &t, &out) == 1 && func_021AB11C(out) != 0) {
        r = 1;
    }
    return r;
}


int func_0219C20C(u32 a, Vec *p, int b, int c)
{
    int r;
    s16 x;
    s16 z;
    Vec t;
    u32 out;

    r = 0;
    t = *p;
    x = (p->x >> 4) / 4096;
    z = (p->z >> 4) / 4096;
    x += (s16)d_021D5414[b][c];
    z += (s16)d_021D5434[b][c];
    t.x = x << 16;
    t.z = z << 16;
    if (func_02163E34(a, &t, &out) == 1 && func_021AB11C(out) != 0) {
        r = 1;
    }
    return r;
}


int func_0219C298(u32 a, int b, int c)
{
    Vec v;
    func_0216D88C((const struct Actor *)a, (struct VecFx32 *)&v);
    return func_0219C180(a, &v, b, c);
}


int func_0219C2BC(u32 a, int b, int c)
{
    Vec v;
    func_0216D88C((const struct Actor *)a, (struct VecFx32 *)&v);
    return func_0219C20C(a, &v, b, c);
}


int func_0219C2E0(u32 a, int b, int c)
{
    if (func_0219C298(a, b, c) == 0) {
        if (func_0219C2BC(a, b, c) == 0) {
            return 9;
        }
        b = d_021D53F4[b][c];
    }
    return b;
}


int func_0219C314(int a, int *s, u32 c)
{
    int v = func_0219C2E0(a, *s, c);
    *s = v;
    if (v != 9) {
        return func_021639C0(a, v);
    }
    return 0;
}


int func_0219C338(char *a, u32 *s, u32 c)
{
    u32 t;
    u32 k;
    u32 v;
    int r;

    k = s[2];
    t = func_0216D608((void *)a);
    r = func_0219C314((int)a, (int *)(&t), k);
    if (t == 9) {
        t = func_0216D608((void *)a);
        func_0216D438(a, (u16)((u32)func_02197E7C((u16)t, (u16)0x1c)));
        return 0;
    }
    if (r == 0) {
        v = (u32)func_02197E7C((u16)t, (u16)c);
        func_0216DA44((int)a);
        func_0216D438(a, (u16)v);
        return 1;
    }
    if ((1 & r) && s[1] == 2) {
        t = func_021642A4(func_0216D608((void *)a));
        k = d_021D5384[k];
        s[2] = k;
        r = func_0219C314((int)a, (int *)(&t), k);
        if (t == 9) {
            t = func_0216D608((void *)a);
            func_0216D438(a, (u16)((u32)func_02197E7C((u16)t, (u16)0x1c)));
            return 0;
        }
        if (r == 0) {
            v = (u32)func_02197E7C((u16)t, (u16)c);
            func_0216DA44((int)a);
            func_0216D438(a, (u16)v);
            return 1;
        }
    }
    if (r & 2) {
        t = d_021D5454[t][k];
        r = func_0219C314((int)a, (int *)(&t), k);
        if (t == 9) {
            t = func_0216D608((void *)a);
            func_0216D438(a, (u16)((u32)func_02197E7C((u16)t, (u16)0x1c)));
            return 0;
        }
        if (r == 0) {
            v = (u32)func_02197E7C((u16)t, (u16)c);
            func_0216DA44((int)a);
            func_0216D438(a, (u16)v);
            return 1;
        }
    }
    t = func_0216D608((void *)a);
    func_0216D438(a, (u16)((u32)func_02197E7C((u16)t, (u16)0x1c)));
    return 0;
}
