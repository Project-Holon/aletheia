/*
 * function: func_0220B1A0
 * address:  0x0220B1A0
 * packet:   pkt_0220B1A0
 * region:   ov197
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0220B188 0x0220B188 thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 */
#include "../include/Obj24989.h"

extern void func_0220B188(char *a);
struct Descriptor;
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);

void func_0220B1A0(char *a)
{
    func_0220B188(a);
    BMP_WIN_Delete((struct Descriptor *)(((struct Obj24989 *)a)->f24));
}
