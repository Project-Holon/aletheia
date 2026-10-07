/*
 * file:     townmap_p11.c
 * unit:     yes
 * function: func_021BAE9C, func_021BAF24, func_021BAF3C, func_021BAF74, func_021BAF9C, func_021BAFA8
 * address:  0x021BAE9C
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
 *   func_021BA774  0x021BA774  thumb  ov072
 *   func_02082BCC  0x02082BCC  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_0204B800  0x0204B800  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B404 0x0204B404 arm
 *   func_021BA5B0  0x021BA5B0  thumb  ov072
 *   func_021BB0E4  0x021BB0E4  thumb  ov072
 */
#include "../../matched/include/Obj04345.h"

struct Node;
struct Obj;
struct Vec2;
typedef short s16;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    s16 w;
} Pos;

typedef struct {
    int obj;
    int f4;
} W;

typedef struct { short x,y; } Pt;

typedef unsigned char u8;

typedef struct {
    int x, y;
} Vec;

typedef struct {
    u16 f00;
    u16 n;
    s16 f04;
    s16 f06;
    s16 f08;
    s16 f0a;
    int done;
    int active;
    int cur;
    int to;
    int from;
    Vec pos;
    Vec dst;
    Vec src;
} Anim;

extern int func_021BA774(char *p, int i);
extern void func_02082BCC(void *p, int v, int n);
extern struct Obj *func_0204B294(void *a, unsigned int b, unsigned int c, unsigned int d, const void *pos, unsigned short f, unsigned short g);
extern void func_0204B84C(int obj, int v);
extern void func_0204B800(struct Node *node, u32 val);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *obj, u32 v);
extern void func_0204B3DC(struct Obj *obj, unsigned int v);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_021BA5B0(void *a, int b, Vec *c);
extern void func_021BB0E4(Anim *p, Vec *c);
void func_021BAE9C(W *p, int a, int b, int c, int s0, int s1, u16 s2);
void func_021BAF24(unsigned int *p);
void func_021BAF3C(u32 *p,const u32 *v);
void func_021BAF74(u8 *p, u32 a, u32 b, int heap);
void func_021BAF9C(void *p);
void func_021BAFA8(Anim *p, void *arg);


void func_021BAE9C(W *p, int a, int b, int c, int s0, int s1, u16 s2)
{
    Pos pos;

    func_02082BCC(p, 0, 8);
    p->f4 = a;
    func_02082BCC(&pos, 0, 8);
    if (a != 0) {
        pos.x = func_021BA774((char *)a, 2);
        pos.y = func_021BA774((char *)a, 3);
    }
    p->obj = (int)func_0204B294((void *)b, c, s1, s0, &pos, 0, s2);
    func_0204B84C(p->obj, 2);
    func_0204B800((struct Node *)p->obj, 2);
    func_0204B878((struct Obj *)p->obj, 6);
    func_0204B92C((struct Obj *)p->obj, 1);
    if (a == 0) {
        func_0204B3DC((struct Obj *)p->obj, 0);
    }
}

void func_021BAF24(unsigned int *p) { func_0204B3B4((struct Obj *)(*p)); func_02082BCC(p,0,8); }

void func_021BAF3C(u32 *p,const u32 *v) { Pt t; if(p[1]!=0) { t.x=v[0]+func_021BA774((char *)p[1],2); t.y=v[1]+func_021BA774((char *)p[1],3); } func_0204B404((void *)p[0],(const struct Vec2 *)(&t),0); }

void func_021BAF74(u8 *p, u32 a, u32 b, int heap) { u16 z=0; func_02082BCC(p,0,0x38); p[0]=a; p[1]=b; ((struct Obj04345 *)p)->f14=0x1000; ((struct Obj04345 *)p)->f4=z; ((struct Obj04345 *)p)->f6=z; ((struct Obj04345 *)p)->f8=z; ((struct Obj04345 *)p)->fA=z; }


void func_021BAF9C(void *p)
{
    func_02082BCC(p, 0, 0x38);
}


void func_021BAFA8(Anim *p, void *arg)
{
    int dy;
    int dx;
    int step;

    p->done = 0;
    if (p->active == 0)
        return;
    step = (p->to - p->from) / 10;
    p->cur = p->from + step * p->n;
    dy = (p->dst.y - p->src.y) << 12;
    dx = (p->dst.x - p->src.x) << 12;
    p->pos.x = p->src.x + ((dx * p->n) / 10 >> 12);
    p->pos.y = p->src.y + ((dy * p->n) / 10 >> 12);
    if (p->to == 0x1000) {
        p->f04 = -96 - (-96 - 0) / 10 * p->n;
        p->f0a = 72 - (72 - 0) / 10 * p->n;
        p->f06 = -128 - (-128 - 0) / 10 * p->n;
        p->f08 = 128 - (128 - 0) / 10 * p->n;
    } else {
        p->f04 = 0 + (-96 - 0) / 10 * p->n;
        p->f0a = 0 + (72 - 0) / 10 * p->n;
        p->f06 = 0 + (-128 - 0) / 10 * p->n;
        p->f08 = 0 + (128 - 0) / 10 * p->n;
    }
    if (p->n++ >= 10) {
        p->n = 0;
        p->active = 0;
        p->cur = p->to;
        p->pos = p->dst;
        if (p->to == 0x1000) {
            p->f04 = 0;
            p->f06 = 0;
            p->f08 = 0;
            p->f0a = 0;
        } else {
            p->f04 = -0x60;
            p->f06 = -0x80;
            p->f08 = 0x80;
            p->f0a = 0x48;
        }
        p->done = 1;
    }
    func_021BA5B0(arg, p->cur, &p->pos);
    func_021BB0E4(p, &p->pos);
}
