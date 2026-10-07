/*
 * file:     demo3d_p03.c
 * unit:     yes
 * function: func_021BDC88, func_021BDCC0, func_021BDD18, func_021BDD30, func_021BDD40
 * address:  0x021BDC88
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
 *   func_020221A4 0x020221A4 thumb
 *   func_020362DC 0x020362DC arm
 *   func_02030734 0x02030734 arm
 *   d_021C3CC0 0x021C3CC0 data a1
 *   d_021C3BC4 0x021C3BC4 data a4
 *   func_020307B0 0x020307B0 arm
 *   func_0204044C 0x0204044C arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0207DD24 0x0207DD24 arm
 *   func_02046A94 0x02046A94 arm
 *   func_02046BE0 0x02046BE0 arm
 *   d_021BFB7C 0x021BFB7C data a2
 */
#include "../../matched/include/Obj14585.h"
#include "../../matched/include/Obj25305.h"
#include "../../matched/include/Obj25306.h"
#include "../../matched/include/Obj25307.h"
#include "../../matched/include/Obj25308.h"

#define DISP3DCNT (*(volatile unsigned short *)0x04000060)
typedef struct Context Context;

typedef struct Methods { void (*init)(Context *); } Methods;

struct Context { unsigned short heap, pad; void *a, *b; const Methods *methods; void *work; int flag; };

typedef unsigned int   u32;

typedef enum { ShadingToon = 0, ShadingHighlight = 1 } GXShading;

typedef unsigned short u16;

extern unsigned func_020221A4(void);
extern unsigned func_020362DC(void);
extern void *func_02030734(unsigned, unsigned, int, const char *, unsigned short);
extern u32 func_020307B0(void *p);
extern void func_0204044C(unsigned);
extern void func_0207DC44(int, int, int, int);
extern void func_0207DD24(unsigned short, int, int, int, int);
extern void func_02046A94(u32 idx, const u16 *src);
extern void func_02046BE0(unsigned, unsigned);
int func_021BDC88(char *p);
Context *func_021BDCC0(int mode, void *a, void *b, unsigned heap);
void func_021BDD18(char *a);
void func_021BDD30(char *a);
void func_021BDD40(void);
extern const char d_021C3CC0[];
extern const Methods d_021C3BC4;
extern const unsigned short d_021BFB7C[][4];

int func_021BDC88(char *p){if(((struct Obj25305 *)(*(char * *)&((struct Obj14585 *)p)->f4))->f14!=0||!func_020221A4())return 0;if(((struct Obj25306 *)(*(char * *)&((struct Obj14585 *)p)->f1C))->f14!=0){if(func_020362DC()&0xcf3)return 1;}return 0;}

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
    func_0207DC44(0, 0, 0, 0);
    func_0207DD24(0, 0, 32767, 63, 0);
    *(volatile unsigned *)0x04000580 = 0xbfff0000;
    for (; i < 4; i++) func_02046A94((unsigned char)i, d_021BFB7C[i]);
    func_02046BE0(0, 0);
}
