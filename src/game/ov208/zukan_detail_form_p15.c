/*
 * file:     zukan_detail_form_p15.c
 * unit:     yes
 * function: func_021C7CE8, func_021C7D80, func_021C7E74, func_021C7EF8, func_021C7F6C, func_021C7FF8, func_021C80AC
 * address:  0x021C7CE8
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C51A0 0x021C51A0 thumb ov208
 *   func_021C51C8 0x021C51C8 thumb ov208
 *   ov208_func_021C569C 0x021C569C thumb ov208
 *   func_02014CEC 0x02014CEC thumb
 *   func_0204B688  0x0204B688  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_021BC518  0x021BC518  thumb
 *   data_021C87C0  0x021C87C0  data
 *   data_021C8854  0x021C8854  data
 *   _fgr      0x0209BBB0  arm
 *   _fmul     0x0209C77C  arm
 *   _fadd     0x0209C95C  arm
 *   _fsub     0x0209CB8C  arm
 *   _ffix     0x0209C494  arm
 *   func_021C7FF8 0x021C7FF8  thumb  ov208
 */
#include "../../matched/include/Obj00147.h"

#define W(o) (*(u32 *)(p + (o)))
#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? \
                                  ((x) * (1 << 12) + 0.5f) : \
                                  ((x) * (1 << 12) - 0.5f)))
struct Actor;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Ov208Tri {
    u32 a;
    u32 b;
    u32 c;
};

struct Ov208Unit {
    u32 f0;
    u32 *f4;
    struct Ov208Tri e[5];
};

struct Ov208Battle {
    u32 pad0[3];
    struct Ov208Unit u[4];
    u8 pad11c[0x54e - 0x11c];
    u16 h54e;
    u16 h550;
};

typedef struct {
    float x;
    float y;
    float z;
} VecF;

struct Ov208PoseEnt {
    u32 species;
    u32 form;
    u32 gender;
    u32 fc;
    u32 f10;
    u32 side;
    u32 f18;
    VecF pos[5];
};

typedef signed int fx32;

typedef struct {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct {
    float x;
    float y;
    float z;
} Ov208VecF;

struct Ov208Mdl {
    unsigned int obj;
    unsigned int f4;
    Ov208VecF pos[1];
};

extern void func_021C51A0(char *p, int a);
extern void func_021C51C8(u32, int, u8 *);
extern void ov208_func_021C569C(u16 *, u8 *, int, int, int, int, u16);
extern void func_02014CEC(u8 *p, u32 value);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0207D63C(u32 reg, int plane1, int plane2, int ev1, int ev2);
extern void func_021BC518(int *p);
extern void func_021C7FF8(int, int, int);
void func_021C7CE8(u16 *a0, u8 *p, int key);
void ov208_func_021C7D80(void *unused, struct Ov208Battle *p);
void ov208_func_021C7E74(void *a0, u8 *p);
void ov208_func_021C7EF8(void *a0, u8 *p);
void ov208_func_021C7F6C(VecF *pos, u32 species, u32 form, u32 gender, u32 shiny, u32 personality, u32 side, u32 extra);
void ov208_func_021C7FF8(struct Ov208Mdl *m, int i, VecFx32 *out);
void func_021C80AC(int a, int b, int c);
extern const VecF data_021C87C0[5];
extern const struct Ov208PoseEnt data_021C8854[15];

void func_021C7CE8(u16 *a0, u8 *p, int key)
{
    int a;
    int b;
    if (((struct Obj00147 *)p)->f6B8 != 0) return;
    func_021C51A0((char *)(p + 0x94), ((struct Obj00147 *)p)->f8);
    func_021C51A0((char *)(p + 0xD8), ((struct Obj00147 *)p)->f8);
    func_02014CEC((u8 *)(((struct Obj00147 *)p)->f8), 0);
    a = ((struct Obj00147 *)p)->f124 != 0 ? 2 : 4;
    b = ((struct Obj00147 *)p)->f124 != 0 ? 4 : 3;
    ov208_func_021C569C(a0, p, key, a, b, 2, ((struct Obj00147 *)p)->f550);
    if (a != 4) func_021C51C8(((struct Obj00147 *)p)->f98, 2, p);
    if (b != 4) func_021C51C8(((struct Obj00147 *)p)->fDC, 3, p);
    func_02014CEC((u8 *)(((struct Obj00147 *)p)->f8), ((struct Obj00147 *)p)->f120);
}


void ov208_func_021C7D80(void *unused, struct Ov208Battle *p)
{
    struct Ov208Tri t;
    struct Ov208Tri t2;
    u16 h;
    u32 w;
    u32 *q;
    u8 i;

    h = p->h54e;
    p->h54e = p->h550;
    p->h550 = h;
    w = p->u[0].f0;
    p->u[0].f0 = p->u[2].f0;
    p->u[2].f0 = w;
    q = p->u[0].f4;
    p->u[0].f4 = p->u[2].f4;
    p->u[2].f4 = q;
    if (p->u[0].f4 != 0)
        *p->u[0].f4 = 0;
    if (p->u[2].f4 != 0)
        *p->u[2].f4 = 2;
    w = p->u[1].f0;
    p->u[1].f0 = p->u[3].f0;
    p->u[3].f0 = w;
    q = p->u[1].f4;
    p->u[1].f4 = p->u[3].f4;
    p->u[3].f4 = q;
    if (p->u[1].f4 != 0)
        *p->u[1].f4 = 1;
    if (p->u[3].f4 != 0)
        *p->u[3].f4 = 3;
    for (i = 0; i < 5; i++) {
        t = p->u[0].e[i];
        p->u[0].e[i] = p->u[2].e[i];
        p->u[2].e[i] = t;
        t2 = p->u[1].e[i];
        p->u[1].e[i] = p->u[3].e[i];
        p->u[3].e[i] = t2;
    }
}


void ov208_func_021C7E74(void *a0, u8 *p)
{
    u8 i;

    for (i = 0; i < 2; i++) {
        if (*(u32 *)(p + i * 4 + 0x13c) != 0)
            func_0204B688((struct Actor *)(*(u32 *)(p + i * 4 + 0x13c)), 0);
    }
    func_0204B688((struct Actor *)W(0x5e4), 0);
    func_0204B688((struct Actor *)W(0x5e8), 0);
    for (i = 0; i < 4; i++)
        func_0204B688((struct Actor *)(*(u32 *)(p + i * 0x28 + 0x618)), 0);
    func_0207D63C(0x04000050, 0, 0x3f, 0xc, 4);
    func_0207D63C(0x04001050, 8, 0x3f, 0xc, 4);
}


void ov208_func_021C7EF8(void *a0, u8 *p)
{
    u8 i;

    for (i = 0; i < 2; i++) {
        if (*(u32 *)(p + i * 4 + 0x13c) != 0)
            func_0204B688((struct Actor *)(*(u32 *)(p + i * 4 + 0x13c)), 1);
    }
    func_0204B688((struct Actor *)W(0x5e4), 1);
    func_0204B688((struct Actor *)W(0x5e8), 1);
    for (i = 0; i < 4; i++)
        func_0204B688((struct Actor *)(*(u32 *)(p + i * 0x28 + 0x618)), 1);
    func_021BC518((int *)W(0x6a4));
    func_021BC518((int *)W(0x6a8));
}


void ov208_func_021C7F6C(VecF *pos, u32 species, u32 form, u32 gender, u32 shiny, u32 personality,
                         u32 side, u32 extra)
{
    u16 k;
    u8 i;

    for (i = 0; i < 5; i++)
        pos[i] = data_021C87C0[i];
    for (k = 0; k < 15; k++) {
        if (species == data_021C8854[k].species && form == data_021C8854[k].form &&
            side == data_021C8854[k].side &&
            (data_021C8854[k].gender == 3 || gender == data_021C8854[k].gender)) {
            for (i = 0; i < 5; i++)
                pos[i] = data_021C8854[k].pos[i];
            return;
        }
    }
}


void ov208_func_021C7FF8(struct Ov208Mdl *m, int i, VecFx32 *out)
{
    out->x = FX_F32_TO_FX32(m->pos[i].x);
    out->y = FX_F32_TO_FX32(m->pos[i].y);
    out->z = FX_F32_TO_FX32(m->pos[i].z);
}


void func_021C80AC(int a, int b, int c)
{
    int m = 0;

    switch (b) {
    case 0:
        break;
    case 1:
        m = 3;
        break;
    case 2:
        m = 4;
        break;
    }
    func_021C7FF8(a, m, c);
}
