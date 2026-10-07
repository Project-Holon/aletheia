/*
 * file:     zukan_detail_graphic_p25.c
 * unit:     yes
 * function: func_021C0D5C, func_021C100C, func_021C1068, func_021C10B8, func_021C1450, func_021C1810, func_021C1920
 * address:  0x021C0D5C
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
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_021BBB3C 0x021BBB3C thumb ov072
 *   func_02051F1C 0x02051F1C arm
 *   func_0205207C 0x0205207C arm
 *   func_02051F34 0x02051F34 arm
 *   func_021BC3B4  0x021BC3B4  thumb  ov208
 *   func_020362DC  0x020362DC  arm
 *   func_0203633C  0x0203633C  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_020355D8  0x020355D8  arm
 *   func_02035D20  0x02035D20  arm
 *   func_021BDC48  0x021BDC48  thumb  ov208
 *   func_021C1E10  0x021C1E10  thumb  ov208
 *   func_021C0CCC 0x021C0CCC thumb ov208
 *   func_021C1D30 0x021C1D30 thumb ov208
 *   func_021C2238 0x021C2238 thumb ov208
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B454 0x0204B454 arm
 *   func_020355C4 0x020355C4 arm
 *   func_0203630C 0x0203630C arm
 *   func_0207CA00 0x0207CA00 arm
 *   func_0207CBD0 0x0207CBD0 arm
 *   func_0207CCA4 0x0207CCA4 arm
 *   func_020520A4 0x020520A4 arm
 *   ov208_func_021C1920  0x021C1920  thumb  ov208
 *   ov208_func_021C1FE0  0x021C1FE0  thumb  ov208
 *   ov208_func_021C2090  0x021C2090  thumb  ov208
 *   ov208_func_021C20C0  0x021C20C0  thumb  ov208
 *   ov208_func_021C21D0  0x021C21D0  thumb  ov208
 *   ov208_func_021C2228  0x021C2228  thumb  ov208
 *   ov208_func_021C2234  0x021C2234  thumb  ov208
 *   func_021BDBAC  0x021BDBAC  thumb  ov208
 *   func_021C0D3C  0x021C0D3C  thumb  ov208
 *   func_021BC3BC  0x021BC3BC  thumb  ov208
 *   func_021BDAAC  0x021BDAAC  thumb  ov208
 *   func_021BDBA0  0x021BDBA0  thumb  ov208
 *   func_021BC3A4  0x021BC3A4  thumb  ov208
 *   func_02012BF8  0x02012BF8  thumb
 *   func_021BDC14  0x021BDC14  thumb  ov208
 */
#include "../../matched/include/Obj14656.h"

#define FX(x) ((int)(((x)>0) ? ((float)((int)(x)<<12)+0.5f) : ((float)((int)(x)<<12)-0.5f)))
#define FIELD(n) func_021BBB3C(*(char **)(p+0x3c8),i,n)
#define W(o) (*(u32 *)(p + (o)))
struct S12;
struct Actor;
struct Obj;
struct Vec2;
struct Vec3;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Vec_021C0D5C { int x,y,z; };

struct Ball { struct Vec_021C0D5C p; int radius; };

struct Seg { struct Vec_021C0D5C a,b; int radius; };

struct Out { u32 hit; struct Vec_021C0D5C n; int distance; };

typedef short s16;

struct Vec_021C1450 { int x, y, z; };

struct PtS { s16 x, y; };

typedef int            s32;

extern u16 func_021BBB3C(char *,int,int);
extern void func_02051F1C(struct Ball *,struct Vec_021C0D5C *,u32);
extern void func_0205207C(char *p, struct S12 *q, struct S12 *r, u32 v);
extern u32 func_02051F34(struct Seg *,struct Ball *,struct Out *);
extern int func_021BC3B4(int *p);
extern u32  func_020362DC(void);
extern unsigned int func_0203633C(void);
extern void func_020061E4(u32 a);
extern void func_020355D8(u8 v);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern void func_021BDC48(void *s, u32 on);
extern void func_021C1E10(u16 *heap, u8 *p, int key, int dir, int touch);
extern u8 func_020355C4(void);
extern unsigned int func_0203630C(void);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_021C0CCC(u16 *heap, u8 *p, int key);
extern void func_021C1D30(u16 *heap, u8 *p, int key);
extern void func_021C2238(u16 *heap, u8 *p, int key);
extern void func_0207CA00(struct Vec_021C1450 *a, struct Vec_021C1450 *b, struct Vec_021C1450 *out);
extern int func_0207CBD0(struct Vec_021C1450 *v);
extern void func_0207CCA4(struct Vec_021C1450 *src, struct Vec_021C1450 *dst);
extern void func_020520A4(const struct Vec3 *v, int s, struct Vec3 *dst);
extern void ov208_func_021C1920(u16 *heap, u8 *p, int key, int mode);
extern void ov208_func_021C1FE0(u16 *heap, u8 *p, int key);
extern void ov208_func_021C2090(u16 *heap, u8 *p, int key);
extern void ov208_func_021C20C0(u16 *heap, u8 *p, int key);
extern void ov208_func_021C21D0(u16 *heap, u8 *p, int key);
extern void ov208_func_021C2228(u16 *heap, u8 *p, int key);
extern void ov208_func_021C2234(u16 *heap, u8 *p, int key);
extern void func_021BDBAC(void *s, u32 on);
extern void func_021C0D3C(int a, char *b, int c);
extern u16  func_021BC3BC(char *p);
extern void func_021BDAAC(void *s, u32 mode, u32 kind, u32 flag);
extern void func_021BDBA0(void *s);
extern int func_021BC3A4(int *p);
extern int func_02012BF8(int a0, int a1);
extern void func_021BDC14(char *p, int b);
u8 func_021C0D5C(void *unused,char *p,int unused2,u8 x,u8 y);
int func_021C100C(void *unused, char *p, int key, u8 index, u8 x, u8 y, unsigned *out);
u8 func_021C1068(void *heap, char *p, int key, u8 x, u8 y);
void func_021C10B8(u16 *heap, u8 *p, int key);
void func_021C1450(u16 *heap, u8 *p, int key);
void ov208_func_021C1810(u16 *heap, u8 *p, int key);
void func_021C1920(u16 *heap, u8 *p, int key, int mode);

u8 func_021C0D5C(void *unused,char *p,int unused2,u8 x,u8 y)
{
    struct Ball ball;
    struct Vec_021C0D5C point;
    struct Seg seg;
    struct Vec_021C0D5C a,b;
    struct Out out;
    int best;
    u8 i;
    u8 result=255;
    point.x=FX(x);
    point.y=FX(y);
    point.z=0;
    func_02051F1C(&ball,&point,0);
    for(i=0;i<61;i++) {
        if (*(u32 *)(p+i*8+0x1e0)==1) continue;
        a.x=FX(FIELD(6));
        a.y=FX(FIELD(7));
        a.z=0;
        b.x=FX(FIELD(8));
        b.y=FX(FIELD(9));
        b.z=0;
        func_0205207C((char *)(&seg),(struct S12 *)(&a),(struct S12 *)(&b),FX(FIELD(10)));
        if (func_02051F34(&seg,&ball,&out)) {
            if(result==255) { best=out.distance; result=i; }
            else if(best>out.distance) { best=out.distance; result=i; }
        }
    }
    return result;
}

/*
 * Tail: 021C1066..021C1068 is two zero alignment bytes, not a follower.
 */
int func_021C100C(void *unused, char *p, int key, u8 index, u8 x, u8 y, unsigned *out)
{
    unsigned dx, dy, distance;
    if (*(unsigned *)(p + index * 8 + 0x1e0) == 1) return 0;
    dx = func_021BBB3C(*(char * *)&((struct Obj14656 *)p)->f3C8, index, 4);
    dy = func_021BBB3C(*(char * *)&((struct Obj14656 *)p)->f3C8, index, 5);
    dy -= y;
    dx -= x;
    distance = dx * dx + dy * dy;
    if (distance < 144) {
        if (out) *out = distance;
        return 1;
    }
    return 0;
}

u8 func_021C1068(void *heap, char *p, int key, u8 x, u8 y)
{
    unsigned distance, bestDistance;
    u8 best = 255, i;
    for (i = 0; i < 61; i++) {
        if (func_021C100C(heap, p, key, i, x, y, &distance)) {
            if (best == 255) {
                best = i;
                bestDistance = distance;
            } else if (bestDistance > distance) {
                best = i;
                bestDistance = distance;
            }
        }
    }
    return best;
}


void func_021C10B8(u16 *heap, u8 *p, int key)
{
    void *s;
    int hit, touch;
    int moved, done;
    u32 x, y, tx, ty;

    s = (void *)func_021BC3B4((int *)key);
    if (W(0x428) == 0 || p[0xd8] != 7)
        return;

    switch (W(0x6c)) {
    case 0:
        hit = 0;
        touch = 0;
        if (func_020362DC() & 1) {
            touch = 1;
            hit = 1;
        } else if (W(0x8c) != 0) {
            if (func_0203633C() & 0x100) {
                p[0x78]++;
                if (p[0x78] >= 4)
                    p[0x78] = 0;
                hit = 1;
                func_021C1E10(heap, p, key, 1, 0);
                func_020061E4(0x54a);
            } else if (func_0203633C() & 0x200) {
                if (p[0x78] == 0) p[0x78] = 3; else p[0x78]--;
                func_021C1E10(heap, p, key, 0, 0);
                func_020061E4(0x54a);
                hit = 1;
            }
        }
        if (hit) {
            func_020355D8(0);
            if (touch)
                W(0x7c) = 0;
        }
        if (hit == 0) {
            if (func_02035D20(&x, &y)) {
                if (W(0x8c) == 0) {
                    if (y < 0xa8) {
                        touch = 1;
                        hit = 1;
                    }
                } else if (x >= 0x88 && x < 0xa0 && y < 0x10) {
                    p[0x78]++;
                    if (p[0x78] >= 4)
                        p[0x78] = 0;
                    hit = 1;
                    func_021C1E10(heap, p, key, 1, hit);
                    func_020061E4(0x54a);
                } else if (x < 0x18 && y < 0x10) {
                    if (p[0x78] == 0) p[0x78] = 3; else p[0x78]--;
                    hit = 1;
                    func_021C1E10(heap, p, key, 0, hit);
                    func_020061E4(0x54a);
                } else if ((x >= 0xa0 || y >= 0x18) && y < 0xa8) {
                    touch = 1;
                    hit = 1;
                }
            }
            if (hit) {
                hit = 1;
                func_020355D8(1);
                if (touch) {
                    W(0x7c) = hit;
                    p[0x80] = x;
                    p[0x81] = y;
                }
            }
        }
        if (touch && (W(0x8c) != 0 || W(0x90) != 0)) {
            func_021C1920(heap, p, key, 1);
            func_020061E4(0x54c);
            func_021BDC48(s, 0);
        }
        break;
    case 5:
        moved = 0;
        done = 1;
        if (func_020362DC() & 2) {
            W(0x428) = 0;
            moved = 1;
            done = 0;
        } else if (W(0x8c) != 0) {
            if (func_0203633C() & 0x100) {
                p[0x78]++;
                if (p[0x78] >= 4)
                    p[0x78] = 0;
                done = 0;
                func_021C1E10(heap, p, key, 1, done);
                moved = 1;
                func_020061E4(0x54a);
            } else if (func_0203633C() & 0x200) {
                if (p[0x78] == 0) p[0x78] = 3; else p[0x78]--;
                done = 0;
                func_021C1E10(heap, p, key, 0, 0);
                func_020061E4(0x54a);
                moved = 1;
            }
        }
        if (moved)
            func_020355D8(0);
        if (moved == 0) {
            if (func_02035D20(&tx, &ty)) {
                if (W(0x8c) == 0) {
                    if (ty >= 0xa8)
                        done = 0;
                } else if (W(0x8c) == 1) {
                    if (tx >= 0x88 && tx < 0xa0 && ty < 0x10) {
                        p[0x78]++;
                        if (p[0x78] >= 4)
                            p[0x78] = 0;
                        moved = 1;
                        func_021C1E10(heap, p, key, 1, moved);
                        func_020061E4(0x54a);
                        done = 0;
                    } else if (tx < 0x18 && ty < 0x10) {
                        if (p[0x78] == 0) p[0x78] = 3; else p[0x78]--;
                        moved = 1;
                        func_021C1E10(heap, p, key, 0, moved);
                        done = 0;
                        func_020061E4(0x54a);
                    } else if (tx < 0xa0 && ty < 0x18) {
                        done = 0;
                    } else if (ty >= 0xa8) {
                        done = 0;
                    }
                }
            }
            if (moved)
                func_020355D8(1);
        }
        if (done)
            func_021C1450(heap, p, key);
        break;
    }
}


static inline void set3(struct Vec_021C1450 *v, int x, int y, int z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}


void func_021C1450(u16 *heap, u8 *p, int key)
{
    u32 tx, ty;
    struct { struct PtS t, c; } pt;
    u8 idx;
    u8 old;
    int found, near;
    int moved;
    unsigned int keys;
    int dx, dy;

    if (W(0x90) == 0)
        return;
    if (func_020355C4() == 0) {
        if (func_02035D20(&tx, &ty)) {
            func_020355D8(1);
            func_0204B3DC((struct Obj *)W(0xcc), 0);
        }
    } else if (func_020362DC()) {
        func_020355D8(0);
        func_021C0CCC(heap, p, key);
        func_021C1D30(heap, p, key);
        func_021C2238(heap, p, key);
        return;
    }
    if (func_020355C4() == 0) {
        old = p[0x79];
        moved = 0;
        found = 0;
        near = 0;
        {
        struct Vec_021C1450 v = {0, 0, 0};
        struct Vec_021C1450 d = {0, 0, 0};
        struct Vec_021C1450 a;
        struct Vec_021C1450 b;
        func_0204B454((struct Actor *)W(0xcc), &pt.c, 0);
        keys = func_0203630C();
        if ((keys & 0x10) || (keys & 0x20) || (keys & 0x40) || (keys & 0x80)) {
            moved = 1;
            if (keys & 0x10)
                v.x += 0x1000;
            if (keys & 0x20)
                v.x -= 0x1000;
            if (keys & 0x40)
                v.y -= 0x1000;
            if (keys & 0x80)
                v.y += 0x1000;
        }
        idx = func_021C1068(heap, (char *)p, key, (u8)pt.c.x, (u8)pt.c.y);
        if (idx != 0xff) {
            found = 1;
            pt.t.x = func_021BBB3C(*(char **)(p + 0x3c8), idx, 4);
            pt.t.y = func_021BBB3C(*(char **)(p + 0x3c8), idx, 5);
            a.x = FX(pt.t.x);
            a.y = FX(pt.t.y);
            a.z = 0;
            b.x = FX(pt.c.x);
            b.y = FX(pt.c.y);
            b.z = 0;
            func_0207CA00(&a, &b, &d);
            if (func_0207CBD0(&d) < 0x1BB6)
                near = 1;
            if (func_0207CBD0(&d) > 0x1000) {
                func_0207CCA4(&d, &d);
                func_020520A4((const struct Vec3 *)(&d), 0x1000, (struct Vec3 *)(&d));
            }
        }
        if (moved == 0 && found == 0)
            return;
        if (moved == 0 && found != 0 && near != 0) {
            pt.c = pt.t;
        } else {
            func_0207CCA4(&v, &v);
            dx = d.x + v.x * 3;
            dy = d.y + v.y * 3;
            if (dx > 0 && dx < 0x1000)
                dx = 0x1000;
            else if (dx > -0x1000 && dx < 0)
                dx = -0x1000;
            if (dy > 0 && dy < 0x1000)
                dy = 0x1000;
            else if (dy > -0x1000 && dy < 0)
                dy = -0x1000;
            pt.c.x = pt.c.x + (s16)(dx >> 12);
            pt.c.y = pt.c.y + (s16)(dy >> 12);
        }
        pt.c.x = pt.c.x > 0xf8 ? 0xf8 : (pt.c.x < 0 ? 0 : pt.c.x);
        pt.c.y = pt.c.y > 0xa8 ? 0xa8 : (pt.c.y < 8 ? 8 : pt.c.y);
        func_0204B404((struct Obj *)W(0xcc), (const struct Vec2 *)(&pt.c), 0);
        p[0x79] = func_021C0D5C(heap, (char *)p, key, (u8)pt.c.x, (u8)pt.c.y);
        if (p[0x79] != old) {
            func_021C1D30(heap, p, key);
            func_021C2238(heap, p, key);
            if (p[0x79] != 0xff)
                func_020061E4(0x548);
        }
        }
    } else if (func_02035D20(&tx, &ty)) {
        p[0x79] = func_021C0D5C(heap, (char *)p, key, (u8)tx, (u8)ty);
        func_021C1D30(heap, p, key);
        func_021C2238(heap, p, key);
        if (p[0x79] != 0xff)
            func_020061E4(0x54C);
    }
}


void ov208_func_021C1810(u16 *heap, u8 *p, int key)
{
    switch (W(0x6c)) {
    case 1:
        ov208_func_021C1920(heap, p, key, 2);
        break;
    case 2:
        ov208_func_021C1920(heap, p, key, 5);
        break;
    case 3:
        switch (W(0x84)) {
        case 1:
            ov208_func_021C1FE0(heap, p, key);
            W(0x84) = 2;
            break;
        case 2:
            ov208_func_021C2090(heap, p, key);
            W(0x84) = 3;
            break;
        case 3:
            ov208_func_021C20C0(heap, p, key);
            W(0x84) = 0;
            ov208_func_021C1920(heap, p, key, 0);
            break;
        }
        break;
    case 4:
        switch (W(0x84)) {
        case 1:
            ov208_func_021C21D0(heap, p, key);
            W(0x84) = 2;
            break;
        case 2:
            ov208_func_021C2228(heap, p, key);
            W(0x84) = 3;
            break;
        case 3:
            ov208_func_021C2234(heap, p, key);
            W(0x84) = 0;
            break;
        }
        break;
    case 6:
        ov208_func_021C1920(heap, p, key, 7);
        break;
    case 7:
        ov208_func_021C1920(heap, p, key, 0);
        break;
    case 8:
        switch (W(0x84)) {
        case 1:
            ov208_func_021C1FE0(heap, p, key);
            W(0x84) = 2;
            break;
        case 2:
            ov208_func_021C2090(heap, p, key);
            W(0x84) = 3;
            break;
        case 3:
            ov208_func_021C20C0(heap, p, key);
            W(0x84) = 0;
            ov208_func_021C1920(heap, p, key, 5);
            break;
        }
        break;
    }
}


void func_021C1920(u16 *heap, u8 *p, int key, int mode)
{
    void *s;
    u32 wide;

    s = (void *)func_021BC3B4((int *)key);
    switch (W(0x6c)) {
    case 0:
        if (mode == 1) {
        } else if (mode == 3) {
            W(0x84) = 1;
        } else if (mode == 4) {
            W(0x84) = 1;
        }
        break;
    case 1:
        if (mode == 2)
            func_021BDBAC(s, 0);
        break;
    case 2:
        if (mode == 5) {
            W(0x70) = 1;
            W(0x74) = 1;
            if (W(0x90) == 1) {
                if (W(0x7c) == 0) {
                    func_021C0D3C((int)heap, (char *)p, key);
                } else {
                    p[0x79] = func_021C0D5C(heap, (char *)p, key, p[0x80], p[0x81]);
                    if (p[0x79] != 0xff)
                        func_0204B3DC((struct Obj *)W(0xd0), 1);
                }
                func_021C1D30(heap, p, key);
                func_021C2238(heap, p, key);
            }
            func_021BDAAC(s, 1, 1, func_021BC3BC((char *)key) > 1);
        }
        break;
    case 3:
        if (mode == 0) {
            if (W(0x42c) != 0) {
                W(0x430) = 1;
                if (W(0x434) != 0) {
                    W(0x42c) = 0;
                    func_021BDBA0(s);
                }
            }
            if (p[0xd8] == 7 && W(0x88) != 0)
                func_021BDC48(s, 1);
        }
        break;
    case 4:
        break;
    case 5:
        if (mode == 6) {
        } else if (mode == 8) {
            W(0x84) = 1;
        }
        break;
    case 6:
        if (mode == 7)
            func_021BDBAC(s, 0);
        break;
    case 7:
        if (mode == 0) {
            W(0x70) = 3;
            W(0x74) = 3;
            func_0204B3DC((struct Obj *)W(0xcc), 0);
            func_0204B3DC((struct Obj *)W(0xd0), 0);
            wide = func_021BC3BC((char *)key) > 1 ? 1 : 0;
            func_021BDAAC(s, 0, 1, wide);
            func_021BDC14(s, func_02012BF8(func_021BC3A4((int *)key), 0x12));
        }
        break;
    case 8:
        if (mode == 5) {
            func_021BDBA0(s);
            if (p[0xd8] == 7 && W(0x88) != 0)
                func_021BDC48(s, 1);
        }
        break;
    }
    W(0x6c) = mode;
}
