/*
 * file:     worldtrade_enter_p06.c
 * unit:     yes
 * function: func_021F9024, func_021F9088, func_021F90A0, func_021F90B8, func_021F914C, func_021F91A0
 * address:  0x021F9024
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D5C70 0x021D5C70 thumb ov115
 *   func_021C8658 0x021C8658 arm ov114
 *   func_0216AD50 0x0216AD50 arm ov009
 *   func_0205CC20 0x0205CC20 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02202878 0x02202878 thumb ov135
 *   func_02202858 0x02202858 thumb ov135
 *   func_022026C4 0x022026C4 thumb ov135
 *   func_02045738 0x02045738 arm
 *   func_022028C8  0x022028C8  thumb  ov135
 */
#include "../../matched/include/Obj04528.h"
#include "../../matched/include/Obj02857.h"

struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
typedef unsigned char u8;

typedef signed short s16;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

extern int func_021D5C70(u8 *p);
extern void func_021C8658(void);
extern void func_0216AD50(void);
extern void func_0205CC20(void);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_0201F73C(void *, int, int, int);
extern void func_02202878(void *a, unsigned b, unsigned c, int d, int e, u8 *p);
extern u32 func_02202858(void *p, u8 b, void *s, u32 x, u32 y, void *out);
extern int func_022026C4(u32 *p, u32 b, u32 a, u32 c);
extern u8 func_02045738(struct Descriptor *p);
extern u32 func_022028C8(u8 *p, u32 z, u32 b, u32 r, u32 d, u32 z2, u16 f, u32 g);
int func_021F9024(u8 *p, void *dialog);
void func_021F9088(u32 a, u32 b, u32 c, u32 d, u16 e);
void func_021F90A0(u32 a, u32 b, u32 c, u32 d, u16 e);
void func_021F90B8(u8 *p, void *bank, u32 index, int unused1, int unused2, int slow);
int func_021F914C(void *win, void *str, int x, int align, int unused, int font, void *ctx);
int func_021F91A0(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g);

int func_021F9024(u8 *p, void *dialog)
{
    switch (((struct Obj04528 *)p)->fF88) {
    case 0:
        (((struct Obj04528 *)p)->fF88)++;
        break;
    case 1:
        if (func_021D5C70(dialog)) (((struct Obj04528 *)p)->fF88)++;
        break;
    case 2:
        (((struct Obj04528 *)p)->fF88)++;
        break;
    case 3:
        func_021C8658();
        func_0216AD50();
        func_0205CC20();
        (((struct Obj04528 *)p)->fF88)++;
        break;
    default:
        (((struct Obj04528 *)p)->fF8A)++;
        if (((struct Obj04528 *)p)->fF8A > 60) return 1;
        break;
    }
    return 0;
}


/*
 * Forward the u16 stack argument to func_021F90B8 with mode 1.
 */
void func_021F9088(u32 a, u32 b, u32 c, u32 d, u16 e)
{
    func_021F90B8((u8 *)a, (void *)b, c, d, e, 1);
}


/*
 * Forward the u16 stack argument to func_021F90B8 with mode 0.
 */
void func_021F90A0(u32 a, u32 b, u32 c, u32 d, u16 e)
{
    func_021F90B8((u8 *)a, (void *)b, c, d, e, 0);
}

void func_021F90B8(u8 *p, void *bank, u32 index, int unused1, int unused2, int slow)
{
    void *str;
    str = func_02045EC0(bank, index);
    func_0201F250(((struct Obj02857 *)p)->fB68, ((struct Obj02857 *)p)->fB88, str);
    func_02045808(str);
    func_02043B5C(func_02045770(((struct Obj02857 *)p)->fD40), 15);
    func_02045334(((struct Obj02857 *)p)->fD40);
    func_0201F73C(((struct Obj02857 *)p)->fD40, 0, 1, 14);
    if (slow)
        func_02202878(((struct Obj02857 *)p)->fD40, 0, (unsigned int)(((struct Obj02857 *)p)->fB88), 0, 0, p + 0xfa0);
    else
        func_02202858(((struct Obj02857 *)p)->fD40, 0, ((struct Obj02857 *)p)->fB88, 0, 0, p + 0xfa0);
    ((struct Obj02857 *)p)->fDFC = 0;
}

/*
 * lever: unused fifth argument leaves font and context in stack slots +4/+8.
 */
int func_021F914C(void *win, void *str, int x, int align, int unused, int font, void *ctx)
{
    int width;
    switch (align) {
    case 1:
        width = func_022026C4(ctx, (u8)font, (u32)str, (int)0);
        x = (func_02045738(win) * 8 - width) / 2;
        break;
    case 2:
        width = func_022026C4(ctx, (u8)font, (u32)str, (int)0);
        x = func_02045738(win) * 8 - width;
        break;
    }
    return x;
}


/*
 * Seven-argument wrapper: forwards the object, three words, the 0 and the u16/g pair to the two helpers.
 */
int func_021F91A0(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g)
{
    u32 r = func_021F914C(p, (void *)b, c, e, f, 0, (void *)g);

    return func_022028C8(p, 0, b, r, d, 0, f, g);
}
