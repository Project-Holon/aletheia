/*
 * file:     townmap_p04.c
 * unit:     yes
 * function: func_021B9F20, func_021B9F50, func_021BA028, func_021BA040, func_021BA04C, func_021BA0D8, func_021BA0E4, func_021BA3BC, func_021BA3CC, func_021BA3E8, func_021BA3EC, func_021BA3F4, func_021BA450
 * address:  0x021B9F20
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B639C 0x021B639C thumb ov067
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021B63D0  0x021B63D0  thumb  ov067
 *   func_0204B454  0x0204B454  arm
 *   func_02035D20  0x02035D20  arm
 *   func_020355D8  0x020355D8  arm
 *   func_020362DC  0x020362DC  arm
 *   func_0204B98C  0x0204B98C  arm
 *   func_021BB0E0  0x021BB0E0  thumb  ov072
 *   func_0204B898  0x0204B898  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B95C  0x0204B95C  arm
 *   func_021B6448 0x021B6448 thumb ov067
 *   func_021B6498  0x021B6498  thumb  ov067
 *   func_0204B404  0x0204B404  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_0204B800  0x0204B800  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_020355C4  0x020355C4  arm
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   func_0203630C  0x0203630C  arm
 *   func_021BA710  0x021BA710  thumb  ov072
 *   func_021BA69C  0x021BA69C  thumb  ov072
 *   func_021BA774  0x021BA774  thumb  ov072
 *   VEC_Subtract   0x0207CA00  arm
 *   VEC_Mag        0x0207CBD0  arm
 *   VEC_Normalize  0x0207CCA4  arm
 *   func_020520A4  0x020520A4  arm
 *   func_0204B9A0  0x0204B9A0  arm
 */
#include "../../matched/include/Obj13193.h"
#include "../../matched/include/Obj13194.h"
#include "../../matched/include/Obj09905.h"

#define FX_F32_TO_FX32(x) \
    ((int)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))
struct Obj;
struct Actor;
struct S;
struct PtS;
struct Vec2;
struct Node;
typedef short s16;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    s16 x, y;
} Pt_021B9F50;

typedef unsigned char  u8;

typedef struct {
    void *f0;
    void *f4;
    u16 f8;
    u16 fA;
    int pad[3];
} S;

struct Vec3 { int x; int y; int z; };

typedef struct {
    s16 x;
    s16 y;
} Pt_021BA0E4;

typedef struct {
    int obj;
    int f4;
    Pt_021BA0E4 pt;
    int fc;
    int f10;
} Cur;

typedef struct {
    s16 x;
    s16 y;
} Pos;

extern void func_021B639C(unsigned char *);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204AFD8(unsigned);
extern void func_0204A8D4(unsigned);
extern void func_0204ADA4(unsigned);
extern void func_02082BCC(void *,int,int);
extern void func_021B63D0(struct S *p);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern void func_020355D8(u8 v);
extern u32 func_020362DC(void);
extern u32 func_0204B98C(struct Actor *a);
extern int func_021BB0E0(void *p);
extern u16 func_0204B898(struct Obj *p);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B95C(struct Actor *a);
extern int func_021B6448(unsigned char *);
int func_021B6498(unsigned char *p);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, unsigned int which);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B84C(void *a, int b);
extern void func_0204B800(struct Node *node, u32 val);
extern void func_0204B92C(struct Obj *p, u32 v);
extern u8 func_020355C4(void);
extern unsigned int func_0203630C(void);
extern char *func_021BA710(void *p, Cur *c);
extern void func_021BA69C(char *p, int *o);
extern int func_021BA774(char *p, int i);
extern void VEC_Subtract(const struct Vec3 *a, const struct Vec3 *b, struct Vec3 *d);
extern int VEC_Mag(const struct Vec3 *v);
extern void VEC_Normalize(const struct Vec3 *v, struct Vec3 *d);
extern void func_020520A4(const struct Vec3 *v, int s, struct Vec3 *d);
extern void func_0204B9A0(struct Actor *a);
void func_021B9F20(unsigned *p);
void func_021B9F50(u32 *p, void *q);
int func_021BA028(char *p);
int func_021BA040(int *p);
void func_021BA04C(S *p, void *a, void *b);
void func_021BA0D8(void *p);
void func_021BA0E4(Cur *c, void *q);
void func_021BA3BC(char *p, int *q);
void func_021BA3CC(char *p, int *q);
int func_021BA3E8(int *p);
void func_021BA3EC(void);
void func_021BA3F4(int *p, int a, int *b);
void func_021BA450(int *p, int *b);

void func_021B9F20(unsigned *p) {
    func_021B639C((unsigned char *)p[3]);
    func_0204B3B4((struct Obj *)p[5]); func_0204AFD8(p[2]);
    func_0204A8D4(p[1]); func_0204ADA4(p[0]);
    func_02082BCC(p,0,32);
}


/*
 * EXACT*: the unlabelled follower at 0x021BA028 (push {r4,lr}; getter
 * over func_021B6448) is outside the handed 216-byte extent.
 * Lever: each sprite-animation pick written as if/else of two calls
 * (tail-merged, h load hoisted over the bne), and func_0204B878's second
 * parameter int here (no truncation before the blx).
 */
void func_021B9F50(u32 *p, void *q)
{
    u32 x;
    u32 y;
    Pt_021B9F50 pt;
    int hit;

    func_021B63D0((void *)p[3]);
    p[6] = -1;
    switch (p[7]) {
    case 0:
        hit = 0;
        func_0204B454((void *)p[5], (struct PtS *)&pt, 0);
        if (func_02035D20(&x, &y)) {
            if (x - pt.x <= 0x18 && y - pt.y <= 0x18) {
                hit = 1;
                func_020355D8(1);
            }
        } else if (func_020362DC() & 4) {
            func_020355D8(hit);
            hit = 1;
        }
        if (hit && func_0204B98C((void *)p[5]) == 0 && func_021BB0E0(q) == 0) {
            if (func_0204B898((void *)p[5]) == 7)
                func_0204B878((void *)p[5], 9);
            else
                func_0204B878((void *)p[5], 10);
            func_0204B95C((void *)p[5]);
            p[6] = 7;
            p[7] = 1;
        }
        break;
    case 1:
        if (func_0204B98C((void *)p[5]) == 0) {
            if (func_0204B898((void *)p[5]) == 9)
                func_0204B878((void *)p[5], 8);
            else
                func_0204B878((void *)p[5], 7);
            p[7] = 0;
        }
        break;
    }
}

int func_021BA028(char *p) {
    int n;
    n = func_021B6448(*(unsigned char * *)&((struct Obj13193 *)p)->fC);
    if (n == -1) n = ((struct Obj13193 *)p)->f18;
    return n;
}


int func_021BA040(int *p)
{
    return func_021B6498((unsigned char *)p[3]);
}


void func_021BA04C(S *p, void *a, void *b)
{
    int z = 0;
    int one;

    func_02082BCC(p, 0, 0x18);
    p->f0 = a;
    p->f4 = b;
    p->f8 = 0x80;
    p->fA = 0x60;
    func_0204B404(a, (const struct Vec2 *)(&p->f8), 0);
    func_0204B404(p->f4, (const struct Vec2 *)(&p->f8), 0);
    func_0204B3DC(p->f0, 1);
    one = 1;
    func_0204B3DC(p->f4, 0);
    func_0204B84C(p->f0, 0);
    func_0204B800(p->f0, 0);
    func_0204B84C(p->f4, 2);
    func_0204B800(p->f4, 3);
    func_0204B92C(p->f4, 1);
    if (func_020355C4() == 0) {
        func_0204B3DC(p->f0, one);
    } else {
        func_0204B3DC(p->f0, z);
    }
}


void func_021BA0D8(void *p)
{
    func_02082BCC(p, 0, 0x18);
}


void func_021BA0E4(Cur *c, void *q)
{
    struct Vec3 dir = { 0, 0, 0 };
    struct Vec3 v = { 0, 0, 0 };
    struct Vec3 a;
    struct Vec3 b;
    int o[2];
    u32 tx;
    u32 ty;
    int moved;
    char *w;
    int dx;
    int dy;
    s16 t;

    moved = 0;
    c->fc = 0;
    if (func_0203630C() & 0x40) {
        func_020355D8(0);
        dir.y -= 0x1000;
        moved = 1;
    }
    if (func_0203630C() & 0x80) {
        func_020355D8(0);
        dir.y += 0x1000;
        moved = 1;
    }
    if (func_0203630C() & 0x20) {
        func_020355D8(0);
        dir.x -= 0x1000;
        moved = 1;
    }
    if (func_0203630C() & 0x10) {
        func_020355D8(0);
        dir.x += 0x1000;
        moved = 1;
    }
    if (c->f10 != 0 && func_020355C4() == 0 && (w = func_021BA710(q, c)) != 0) {
        func_021BA69C(q, o);
        a.x = FX_F32_TO_FX32(o[0] + func_021BA774(w, 4));
        a.y = FX_F32_TO_FX32(o[1] + func_021BA774(w, 5));
        a.z = 0;
        b.x = FX_F32_TO_FX32(c->pt.x);
        b.y = FX_F32_TO_FX32(c->pt.y);
        b.z = 0;
        VEC_Subtract(&a, &b, &v);
        if (VEC_Mag(&v) > 0x1000) {
            VEC_Normalize(&v, &v);
            func_020520A4(&v, 0x1000, &v);
        }
        moved = 1;
    }
    if (moved) {
        VEC_Normalize(&dir, &dir);
        dx = v.x + dir.x * 3;
        dy = v.y + dir.y * 3;
        if (dx > 0 && dx < 0x1000)
            dx = 0x1000;
        else if (dx > -0x1000 && dx < 0)
            dx = -0x1000;
        if (dy > 0 && dy < 0x1000)
            dy = 0x1000;
        else if (dy > -0x1000 && dy < 0)
            dy = -0x1000;
        c->pt.x += (s16)(dx >> 12);
        c->pt.y += (s16)(dy >> 12);
        t = c->pt.x;
        if (t > 0xf8)
            t = 0xf8;
        else if (t < 0)
            t = 0;
        c->pt.x = t;
        t = c->pt.y;
        if (t > 0xa8)
            t = 0xa8;
        else if (t < 8)
            t = 8;
        c->pt.y = t;
        func_0204B404((struct Obj *)c->obj, (const struct Vec2 *)(&c->pt), 0);
    }
    if (func_020362DC() & 1) {
        func_020355D8(0);
        c->fc = 1;
    }
    if (func_02035D20(&tx, &ty)) {
        func_020355D8(1);
        if (tx <= 0xf8 && ty - 8 <= 0xa0) {
            c->fc = 1;
            c->pt.x = tx;
            c->pt.y = ty;
        }
    }
    if (func_020355C4() == 0)
        func_0204B3DC((struct Obj *)c->obj, 1);
    else
        func_0204B3DC((struct Obj *)c->obj, 0);
}

/*
 * note: trailing two-byte alignment padding.
 */
void func_021BA3BC(char *p, int *q) {
    q[0] = ((struct Obj13194 *)p)->f8;
    q[1] = ((struct Obj13194 *)p)->fA;
}

void func_021BA3CC(char *p, int *q) {
    ((struct Obj09905 *)p)->f8 = q[0];
    ((struct Obj09905 *)p)->fA = q[1];
    func_0204B404(((struct Obj09905 *)p)->f0, (const struct Vec2 *)(p + 8), 0);
}

int func_021BA3E8(int *p)
{
    return p[3];
}


void func_021BA3EC(void)
{
    func_0203630C();
}


void func_021BA3F4(int *p, int a, int *b)
{
    Pos pos;

    if (a == 0) {
        func_0204B3DC((struct Obj *)p[1], 0);
        p[5] = 0;
        return;
    }
    if (p[5] != a) {
        pos.x = b[0] + func_021BA774((char *)a, 4);
        pos.y = b[1] + func_021BA774((char *)a, 5);
        func_0204B404((struct Obj *)p[1], (const struct Vec2 *)(&pos), 0);
        func_0204B3DC((struct Obj *)p[1], 1);
        func_0204B9A0((struct Actor *)p[1]);
        p[5] = a;
    }
}

void func_021BA450(int *p, int *b) { Pos pos; if(p[5]) { pos.x=b[0]+func_021BA774((void *)p[5],4); pos.y=b[1]+func_021BA774((void *)p[5],5); func_0204B404((struct Obj *)p[1],(const struct Vec2 *)(&pos),0); } }
