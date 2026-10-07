/*
 * function: func_06899CA4
 * address: 0x06899CA4
 * packet: pkt_ov095_06899CA4
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: signed bytes, enum zero, const source pointer preserve codegen;
 *       trailing two-byte alignment padding.
 * symbols:
 *   func_06899CCC 0x06899CCC thumb ov095
 */
#include "../../../matched/include/Obj07907.h"
typedef signed char s8;
typedef unsigned int u32;
extern int func_06899CCC(u32, u32);
void func_06899CA4(const s8 *p, u32 a)
{
    enum { ZERO = 0 } zero = ZERO;
    ((struct Obj07907 *)p)->f8C = zero;
    ((struct Obj07907 *)p)->f8D = -16;
    ((struct Obj07907 *)p)->f8E = zero - 1;
    func_06899CCC(*(const u32 *)&((struct Obj07907 *)p)->fB0, a);
}
