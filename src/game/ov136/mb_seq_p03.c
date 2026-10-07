/*
 * file:     mb_seq_p03.c
 * unit:     yes
 * function: func_021C6E28, func_021C6E64, func_021C6E98
 * address:  0x021C6E28
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C5C00 0x021C5C00 thumb
 *   func_021C66B8 0x021C66B8 thumb
 *   func_021C5C64  0x021C5C64  thumb
 *   func_021C6284 0x021C6284 thumb
 *   func_021C62BC 0x021C62BC thumb
 *   func_021C71A8 0x021C71A8 thumb
 *   func_021C7298 0x021C7298 thumb
 *   func_021C5AEC  0x021C5AEC  thumb
 */
#include "../../matched/include/Obj03302.h"
#include "../../matched/include/Obj00127.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_021C66B8(u8 *, int, u32);
extern void func_021C5C00(u8 *);
extern void func_021C7298(void *p, int v);
extern void func_021C5C64(u8 *);
extern void func_021C62BC(u8 *);
extern void func_021C6284(u8 *);
extern int func_021C71A8(char *p, int v, int w);
extern void func_021C5AEC(u8 *);
int func_021C6E28(u8 *p);
void func_021C6E64(u8 *p);
int func_021C6E98(u8 *p);

int func_021C6E28(u8 *p)
{
    if (((struct Obj03302 *)p)->f1C == 0) {
        func_021C66B8(*(u8 * *)&((struct Obj03302 *)p)->f8, 0, 0);
        func_021C66B8(*(u8 * *)&((struct Obj03302 *)p)->f8, 1, 1);
    } else {
        func_021C66B8(*(u8 * *)&((struct Obj03302 *)p)->f8, 0, 1);
        func_021C66B8(*(u8 * *)&((struct Obj03302 *)p)->f8, 1, 0);
    }
    func_021C5C00(p);
    return 9;
}

void func_021C6E64(u8 *p)
{
    func_021C66B8(*(u8 * *)&((struct Obj00127 *)p)->f8, 2, 0);
    func_021C7298(*(u8 * *)&((struct Obj00127 *)p)->f8, 1);
    func_021C5C64(p);
    func_021C62BC(p);
    func_021C6284(p);
    func_021C71A8((char *)p, 0, 0xD);
}

int func_021C6E98(u8 *p)
{
    func_021C5AEC(p);
    return 0xE;
}
