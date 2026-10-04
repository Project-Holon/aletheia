/*
 * function: func_02031994
 * address:  0x02031994
 * packet:   pkt_0203195C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02031994.c \\
 *       --func func_02031994 --addr 0x02031994 --arm --cc 1.1p1
 */
#include "../include/Obj11324.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_020307B0(void *p);
struct Obj02033410;
extern void func_020339B4(int *p);
extern u32 func_02033B68(u8 *p, u32 i);
extern void func_020339D0(u32 a, u32 b);
extern void func_02033410(struct Obj02033410 *p, u32 val);

u32 func_02031994(u8 *p, u32 *out)
{
    *out = ((struct Obj11324 *)p)->f30;
    return ((struct Obj11324 *)p)->f34;
}
