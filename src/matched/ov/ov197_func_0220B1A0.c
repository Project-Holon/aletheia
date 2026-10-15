/*
 * function: B_BAG_MAIN_ExitWindows
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
 *   B_BAG_MAIN_DeleteWindows 0x0220B188 thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 */
#include "../include/Obj24989.h"

extern void B_BAG_MAIN_DeleteWindows(char *a);
struct Descriptor;
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);

void B_BAG_MAIN_ExitWindows(char *a)
{
    B_BAG_MAIN_DeleteWindows(a);
    BMP_WIN_Delete((struct Descriptor *)(((struct Obj24989 *)a)->f24));
}
