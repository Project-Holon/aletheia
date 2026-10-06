/*
 * function: func_0217D904
 * address: 0x0217D904
 * packet: pkt_ov018_0217D904
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two alignment bytes at 0x0217D916.
 * symbols:
 *   func_020452E8 0x020452E8 arm
 */
#include "../include/Obj00703.h"
struct Descriptor;
typedef unsigned int   u32;
extern u32 func_020452E8(struct Descriptor *d);
void func_0217D904(char *p)
{
    func_020452E8(*(struct Descriptor * *)&((struct Obj00703 *)p)->f44);
    func_020452E8(*(struct Descriptor * *)&((struct Obj00703 *)p)->f4C);
}
