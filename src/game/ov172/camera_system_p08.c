/*
 * file:     camera_system_p08.c
 * unit:     yes
 * function: func_021B657C, func_021B65C4, func_021B65D8
 * address:  0x021B657C
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020490A8 0x020490A8 arm
 *   func_0203D7C8 0x0203D7C8 arm
 *   func_02048F4C 0x02048F4C arm
 *   func_020862F0 0x020862F0 arm
 *   d_021C71C0 0x021C71C0 data a4
 *   func_0203D7FC  0x0203D7FC  arm
 *   func_02085D3C  0x02085D3C  arm
 *   func_021B6608  0x021B6608  arm    ov172
 *   func_021B6610  0x021B6610  arm    ov172
 *   func_021B6618  0x021B6618  arm    ov172
 *   g_021C88E0     0x021C88E0  data
 */
#include "../../matched/include/Obj01559.h"
#include "../../matched/include/Obj02504.h"
#include "../../matched/include/Obj14292.h"

typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned char  u8;

typedef signed int     s32;

extern u32 func_020490A8(u32 a, u32 b);
extern void *func_0203D7C8(u32, u32, const char *, u16);
extern void func_02048F4C(void *dst, u32 archive_id, u32 member);
extern void func_020862F0(void *, u32);
extern void func_0203D7FC(void *p);
extern int func_02085D3C(void *p);
extern void func_021B6608(void);
extern u32 func_021B6610(u32 a);
extern void func_021B6618(void);
void func_021B657C(char *obj, int mode);
void func_021B65C4(void *p);
void func_021B65D8(void);
extern const char d_021C71C0[];
extern u32 g_021C88E0;

void func_021B657C(char *obj, int mode)
{
    char *p = obj;
    int which = 0;
    u32 size;
    if (mode != 1) which = 1;
    func_021B65C4(p);
    which = (u16)which;
    size = func_020490A8(0xD4, which);
    ((struct Obj01559 *)p)->f4C = size;
    ((struct Obj01559 *)p)->f48 = func_0203D7C8(((struct Obj01559 *)p)->f0, size, d_021C71C0, 0x13B);
    func_02048F4C(((struct Obj01559 *)p)->f48, 0xD4, which);
    func_020862F0(((struct Obj01559 *)p)->f48, ((struct Obj01559 *)p)->f4C);
}


/*
 * Release the word at +0x48 through 0x0203D7FC and clear it.
 *
 * Addresses are Black-image addresses.
 */
void func_021B65C4(void *p)
{
    u32 v = ((struct Obj02504 *)p)->f48;
    if (v != 0) {
        func_0203D7FC((void *)v);
        ((struct Obj02504 *)p)->f48 = 0;
    }
}


void func_021B65D8(void)
{
    u32 *p = (u32 *)g_021C88E0;

    if (func_02085D3C(&g_021C88E0) == 1)
        func_021B6608();
    if (func_02085D3C((void *)func_021B6610(1)) == 1)
        func_021B6618();
    ((struct Obj14292 *)p)->f24 = 1;
    ((struct Obj14292 *)p)->f1C = 1;
}
