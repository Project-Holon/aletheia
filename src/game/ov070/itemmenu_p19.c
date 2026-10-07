/*
 * file:     itemmenu_p19.c
 * unit:     yes
 * function: func_021BACF0, func_021BADAC, func_021BADB8, func_021BADF0, func_021BAE98, func_021BAF10, func_021BAF38, func_021BAFC4
 * address:  0x021BACF0
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_021BB6E0  0x021BB6E0  thumb  ov070
 *   func_0201F73C  0x0201F73C  thumb
 *   func_021BB724  0x021BB724  thumb  ov070
 *   func_02045CAC 0x02045CAC arm
 *   func_021B61F4 0x021B61F4 thumb ov070
 *   func_0201F250 0x0201F250 thumb
 *   func_0201CE30  0x0201CE30  thumb
 *   func_020286C4  0x020286C4  thumb
 *   func_0201CE48  0x0201CE48  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_02035C60  0x02035C60  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_0201CE38  0x0201CE38  thumb
 *   func_0203630C  0x0203630C  arm
 *   func_02035C38  0x02035C38  arm
 *   func_0201CE5C  0x0201CE5C  thumb
 *   func_021BA96C  0x021BA96C  thumb  ov070
 *   func_020452E8 0x020452E8 arm
 *   func_0201F14C  0x0201F14C  thumb
 *   func_0201D304  0x0201D304  thumb
 *   func_02012F08 0x02012F08 thumb
 *   func_0200C274 0x0200C274 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 */
#include "../../matched/include/Obj00002.h"
#include "../../matched/include/Obj04334.h"
#include "../../matched/include/Obj06177.h"
#include "../../matched/include/Obj06178.h"
#include "../../matched/include/Obj09882.h"
#include "../../matched/include/Obj01516.h"

#define P(k) (*(void **)((u32)p+(k)))
#define W(k) (*(u32 *)((u32)p+(k)))
struct Descriptor;
struct CharBuf;
struct MsgBank;
struct WordSet;
struct Ctx;
struct Rec;
struct Rec3;
struct StrObj;
struct Blk34;
typedef unsigned short u16;

typedef signed short s16_021BACF0;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed int     s32;

typedef signed short   s16_021BAF38;

typedef short s16_021BAFC4;

extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern signed char func_02012FFC(void);
extern int func_0201CCE4(int, int, int, int, int, int, int, int, int, int);
extern void func_021BB6E0(int p, u32 *obj, u32 str, u16 x, s16_021BACF0 y, u16 color);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_021BB724(void **p);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021B61F4(u8 *p, int a, unsigned int b);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201CE30(void *p);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern void func_0201CE48(struct Rec3 *p);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_020061E4(u32 a);
extern void func_0201CE38(void *p);
extern unsigned int func_0203630C(void);
extern int func_02035C38(void);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern void func_021BA96C(int, unsigned);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_0201F14C(struct WordSet *p, u32 i, u32 v);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void *func_02012F08(int *);
extern u32 func_0200C274(struct Blk34 *);
extern void func_0201EFA4(struct WordSet *,u32,u32,u32,u32,u32);
void func_021BACF0(int p, int mode);
void func_021BADAC(void *p);
void func_021BADB8(char *p, unsigned v);
int func_021BADF0(int p);
void func_021BAE98(int p);
void func_021BAF10(char *p);
void func_021BAF38(int p, int val);
void func_021BAFC4(u8 *p);


/*
 * Creates the window at p+0x4FC on first use, clears it, then either prints
 * through func_0201CCE4 (mode 1) or through func_021BB6E0, and finishes the
 * window. The window address is a named local taken after the clear calls:
 * without it the 0x4FC offset went to r4 and mode to r6, the mode-1 arm
 * consumed the offset register destructively and the join reloaded it
 * (4 bytes short).
 */
void func_021BACF0(int p, int mode)
{
    int win;

    if (((struct Obj00002 *)p)->f4FC == 0) {
        ((struct Obj00002 *)p)->f4FC = func_020450F0(3, 1, 1, 0x1E, 4, 0xC, 1);
    }
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)((struct Obj00002 *)p)->f4FC)), 0xF);
    func_02045334((struct Descriptor *)((struct Obj00002 *)p)->f4FC);
    win = p + 0x4FC;
    if (mode == 1) {
        ((struct Obj00002 *)p)->f510 = func_0201CCE4(((struct Obj00002 *)p)->f4FC, 0, 0, *(int *)&((struct Obj00002 *)p)->f528,
                                            ((struct Obj00002 *)p)->f530, func_02012FFC(),
                                            ((struct Obj00002 *)p)->f730, 2, ((struct Obj00002 *)p)->f544, 0xF);
    } else {
        func_021BB6E0(p, (u32 *)win, *(int *)&((struct Obj00002 *)p)->f528, 0, 0, 0x44F);
    }
    func_0201F73C((void *)(*(int *)&((struct Obj04334 *)win)->f0), 1, (u16)((struct Obj00002 *)p)->f838, 0xD);
    func_021BB724((void **)win);
}

/*
 * Tail call to func_021BACF0(p, 0).
 */
void func_021BADAC(void *p)
{
    void func_021BACF0(int p, int mode);
    func_021BACF0((int)p, 0);
}

void func_021BADB8(char *p, unsigned v) { func_02045CAC((struct MsgBank *)(((struct Obj06177 *)p)->f51C), 0x2B, (void *)(*(int *)&((struct Obj06177 *)p)->f524)); func_021B61F4((u8 *)p, 0, v); func_0201F250(((struct Obj06177 *)p)->f520, ((struct Obj06177 *)p)->f528, ((struct Obj06177 *)p)->f524); }


int func_021BADF0(int p)
{
    int r;

    if (((struct Obj00002 *)p)->f510 != 0) {
        r = func_0201CE30((void *)(((struct Obj00002 *)p)->f510));
        func_020286C4((struct Ctx *)(((struct Obj00002 *)p)->f518), (void *)(((struct Obj00002 *)p)->f510), (void *)(((struct Obj00002 *)p)->f4FC));
        switch (r) {
        case 2:
            func_0201CE48((struct Rec3 *)(((struct Obj00002 *)p)->f510));
            ((struct Obj00002 *)p)->f510 = 0;
            ((struct Obj00002 *)p)->f514 = 0;
            break;
        case 1:
            if (((struct Obj00002 *)p)->f514 == 0) {
                if ((func_020362DC() & 3) != 0 || func_02035C60() != 0) {
                    func_020061E4(0x547);
                    func_0201CE38((void *)(((struct Obj00002 *)p)->f510));
                    ((struct Obj00002 *)p)->f514 = 1;
                }
            }
            break;
        case 0:
            if ((func_0203630C() & 3) != 0 || func_02035C38() != 0) {
                func_0201CE5C((struct Rec *)(((struct Obj00002 *)p)->f510), 0);
            }
            ((struct Obj00002 *)p)->f514 = 0;
            break;
        }
        return 0;
    }
    return 1;
}


void func_021BAE98(int p)
{
    ((struct Obj06178 *)p)->f504 = func_020450F0(2, 3, 0x15, 0xC, 3, 0xC, 1);
    ((struct Obj06178 *)p)->f75C = func_020450F0(2, 1, 0x15, 8, 3, 0xC, 1);
    ((struct Obj06178 *)p)->f764 = func_020450F0(2, 9, 0x15, 9, 3, 0xC, 1);
    func_021BAF38(p, ((struct Obj06178 *)p)->f80C);
    func_021BA96C(p, ((struct Obj06178 *)p)->f80C);
}

void func_021BAF10(char *p) { func_020452E8(((struct Obj09882 *)p)->f504); func_020452E8(((struct Obj09882 *)p)->f764); func_020452E8(((struct Obj09882 *)p)->f75C); }


void func_021BAF38(int p, int val)
{
    int r;

    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)((struct Obj01516 *)p)->f504)), 0);
    func_02045CAC((struct MsgBank *)(((struct Obj01516 *)p)->f51C), 0x8B, (void *)(((struct Obj01516 *)p)->f524));
    func_0201F14C((struct WordSet *)(((struct Obj01516 *)p)->f520), 0, val);
    func_0201F250((struct WordSet *)(((struct Obj01516 *)p)->f520), (void *)(((struct Obj01516 *)p)->f528), (void *)(((struct Obj01516 *)p)->f524));
    r = 0x60 - func_0201D304((struct StrObj *)(((struct Obj01516 *)p)->f528), *(int *)&((struct Obj01516 *)p)->f530, 0);
    func_021BB6E0(p, (u32 *)(p + 0x504), ((struct Obj01516 *)p)->f528, (unsigned short)(r >> 1), 4, 0x3C40);
    func_021BB724((void **)(p + 0x504));
}

void func_021BAFC4(u8 *p)
{
 unsigned long win = 0x764;
 func_02043B5C(func_02045770(P(win)),0);
 func_02043B5C(func_02045770(*(void **)(p+(win-8))),0);
 func_02045CAC(P(0x51C),0x51,P(0x524));
 func_021BB6E0((int)p,(u32 *)((u32)p+(win-8)),W(0x524),0,4,0x3C40);
 func_021BB724((void **)((unsigned long)p+(win-8)));
 func_02045CAC(P(0x51C),0x52,P(0x524));
 func_0201EFA4(P(0x520),0,func_0200C274(func_02012F08(P(0))),7,1,1);
 func_0201F250(P(0x520),P(0x528),P(0x524));
 func_021BB6E0((int)p,(u32 *)((u32)p+win),W(0x528),0,4,0x3C40);
 func_021BB724((void **)((u32)p+win));
}
