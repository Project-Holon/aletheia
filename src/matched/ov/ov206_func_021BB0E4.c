/*
 * function: func_021BB0E4
 * address: 0x021BB0E4
 * packet: pkt_ov206_021BB0E4
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020452E8 0x020452E8 arm
 */
#include "../include/Obj00173.h"
struct Descriptor;
typedef unsigned int   u32;
extern u32 func_020452E8(struct Descriptor *d);
void func_021BB0E4(char *p)
{
    func_020452E8(((struct Obj00173 *)p)->f8C);
    func_020452E8(((struct Obj00173 *)p)->f90);
}
