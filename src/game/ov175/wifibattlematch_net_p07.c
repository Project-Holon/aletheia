/*
 * file:     wifibattlematch_net_p07.c
 * unit:     yes
 * function: func_021D63B0, func_021D63BC, func_021D63C8
 * address:  0x021D63B0
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021E64C8  0x021E64C8  thumb  ov177
 *   func_021E65FC  0x021E65FC  thumb  ov177
 *   func_021D62A4  0x021D62A4  thumb
 */
#include "../../matched/include/Obj24228.h"
#include "../../matched/include/Obj24229.h"

typedef unsigned long u32;

extern u32 func_021E64C8(u32 p);
extern u32 func_021E65FC(u32 p);
extern void func_021D62A4(u32 *p, u32 mode);
u32 func_021D63B0(char *obj);
u32 func_021D63BC(char *obj);
void func_021D63C8(char *obj, u32 arg);


/*
 * Thunk: hands the +0x18 block to 0x021E64C8 and returns its result.  No
 *     lr save anywhere, so the compiler emitted the call as a pooled
 *     `ldr r3; bx r3` tail jump.
 */
u32 func_021D63B0(char *obj)
{
    return func_021E64C8(((struct Obj24228 *)obj)->f18);
}


/*
 * Thunk: hands the +0x18 block to 0x021E65FC and returns its result, the
 *     poll partner of func_021D63B0 on the same field.
 */
u32 func_021D63BC(char *obj)
{
    return func_021E65FC(((struct Obj24229 *)obj)->f18);
}


void func_021D63C8(char *obj, u32 arg)
{
    func_021D62A4((u32 *)obj, arg);
    while (func_021D63B0(obj) == 0)
        ;
}
