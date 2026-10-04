/*
 * function: func_021F4E30
 * address:  0x021F4E30
 * packet:   pkt_021F4E30
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
  *
  *
  *
  *
  *
 * symbols:
 *   func_021F5060  0x021F5060  thumb
 */
#include "../include/Obj00045.h"

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_02027974(void *m);
struct TaskMenu;
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_021F5060(void);

u32 func_021F4E30(u8 *p)
{
    u32 r = (u32)-1;

    if (((struct Obj00045 *)p)->fE08 != 0) {
        func_02027974(((struct Obj00045 *)p)->fE08);
        if (func_020279E8(((struct Obj00045 *)p)->fE08) != 0) {
            r = func_02027A04(((struct Obj00045 *)p)->fE08) + 1;
            func_021F5060();
        }
    }
    return r;
}
