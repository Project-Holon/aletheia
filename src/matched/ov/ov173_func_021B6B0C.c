/*
 * function: func_021B6B0C
 * address: 0x021B6B0C
 * packet: pkt_ov173_021B6B0C
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B7438 0x021B7438 thumb ov173
 *   func_02017E40 0x02017E40 thumb
 *   WAZA_TOOL_GetMaxPP 0x0201C158 thumb
 */
#include "../include/Obj05450.h"
#include "../include/Obj24157.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 func_021B7438(char **);
extern void func_02017E40(void *, u32, u32);
extern u8 WAZA_TOOL_GetMaxPP(u16 move, u32 ppUp);
int func_021B6B0C(char **p)
{
    char *q;
    u32 zero;
    q = *p;
    func_02017E40(((struct Obj05450 *)q)->f0, ((struct Obj05450 *)q)->f1B + 0x36, func_021B7438(p));
    q = *p;
    zero = 0;
    func_02017E40(((struct Obj05450 *)q)->f0, ((struct Obj05450 *)q)->f1B + 0x3e, 0);
    q = *p;
    func_02017E40(((struct Obj05450 *)q)->f0, ((struct Obj05450 *)q)->f1B + 0x3a, WAZA_TOOL_GetMaxPP(func_021B7438(p), 0));
    ((struct Obj24157 *)(*p))->f1A = zero;
    return 8;
}
