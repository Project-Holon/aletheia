/*
 * function: func_021B83C0
 * address:  0x021B83C0
 * packet:   pkt_ov071_021B83C0
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to BMP_WIN_Delete on the pointer loaded from offset 0x3c.
 *
 * symbols:
 *   BMP_WIN_Delete  0x020452E8  arm
 */
#include "../include/Obj20724.h"

struct Descriptor;
typedef unsigned int   u32;
void func_021B83C0(void *p)
{
    u32 BMP_WIN_Delete(struct Descriptor *d);
    BMP_WIN_Delete(((struct Obj20724 *)p)->f3C);
}
