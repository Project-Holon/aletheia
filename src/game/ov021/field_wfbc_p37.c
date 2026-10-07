/*
 * file:     field_wfbc_p37.c
 * unit:     yes
 * function: func_02196D88, func_02196D94
 * address:  0x02196D88
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
 *   func_02196034  0x02196034  thumb  ov021
 *   func_02196D24  0x02196D24  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 */
#include "../../matched/include/Obj17948.h"
#include "../../matched/include/Obj07463.h"

struct Ctx;
struct Obj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

extern s32 func_02051C88(struct Ctx *c);
extern void func_02196034(u8 *p, void *fn, u32 n);
extern void func_02196D24(struct Obj *a);
extern void func_020061E4(u32 a);
void func_02196D88(u8 *p);
int func_02196D94(u32 v, u8 *p);


/*
 * Untraced thunk: tail call on the word at +0x24 into the ARM9 image.
 *
 * Addresses are Black-image addresses.
 */
void func_02196D88(u8 *p)
{
    func_02051C88((struct Ctx *)(((struct Obj17948 *)p)->f24));
}


/*
 * Handler: stores the request at +0x300 and dispatches on it.
 *
 * Addresses are Black-image addresses.
 */
int func_02196D94(u32 v, u8 *p)
{
    int r = 0;

    ((struct Obj07463 *)p)->f300 = v;
    switch (v) {
    case 1:
        func_020061E4(0x73B);
        ((struct Obj07463 *)p)->fC = 0;
        func_02196034(p, func_02196D24, 0x524);
        r = 1;
        break;
    case 0:
        func_020061E4(0x73B);
        r = 1;
        ((struct Obj07463 *)p)->fC = 1;
        func_02196034(p, func_02196D24, 0x52A);
        break;
    case 2:
        func_020061E4(0x73C);
        ((struct Obj07463 *)p)->fC = 2;
        func_02196034(p, func_02196D24, 0x530);
        break;
    }
    return r;
}
