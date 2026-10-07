/*
 * file:     sta_acting_p04.c
 * unit:     yes
 * function: func_021F8DC4, func_021F8E58, func_021F8E88, func_021F8EA8, func_021F90E0, func_021F9140, func_021F91A8, func_021F91CC
 * address:  0x021F8DC4
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F5164 0x021F5164 thumb ov112
 *   func_021F5438 0x021F5438 thumb ov112
 *   func_021F48C0 0x021F48C0 thumb ov112
 *   func_021F709C 0x021F709C thumb ov112
 *   func_021F760C 0x021F760C thumb ov112
 *   func_021F8054 0x021F8054 thumb ov112
 *   d_021FDBE0 0x021FDBE0 data a4
 *   func_021F69E4 0x021F69E4 thumb ov112
 *   func_021F9E50 0x021F9E50 thumb ov132
 *   func_021F8044 0x021F8044 thumb ov112
 *   func_021F6F04 0x021F6F04 thumb ov112
 *   func_021F7098 0x021F7098 thumb ov112
 *   func_021F75DC 0x021F75DC thumb ov112
 *   func_021F6AF0 0x021F6AF0 thumb ov112
 *   func_021FA57C 0x021FA57C thumb ov132
 *   func_0203630C 0x0203630C arm
 *   func_02048AFC 0x02048AFC arm
 *   func_02048B44 0x02048B44 arm
 *   func_02048AD0 0x02048AD0 arm
 *   func_02040618 0x02040618 arm
 *   d_021FDBEC 0x021FDBEC data a4
 *   _fflt 0x0209BDBC arm
 *   _ffltu 0x0209BE04 arm
 *   _fdiv 0x0209CE10 arm
 *   _fsub 0x0209CB8C arm
 *   _fmul 0x0209C77C arm
 *   _fadd 0x0209C95C arm
 *   _fgr 0x0209BBB0 arm
 *   _ffix 0x0209C494 arm
 *   func_021FAC74 0x021FAC74 thumb ov132
 *   d_021FDBD0 0x021FDBD0 data a1
 *   func_0204A380 0x0204A380 arm
 *   func_021FAD0C 0x021FAD0C thumb ov132
 *   d_020A1B38 0x020A1B38 data a2
 *   func_02061CA4 0x02061CA4 arm
 */
#include "../../matched/include/Obj01410.h"
#include "../../matched/include/Obj10530.h"
#include "../../matched/include/Obj14084.h"
#include "../../matched/include/Obj08150.h"
#include "../../matched/include/Obj05397.h"
#include "../../matched/include/Obj10531.h"

#define FX(x) ((int)(((x) > 0) ? ((x) * 4096.0f + 0.5f) : ((x) * 4096.0f - 0.5f)))
struct Object;
struct Light;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Vec { int x, y, z; };

struct Slots { u8 pad[0x44]; void *slots[4]; };

typedef struct Object Object;

typedef signed short s16;

typedef struct { int x, y, z; } Vec;

struct Bytes { u8 a, b, c, d; };

typedef signed char s8;

typedef struct {
    u8 pad[0x168];
    u16 phase;
    u16 base[16];
    s8 dr[16];
    s8 dg[16];
    s8 db[16];
    u16 out[16];
} Fade;

extern void *func_021F5164(u32);
extern void func_021F5438(void **p, int b);
extern struct Object *func_021F48C0(u32 owner, int count, u16 heap);
extern u8 *func_021F709C(u16 heap, u32 b, u32 c, u32 d, u32 e);
extern void *func_021F760C(void *,void *);
extern void func_021F8054(void *unused, u32 *p, const u32 *q);
extern Object *func_021F69E4(u16,void *);
extern char *func_021F9E50(unsigned);
extern u32 func_0203630C(void);
extern void func_021F8044(void *unused, u32 *p, u32 *q);
extern void func_021F6F04(void *, void *, Vec *);
extern void func_021F7098(u8 *p, u16 v);
extern void func_021F75DC(u8 *p, u16 v);
extern void func_021F6AF0(void *, u16);
extern void func_021FA57C(void *unused, int x);
extern void func_02048AFC(void *, const Vec *);
extern void func_02048B44(void *, const Vec *);
extern void func_02048AD0(struct Light *l);
extern void func_02040618(u32, u32, u32);
extern void *func_021FAC74(char *p, void *arg, int flag);
extern void *func_0204A380(void *a0, u32 a1, u32 a2, u32 a3);
extern char *func_021FAD0C(char *p, char *base, unsigned index, unsigned char flag);
extern int func_02061CA4(void *, u32, u32, int);
void func_021F8DC4(u8 *p);
void func_021F8E58(char *p);
void func_021F8E88(char *p);
void func_021F8EA8(u8 *p);
void func_021F90E0(u8 *p);
void func_021F9140(u8 *p, u8 n, u8 i);
void func_021F91A8(char *p, u8 n, u8 mask);
void func_021F91CC(Fade *p);
extern const struct Vec d_021FDBE0;
extern const Vec d_021FDBEC;
extern const struct Bytes d_021FDBD0;
extern const s16 d_020A1B38[];

void func_021F8DC4(u8 *p)
{
    struct Vec pos;
    u8 i;
    pos = d_021FDBE0;
    ((struct Obj01410 *)p)->f34=func_021F5164(((struct Obj01410 *)p)->f0);
    func_021F5438(((struct Obj01410 *)p)->f34,0x20000);
    ((struct Obj01410 *)p)->f38=func_021F48C0(((struct Obj01410 *)p)->fAC,36,((struct Obj01410 *)p)->f0);
    ((struct Obj01410 *)p)->f40=func_021F709C(((struct Obj01410 *)p)->f0,(u32)p,(u32)(((struct Obj01410 *)p)->f34),(u32)(((struct Obj01410 *)p)->f38),((struct Obj01410 *)p)->fAC);
    for (i=0;i<4;i++) *(u32 *)(p+0x44+i*4)=0;
    for (i=0;i<4;i++) {
        ((struct Slots *)p)->slots[i]=func_021F760C(((struct Obj01410 *)p)->f40,*(void **)(*(u8 * *)&((struct Obj01410 *)p)->f30+4+i*4));
        func_021F8054(((struct Obj01410 *)p)->f40,((struct Slots *)p)->slots[i],(const u32 *)(&pos));
        pos.z-=0x1e000;
    }
}

void func_021F8E58(char *p){int tmp[3]={0};int i;for(i=0;i<5;i++)*(int *)((u32)p+i*4+0x58)=0;*(Object * *)&((struct Obj10530 *)p)->f54=func_021F69E4(((struct Obj10530 *)p)->f0,((struct Obj10530 *)p)->fAC);}

void func_021F8E88(char *p){int i;*(char * *)&((struct Obj14084 *)p)->f6C=func_021F9E50(((struct Obj14084 *)p)->f0);for(i=0;i<8;i++)*(int *)((u32)p+i*4+0x70)=0;}

/*
 * blocker C (read-only root show):
 *   void func_02048AFC(char *p, const Vec *v) { *(Vec *)(p + 0x20) = *v; }
 *   void func_02048B44(char *p, const Vec *v) { *(Vec *)(p + 0x38) = *v; }
 */
void func_021F8EA8(u8 *p)
{
    Vec v;
    s16 target;
    u8 index;
    if (func_0203630C() & 16) {
        if (*(u16 *)(p + 6) + 2 < 256) *(u16 *)(p + 6) = *(u16 *)(p + 6) + 2;
        else *(u16 *)(p + 6) = 256;
    }
    if (func_0203630C() & 32) {
        if (*(u16 *)(p + 6) - 2 > 0) *(u16 *)(p + 6) = *(u16 *)(p + 6) - 2;
        else *(u16 *)(p + 6) = 0;
    }
    if (!(func_0203630C() & 48) && !*(int *)(p + 0x14) && !*(int *)(p + 0x10) && !*(int *)(p + 0xC)) {
        if (*(u8 *)(p + 0xF2) == 4) {
            index = *(u8 *)(p + 0xF1);
            if (index == 4) index = *(u8 *)(p + 0xA);
            if (*(void **)(p + 0x44 + index * 4)) {
                func_021F8044(*(void **)(p + 0x40), *(void **)(p + 0x44 + index * 4), (u32 *)(&v));
                target = (float)v.x / 4096.0f - 128.0f;
            }
        } else {
            func_021F6F04(*(void **)(p + 0x90), *(void **)(p + 0x94 + *(u8 *)(p + 0xF2) * 4), &v);
            target = (float)v.x / 4096.0f - 128.0f;
        }
        if (target > 256) target = 256;
        else if (target < 0) target = 0;
        if (target != *(u16 *)(p + 4)) *(u16 *)(p + 6) = target;
    }
    if (*(u16 *)(p + 6) != *(u16 *)(p + 4)) {
        Vec scale = d_021FDBEC;
        Vec translation = {0, 0, 0};
        if (*(u16 *)(p + 4) > *(u16 *)(p + 6)) {
            if (*(u16 *)(p + 4) > 4 && *(u16 *)(p + 4) - 4 > *(u16 *)(p + 6)) *(u16 *)(p + 4) -= 4;
            else *(u16 *)(p + 4) = *(u16 *)(p + 6);
        } else if (*(u16 *)(p + 4) < *(u16 *)(p + 6)) {
            if (*(u16 *)(p + 4) + 4 < *(u16 *)(p + 6)) *(u16 *)(p + 4) += 4;
            else *(u16 *)(p + 4) = *(u16 *)(p + 6);
        }
        scale.x = FX((float)*(u16 *)(p + 4) / 16.0f);
        translation.x = FX((float)*(u16 *)(p + 4) / 16.0f);
        func_02048AFC(*(void **)(p + 0xA8), &scale);
        func_02048B44(*(void **)(p + 0xA8), &translation);
        func_02048AD0(*(void **)(p + 0xA8));
        func_02040618(2, 0, *(u16 *)(p + 4));
        func_021F7098(*(void **)(p + 0x3C), *(u16 *)(p + 4));
        func_021F75DC(*(void **)(p + 0x40), *(u16 *)(p + 4));
        func_021F6AF0(*(void **)(p + 0x54), *(u16 *)(p + 4));
        func_021FA57C(*(void **)(p + 0xB8), *(u16 *)(p + 4));
    }
    if (*(u16 *)(p + 8) == 224) *(int *)(p + 0xC) = 0;
    func_02040618(2, 3, *(u16 *)(p + 8));
}

void func_021F90E0(u8 *p)
{
    u8 i;
    u32 *table;
    struct Bytes order;
    table = *(u32 * *)&((struct Obj08150 *)p)->fB4;
    order = d_021FDBD0;
    func_021FAC74(((struct Obj08150 *)p)->fB0, (u8 *)table + table[0], 1);
    for (i = 0; i < 4; i++) {
        if (table[0] != table[((u8 *)&order)[i]]) {
            func_021FAC74(((struct Obj08150 *)p)->fB0, *(u8 * *)&((struct Obj08150 *)p)->fB4 + table[((u8 *)&order)[i]], 1);
        }
    }
}

void func_021F9140(u8 *p, u8 n, u8 i)
{
    void *table;
    u16 score;
    table = func_0204A380((void *)(((struct Obj05397 *)p)->f18), n + 0x37, 0, ((struct Obj05397 *)p)->f0);
    score = *(u16 *)(*(u8 **)(*(u8 * *)&((struct Obj05397 *)p)->f30 + i * 4 + 4) + 0x4a);
    if (score >= 70) {
        func_021FAD0C(((struct Obj05397 *)p)->fB0, table, 0, (u8)(1 << i));
    } else if (score >= 40) {
        func_021FAD0C(((struct Obj05397 *)p)->fB0, table, 1, (u8)(1 << i));
    } else {
        func_021FAD0C(((struct Obj05397 *)p)->fB0, table, 2, (u8)(1 << i));
    }
}

void func_021F91A8(char *p, u8 n, u8 mask){void *table;table=func_0204A380((void *)(((struct Obj10531 *)p)->f18),n+0x4b,0,((struct Obj10531 *)p)->f0);func_021FAD0C(((struct Obj10531 *)p)->fB0,table,0,mask);}

/*
 * Palette fade, 16 colours. The object holds a u16 phase at +0x168 (advanced by 0x160, wrapped at
 * 0x10000), 16 base colours at +0x16A, s8 red, green and blue deltas at +0x18A, +0x19A, +0x1AA,
 * and 16 output colours at +0x1BA. The factor is (cos table entry + 0x1000) / 2. Each channel gets
 * (s8 delta * factor >> 12) added, then the colours go to func_02061CA4(31, 0, out, 32).
 * Twins for the channel pack: ov068 021B9D68, ov104 021B89DC.
 * What closed it: a struct view of the object (p->phase, p->base[i], p->out[i]) with no colour
 * local (every channel reads p->base[i], CSE keeps one load), which makes the allocator spill p
 * instead of p + 2i; compound assignment `p->phase += 0x160` in the else wrap
 * arm (the else arm then recomputes the sum, as the image does); `u8 i` declared before
 * `int factor`. final push 2026-10-05 G9L6.
 */
void func_021F91CC(Fade *p)
{
    u8 i;
    int factor;
    if (p->phase + 0x160 >= 0x10000)
        p->phase = p->phase - 0xFEA0;
    else
        p->phase += 0x160;
    factor = (d_020A1B38[(p->phase >> 4) * 2] + 0x1000) / 2;
    for (i = 0; i < 16; i++) {
        u8 b = (p->base[i] & 0x7C00) >> 10;
        u8 r = p->base[i] & 0x1F;
        u8 g = (p->base[i] & 0x3E0) >> 5;
        int B = b + (s8)((p->db[i] * factor) >> 12);
        int R = r + (s8)((p->dr[i] * factor) >> 12);
        int G = g + (s8)((p->dg[i] * factor) >> 12);
        p->out[i] = (B << 10) | (R | (G << 5));
    }
    func_02061CA4((void *)31, 0, (u32)p->out, 32);
}
