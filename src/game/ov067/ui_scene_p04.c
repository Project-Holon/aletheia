/*
 * file:     ui_scene_p04.c
 * unit:     yes
 * function: func_021B67F8, func_021B691C, func_021B6934
 * address:  0x021B67F8
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
 *   func_02082BCC  0x02082BCC  arm
 *   func_021B6730  0x021B6730  thumb  ov067
 *   d_021B942C     0x021B942C  data  ov067  a4
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_021B6A28  0x021B6A28  thumb  ov067
 *   func_021B6A68  0x021B6A68  thumb  ov067
 *   func_021B6A44  0x021B6A44  thumb  ov067
 *   func_021B6A98  0x021B6A98  thumb  ov067
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B3F4  0x0204B3F4  arm
 *   func_02035D20  0x02035D20  arm
 *   func_020355D8  0x020355D8  arm
 *   func_020362DC  0x020362DC  arm
 */
struct Obj;
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

typedef struct {
    int kind;
    s16 x;
    s16 y;
    u16 h8;
    u16 hA;
    u16 hC;
    u16 hE;
    u16 h10;
    u16 h12;
    u16 h14;
    u16 pad16;
    u32 w18;
    u32 w1C;
} Src;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u16 d;
    u16 e;
    u16 padA;
    u32 f;
    u32 g;
} Ent;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    void *fC;
    void *f10;
    u32 f14;
    Src src;
} Obj;

typedef struct {
    s16 x;
    s16 y;
    u16 z;
    u16 pad;
} Pos;

typedef struct S {
    u32 f00;
    u32 f04;
    u32 f08;
    void (*f0c)(struct S *);
    u8 pad10[0x1c - 0x10];
    s16 f1c;
    s16 f1e;
    u8 pad20[0x30 - 0x20];
    u32 f30;
} S;

extern void func_02082BCC(void *p, u32 v, u32 n);
extern int func_021B6730(void *p, int i);
extern struct Obj *func_0204B294(void *a, unsigned int b, unsigned int c, unsigned int d, const void *pos, u16 f, u16 g);
extern void func_0204B92C(struct Obj *obj, u32 v);
extern void func_021B6A28(u8 *p);
extern void func_021B6A68(struct S *p, u32 flag);
extern void func_021B6A44(u8 *p);
extern void func_021B6A98(struct S *p, u32 flag);
extern void func_0204B3B4(struct Obj *p);
extern u32 func_0204B3F4(struct Obj *p);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern void func_020355D8(u8 v);
extern u32 func_020362DC(void);
void func_021B67F8(Obj *p, u32 a1, void *a2, Src *src, u32 a4, u16 a5);
void func_021B691C(void **p);
int func_021B6934(S *p);
extern Ent d_021B942C[];


void func_021B67F8(Obj *p, u32 a1, void *a2, Src *src, u32 a4, u16 a5)
{
    Pos pos;
    u32 v0;
    u32 v1;
    u32 v2;
    int i;

    func_02082BCC(p, 0, 0x38);
    p->src = *src;
    p->f4 = 1;
    func_02082BCC(&pos, 0, 8);
    pos.x = src->x;
    pos.y = src->y;
    if (src->kind >= 7) {
        v0 = src->h8;
        v1 = src->hA;
        v2 = src->hC;
        p->f14 = 0;
    } else {
        v0 = func_021B6730(a2, 1);
        v1 = func_021B6730(a2, 0);
        v2 = func_021B6730(a2, 2);
        i = src->kind;
        p->src.hE = d_021B942C[i].a;
        p->src.h10 = d_021B942C[i].b;
        p->src.h12 = d_021B942C[i].c;
        p->src.h14 = d_021B942C[i].d;
        p->src.w18 = d_021B942C[i].f;
        p->src.w1C = d_021B942C[i].e;
        p->f14 = d_021B942C[i].g;
    }
    p->f8 = p->src.hE;
    pos.z = p->f8;
    p->f0 = (u32)func_0204B294((void *)a1, v0, v1, v2, &pos, a4, a5);
    func_0204B92C((struct Obj *)p->f0, 1);
    switch (p->f14) {
    case 0:
        p->fC = func_021B6A28;
        p->f10 = func_021B6A68;
        break;
    case 1:
        p->fC = func_021B6A44;
        p->f10 = func_021B6A98;
        break;
    }
}

/*
 * extent: trailing two-byte alignment padding at 0x021B6932.
 */
void func_021B691C(void **p)
{
    func_0204B3B4(*p);
    func_02082BCC(p, 0, 0x38);
}


int func_021B6934(S *p)
{
    u32 x;
    u32 y;
    int hit = 0;

    if (func_0204B3F4((struct Obj *)p->f00) & p->f04) {
        if (func_02035D20(&x, &y)) {
            if (x - p->f1c <= 0x18 && y - p->f1e <= 0x18) {
                hit = 1;
                func_020355D8(1);
            }
        }
        if (p->f30 != 0 && (func_020362DC() & p->f30)) {
            func_020355D8(0);
            hit = 1;
        }
        if (hit) {
            p->f0c(p);
            return 1;
        }
    }
    return 0;
}
