/*
 * file:     unit_06899D2C.c
 * unit:     yes
 * function: func_06899D2C, func_06899D38, func_06899D3C, func_06899D64
 * address:  0x06899D2C
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F81EC  0x021F81EC  thumb
 *   func_021F8A78  0x021F8A78  thumb
 *   func_0220270C  0x0220270C  thumb
 *   func_022033F0  0x022033F0  thumb
 */
#include "../../matched/include/Obj21885.h"

typedef unsigned int u32;

extern int func_022033F0(u32);
extern void func_0220270C(u32, int, int);
extern u32 func_021F81EC(int);
extern void func_021F8A78(u32);
void func_06899D2C(void);
void func_06899D30(void);
void func_06899D38(void);
void func_06899D3C(u32 p);
void func_06899D64(u32 p);


/*
 * note: veneer follower unit; function_starts seeds 06899D2C, 06899D30.
 */
void func_06899D2C(void) {}


void func_06899D30(void) { func_06899D38(); }


/*
 * note:     listing extent (4) runs 2 bytes past the compiled function (2);
 *           trailing alignment padding, no byte difference.
 */
void func_06899D38(void)
{
}


void func_06899D3C(u32 p)
{
    if (func_022033F0(*(u32 *)(p + 0xB0)) != 0) func_06899D64(p);
}

void func_06899D64(u32 p)
{
    func_0220270C(((struct Obj21885 *)p)->fB0, 0, 0);
    func_021F8A78(func_021F81EC(8));
}
