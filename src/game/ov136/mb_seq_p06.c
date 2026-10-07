/*
 * file:     mb_seq_p06.c
 * unit:     yes
 * function: func_021C74BC, func_021C74C8, func_021C74F8
 * address:  0x021C74BC
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
 *   func_020307B0            0x020307B0  arm
 */
#include "../../matched/include/Obj23651.h"
#include "../../matched/include/Obj14197.h"
#include "../../matched/include/Obj14198.h"
#include "../../matched/include/Obj23652.h"

typedef unsigned char u8;

typedef unsigned int   u32;

struct Bf7 {
    u8 v : 7;
    u8 w : 1;
};

extern u32 func_020307B0(void *p);
int func_021C74BC(u8 *p);
int func_021C74C8(u8 *p);
int func_021C74F8(u8 *p);

int func_021C74BC(u8 *p)
{
    func_020307B0(((struct Obj23651 *)p)->f10);
    return 8;
}

int func_021C74C8(u8 *p)
{
    u8 *q = *(u8 * *)&((struct Obj14197 *)p)->f10;
    ((struct Bf7 *)(p + 0x21))->v = ((struct Obj14198 *)q)->f3C;
    p[0x20] = ((struct Obj14198 *)q)->f40;
    func_020307B0(q);
    return 0;
}

int func_021C74F8(u8 *p)
{
    func_020307B0(((struct Obj23652 *)p)->f10);
    return 8;
}
