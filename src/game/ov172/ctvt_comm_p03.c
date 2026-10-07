/*
 * file:     ctvt_comm_p03.c
 * unit:     yes
 * function: func_021B7B64, func_021B7B80
 * address:  0x021B7B64
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
 *   func_021BE100  0x021BE100  thumb  ov172
 *   func_021B69D0  0x021B69D0  thumb  ov172
 *   func_021B69D8  0x021B69D8  thumb  ov172
 */
#include "../../matched/include/Obj14297.h"
#include "../../matched/include/Obj06558.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

extern int func_021BE100(void);
extern void func_021B69D0(void *p);
extern void func_021B69D8(void *p);
void func_021B7B64(int x, char *p);
void func_021B7B80(int x, char *p);


/*
 * Guarded flag set at +0x24.
 *
 * Addresses are Black-image addresses.
 */
void func_021B7B64(int x, char *p)
{
    if (func_021BE100() != 1) {
        return;
    }
    func_021B69D0(((struct Obj14297 *)p)->fA4);
    ((struct Obj14297 *)p)->f24 = 1;
}


void func_021B7B80(int x, char *p)
{
    if (func_021BE100() != 1) {
        return;
    }
    if (((struct Obj06558 *)p)->f24 != 1) {
        return;
    }
    if (((struct Obj06558 *)p)->f28 != 0) {
        return;
    }
    func_021B69D8(((struct Obj06558 *)p)->fA4);
    ((struct Obj06558 *)p)->f28 = 1;
}
