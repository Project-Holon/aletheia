/*
 * function: func_021F36FC
 * address: 0x021F36FC
 * packet: pkt_ov039_021F36FC
 * region: ov039
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov039/unit_021F36C0.c and filed here.
 *
 * symbols:
 *   func_02188C84 0x02188C84 thumb ov021
 *   func_02189764 0x02189764 thumb ov021
 *   func_021BE760 0x021BE760 thumb ov021
 *   func_021BE480 0x021BE480 thumb ov021
 *   func_021BE6B8 0x021BE6B8 thumb ov021
 *   func_02188D30 0x02188D30 thumb ov021
 *   func_02030DA8 0x02030DA8 arm
 *   d_021F4C18 0x021F4C18 data ov039 a4
 *   d_021F4D60 0x021F4D60 data ov039 a4
 *   d_021F4D0C 0x021F4D0C data ov039 a4
 *   d_021F4D6C 0x021F4D6C data ov039 a4
 *   d_021F4D18 0x021F4D18 data ov039 a4
 *   d_021F4D24 0x021F4D24 data ov039 a4
 *   d_021F4D3C 0x021F4D3C data ov039 a4
 *   d_021F4D00 0x021F4D00 data ov039 a4
 *   d_021F4CD0 0x021F4CD0 data ov039 a4
 *   d_021F4CDC 0x021F4CDC data ov039 a4
 *   d_021F4D30 0x021F4D30 data ov039 a4
 *   d_021F4D48 0x021F4D48 data ov039 a4
 *   d_021F4CE8 0x021F4CE8 data ov039 a4
 *   func_02188D2C 0x02188D2C thumb ov021
 *   func_021897BC 0x021897BC thumb
 *   func_02188C80 0x02188C80 thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_02012A30 0x02012A30 thumb
 *   func_021BE674 0x021BE674 thumb ov021
 *   func_021BE6B0 0x021BE6B0 thumb ov021
 *   func_02028A7C 0x02028A7C thumb
 *   func_02028B18 0x02028B18 thumb
 *   func_021BE700 0x021BE700 thumb ov021
 *   func_021BE6CC 0x021BE6CC thumb ov021
 *   func_021BE748 0x021BE748 thumb ov021
 *   func_021F3A34 0x021F3A34 thumb
 */

#include "../include/G_Vec.h"

struct Big;
struct Ctx;
struct SoundSys2;
struct Rec94;
struct BigObj;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int x, y, z;
} Vec;

typedef struct {
    void *task;
    u8 sel;
    s8 idx;
    u8 mode;
    s8 hold;
    int timer[4];
    u32 anim;
    u8 f1c[0x21E4 - 0x1C];
    int active;
    u8 req[4];
    u8 cur[4];
    s8 slot[4];
} Work;

typedef struct {
    int v[4];
    u8 flag[8];
} Save;

typedef signed int     s32;
extern int func_02188D2C(int *p);
extern Work *func_021897BC(void *p, int idx);
extern u32 func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern u32 func_02012A30(const struct BigObj *a);
extern void *func_021BE674(char *base, int i, u8 j, int k);
extern void func_021BE6B0(unsigned char *p, int v);
extern void func_02028A7C(struct SoundSys2 *s, u32 id);
extern void func_02028B18(struct SoundSys2 *s, u32 id, u32 who);
extern void func_021BE700(void *p, int i, int j, u8 k, int flag);
extern void func_021BE6CC(int a, int b, int c, int d, int e);
extern int func_021BE748(u32 a);
void func_021F3A34(int a0, void *a1);
extern u16 func_02188C84(void *p);
extern void *func_02189764(void *p, int id, int a, int b);
extern void func_021BE760(int h, const void *res, int c);
extern void *func_021BE480(int h, int i, int j);
extern void func_021BE6B8(void *p, int i);
extern void *func_02188D30(void *p);
extern void *func_02030DA8(void *mgr, void (*fn)(int, void *), void *work, u32 key);
extern const Vec d_021F4C18, d_021F4D60, d_021F4D0C, d_021F4D6C, d_021F4D18, d_021F4D24, d_021F4D3C, d_021F4D00, d_021F4CD0, d_021F4CDC, d_021F4D30, d_021F4D48, d_021F4CE8;

void func_021F36FC(void *a)
{
    int h;
    Work *w;
    u32 t;
    Save *q;
    int snd;
    u32 i;
    int n;
    int f, g;
    u8 *p;
    u8 x;
    u8 j;
    void *o;

    h = func_02188D2C(a);
    t = (u32)func_020120F4((const struct Ctx *)func_02188C80(a));
    q = (Save *)func_0200B3A4((struct Rec94 *)func_02012EC4((struct Big *)t), 2);
    snd = func_02012A30((const struct BigObj *)t);
    func_02189764(a, 1, func_02188C84(a), 0x21F4);
    func_021BE760(h, &d_021F4C18, 0);
    *(Vec *)func_021BE480(h, 0, 0) = d_021F4D60;
    *(Vec *)func_021BE480(h, 0, 1) = d_021F4D0C;
    *(Vec *)func_021BE480(h, 0, 2) = d_021F4D6C;
    *(Vec *)func_021BE480(h, 0, 3) = d_021F4D18;
    *(Vec *)func_021BE480(h, 0, 4) = d_021F4D24;
    *(Vec *)func_021BE480(h, 0, 5) = d_021F4D3C;
    *(Vec *)func_021BE480(h, 0, 6) = d_021F4D00;
    *(Vec *)func_021BE480(h, 0, 7) = d_021F4CD0;
    *(Vec *)func_021BE480(h, 0, 8) = d_021F4CDC;
    *(Vec *)func_021BE480(h, 0, 9) = d_021F4D30;
    *(Vec *)func_021BE480(h, 0, 10) = d_021F4D48;
    *(Vec *)func_021BE480(h, 0, 11) = d_021F4CE8;
    for (i = 0; i < 4; i = (u8)(i + 1)) {
        j = i;
        p = (u8 *)q + i;
        x = p[0x10] ? i * 2 + 2 : i * 2 + 1;
        func_021BE700((void *)h, 0, j, x, 1);
        func_021BE700((void *)h, 0, j, 0, 1);
        o = func_021BE674((char *)h, 0, j, 0);
        func_021BE6B0(o, 1);
        func_021BE6B8(o, 0);
        func_021BE6CC(h, 0, j, x, q->v[i]);
        j = i + 4;
        f = p[0x10];
        func_021BE700((void *)h, 0, j, f, 1);
        func_021BE6B8(func_021BE674((char *)h, 0, j, 0), 0);
        func_021BE6B8(func_021BE674((char *)h, 0, j, 1), 0);
        func_021BE6CC(h, 0, j, f, func_021BE748((u32)func_021BE674((char *)h, 0, j, f)));
        g = p[0x10];
        j = i + 8;
        func_021BE700((void *)h, 0, j, g, 1);
        func_021BE6B8(func_021BE674((char *)h, 0, j, 0), 0);
        func_021BE6B8(func_021BE674((char *)h, 0, j, 1), 0);
        func_021BE6CC(h, 0, j, g, func_021BE748((u32)func_021BE674((char *)h, 0, j, g)));
    }
    w = func_021897BC(a, 1);
    w->task = func_02030DA8(func_02188D30(a), func_021F3A34, a, 0);
    for (n = 0; n < 4; n++) {
        w->req[n] = 0;
        w->cur[n] = n * 2 + q->flag[n];
        w->slot[n] = -1;
    }
    w->idx = -1;
    w->hold = -1;
    w->sel = 0xff;
    func_02028A7C((struct SoundSys2 *)snd, 0x68A);
    func_02028B18((struct SoundSys2 *)snd, 0x68A, 0);
}
