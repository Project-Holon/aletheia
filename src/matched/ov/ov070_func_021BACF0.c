/*
 * function: func_021BACF0
 * address:  0x021BACF0
 * packet:   pkt_ov070_021BACF0
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Creates the window at p+0x4FC on first use, clears it, then either prints
 * through func_0201CCE4 (mode 1) or through func_021BB6E0, and finishes the
 * window. The window address is a named local taken after the clear calls:
 * without it the 0x4FC offset went to r4 and mode to r6, the mode-1 arm
 * consumed the offset register destructively and the join reloaded it
 * (4 bytes short).
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
 */
#include "../include/Obj00002.h"
#include "../include/Obj04334.h"

typedef unsigned short u16;
typedef signed short s16;

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
struct CharBuf;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern signed char func_02012FFC(void);
extern int func_0201CCE4(int, int, int, int, int, int, int, int, int, int);
extern void func_021BB6E0(int p, u32 *obj, u32 str, u16 x, s16 y, u16 color);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_021BB724(void **p);

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
