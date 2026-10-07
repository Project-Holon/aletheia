/*
 * file:     shinka_demo_view_p16.c
 * unit:     yes
 * function: func_022089A4, func_02208A24, func_02208A2C, func_02208A38, func_02208A48, func_02208A54, func_02208A6C, func_02208A78, func_02208AB0, func_02208B54, func_02208B6C, func_02208C10, func_02208C18, func_02208C28
 * address:  0x022089A4
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020515B4 0x020515B4 arm
 *   func_02051620 0x02051620 arm
 *   func_02050BE8 0x02050BE8 arm
 *   func_02047CFC 0x02047CFC arm
 *   func_02047E54 0x02047E54 arm
 *   func_02048A18 0x02048A18 arm
 *   func_02047A60 0x02047A60 arm
 *   d_02208EC0 0x02208EC0 data
 *   func_022086C8 0x022086C8 thumb ov195
 *   func_02047E88 0x02047E88 arm
 *   func_020489F4 0x020489F4 arm
 *   func_020477A4 0x020477A4 arm
 *   func_0204784C 0x0204784C arm
 *   func_020480E4 0x020480E4 arm
 *   func_02208714 0x02208714 thumb
 *   func_02047910  0x02047910  arm
 *   func_020478B8  0x020478B8  arm
 */
#include "../../matched/include/Obj24981.h"
#include "../../matched/include/Obj14537.h"
#include "../../matched/include/Obj00687.h"
#include "../../matched/include/Obj05518.h"
#include "../../matched/include/Obj00789.h"

struct Rec;
struct Transform;
struct Arg;
struct G3dSys;
struct AnmCtl;
struct Ctx;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16_022089A4;

typedef unsigned int u32;

typedef signed int s32;

typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x, y, z;
} VecFx32;

typedef struct Cue {
    u16 frame;
    u8 emit;
    u8 id;
} Cue;

typedef struct Emit {
    u8 work[0x4800];
    void *spl;
    u8 res;
    u8 pad[3];
} Emit;

typedef struct Ptc_022089A4 {
    u16 frame;
    u16 cue;
    u16 ncue;
    u16 pad06;
    Cue *cues;
    Emit emit[1];
    u32 active;
    s32 timer;
} Ptc_022089A4;

typedef short s16_02208A38;

typedef struct Ptc_02208A48 {
    u16 frame;
    u16 cue;
    u16 ncue;
    u16 pad06;
    void *cues;
    Emit emit[1];
    u32 active;
    s32 timer;
} Ptc_02208A48;

typedef short s16_02208A6C;

typedef short s16_02208A78;

typedef struct Node_02208A78 { u16 id,pad02; int tx,ty,tz,sx,sy,sz; u8 mtx[0x24]; u32 f40; } Node_02208A78;

typedef struct Anim_02208A78 { u16 heap; u8 pad02[0x12]; void *res; u16 f18,f1a,count,pad1e; Node_02208A78 *nodes; u32 f24,f28; } Anim_02208A78;

typedef struct Node_02208AB0 {
    u16 id;
    u16 pad02;
    fx32 tx, ty, tz;
    fx32 sx, sy, sz;
    u8 mtx[0x24];
    u32 f40;
} Node_02208AB0;

typedef struct Anim_02208AB0 {
    u16 heap;
    u8 pad02[0x12];
    void *res;
    u16 f18;
    u16 f1a;
    u16 count;
    u16 pad1e;
    Node_02208AB0 *nodes;
    u32 f24;
    u32 f28;
} Anim_02208AB0;

typedef struct Anim_02208C10 {
    u8 pad00[0x28];
    int state;
} Anim_02208C10;

typedef struct Anim_02208C18 {
    u8 pad00[0x28];
    int state;
} Anim_02208C18;

typedef struct Anim_02208C28 {
    u8 pad00[0x28];
    int state;
} Anim_02208C28;

extern int func_020515B4(void *p, int b, int c);
extern void func_02051620(void *spl);
extern void func_02050BE8(void);
extern int func_02047CFC(int, int, int);
extern void func_02047E54(struct Rec *);
extern u32 func_02048A18(u8 *a0, int i);
extern void func_02047A60(void *a0, struct Arg *a1);
extern Node_02208AB0 *func_022086C8(u16 heap, u16 n);
extern u16 func_02047E88(void *res, void *name);
extern u32 func_020489F4(u8 *a0, int i);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern u32 func_0204784C(struct AnmCtl *c, u16 idx, s32 *frame);
extern void func_020480E4(struct Ctx *c, u32 i);
extern void func_02208714(void *p);
extern int func_02047910(void *a, int idx, int amount);
extern int func_020478B8(void *a, int idx, int amount);
void func_022089A4(Ptc_022089A4 *p);
void func_02208A24(int a0);
void func_02208A2C(char *p);
void func_02208A38(char *p,u32 v);
void func_02208A48(Ptc_02208A48 *p, s32 timer);
void func_02208A54(char *a);
void func_02208A6C(char *p);
void func_02208A78(Anim_02208A78 *p);
void func_02208AB0(Anim_02208AB0 *p);
void func_02208B54(char *a);
void func_02208B6C(char *p);
void func_02208C10(Anim_02208C10 *p);
int func_02208C18(Anim_02208C18 *p);
void func_02208C28(Anim_02208C28 *p);
extern char d_02208EC0[];


void func_022089A4(Ptc_022089A4 *p)
{
    if (p->active != 0) {
        VecFx32 v = {0, 0, 0};
        Cue *c;

        for (; p->cue < p->ncue; p->cue++) {
            if (p->frame != p->cues[(int)p->cue].frame)
                break;
            c = &p->cues[p->cue];
            func_020515B4(p->emit[c->emit].spl, c->id, (int)(&v));
        }
        p->frame++;
    }
    if (p->timer >= 0) {
        if (p->timer == 0)
            func_02051620(p->emit[0].spl);
        p->timer--;
    }
}

void func_02208A24(int a0){func_02050BE8();}


void func_02208A2C(char *p){((struct Obj24981 *)p)->f4814=1;}

void func_02208A38(char *p,u32 v) { ((struct Obj14537 *)p)->f4814=0; ((struct Obj14537 *)p)->f4818=v; }


/*
 * Unlabelled Thumb leaf (saves no lr), seeded by address.
 */
void func_02208A48(Ptc_02208A48 *p, s32 timer)
{
    p->timer = timer;
}


void func_02208A54(char *a)
{
    *(int *)&((struct Obj00687 *)a)->f14 = func_02047CFC(4, 1, ((struct Obj00687 *)a)->f0);
    ((struct Obj00687 *)a)->f1C = 0;
}

void func_02208A6C(char *p) { func_02047E54(*(struct Rec * *)&((struct Obj05518 *)p)->f14); }

void func_02208A78(Anim_02208A78 *p) { u16 i; Node_02208A78 *n; for(i=0;i<p->count;i++) { n=p->nodes+i; if(n->f40) func_02047A60((void *)func_02048A18(p->res,n->id),(struct Arg *)((struct Transform *)&n->tx)); } }


/*
 * promoted: from src/pending on 2026-09-27, no C change. Its blocker, the
 *   two calls to the unlabelled ARM leaf 0x0204784C (sites +0x8E, +0x98),
 *   closed when that leaf was seeded in layout/function_starts.txt and
 *   matched (src/matched/func_0204784C.c); all 11 relocations resolve.
 */
void func_02208AB0(Anim_02208AB0 *p)
{
    u32 x;
    void *q;
    u16 i;
    Node_02208AB0 *n;
    u16 id;

    p->f18 = func_02047E88(p->res, d_02208EC0);
    p->count = 1;
    p->nodes = func_022086C8(p->heap, p->count);
    id = func_020489F4(p->res, p->f18);
    n = p->nodes;
    p->f1a = 0;
    n->id = id;
    n->tx = 0;
    n->ty = 0;
    n->tz = 0;
    n->f40 = 1;
    for (i = 0; i < p->count; i++)
        func_020477A4((struct G3dSys *)func_02048A18(p->res, p->nodes[i].id), 0);
    p->f24 = 0;
    q = (void *)func_02048A18(p->res, p->nodes[p->f1a].id);
    x = 0;
    p->f28 = 0;
    func_020477A4(q, 1);
    func_020477A4(q, 2);
    func_0204784C(q, 1, (s32 *)(&x));
    func_0204784C(q, 2, (s32 *)(&x));
}


void func_02208B54(char *a)
{
    func_020480E4((struct Ctx *)(*(int *)&((struct Obj05518 *)a)->f14), ((struct Obj05518 *)a)->f18);
    func_02208714((void *)(((struct Obj05518 *)a)->f20));
    ((struct Obj05518 *)a)->f1C = 0;
}


/*
 * blocker resolved: 0x02047910 and 0x020478B8 were matched in arm9
 *           (src/matched/func_02047910.c, src/matched/func_020478B8.c;
 *           shards pkt_02047910 and pkt_020478B8), so their call sites now
 *           attest as `matched`.  0x02048A18 already resolved via matched;
 *           all 164 bytes are correct.
 */
void func_02208B6C(char *p)
{
    unsigned short i;
    int j = 0;
    int v2;

    for (i = 0; i < ((struct Obj00789 *)p)->f1C; i++) {
        unsigned short v = *(unsigned short *)(((struct Obj00789 *)p)->f20 + i * 0x44);
        int x = func_02048A18((u8 *)(((struct Obj00789 *)p)->f14), v);

        func_02047910((void *)x, j, 0x1000);
    }
    ((struct Obj00789 *)p)->f24 = ((struct Obj00789 *)p)->f24 + 1;
    v2 = func_02048A18((u8 *)(((struct Obj00789 *)p)->f14),
                       *(unsigned short *)(((struct Obj00789 *)p)->f20 +
                                           ((struct Obj00789 *)p)->f1A * 0x44));
    if (((struct Obj00789 *)p)->f28 == 1) {
        int a = func_020478B8((void *)v2, 1, 0x5000);
        int b = func_020478B8((void *)v2, 2, 0x5000);

        if (a == 0 && b == 0)
            ((struct Obj00789 *)p)->f28 = 2;
    } else if (((struct Obj00789 *)p)->f28 == 3) {
        int a = func_020478B8((void *)v2, 1, -0x2000);
        int b = func_020478B8((void *)v2, 2, -0x2000);

        if (a == 0 && b == 0)
            ((struct Obj00789 *)p)->f28 = 0;
    }
}


void func_02208C10(Anim_02208C10 *p)
{
    p->state = 1;
}


int func_02208C18(Anim_02208C18 *p)
{
    if (p->state == 2)
        return 1;
    return 0;
}


void func_02208C28(Anim_02208C28 *p)
{
    p->state = 3;
}
