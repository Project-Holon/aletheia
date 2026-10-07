/*
 * file:     field_wfbc_p39.c
 * unit:     yes
 * function: func_02196FF0, func_02196FFC
 * address:  0x02196FF0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02051C88  0x02051C88  arm
 *   func_020490F4  0x020490F4  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 */
#include "../../matched/include/Obj17949.h"
#include "../../matched/include/Obj04220.h"

struct Ctx;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

extern s32 func_02051C88(struct Ctx *c);
extern void *func_020490F4(u32 id, u32 heap);
extern s32 func_0204A6C8(void *h, u32 b, u32 c, u32 d, u16 e);
extern s32 func_0204AC18(void *h, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204AF28(void *h, u32 b, u32 c, u32 d);
extern void func_02049238(void *h);
void func_02196FF0(u8 *p);
void func_02196FFC(u8 *p);


/*
 * Untraced thunk: tail call on the word at +0x24 into the ARM9 image.
 *
 * Addresses are Black-image addresses.
 */
void func_02196FF0(u8 *p)
{
    func_02051C88((struct Ctx *)(((struct Obj17949 *)p)->f24));
}


/*
 * Builds three objects on one owner handle and stores them at +0x274,
 * +0x27C and +0x284.
 *
 * Addresses are Black-image addresses.
 */
void func_02196FFC(u8 *p)
{
    void *h = func_020490F4(0x1D, ((struct Obj04220 *)p)->f10);

    ((struct Obj04220 *)p)->f27C = func_0204A6C8(h, 5, 0, 1, ((struct Obj04220 *)p)->f10);
    ((struct Obj04220 *)p)->f274 = func_0204AC18(h, 3, 1, 0, 0, 0xA, ((struct Obj04220 *)p)->f10);
    ((struct Obj04220 *)p)->f284 = func_0204AF28(h, 7, 0x10, ((struct Obj04220 *)p)->f10);
    func_02049238(h);
}
