/*
 * function: APP_TASKMENU_TransWinAfterPrint
 * address:  0x020278F4
 * packet:   pkt_020278F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * app_taskmenu.c: the deselect sweep.  If the menu is in state 1, scan every
 * entry's cell for a hit; a hit clears the sentinel, and only when no hit was
 * found (sentinel still 1) does the second loop tear every cell down and
 * leave state 0.
 *
 * NOTE: the earlier DIFF note read the `adds r7, r4, #0` at +0x18 as a live
 * copy of the loop index, and every spelling chasing that came out 126 bytes.
 * It is not a copy of the index: +0x18 sits BEFORE the loop's back-edge target
 * (0x0202790E), so r7 is set once and never updated.  The assignment in the
 * loop is the constant `sel = 0`, rematerialised off the already-zero r4 per
 * docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md.
 *
 * symbols:
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045770  0x02045770  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 */
#include "../include/Obj00104.h"
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Cfg;
struct Descriptor;
struct PrintSys;
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02045334(struct Descriptor *p);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);

void APP_TASKMENU_TransWinAfterPrint(u8 *p)
{
    u8 i;
    u8 sel;

    if (((struct Obj00104 *)p)->f8 != 1) {
        return;
    }
    sel = 1;
    for (i = 0; i < ((struct Obj00104 *)p)->f24; i++) {
        if (func_0201C6C4((struct PrintSys *)(*(u32 *)(*(u32 *)&((struct Obj00104 *)p)->f34 + 0x14)),
                          (void *)((u32)func_02045770((struct Descriptor *)(*(u32 **)(p + 0x18))[i]))) == 1) {
            sel = 0;
        }
    }
    if (sel != 1) {
        return;
    }
    for (i = 0; i < ((struct Obj00104 *)p)->f24; i++) {
        u32 v = (*(u32 **)(p + 0x18))[i];
        func_02045334((struct Descriptor *)v);
        func_02045374((struct Cfg *)v);
        func_02041B6C(func_02045730((struct Descriptor *)v));
    }
    ((struct Obj00104 *)p)->f8 = 0;
}
