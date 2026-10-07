/*
 * file:     ui_scene_p15.c
 * unit:     yes
 * function: func_021B8FE4, func_021B90B8, func_021B9138, func_021B9190
 * address:  0x021B8FE4
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
 *   func_0202CF8C  0x0202CF8C  thumb
 *   func_021B8FA0  0x021B8FA0  thumb  ov067
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
 */
struct WinMgr;
struct Bmp;
struct Descriptor;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Ent {
    u32 f0;
    u32 f4;
};

struct S_021B8FE4 {
    u8 _0[4];
    u8 f4;
    u8 _5[0x28 - 5];
    struct Ent *f28;
    u8 _2c[0x38 - 0x2c];
    struct Ent *f38;
    void *f3c;
    u16 **f40;
};

typedef signed char s8;

struct S_021B90B8 {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    u8 f4;
    u8 f5;
    u8 _6[0x3c - 6];
    void *f3c;
};

struct S_021B9138 {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    u8 f4;
    u8 f5;
};

extern u8 func_0202CF8C(struct WinMgr *mgr, u32 idx);
extern int func_021B8FA0(int x);
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
void func_021B8FE4(struct S_021B8FE4 *s, u32 a1, u32 a2);
void func_021B90B8(struct S_021B90B8 *p, int a1, s8 a2);
void func_021B9138(struct S_021B9138 *p, u32 a1, s8 a2);
signed char func_021B9190(const signed char *p, int step);


void func_021B8FE4(struct S_021B8FE4 *s, u32 a1, u32 a2)
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

    res = (void *)s->f38[a2].f0;
    map = s->f40[s->f28[a1].f0];
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


void func_021B90B8(struct S_021B90B8 *p, int a1, s8 a2)
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


void func_021B9138(struct S_021B9138 *p, u32 a1, s8 a2)
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
