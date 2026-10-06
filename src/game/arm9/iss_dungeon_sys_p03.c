/*
 * file:     iss_dungeon_sys_p03.c
 * unit:     yes
 * function: func_0202B47C, func_0202B490, func_0202B49C
 * address:  0x0202B47C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0202B374  0x0202B374  thumb
 *   func_02012984  0x02012984  thumb
 *   func_0202B2CC  0x0202B2CC  thumb
 */
#include "../../matched/include/Obj02009.h"
#include "../../matched/include/Obj11315.h"

struct BigObj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern u32  func_0202B374(u32 desc, u32 id);
extern u8 func_02012984(const struct BigObj *p);
extern void func_0202B2CC(u8 *p, u32 idx);
void func_0202B47C(u8 *p);
void func_0202B490(u8 *p);
void func_0202B49C(u8 *p, u32 id);


/*
 * When the object is idle, marks it active and resolves its current
 * record.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B47C.c \
 *       --func func_0202B47C --addr 0x0202B47C --thumb --cc 1.1p1
 */
void func_0202B47C(u8 *p)
{
    if (((struct Obj02009 *)p)->fC == 0) {
        ((struct Obj02009 *)p)->fC = 1;
        func_0202B49C(p, ((struct Obj02009 *)p)->f10);
    }
}


/*
 * Clears the object's active word when it is set.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B490.c \
 *       --func func_0202B490 --addr 0x0202B490 --thumb --cc 1.1p1
 */
void func_0202B490(u8 *p)
{
    if (((struct Obj11315 *)p)->fC != 0) {
        ((struct Obj11315 *)p)->fC = 0;
    }
}


/*
 * closed:   blocker func_0202B2CC.c is now a manifest entry (matched class)
 *
 * Resolves the node's 0x14 descriptor into the 0x18 slot and, when that
 * succeeds, feeds the resolved handle and the key derived from the node's
 * second word to func_0202B2CC.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202B49C.c \
 *       --func func_0202B49C --addr 0x0202B49C --thumb --cc 1.1p1
 */
void func_0202B49C(u8 *p, u32 id)
{
    u32 r = func_0202B374(((struct Obj02009 *)p)->f14, id);

    ((struct Obj02009 *)p)->f18 = r;
    if (r != 0) {
        func_0202B2CC((u8 *)(((struct Obj02009 *)p)->f18), func_02012984((const struct BigObj *)(((struct Obj02009 *)p)->f8)));
    }
}
