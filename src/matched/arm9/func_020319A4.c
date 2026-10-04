/*
 * function: func_020319A4
 * address:  0x020319A4
 * packet:   pkt_0203195C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020319A4.c \\
 *       --func func_020319A4 --addr 0x020319A4 --arm --cc 1.1p1
 */
#include "../include/Obj01020.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_020307B0(void *p);
struct Obj02033410;
extern void func_020339B4(int *p);
extern u32  func_02033B68(u8 *p, u32 i);
extern void func_020339D0(u32 a, u32 b);
extern void func_02033410(struct Obj02033410 *p, u32 val);

u32 func_020319A4(u8 *p, u32 id)
{
    return func_02033B68(*(u8 * *)&((struct Obj01020 *)p)->f2C, id) + ((struct Obj01020 *)p)->f34;
}
