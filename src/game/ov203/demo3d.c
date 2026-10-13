/*
 * file:     demo3d.c
 * unit:     yes
 * function: func_021BDA40, func_021BDB20, func_021BDB64, func_021BDC20, func_021BDC88, func_021BDCC0, func_021BDD18, func_021BDD30, func_021BDD40
 * address:  0x021BDA40
 * region:   ov203
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02034AC4 0x02034AC4 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021BDDD8 0x021BDDD8 thumb ov203
 *   func_02045B38 0x02045B38 arm
 *   func_0201C440 0x0201C440 thumb
 *   func_02040588 0x02040588 arm
 *   func_020434DC 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   func_021BE160 0x021BE160 thumb ov203
 *   func_021BE62C 0x021BE62C thumb ov203
 *   func_021BE948 0x021BE948 thumb ov203
 *   ov067_id 0x00000043 data a1
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_021BE4B4 0x021BE4B4 thumb ov203
 *   func_021BDE98 0x021BDE98 thumb ov203
 *   func_021BDF00 0x021BDF00 thumb ov203
 *   func_021BE538 0x021BE538 thumb ov203
 *   func_021BE620 0x021BE620 thumb ov203
 *   func_021BE638 0x021BE638 thumb ov203
 *   d_02FFFC3C 0x02FFFC3C data
 *   WIPE_SetMstBrightColor 0x02022268 thumb
 *   FADE_GetSpeed 0x0204E6E0 arm
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   func_020362DC 0x020362DC arm
 *   func_02030734 0x02030734 arm
 *   d_021C3CC0 0x021C3CC0 data a1
 *   d_021C3BC4 0x021C3BC4 data a4
 *   func_020307B0 0x020307B0 arm
 *   func_0204044C 0x0204044C arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   d_021BFB7C 0x021BFB7C data a2
 *   BRIGHTNESS_ChangeReset  0x02023F98  thumb  arm9
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb  arm9
 */
#include "../../matched/include/Obj06663.h"
#include "../../matched/include/Obj06664.h"
#include "../../matched/include/Obj01433.h"
#include "../../matched/include/Obj14585.h"
#include "../../matched/include/Obj25305.h"
#include "../../matched/include/Obj25306.h"
#include "../../matched/include/Obj25307.h"
#include "../../matched/include/Obj25308.h"

#define DISP3DCNT (*(volatile unsigned short *)0x04000060)
struct Obj0203159C;
struct MsgBank;
struct Cfg;
struct Ctx;
struct PrintSys;
struct Rec;
struct S020315D4;
struct Context;
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct Work { u16 heap, pad; void *arg; int state; void *view, *str, *msg, *model, *ctx; int tail[3]; } Work;

typedef unsigned int   u32;

typedef struct Context Context;

typedef struct Methods { void (*init)(Context *); } Methods;

struct Context { unsigned short heap, pad; void *a, *b; const Methods *methods; void *work; int flag; };

typedef enum { ShadingToon = 0, ShadingHighlight = 1 } GXShading;

extern int func_02034AC4(int);
extern void GFL_HEAP_CreateChildHeap(unsigned, unsigned, unsigned);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, unsigned int size, unsigned int heap);
extern void func_02082BCC(void *, int, unsigned);
extern void *func_021BDDD8(unsigned, void *, unsigned);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern unsigned func_0201C440(void *);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020434DC(unsigned, unsigned);
extern void BG_SYS_SetSubPlaneVisible(unsigned, unsigned);
extern struct Ctx *func_021BE160(void *owner, struct Cfg *cfg, u16 heap);
extern u32 func_021BE62C(char *p);
extern void func_021BE948(void *, int, u8 *, u8 *);
extern void BRIGHTNESS_ChangeReset(u32 mask);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_021BE4B4(char *ctx);
extern void func_021BDE98(char *ctx);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32 heap);
extern void func_02034A5C(int);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void func_021BDF00(unsigned char *);
extern int func_021BE538(const struct Context *ctx, u32 frames);
extern int func_021BE620(char *p);
extern void func_021BE638(char *p, int a);
extern u32 WIPE_SYS_EndCheck(void);
extern void WIPE_SetMstBrightColor(unsigned);
extern unsigned FADE_GetSpeed(void);
extern void WIPE_SYS_Start(void *, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
extern unsigned func_020362DC(void);
extern void *func_02030734(unsigned, unsigned, int, const char *, unsigned short);
extern u32 func_020307B0(void *p);
extern void func_0204044C(unsigned);
extern void G3X_SetFog(int, int, int, int);
extern void G3X_SetClearColor(unsigned short, int, int, int, int);
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);
extern void G3D_SYSTEM_SetSwapBuffersMode(unsigned, unsigned);
int func_021BDA40(void *manager, int unused, u8 *p);
int func_021BDB20(void *a, void *b, void *c, char *work);
int func_021BDB64(void *unused, int *state, void *c, char *work);
int func_021BDC20(void *ctx, unsigned mode, unsigned heap);
int func_021BDC88(char *p);
Context *func_021BDCC0(int mode, void *a, void *b, unsigned heap);
void func_021BDD18(char *a);
void func_021BDD30(char *a);
void func_021BDD40(void);
extern const char ov067_id[];
extern unsigned int d_02FFFC3C;
extern const char d_021C3CC0[];
extern const Methods d_021C3BC4;
extern const unsigned short d_021BFB7C[][4];


int func_021BDA40(void *manager, int unused, u8 *p)
{
    Work *w;
    u8 width, height;
    int delta;
    unsigned one = 1;
    unsigned heap = 0x6c;
    func_02034AC4((int)ov067_id);
    GFL_HEAP_CreateChildHeap(1, 0x6c, 0x130000);
    w = PROCSYS_AllocProcWork(manager, sizeof(Work), 0x6c);
    func_02082BCC(w, 0, sizeof(Work));
    w->heap = heap;
    w->arg = p;
    w->view = func_021BDDD8(1, ((struct Obj06663 *)p)->f4, w->heap);
    w->msg = func_02045B38(0, 2, 0x41, w->heap);
    w->str = (void *)func_0201C440((void *)w->heap);
    func_02040588(6, 0);
    func_02040588(4, 0);
    func_02040588(3, 0);
    func_02040588(2, 0);
    func_02040588(1, 0);
    func_020434DC(0x10, 0);
    BG_SYS_SetSubPlaneVisible(0x10, 0);
    w->model = func_021BE160(w->view, (struct Cfg *)p, w->heap);
    w->ctx = func_021BDCC0(*(int *)&((struct Obj06663 *)p)->f4, w->view, w->model, w->heap);
    delta = func_021BE62C(w->model) - ((struct Obj06663 *)p)->f8;
    func_021BE948(((struct Obj06663 *)p)->f4, 0, &width, &height);
    if (delta > height) func_021BDC20((void *)(u8)*(unsigned *)&((struct Obj06663 *)p)->f4, one, w->heap);
    return 1;
}


int func_021BDB20(void *a, void *b, void *c, char *work)
{
    BRIGHTNESS_ChangeReset(3);
    func_021BDD18(*(char * *)&((struct Obj06664 *)work)->f1C);
    MSGDATA_Delete(((struct Obj06664 *)work)->f14);
    func_0201C4C0(((struct Obj06664 *)work)->f10);
    func_021BE4B4(((struct Obj06664 *)work)->f18);
    func_021BDE98(((struct Obj06664 *)work)->fC);
    func_020315D4(a);
    func_020306F0(0x6c);
    func_02034A5C((int)ov067_id);
    return 1;
}



int func_021BDB64(void *unused, int *state, void *c, char *work)
{
    int result;
    unsigned int now, delta;
    func_021BDD30(*(char * *)&((struct Obj01433 *)work)->f1C);
    PRINTSYS_QUE_Main(((struct Obj01433 *)work)->f10);
    func_021BDF00(*(unsigned char * *)&((struct Obj01433 *)work)->fC);
    result = func_021BE538(((struct Obj01433 *)work)->f18, ((struct Obj01433 *)work)->f24);
    now = d_02FFFC3C;
    delta = now - ((struct Obj01433 *)work)->f20;
    ((struct Obj01433 *)work)->f24 = 0;
    if (((struct Obj01433 *)work)->f20 != 0 && delta > 1)
        ((struct Obj01433 *)work)->f24 = delta - 1;
    ((struct Obj01433 *)work)->f20 = now;
    ((struct Obj01433 *)work)->f28 = ((struct Obj01433 *)work)->f28 + ((struct Obj01433 *)work)->f24;
    switch (*state) {
    case 0:
        if (func_021BDC88(work) != 0 || result != 0) {
            (*(int **)(work + 4))[4] = func_021BE620(((struct Obj01433 *)work)->f18) >> 12;
            (*(int **)(work + 4))[5] = result + 1;
            func_021BE638(((struct Obj01433 *)work)->f18, (*(int **)(work + 4))[5]);
            (*state)++;
        }
        break;
    case 1:
        if (WIPE_SYS_EndCheck() == 1) {
            if (func_021BDC20((void *)((unsigned char)(*(int **)(work + 4))[1]), 0, ((struct Obj01433 *)work)->f0))
                return 1;
            (*state)++;
        }
        break;
    case 2:
        if (WIPE_SYS_EndCheck() == 1)
            return 1;
        break;
    }
    return 0;
}



int func_021BDC20(void *ctx, unsigned mode, unsigned heap)
{
    unsigned char width, height;
    unsigned char factor;
    int color;
    func_021BE948(ctx, (unsigned char)(mode == 0), &width, &height);
    color = 0;
    if (width) color = 32767;
    WIPE_SetMstBrightColor(color);
    if (height) {
        factor = FADE_GetSpeed();
        WIPE_SYS_Start(0, mode, mode, color, height * factor, 1, heap);
        return 0;
    }
    return 1;
}



int func_021BDC88(char *p){if(((struct Obj25305 *)(*(char * *)&((struct Obj14585 *)p)->f4))->f14!=0||!WIPE_SYS_EndCheck())return 0;if(((struct Obj25306 *)(*(char * *)&((struct Obj14585 *)p)->f1C))->f14!=0){if(func_020362DC()&0xcf3)return 1;}return 0;}



Context *func_021BDCC0(int mode, void *a, void *b, unsigned heap)
{
    Context *ctx;
    ctx = func_02030734(heap, 24, 1, d_021C3CC0, 0x1e1);
    ctx->a = a;
    ctx->b = b;
    ctx->heap = heap;
    ctx->methods = 0;
    ctx->flag = 0;
    if (mode == 1) {
        ctx->methods = &d_021C3BC4;
        ctx->flag = 1;
    }
    if (ctx->methods) ctx->methods->init(ctx);
    return ctx;
}




void func_021BDD18(char *a)
{
    void **p = *(void ** *)&((struct Obj25307 *)a)->fC;

    if (p)
        ((void (*)(void *))p[2])(a);
    func_020307B0(a);
}




void func_021BDD30(char *a)
{
    void **p = *(void ** *)&((struct Obj25308 *)a)->fC;

    if (p)
        ((void (*)(void *))p[1])(a);
}



static inline void G3X_SetShading(GXShading shading) { DISP3DCNT = (unsigned short)((DISP3DCNT & ~0x3002) | (shading << 1)); }



static inline void G3X_AntiAlias(int enable) { if (enable) DISP3DCNT = (unsigned short)(DISP3DCNT & ~0x3000 | 16); else DISP3DCNT &= (unsigned short)~0x3010; }



static inline void G3X_AlphaTest(int enable, int ref) { if (enable) { DISP3DCNT = (unsigned short)(DISP3DCNT & ~0x3000 | 4); *(volatile unsigned short *)0x04000340 = ref; } else DISP3DCNT &= (unsigned short)~0x3004; }



static inline void G3X_AlphaBlend(int enable) { if (enable) DISP3DCNT = (unsigned short)(DISP3DCNT & ~0x3000 | 8); else DISP3DCNT &= (unsigned short)~0x3008; }



static inline void G3X_EdgeMarking(int enable) { if (enable) DISP3DCNT = (unsigned short)(DISP3DCNT & ~0x3000 | 32); else DISP3DCNT &= (unsigned short)~0x3020; }



void func_021BDD40(void)
{
    unsigned i = 0;
    func_0204044C(0);
    G3X_SetShading(ShadingHighlight);
    G3X_AntiAlias(0);
    G3X_AlphaTest(0, 0);
    G3X_AlphaBlend(1);
    G3X_EdgeMarking(0);
    G3X_SetFog(0, 0, 0, 0);
    G3X_SetClearColor(0, 0, 32767, 63, 0);
    *(volatile unsigned *)0x04000580 = 0xbfff0000;
    for (; i < 4; i++) G3D_SYSTEM_SetLight((unsigned char)i, d_021BFB7C[i]);
    G3D_SYSTEM_SetSwapBuffersMode(0, 0);
}
