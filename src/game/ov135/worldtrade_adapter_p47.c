/*
 * file:     worldtrade_adapter_p47.c
 * unit:     yes
 * function: func_02202878, func_022028C8
 * address:  0x02202878
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
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_02034714  0x02034714  arm
 *   func_02045770  0x02045770  arm
 *   func_0201C724  0x0201C724  thumb
 */
#include "../../matched/include/Obj04532.h"

struct Rec3;
struct Descriptor;
typedef unsigned char u8;

typedef signed short s16;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    void *win;
    u8 busy;
    u8 pad5[3];
    u32 used;
} Slot;

typedef struct {
    u32 font;
    u8 pad4[0xC - 0x4];
    u32 print;
    u8 pad10[0x18 - 0x10];
    Slot slots[24];
} Ctx;

extern void func_0201CE48(struct Rec3 *p);
extern signed char func_02012FFC(void);
extern void *func_0201CCE4(void *, s16, s16, unsigned, unsigned, int, unsigned, unsigned, unsigned, unsigned);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
void func_02202878(void *a, unsigned b, unsigned c, int d, int e, u8 *p);
u32 func_022028C8(void *win, u32 z, u32 str, u32 x, u32 y, u32 z2, u16 color, Ctx *g);

/*
 * tail: 022028C6..022028C8 zero alignment padding.
 */
void func_02202878(void *a, unsigned b, unsigned c, int d, int e, u8 *p)
{
    int v;
    if (((struct Obj04532 *)p)->f10) {
        func_0201CE48(((struct Obj04532 *)p)->f10);
        ((struct Obj04532 *)p)->f10 = 0;
    }
    v = func_02012FFC();
    ((struct Obj04532 *)p)->f10 = func_0201CCE4(a, d, e, c, ((struct Obj04532 *)p)->f0, v, ((struct Obj04532 *)p)->f4, 0, 0x48, 0xF);
    ((struct Obj04532 *)p)->f14 = a;
}


u32 func_022028C8(void *win, u32 z, u32 str, u32 x, u32 y, u32 z2, u16 color, Ctx *g)
{
    Slot *found = 0;
    int i;
    u32 print;

    for (i = 0; i < 24; i++) {
        if (g->slots[i].used == 0) {
            found = &g->slots[i];
        }
    }
    if (found == 0) {
        func_02034714((void *)0x02203F74, 0, (void *)0x02203F74);
    }
    found->win = win;
    found->busy = 0;
    print = g->print;
    func_0201C724((void *)print, (u32)func_02045770((struct Descriptor *)win), (s16)x, (s16)y, str, g->font, color);
    found->busy = 1;
    found->used = 1;
    return 1;
}
