/*
 * file:     worldtrade_box_p11.c
 * unit:     yes
 * function: func_021F6384, func_021F63A8, func_021F63EC, func_021F6418, func_021F643C
 * address:  0x021F6384
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
 *   func_021F4BE0  0x021F4BE0  thumb  ov135
 *   func_021F4D14 0x021F4D14 thumb ov135
 *   func_021F4CE4 0x021F4CE4 thumb ov135
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_02034714 0x02034714 arm
 *   d_02203B68 0x02203B68 data a4
 *   func_021F663C  0x021F663C  thumb  ov135
 *   func_021F4E98  0x021F4E98  thumb  ov135
 *   func_021F6474  0x021F6474  thumb  ov135
 */
#include "../../matched/include/Obj18540.h"
#include "../../matched/include/Obj00045.h"
#include "../../matched/include/Obj18541.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

extern void func_021F4BE0(u32 a, u32 b, u32 c, u32 d, u8 e);
extern int func_021F4D14(char *p);
extern void func_021F4CE4(char *p);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_021F663C(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e);
extern void func_021F4E98(u8 *p, u32 a, u32 b);
extern void func_021F6474(u8 *p);
extern void func_0201F7A8(void *desc, u32 kind);
int func_021F6384(u8 *p);
int func_021F63A8(u8 *p);
int func_021F63EC(u8 *p);
int func_021F6418(u8 *p);
int func_021F643C(u8 *p);
extern const char d_02203B68[];


/*
 * State setter: build with the fixed 0x14/0x1ad/0x8/0x1 argument pair and latch state 0x6.
 */
int func_021F6384(u8 *p)
{
    func_021F4BE0((u32)p, 0x14, 0x1ad, 0x8, 0x1);
    ((struct Obj18540 *)p)->f28 = 0x6;
    return 2;
}

int func_021F63A8(u8 *p)
{
    unsigned result = func_021F4D14((char *)p);
    func_02034714(d_02203B68, 0, d_02203B68);
    if (result == 1) {
        func_021F4CE4((char *)p);
        ((struct Obj00045 *)p)->f28 = 2;
        func_021F4EC0(p, 0, 0);
    } else if (result == 2) {
        func_021F4CE4((char *)p);
        ((struct Obj00045 *)p)->f28 = 0;
    }
    return 2;
}


/*
 * Build through func_021F663C and publish the 3/0xc pair.
 */
int func_021F63EC(u8 *p)
{
    func_021F663C(p, 0x19, 1, 0, 0xf0f, 1);
    func_021F4E98(p, 3, 0xc);
    return 2;
}


/*
 * State setter: build with the fixed 0x12/0x1ad/0x8/0x1 argument pair and latch state 0xd.
 */
int func_021F6418(u8 *p)
{
    func_021F4BE0((u32)p, 0x12, 0x1ad, 0x8, 0x1);
    ((struct Obj18541 *)p)->f28 = 0xd;
    return 2;
}


/*
 * Two-way mode dispatch: mode 1 clears and runs the sub-step, mode 2 clears, releases the +0xdd0 word and latches state 1.
 */
int func_021F643C(u8 *p)
{
    u32 k = func_021F4D14((char *)p);

    if (k == 1) {
        func_021F4CE4((char *)p);
        func_021F6474(p);
    } else if (k == 2) {
        func_021F4CE4((char *)p);
        func_0201F7A8((void *)(*(u32 *)&((struct Obj00045 *)p)->fDD0), 0);
        ((struct Obj00045 *)p)->f28 = 1;
    }
    return 2;
}
