/*
 * function: func_02020DC8
 * address:  0x02020DC8
 * packet:   pkt_02020D5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  +0020 ABS32 sub_0209E8CC_Obj       : 0209E8CC (data, from header) has no witness outside 02020DC8..02020DEC
 * symbols:
 *   sub_0209E8CC_Obj  0x0209E8CC  data
 */
#include "../include/Obj15729.h"

typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char u8;

struct Bmp;
extern struct Bmp *func_020436FC(void *pixels, u32 width, u32 height, u32 depth, u16 heap);
extern u8 sub_0209E8CC_Obj[];

void func_02020DC8(char *p, int a)
{
    ((struct Obj15729 *)p)->f8 = (u32)func_020436FC((void *)((int)sub_0209E8CC_Obj), 1, 1, 0x20, a);
}
