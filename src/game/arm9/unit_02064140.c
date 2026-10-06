/*
 * file:     unit_02064140.c
 * unit:     yes
 * function: func_02064140, func_02064150
 * address:  0x02064140
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj08899.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct O02064140 {
    u32 unk0;
};

int func_02064150(int a0);


void func_02064140(struct O02064140 *o, u32 a)
{
    o->unk0 = a;
    func_02064150((int)o);
}


int func_02064150(int a0){ int t0; t0 = func_02082A48((int)0, (int)(a0 + 4), (int)0x18); ((struct Obj08899 *)((char *)(a0)))->f4 = (int)0x1000; ((struct Obj08899 *)((char *)(a0)))->f8 = (int)0x1000; return 0x1000; }
