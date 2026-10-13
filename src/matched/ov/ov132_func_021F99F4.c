/*
 * function: func_021F99F4
 * address: 0x021F99F4
 * packet: pkt_ov132_021F99F4
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F9E0C 0x021F9E0C thumb ov132
 *   func_021F5140 0x021F5140 thumb ov112
 *   MUSICAL_PROGRAM_GetCategoryShare 0x02157394 thumb ov010
 *   func_021F95F0 0x021F95F0 thumb ov132
 */
#include "../include/Obj10534.h"
#include "../include/Obj23204.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 func_021F9E0C(u8 *p);
extern unsigned char func_021F5140(void *p, int i);
extern u16 MUSICAL_PROGRAM_GetCategoryShare(int a0, int a1);
extern void func_021F95F0(u8 *);
int func_021F99F4(char *p, unsigned i, unsigned j)
{
    u16 v;
    u8 old;
    v = MUSICAL_PROGRAM_GetCategoryShare((int)(((struct Obj23204 *)(*(char * *)&((struct Obj10534 *)p)->f30))->f14), (u8)(int)func_021F5140((void *)func_021F9E0C((u8 *)p), (u16)(*(u16 *)(*(char **)(*(char * *)&((struct Obj10534 *)p)->f30 + i * 4 + 4) + j * 6 + 0x14))));
    old = *(u8 *)(p + 0xf7 + i);
    *(u8 *)(p + 0xf7 + i) = old + v;
    func_021F95F0((u8 *)p);
    return (unsigned)v >= 7 ? 1579 : 1580;
}
