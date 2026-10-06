/*
 * function: func_020319C0
 * address:  0x020319C0
 * packet:   pkt_0203195C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * promoted: from src/pending on 2026-09-19, no C change: its blocker is filed,
 *           every relocation site resolves and match.py one reports EXACT*.
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020319C0.c \\
 *       --func func_020319C0 --addr 0x020319C0 --arm --cc 1.1p1
 */
#include "../include/Obj02604.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 func_020307B0(void *p);
extern void func_020339B4(int *p);
extern u32 func_02033B68(u8 *p, u32 i);
extern void func_020339D0(u32 a, u32 b);
struct Obj02033410;
extern void func_02033410(struct Obj02033410 *p, u32 val);

void func_020319C0(u8 *p)
{
    func_020339D0(((struct Obj02604 *)p)->f34, *(u32 *)&((struct Obj02604 *)p)->f2C);
    func_02033410((struct Obj02033410 *)p, 1);
}
