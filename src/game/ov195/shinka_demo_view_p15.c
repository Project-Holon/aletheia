/*
 * file:     shinka_demo_view_p15.c
 * unit:     yes
 * function: func_022086C8, func_02208714, func_0220871C, func_02208770, func_0220878C, func_02208804, func_02208814, func_0220882C, func_02208844, func_02208850, func_02208860, func_0220887C, func_02208994
 * address:  0x022086C8
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
 *   d_02208F7C 0x02208F7C data
 *   func_02030734 0x02030734 arm
 *   func_0207ADC4 0x0207ADC4 arm
 *   func_020307B0 0x020307B0 arm
 *   d_02208ED0 0x02208ED0 data
 *   func_02208A54 0x02208A54 thumb ov195
 *   func_02208AB0 0x02208AB0 thumb ov195
 *   func_02208B54 0x02208B54 thumb
 *   func_02208A6C 0x02208A6C thumb
 *   func_02208C10 0x02208C10 thumb ov195
 *   func_02208C18 0x02208C18 thumb ov195
 *   func_02208C28 0x02208C28 thumb ov195
 *   func_02208C30 0x02208C30 thumb ov195
 *   func_02208A48 0x02208A48 thumb ov195
 *   func_02208B6C 0x02208B6C thumb ov195
 *   func_022089A4 0x022089A4 thumb ov195
 *   func_02208A78 0x02208A78 thumb
 *   func_02208A24 0x02208A24 thumb
 *   func_02208A38 0x02208A38 thumb
 *   func_02208A2C  0x02208A2C  thumb
 *   d_02208F24 0x02208F24 data
 *   d_02208F30 0x02208F30 data
 *   d_02208E9C 0x02208E9C data
 *   FX_SinCosTable_ 0x020A1B38 data
 *   func_02050B80 0x02050B80 arm
 *   func_02050C30 0x02050C30 arm
 *   func_02051758 0x02051758 arm
 *   func_02051648 0x02051648 arm
 *   func_0205121C 0x0205121C arm
 *   func_02051B04 0x02051B04 arm
 *   func_02051230 0x02051230 arm
 *   func_02050ED4 0x02050ED4 arm
 */
#include "../../matched/include/Obj05518.h"
#include "../../matched/include/Obj08350.h"
#include "../../matched/include/Obj10830.h"

struct Ptc;
struct Anim;
struct Dst648;
struct Src648;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef s32 fx32;

typedef struct Node {
    u16 f00;
    u16 pad02;
    fx32 tx, ty, tz;
    fx32 sx, sy, sz;
    u8 mtx[0x24];
    u8 pad40[4];
} Node;

typedef struct Anim_0220871C {
    u16 heap;
    u16 pad02;
    u32 f04;
    u32 f08;
    u32 f0c;
    void *ptc;
    void *res;
    u16 f18;
    u16 f1a;
    u16 count;
    u16 pad1e;
    void *nodes;
    u32 f24;
    u32 f28;
} Anim_0220871C;

typedef struct Anim_0220878C {
    u16 heap;
    u16 pad02;
    u32 f04;
    u32 state;
    u32 wait;
    void *ptc;
} Anim_0220878C;

typedef signed short s16;

typedef struct VecFx32 {
    fx32 x, y, z;
} VecFx32;

typedef struct EmitParam {
    u32 f00;
    fx32 f04;
    fx32 f08;
    u32 f0c;
    u32 f10;
    fx32 f14;
    u32 f18;
    u32 f1c;
} EmitParam;

typedef struct Ptc {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 pad06;
    void *f08;
    u8 work[0x4800];
    void *spl;
    u8 f4810;
    u8 pad4811[3];
    u32 f4814;
    s32 f4818;
} Ptc;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_0207ADC4(void *);
extern u32 func_020307B0(void *p);
extern void func_02208A54(char *a);
extern void func_02208AB0(Anim_0220871C *p);
extern void func_02208B54(char *a);
extern void func_02208A6C(char *p);
extern void func_02208C10(Anim_0220878C *p);
extern int func_02208C18(Anim_0220878C *p);
extern void func_02208C28(Anim_0220878C *p);
extern int func_02208C30(Anim_0220878C *p);
extern void func_02208A48(struct Ptc *p, s32 timer);
extern void func_02208B6C(char *p);
extern void func_022089A4(struct Ptc *p);
extern void func_02208A78(struct Anim *p);
extern void func_02208A24(int);
extern void func_02208A38(char *p, u32 v);
extern void func_02050B80(u32 heap);
extern void *func_02050C30(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 heap);
extern int func_02051758(int a0);
extern void func_02051648(struct Dst648 *this, struct Src648 *src, u16 a2, int *a3, int *a4, int *a5, u32 a6);
extern int func_0205121C(u32 a, u32 b, u32 c);
extern u16 func_02051B04(void *res);
extern void func_02051230(void *spl, u32 res, u32 a2, u32 a3);
extern void func_02050ED4(void);
Node *func_022086C8(u16 heap, u16 n);
void func_02208714(void *p);
Anim_0220871C *func_0220871C(u16 heap, u32 x);
void func_02208770(char *a);
void func_0220878C(Anim_0220878C *p);
void func_02208804(char *a);
void func_02208814(char *a);
void func_0220882C(int *p);
void func_02208844(int *p);
int func_02208850(int *p);
int func_02208860(int *p);
Ptc *func_0220887C(u16 heap, u16 a, void *b);
void func_02208994(char *a);
extern char d_02208F7C[];
extern char d_02208ED0[];
extern const VecFx32 d_02208F24;
extern const VecFx32 d_02208F30;
extern const u32 d_02208E9C[2];
extern s16 FX_SinCosTable_[];


Node *func_022086C8(u16 heap, u16 n)
{
    Node *p = func_02030734(heap, n * sizeof(Node), 1, d_02208F7C, 0xe8);
    u16 i;

    for (i = 0; i < n; i++) {
        p[i].tx = 0;
        p[i].ty = 0;
        p[i].tz = 0;
        p[i].sx = 0x1000;
        p[i].sy = 0x1000;
        p[i].sz = 0x1000;
        func_0207ADC4(p[i].mtx);
    }
    return p;
}

void func_02208714(void *p){func_020307B0(p);}


Anim_0220871C *func_0220871C(u16 heap, u32 x)
{
    Anim_0220871C *p = func_02030734(heap, sizeof(Anim_0220871C), 1, d_02208F7C, 0x150);

    p->heap = heap;
    p->f04 = x;
    if (x == 0)
        p->f08 = 0;
    else
        p->f08 = 7;
    p->f0c = 0;
    p->ptc = func_0220887C(p->heap, 9, d_02208ED0);
    func_02208A54((char *)p);
    func_02208AB0(p);
    return p;
}


void func_02208770(char *a)
{
    func_02208B54(a);
    func_02208A6C(a);
    func_02208994((char *)(((struct Obj05518 *)a)->f10));
    func_020307B0(a);
}


void func_0220878C(Anim_0220878C *p)
{
    switch (p->state) {
    case 0:
    case 1:
        break;
    case 2:
        func_02208C10(p);
        p->state = 3;
        break;
    case 3:
        if (func_02208C18(p)) {
            p->state = 4;
            p->wait = 3;
            func_02208A48(p->ptc, 0);
        }
        break;
    case 4:
        if (p->wait == 0) {
            func_02208C28(p);
            p->state = 5;
        } else {
            p->wait = p->wait - 1;
        }
        break;
    case 5:
        if (func_02208C30(p))
            p->state = 6;
        break;
    case 6:
    case 7:
        break;
    }
    func_02208B6C((char *)p);
    func_022089A4(p->ptc);
}


void func_02208804(char *a)
{
    func_02208A78((struct Anim *)a);
    func_02208A24(((struct Obj08350 *)a)->f10);
}


void func_02208814(char *a)
{
    func_02208A38((char *)(((struct Obj10830 *)a)->f10), 0x1e);
    if (((struct Obj10830 *)a)->f8 == 1)
        ((struct Obj10830 *)a)->f8 = 2;
}

/*
 * Move the ov195 scene object to state 1 with a 0x26c timer.  Labelled leaf.
 */
void func_0220882C(int *p)
{
    void func_02208A2C(char *p);

    func_02208A2C((char *)p[4]);
    p[2] = 1;
    p[3] = 0x26c;
}

/*
 * Flag bump on the ov195 scene object (+8 == 1 -> 2); unlabelled leaf.
 */
void func_02208844(int *p)
{
    if (p[2] == 1)
        p[2] = 2;
}

/*
 * True when the ov195 scene object's +8 state is 4; unlabelled leaf.
 */
int func_02208850(int *p)
{
    if (p[2] == 4)
        return 1;
    return 0;
}

/*
 * Camera-state predicate on the ov195 scene object's +8/+0xc words:
 * state 4 with +0xc <= 1, or state 5.  Unlabelled leaf.
 */
int func_02208860(int *p)
{
    if (p[2] == 4 && (unsigned)p[3] <= 1)
        return 1;
    if (p[2] == 5)
        return 1;
    return 0;
}


/*
 * promoted: from src/pending on 2026-09-27, no C change. Its blocker, the
 *   call at +0xD8 to the unlabelled ARM leaf 0x02051B04, closed when that
 *   leaf was seeded in layout/function_starts.txt and matched
 *   (src/matched/func_02051B04.c); all 13 relocations resolve.
 */
Ptc *func_0220887C(u16 heap, u16 a, void *b)
{
    VecFx32 v1 = d_02208F24;
    VecFx32 v2 = d_02208F30;
    VecFx32 v3 = {0, 0, 0};
    EmitParam prm;
    Ptc *p;
    u32 res;

    prm.f00 = 0;
    prm.f04 = FX_SinCosTable_[0xe3 * 2];
    prm.f08 = FX_SinCosTable_[0xe3 * 2 + 1];
    prm.f0c = 0x1555;
    prm.f10 = 0;
    prm.f14 = 0x1000;
    prm.f18 = 0x400000;
    prm.f1c = 0;

    p = func_02030734(heap, sizeof(Ptc), 1, d_02208F7C, 0x2e5);
    p->f00 = 0;
    p->f02 = 0;
    p->f04 = a;
    p->f08 = b;
    p->f4814 = 0;
    p->f4818 = -1;
    func_02050B80(heap);
    p->spl = func_02050C30((u32)p->work, sizeof(p->work), 1, 5, 6, 0x3b, heap);
    func_02051758((int)p->spl);
    func_02051648(p->spl, (struct Src648 *)(&prm), 0x2000, (int *)(&v1), (int *)(&v2), (int *)(&v3), heap);
    res = func_0205121C(d_02208E9C[0], d_02208E9C[1], heap);
    p->f4810 = func_02051B04((void *)res);
    func_02051230(p->spl, res, 1, 0);
    return p;
}


void func_02208994(char *a)
{
    func_02050ED4();
    func_020307B0(a);
}
