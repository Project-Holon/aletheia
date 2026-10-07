/*
 * file:     unit_021BA81C_p03.c
 * unit:     yes
 * function: func_021BA928, func_021BA978, func_021BAAB8, func_021BAADC
 * address:  0x021BA928
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020286C4  0x020286C4  thumb
 *   func_02028484  0x02028484  thumb
 *   func_0201CE48  0x0201CE48  thumb
 *   func_02012FFC  0x02012FFC  thumb
 *   func_021BA8D4  0x021BA8D4  thumb  ov099
 *   func_021BA8BC  0x021BA8BC  thumb  ov099
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_020450F0  0x020450F0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_02028470  0x02028470  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_0201DD68 0x0201DD68 thumb
 */
#include "../../matched/include/Obj13683.h"
#include "../../matched/include/Obj13684.h"

struct Ctx;
struct Blk;
struct Rec3;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct PrintSys;
struct WordSet;
typedef unsigned char  u8;

typedef unsigned long  u32_021BA928;

typedef signed int     s32_021BA928;

typedef struct {
    char pad00[0x190];
    int f190;
    char pad194[0x28];
    void *f1bc;
    char pad1c0[0x26c - 0x1c0];
    char f26c[0x744];
    void *f9b0;
} W;

typedef unsigned short u16;

typedef unsigned int u32_021BA978;

typedef signed short   s16;

typedef unsigned long  u32_021BAAB8;

typedef signed char    s8;

typedef signed long    s32_021BAAB8;

typedef int BOOL;

extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern s32_021BA928 func_02028484(struct Blk *blk, void *h);
extern void func_0201CE48(struct Rec3 *p);
extern signed char func_02012FFC(void);
extern void func_021BA8D4(char *p);
extern int func_021BA8BC(void *p);
extern u32_021BA978 func_0201C6B4(const struct PrintSys *p);
extern void func_0201C6EC(struct PrintSys *p);
extern u32_021BA978 func_020450F0(u32_021BA978 layer, u32_021BA978 a, u32_021BA978 b, u32_021BA978 tiles, u8 c, u8 d, u8 slot);
extern void func_02045CAC(struct MsgBank *bank, u32_021BA978 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern u32_021BA978 func_0201CCE4(u32_021BA978 a, u32_021BA978 b, u32_021BA978 c, u32_021BA978 d, u32_021BA978 e, u32_021BA978 f, u32_021BA978 g, u32_021BA978 h, u32_021BA978 i, u32_021BA978 j);
extern void func_02028470(u8 *p, u32_021BA978 v);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32_021BA978 a);
extern void func_0201DD68(void);
int func_021BA928(W *w);
void func_021BA978(char *p, int a1, int a2, int a3);
void func_021BAAB8(char *p, int a, int b);
void func_021BAADC(char *p, int a, int b);


int func_021BA928(W *w)
{
    int r = 1;
    if (w->f1bc != 0) {
        if (w->f190 != 0) {
            func_020286C4(w->f9b0, w->f1bc, (void *)w->f190);
        }
        r = func_02028484((struct Blk *)w->f26c, w->f1bc);
        if (r != 0 && w->f1bc != 0) {
            func_0201CE48(w->f1bc);
            w->f1bc = 0;
        }
    }
    return r;
}


void func_021BA978(char *p, int a1, int a2, int a3)
{
    int k, e;
    func_02012FFC();
    func_021BA8D4(p);
    *(u32_021BA978 *)(p + 0x190) = (u32_021BA978)func_021BA8BC((void *)(*(u32_021BA978 *)(p + 0x190)));
    if ((int)func_0201C6B4((const struct PrintSys *)(*(u32_021BA978 *)(p + 0x1B8))) == 0)
        func_0201C6EC((struct PrintSys *)(*(u32_021BA978 *)(p + 0x1B8)));
    if (*(u32_021BA978 *)(p + 0x1BC) != 0) {
        func_0201CE48((struct Rec3 *)(*(u32_021BA978 *)(p + 0x1BC)));
        *(u32_021BA978 *)(p + 0x1BC) = 0;
    }
    *(u32_021BA978 *)(p + 0x190) = func_020450F0(2, 2, 0x13, 0x1B, (u32_021BA978)4, (u32_021BA978)0xF, (u32_021BA978)1);
    if (a2)
        func_02045CAC((struct MsgBank *)(*(u32_021BA978 *)(p + 0xE4)), a1, (void *)(*(u32_021BA978 *)(p + 0xF0)));
    else
        func_02045CAC((struct MsgBank *)(*(u32_021BA978 *)(p + 0xE0)), a1, (void *)(*(u32_021BA978 *)(p + 0xF0)));
    func_0201F250((struct WordSet *)(*(u32_021BA978 *)(p + 0xDC)), (void *)(*(u32_021BA978 *)(p + 0xF4)), (void *)(*(u32_021BA978 *)(p + 0xF0)));
    k = 0xFF;
    func_02043B5C(func_02045770((struct Descriptor *)(*(u32_021BA978 *)(p + 0x190))), (u32_021BA978)k);
    e = 0xE;
    func_0201F73C((void *)(*(u32_021BA978 *)(p + 0x190)), (u32_021BA978)1, (u16)(*(u32_021BA978 *)(p + 0x1334)), (u32_021BA978)e);
    if (a3 == 0) {
        func_0201C7A4(func_02045770((struct Descriptor *)(*(u32_021BA978 *)(p + 0x190))), (u32_021BA978)0, (u32_021BA978)0, (void *)(*(u32_021BA978 *)(p + 0xF4)), (void *)(*(u32_021BA978 *)(p + 0xE8)));
    } else {
        u32_021BA978 t = func_02012FFC();
        *(u32_021BA978 *)(p + (k + 0xBD)) = func_0201CCE4(*(u32_021BA978 *)(p + 0x190), 0, 0, *(u32_021BA978 *)(p + 0xF4), *(u32_021BA978 *)(p + 0xE8), t, *(u32_021BA978 *)(p + e * 0x20), 2, 0x21, 0xF);
        func_02028470((u8 *)(p + 0x26C), 2);
    }
    func_02045334((struct Descriptor *)(*(u32_021BA978 *)(p + 0x190)));
    func_02045374((struct Cfg *)(*(u32_021BA978 *)(p + 0x190)));
    func_02041B6C(2);
}


void func_021BAAB8(char *p, int a, int b)
{
    ((struct Obj13683 *)p)->f19C = (void *)func_021BA8BC(((struct Obj13683 *)p)->f19C);
    func_021BA978(p, a, b, 1);
}

/*
 * note: Two bytes of alignment padding follow at 0x021BAB02.
 */
void func_021BAADC(char *p, int a, int b)
{
    *(int *)&((struct Obj13684 *)p)->f19C = func_021BA8BC(((struct Obj13684 *)p)->f19C);
    func_0201DD68();
    func_021BA978(p, a, b, 0);
}
