/*
 * function: func_021BD038
 * address:  0x021BD038
 * packet:   pkt_ov172_021BD038
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD134  0x021BD134  thumb  ov172
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_021BD0C4  0x021BD0C4  thumb  ov172
 *   func_021BE34C  0x021BE34C  thumb  ov172
 *   func_020409B4  0x020409B4  arm
 *
 * Follows the mode byte at +0x14 against its last seen value (+0x15): entering mode 0 prints message 0x1c in the text window and switches the display to the window at +0x2c; leaving mode 0 prints message 0x11 in the window at +0x30 and switches back.
 */
#include "../include/Obj01266.h"

typedef unsigned char u8;
typedef unsigned long u32;

extern void func_021BD134(void *ctx, char *st, u32 msgId);
struct Descriptor;
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_021BD0C4(void *ctx, char *st, int msgId);
extern void func_021BE34C(void *p);
extern void func_020409B4(u32 index);

static inline u8 func_021BD038_show(u32 win)
{
    BMP_WIN_ClearScreen((struct Descriptor *)win);
    return BMP_WIN_GetBgLayer((struct Descriptor *)win);
}

void func_021BD038(void *ctx, char *st)
{
    if (((struct Obj01266 *)st)->f14 == ((struct Obj01266 *)st)->f15)
        return;
    if (((struct Obj01266 *)st)->f14 == 0) {
        func_021BD134(ctx, st, 0x1c);
        ((struct Obj01266 *)st)->f38 = 1;
        func_02041B6C(func_021BD038_show(((struct Obj01266 *)st)->f2C));
        func_0201F7A8((void *)(((struct Obj01266 *)st)->f2C), 1);
    } else if (((struct Obj01266 *)st)->f15 == 0 && ((struct Obj01266 *)st)->f14 != 0) {
        func_021BD0C4(ctx, st, 0x11);
        func_021BE34C(ctx);
        func_0201F7A8((void *)(((struct Obj01266 *)st)->f30), 1);
        func_020409B4(func_021BD038_show(((struct Obj01266 *)st)->f30));
    }
    ((struct Obj01266 *)st)->f15 = ((struct Obj01266 *)st)->f14;
}
