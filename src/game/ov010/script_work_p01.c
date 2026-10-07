/*
 * file:     script_work_p01.c
 * unit:     yes
 * function: func_02157954, func_02157960
 * address:  0x02157954
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj18739.h"

typedef unsigned char u8;

typedef unsigned int u32;

void func_02157954(u8 *p, int v, int a2);
void func_02157960(int a, int b, int c);


/*
 * Unlabelled leaf setter (hidden in a .word run); filed as a helper because
 * its address is the witness for the tail-call thunk at 0x02157960.
 */
void func_02157954(u8 *p, int v, int a2)
{
    ((struct Obj18739 *)p)->f678 = v;
}


void func_02157960(int a, int b, int c)
{
    func_02157954((u8 *)a, b, c);
}
