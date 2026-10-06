/*
 * file:     iss_dungeon_sys_p02.c
 * unit:     yes
 * function: func_0202B438, func_0202B454
 * address:  0x0202B438
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj15837.h"
#include "../../matched/include/Obj15838.h"

typedef unsigned char u8;

typedef unsigned int  u32;

extern u8 *func_0202B374(u8 *p, u32 id);
u32 func_0202B438(u8 *p, u32 id);
void func_0202B454(char *p);


/*
 * Returns 1 when the object's +0x14 sub-object holds a record with the
 * given id, else 0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B438.c \
 *       --func func_0202B438 --addr 0x0202B438 --thumb --cc 1.1p1
 */
u32 func_0202B438(u8 *p, u32 id)
{
    u8 *q = *(u8 * *)&((struct Obj15837 *)p)->f14;

    if (q == 0) {
        return 0;
    }
    return func_0202B374(q, id) != 0 ? 1 : 0;
}


void func_0202B454(char *p)
{
    int i;
    ((struct Obj15838 *)p)->f1C = 0xffff;
    for (i = 0; i < 4; i++) {
        *(unsigned short *)(p + i * 2 + 0x20) = 0;
        *(unsigned short *)(p + i * 2 + 0x28) = 0x100;
        *(unsigned short *)(p + i * 2 + 0x30) = 0;
    }
}
