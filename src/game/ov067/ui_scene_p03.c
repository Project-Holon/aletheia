/*
 * file:     ui_scene_p03.c
 * unit:     yes
 * function: func_021B8DF0, func_021B8EA0, func_021B8FA0, func_021B8FE4, func_021B90B8, func_021B9138, func_021B9190, func_021B91BC, func_021B91D0, func_021B9228, func_021B9280, func_021B92F0, func_021B9344, func_021B9394, func_021B9398, func_021B93A4, func_021B93B0, func_021B93B8, func_021B93C0, func_021B93D4, func_021B940C, func_021B941C
 * address:  0x021B8DF0
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B841C  0x021B841C  thumb
 *   func_021B8434  0x021B8434  thumb
 *   d_021B94F8     0x021B94F8  data   ov067  a1
 *   d_021B94FE     0x021B94FE  data   ov067  a1
 *   func_0202CF8C  0x0202CF8C  thumb
 *   func_02051B0C  0x02051B0C  arm
 *   func_0202CAC4  0x0202CAC4  thumb
 *   func_0202CEBC  0x0202CEBC  thumb
 *   func_02045748  0x02045748  arm
 *   func_02045750  0x02045750  arm
 *   func_02045758  0x02045758  arm
 *   func_02045760  0x02045760  arm
 *   func_02045770  0x02045770  arm
 *   func_020437D4  0x020437D4  arm
 *   func_02082A90  0x02082A90  arm
 *   func_0202CF84  0x0202CF84  thumb
 *   func_020410D0  0x020410D0  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_02041300  0x02041300  arm
 *   func_020413B0  0x020413B0  arm
 *   func_020355C4  0x020355C4  arm
 *   func_0202EB04  0x0202EB04  thumb
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

struct WinMgr;
struct Bmp;
struct Descriptor;
struct CodeIn;
struct PrintSys;

struct Ops {
    void (*fn)(void *a, int b, u8 *c, s16 d, int e);
    void (*f4)(void *obj, int pos, int flag);
};

struct Pair {
    u32 a;
    u32 b;
};

struct Elem {
    void *p;
    u8 flag;
    u8 pad[3];
};

struct Scene {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    u8 f4;
    u8 f5;
    u8 _6[0xb - 6];
    s8 fb[6];
    u8 f11;
    u8 _12[0x20 - 0x12];
    struct Ops *f20;
    void *f24;
    struct Pair *f28;
    u8 _2c[0x30 - 0x2c];
    void *f30;
    int f34;
    struct Elem *f38;
    void *f3c;
    u16 **f40;
    u8 count;
    u8 f45;
    s8 f46;
    s8 f47;
    u8 _48[0x4c - 0x48];
    u16 f4c;
    u8 _4e[0x5c - 0x4e];
    s16 f5c;
    u16 f5e;
    s16 f60;
    s16 f62;
    u16 f64;
    s8 f66;
    u8 _67[0x70 - 0x67];
    u32 f70;
    u8 _74[0x85 - 0x74];
    s8 f85;
    u8 f86 : 5;
    u8 f86_5 : 3;
    u8 f87;
    u8 _88;
    u8 f89;
    u8 _8a[0x8c - 0x8a];
    u32 f8c;
    u32 f90;
};

extern int func_021B841C(u8 *p, int n);
extern void func_021B8434(u8 *p, s8 a, u8 b, u16 c, u32 d);
extern u8 func_0202CF8C(struct WinMgr *mgr, u32 idx);
extern int func_02051B0C(int i);
extern void func_0202CAC4(struct WinMgr *mgr, u32 idx, const void *src);
extern void func_0202CEBC(struct WinMgr *mgr, u32 idx, void *a);
extern u8 func_02045748(struct Descriptor *p);
extern u8 func_02045750(struct Descriptor *p);
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern void *func_02045770(struct Descriptor *p);
extern void *func_020437D4(const struct Bmp *bmp);
extern void func_02082A90(const void *src, void *dst, u32 size);
extern u32 func_0202CF84(struct WinMgr *mgr, u32 idx);
extern void func_020410D0(u8 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5,
                          u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_02041B6C(u32 bit);
extern void func_02041300(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
int func_021B8DF0(struct Scene *s, int a1);
int func_021B8EA0(struct Scene *s);
int func_021B8FA0(int x);
void func_021B8FE4(struct Scene *s, u32 a1, u32 a2);
void func_021B90B8(struct Scene *p, int a1, s8 a2);
void func_021B9138(struct Scene *p, u32 a1, s8 a2);
signed char func_021B9190(const signed char *p, int step);
signed char func_021B91BC(signed char a, signed char limit, int step);
extern const u8 d_021B94F8[6];
extern const u8 d_021B94FE[][6];
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern u8 func_020355C4(void);
extern void func_0202EB04(struct CodeIn *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *d);
void func_021B91D0(struct Scene *p, int i, s8 a2);
void func_021B9228(struct Scene *p, int i, s8 a2);
void func_021B9280(struct Scene *s, int a, u32 b);
void func_021B92F0(struct Scene *p, u32 a1, u32 a2);
void func_021B9344(struct Scene *s);
unsigned func_021B9394(struct Scene *p);
u32 func_021B9398(struct Scene *p, int index);
int func_021B93A4(struct Scene *p);
int func_021B93B0(struct Scene *p);
int func_021B93B8(struct Scene *p);
int func_021B93C0(struct Scene *p);
void func_021B93D4(struct Scene *s, int v);
void func_021B940C(struct Scene *s);
void func_021B941C(struct Scene *s);


/*
 * Note: the second parameter of func_021B8434 is declared int here (its own
 * file has u8): the original passes the muls result untruncated.
 */
int func_021B8DF0(struct Scene *s, int a1)
{
    int d;
    s8 v;
    u32 lim;

    d = s->f87 - a1;
    if ((d < 0 && s->f85 > 0) || (d > 0 && s->f85 < 0))
        return 0;
    if ((s->f85 < 0 && s->f62 == 0) || (s->f85 > 0 && s->f62 == s->f64))
        return 0;
    if (d < 0)
        d = -d;
    if (d == 0)
        return 0;
    if (d == 1)
        v = s->fb[3];
    else if (d == 2)
        v = s->fb[2];
    else if (d == 3)
        v = s->fb[1];
    else
        v = s->fb[0];
    if (a1 > s->f87)
        v *= -1;
    lim = func_021B841C((u8 *)s, v);
    if (lim != 0) {
        if (lim < d)
            d = lim;
        func_021B8434((u8 *)s, v, d, 3, 1);
        s->f87 = a1;
        return 1;
    }
    return 0;
}





/*
 * pass 2 2026-10-06 P2L28: EXACT (was DIFF 14/256 in X8 and G4L7). The fix is the callee
 *   declaration that the matched ov067 callers 021B8B74 and 021B806C use: func_021B8434 takes
 *   `s8 a`, and v is an s8 local. With `int a` the 1 for the stack argument was placed after
 *   the u8 narrowing of d; with s8 it is stored first, as in the image. EXACT in c99 and c.
 */
int func_021B8EA0(struct Scene *s)
{
    u32 d;
    s8 v;
    int lim;

    if ((s->f85 < 0 && s->f90 > s->f8c) || (s->f85 > 0 && s->f90 < s->f8c))
        return 0;
    d = s->f90 - s->f8c;
    if ((int)d < 0)
        d = -d;
    if (d == 0)
        return 0;
    for (s->f89 = 0; s->f89 < 6; s->f89++) {
        if (d >= d_021B94FE[s->f86][s->f89]) {
            v = s->fb[s->f89];
            d = d_021B94F8[s->f89];
            break;
        }
    }
    if (s->f89 == 6)
        return 0;
    if (s->f8c > s->f90)
        v *= -1;
    lim = func_021B841C((u8 *)s, v);
    if (lim != 0) {
        if (lim < d)
            d = lim;
        func_021B8434((u8 *)s, v, d, 3, 1);
        s->f70 = 1;
        return 1;
    }
    return 0;
}




int func_021B8FA0(int x)
{
    if (x == 0)
        return 0;
    if (x == 1)
        return 1;
    if (x == 2)
        return 2;
    if (x == 3)
        return 3;
    if (x == 4)
        return 4;
    if (x == 5)
        return 5;
    if (x == 6)
        return 6;
    if (x == 7)
        return 7;
    return 0;
}





void func_021B8FE4(struct Scene *s, u32 a1, u32 a2)
{
    u8 *gfx;
    int vram;
    void *res;
    u16 *map;
    u8 stride;
    u8 w;
    u8 h;
    u8 x0;
    u8 y0;
    u8 i;
    u8 j;

    res = s->f38[a2].p;
    map = s->f40[s->f28[a1].a];
    vram = func_02051B0C(func_021B8FA0(func_0202CF8C(s->f3c, a2)));
    func_0202CAC4(s->f3c, a2, map);
    func_0202CEBC(s->f3c, a2, res);
    stride = s->f4;
    w = func_02045748(res);
    h = func_02045750(res);
    x0 = func_02045758(res);
    y0 = func_02045760(res);
    gfx = func_020437D4(func_02045770(res));
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            func_02082A90((u8 *)vram + (map[x0 + j + (i + y0) * stride] & 0x3ff) * 32,
                          gfx + (j + i * w) * 32, 0x20);
        }
    }
}





void func_021B90B8(struct Scene *p, int a1, s8 a2)
{
    u32 t;
    u32 id;
    u16 j;

    t = func_0202CF84(p->f3c, a1);
    id = func_0202CF8C(p->f3c, a1);
    for (j = 0; j < p->f5; j++) {
        if (a2 < 0)
            a2 += 0x20;
        else if (a2 >= 0x20)
            a2 -= 0x20;
        func_020410D0(id, p->f2, (u8)a2, p->f4, 1, t, 0, j, p->f4, p->f5);
        a2++;
    }
    func_02041B6C((u8)id);
}





void func_021B9138(struct Scene *p, u32 a1, s8 a2)
{
    u32 j;

    for (j = 0; j < p->f5; j++) {
        if (a2 < 0)
            a2 += 0x20;
        else if (a2 >= 0x20)
            a2 -= 0x20;
        func_02041300(a1, 0, p->f2, (u8)a2, p->f4, 1, 0);
        a2++;
    }
    func_02041B6C(a1);
}




signed char func_021B9190(const signed char *p, int step)
{
    signed char value, delta;
    value = p[3];
    delta = (unsigned int)(unsigned char)p[5] * (unsigned int)step;
    do { value += delta; } while (value >= 0 && value < 24);
    return value + p[0x66] / 8;
}


signed char func_021B91BC(signed char a, signed char limit, int step)
{
    a = (signed char)((unsigned int)a + (unsigned int)step);
    if (a < 0) return limit;
    if (a > limit) return 0;
    return a;
}

void func_021B91D0(struct Scene *p, int i, s8 a2)
{
    if (i >= 0 && i < p->f4c) {
        func_021B8FE4(p, i, p->f46);
        func_021B90B8(p, p->f46, a2);
        p->f20->fn(p->f24, i, (u8 *)p->f38 + p->f46 * 8, a2 * 8 - p->f66, 1);
    } else {
        func_021B9138(p, p->f0, a2);
    }
}



void func_021B9228(struct Scene *p, int i, s8 a2)
{
    int k;

    if (p->f1 != 0xff) {
        if (i >= 0) {
            k = p->f47 + p->f45;
            func_021B8FE4(p, i, k);
            func_021B90B8(p, k, a2);
            p->f20->fn(p->f24, i, (u8 *)p->f38 + k * 8, a2 * 8 - p->f66, 0);
        } else {
            func_021B9138(p, p->f1, a2);
        }
    }
}


void func_021B9280(struct Scene *s, int a, u32 b)
{
    s16 pos = s->f66 / 8 + ((s8)s->f3 + a * s->f5);
    u16 i = 0;
    for (; i < s->f5; i++) {
        if (pos < 0) pos += 32;
        else if (pos >= 32) pos -= 32;
        func_020413B0(s->f0, s->f2, (u8)pos, s->f4, 1, (u8)b);
        pos++;
    }
    func_02041B6C(s->f0);
}



void func_021B92F0(struct Scene *p, u32 a1, u32 a2)
{
    if (a2 < p->f5e)
        func_021B9280(p, a2, (u16)(p->f40[p->f28[p->f62 + a2].a][0] >> 12));
    if (a1 < p->f5e && func_020355C4() == 0) {
        func_0202EB04(p->f30);
        func_021B9280(p, a1, p->f11);
    }
}



void func_021B9344(struct Scene *s)
{
    u32 i;

    func_0201C4E4((struct PrintSys *)s->f34);
    for (i = 0; i < s->count; i++) {
        struct Elem *e = &s->f38[i];
        int a = s->f34;

        if (e->flag != 0) {
            if (func_0201C6C4((struct PrintSys *)a, (void *)((int)func_02045770((struct Descriptor *)e->p))) == 0) {
                func_02045334((struct Descriptor *)e->p);
                e->flag = 0;
            }
        }
    }
}

/*
 * extent: four-byte getter; next leaf 021B9398 belongs to S27, not this file.
 */
unsigned func_021B9394(struct Scene *p)
{
    return p->f34;
}

/*
 * trailing: 2-byte alignment padding; separate existing functions follow
 */
u32 func_021B9398(struct Scene *p, int index)
{
    return p->f28[index].b;
}

/*
 * Caller ov209 021BCE98 reads the signed sum. ov067 is loaded by
 * ov209 021BCC94 and unloaded by 021BCD48. Following code starts at 021B93B0.
 */
int func_021B93A4(struct Scene *p)
{
    return p->f5c + p->f62;
}


/*
 * Unlabelled leaf in ov067, printed as a .word run; signed halfword getter.
 * Blocker target of ov210's func_021BF728 (pkt_021BF728), reached across the
 * ov210/ov067 overlay pair.
 */
int func_021B93B0(struct Scene *p)
{
    return p->f5c;
}


int func_021B93B8(struct Scene *p)
{
    return p->f62;
}


/*
 * Unlabelled leaf in ov067, printed as a .word run: true when the signed
 * halfword at +0x62 is below the unsigned halfword at +0x64.  Blocker target
 * of ov210's func_021BF728 (pkt_021BF728), across the ov210/ov067 pair.
 */
int func_021B93C0(struct Scene *p)
{
    return p->f62 < p->f64;
}


void func_021B93D4(struct Scene *s, int v)
{
    s->f60 = s->f5c;
    s->f5c = v;
    func_021B92F0(s, (u16)s->f5c, (u16)s->f60);
    s->f20->f4(s->f24, s->f5c + s->f62, 1);
}


void func_021B940C(struct Scene *s)
{
    func_021B92F0(s, (u16)s->f5c, (u16)0xff);
}


/*
 * The handed 460-byte extent is this 56-byte function, two unlabelled
 * 16-byte tail-call stubs into func_021B92F0 (0x021B940C, 0x021B941C), and
 * rodata from 0x021B942C on. tu reproduces 0x021B93D4..0x021B942C.
 */
void func_021B941C(struct Scene *s)
{
    func_021B92F0(s, (u16)0xff, (u16)s->f5c);
}
