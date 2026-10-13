/*
 * function: INTRUDE_SUBDISP_BmpWinExit
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
 *   BMP_WIN_Delete 0x020452E8 arm
 */
#include "../include/Obj00703.h"
struct Descriptor;
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
void INTRUDE_SUBDISP_BmpWinExit(char *p)
{
    BMP_WIN_Delete(*(struct Descriptor * *)&((struct Obj00703 *)p)->f44);
    BMP_WIN_Delete(*(struct Descriptor * *)&((struct Obj00703 *)p)->f4C);
}
