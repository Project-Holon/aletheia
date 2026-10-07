/*
 * file:     zukan_detail_form_p08.c
 * unit:     yes
 * function: func_021C5128, func_021C51A0, func_021C51C8, func_021C51D4, func_021C5200, func_021C5214, func_021C5248, func_021C526C, func_021C52F0, func_021C533C, func_021C535C, func_021C53E0
 * address:  0x021C5128
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
 *   ov208_func_021C5000  0x021C5000  thumb
 *   func_02030734  0x02030734  arm
 *   func_02015EE8  0x02015EE8  thumb
 *   func_02063000  0x02063000  arm
 *   ov208_func_021C7F6C  0x021C7F6C  thumb
 *   data_021C8E64  0x021C8E64  data
 *   func_021C5078 0x021C5078  thumb  ov208
 *   func_02064CBC 0x02064CBC arm
 *   func_02015E4C 0x02015E4C thumb
 *   func_02015E04  0x02015E04  thumb
 *   func_02016380  0x02016380  thumb
 *   func_02015EA0 0x02015EA0 thumb
 *   func_02015EB0 0x02015EB0 thumb
 *   func_021C595C 0x021C595C thumb ov208
 *   func_020490F4  0x020490F4  arm
 *   func_0201BC3C  0x0201BC3C  thumb
 *   func_0204ACEC  0x0204ACEC  arm
 *   func_0201BC78  0x0201BC78  thumb
 *   func_0201BCEC  0x0201BCEC  thumb
 *   func_0204AF28  0x0204AF28  arm
 *   func_0201BABC  0x0201BABC  thumb
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0201BB5C  0x0201BB5C  thumb
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_0204B688  0x0204B688  arm
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 */
#include "../../matched/include/Obj04897.h"
#include "../../matched/include/Obj00147.h"
#include "../../matched/include/Obj09213.h"

struct Obj;
struct Actor;
typedef unsigned int u32;

typedef struct {
    float x;
    float y;
    float z;
} VecF;

struct Ov208Mdl {
    u32 obj;
    void *turn;
    VecF pos[5];
};

typedef unsigned short u16;

typedef struct {
    int w0;
    int w4;
    char b8;
    char pad[3];
    int wc;
} S;

typedef unsigned char u8;

struct Ov208Anm_021C51D4 { u8 pad0[8]; u8 f8; u8 pad9[3]; u32 fc; };

struct Ov208Slot { void *obj; struct Ov208Anm_021C51D4 *anm; };

struct Ov208AnmState {
    u32 f0;
    u32 f4;
    u32 f8;
    int active;
};

struct Ov208Anm_021C5214 {
    u32 obj;
    struct Ov208AnmState *state;
};

struct Ov208Turn {
    int side;
    u8 *scene;
    u8  count;
    u8  pad9[3];
    int done;
};

struct Ov208Menu {
    u8  pad0[0x128];
    void *arc;
    u32 res[2];
    u32 j;
    u32 k;
};

typedef signed int     s32;

typedef signed short   s16;

typedef struct {
    s16 x;
    s16 y;
    u16 z;
    u8  b6;
    u8  b7;
} Ov208ObjPos;

extern u32  ov208_func_021C5000(void *sys, u32 species, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6,
                                u32 a7);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02015EE8(void *p);
extern void func_02063000(int p0, int p1, int p2, int p3);
extern void ov208_func_021C7F6C(VecF *pos, u32 species, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6,
                                u32 a7);
extern void func_021C5078(int, int);
extern u32 func_020307B0(void *p);
extern void func_02064CBC(struct Obj *x);
extern void func_02015E4C(void *p);
extern void func_02015E04(void *p);
extern void func_02016380(void *o);
extern void func_02015EA0(void *p);
extern void func_02015EB0(void *p);
extern void func_021C595C(u16 *heap,u8 *p,int key);
extern void *func_020490F4(u32 id, u32 heap);
extern int func_0201BC3C(void);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern int func_0201BC78(void);
extern int func_0201BCEC(void);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_0204AFD8(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_02049238(int);
extern u32  func_0201BABC(u32 species, u32 form, u32 gender, u32 isEgg);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern struct Obj *func_0204B294(void *owner, unsigned int res, unsigned int j, unsigned int k, const void *pos, unsigned short f, unsigned short heap);
extern void func_0204B92C(struct Obj *obj, u32 v);
extern u32  func_0201BB5C(u32 species, u32 form, u32 half, u32 isEgg);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(u32 i);
void ov208_func_021C5128(struct Ov208Mdl *m, u32 heap, void *sys, u32 species, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9);
void func_021C51A0(char *p, int a);
void func_021C51C8(S *p, int a, int b);
void func_021C51D4(struct Ov208Slot *s);
void func_021C5200(int *p);
void ov208_func_021C5214(struct Ov208Anm_021C5214 *p);
void ov208_func_021C5248(struct Ov208Turn *t);
void func_021C526C(u16 *heap,u8 *p,int key);
void ov208_func_021C52F0(u16 *heap, struct Ov208Menu *p);
void func_021C533C(void *a, char *q);
u32 ov208_func_021C535C(u32 arc, u32 *res, u32 j, u32 k, u32 owner, u16 heap, u32 species, u32 form, u32 gender, u32 isEgg);
void func_021C53E0(int a, int b);
extern const char data_021C8E64[];


void ov208_func_021C5128(struct Ov208Mdl *m, u32 heap, void *sys, u32 species, u32 a4, u32 a5,
                         u32 a6, u32 a7, u32 a8, u32 a9)
{
    m->obj = ov208_func_021C5000(sys, species, a4, a5, a6, a7, a8, a9);
    m->turn = func_02030734(heap, 0x10, 1, data_021C8E64, 0xab1);
    func_02063000((int)func_02015EE8((void *)m->obj), 1, (int)m->turn, (int)ov208_func_021C5248);
    ov208_func_021C7F6C(m->pos, species, a4, a5, a6, a7, a8, a9);
}


void func_021C51A0(char *p, int a)
{
    if (((struct Obj04897 *)p)->f0 != 0)
        func_021C5078(a, ((struct Obj04897 *)p)->f0);
    ((struct Obj04897 *)p)->f0 = 0;
    if (((struct Obj04897 *)p)->f4 != 0)
        func_020307B0((void *)(((struct Obj04897 *)p)->f4));
    ((struct Obj04897 *)p)->f4 = 0;
}


void func_021C51C8(S *p, int a, int b)
{
    p->w0 = a;
    p->w4 = b;
    p->b8 = 0;
    p->wc = 0;
}

void func_021C51D4(struct Ov208Slot *s)
{
    if (s->obj != 0 && s->anm != 0) {
        void *r = func_02015EE8(s->obj);
        s->anm->f8 = 0;
        s->anm->fc = 0;
        func_02064CBC(r);
        func_02015E4C(s->obj);
    }
}

void func_021C5200(int *p)
{
    if (p[0] == 0)
        return;
    if (p[1] == 0)
        return;
    *(int *)(p[1] + 0xc) = 1;
}


void ov208_func_021C5214(struct Ov208Anm_021C5214 *p)
{
    void *anm;

    if (p->obj != 0 && p->state != 0) {
        anm = func_02015EE8((void *)p->obj);
        if (p->state->active != 0) {
            func_02015E04((void *)p->obj);
            func_02064CBC(anm);
            p->state->active = 0;
        }
    }
}


void ov208_func_021C5248(struct Ov208Turn *t)
{
    u8 *scene = t->scene;

    t->count++;
    if (t->count >= 2)
        t->done = 1;
    func_02016380((void *)(*(u32 *)(scene + t->side * 0x44 + 0xc)));
}

void func_021C526C(u16 *heap,u8 *p,int key)
{
    if(*(int *)&((struct Obj00147 *)p)->f124) {
        func_02015EA0(((struct Obj00147 *)p)->fC);
        if(((struct Obj00147 *)p)->f94)func_02015EA0(((struct Obj00147 *)p)->f94);
        *(int *)&((struct Obj00147 *)p)->f124=0;
    } else {
        func_02015EA0(((struct Obj00147 *)p)->f50);
        if(((struct Obj00147 *)p)->fD8)func_02015EA0(((struct Obj00147 *)p)->fD8);
        *(int *)&((struct Obj00147 *)p)->f124=1;
    }
    func_021C595C(heap,p,key);
    if(*(int *)&((struct Obj00147 *)p)->f124) {
        func_02015EB0(((struct Obj00147 *)p)->fC);
        if(((struct Obj00147 *)p)->f94)func_02015EB0(((struct Obj00147 *)p)->f94);
    } else {
        func_02015EB0(((struct Obj00147 *)p)->f50);
        if(((struct Obj00147 *)p)->fD8)func_02015EB0(((struct Obj00147 *)p)->fD8);
    }
}


void ov208_func_021C52F0(u16 *heap, struct Ov208Menu *p)
{
    p->arc = func_020490F4(7, *heap);
    p->j = func_0204ACEC(p->arc, func_0201BC3C(), 1, 0, *heap);
    p->k = func_0204AF28(p->arc, func_0201BC78(), func_0201BCEC(), *heap);
}


/*
 * Calls 0x0204AFD8 on +0x138, 0x0204ADA4 on +0x134 and 0x02049238 on +0x128 of the second argument.
 */
void func_021C533C(void *a, char *q)
{
    func_0204AFD8(((struct Obj09213 *)q)->f138);
    func_0204ADA4(((struct Obj09213 *)q)->f134);
    func_02049238(((struct Obj09213 *)q)->f128);
}


u32 ov208_func_021C535C(u32 arc, u32 *res, u32 j, u32 k, u32 owner, u16 heap, u32 species,
                        u32 form, u32 gender, u32 isEgg)
{
    Ov208ObjPos pos;
    u32 obj;

    pos.x = 0x80;
    pos.y = 0x80;
    pos.z = 1;
    pos.b6 = 1;
    pos.b7 = 0;
    *res = func_0204A6C8((void *)arc, func_0201BABC(species, form, gender, isEgg), 0, 1, heap);
    obj = (u32)func_0204B294((void *)owner, *res, j, k, &pos, 1, heap);
    func_0204B92C((struct Obj *)obj, 0);
    func_0204B6F4((struct Obj *)obj, func_0201BB5C(species, form, gender, isEgg), 0);
    func_0204B688((struct Actor *)obj, 0);
    return obj;
}


/*
 * Forwards its second argument to func_0204B3B4 and then the first to
 * func_0204A8D4.
 */
void func_021C53E0(int a, int b)
{
    func_0204B3B4((struct Obj *)b);
    func_0204A8D4(a);
}
