/*
 * function: ZUKAN_INFO_DeleteMainWindows
 * address: 0x021BB0E4
 * packet: pkt_ov206_021BB0E4
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_WIN_Delete 0x020452E8 arm
 */
#include "../include/Obj00173.h"
struct Descriptor;
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
void ZUKAN_INFO_DeleteMainWindows(char *p)
{
    BMP_WIN_Delete(((struct Obj00173 *)p)->f8C);
    BMP_WIN_Delete(((struct Obj00173 *)p)->f90);
}
