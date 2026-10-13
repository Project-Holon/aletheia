/*
 * function: func_021BA5F4
 * address: 0x021BA5F4
 * packet: pkt_ov100_021BA5F4
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_WIN_Delete 0x020452E8 arm
 */
#include "../include/Obj00060.h"
struct Descriptor;
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
void func_021BA5F4(unsigned a)
{
 if(*(unsigned *)&((struct Obj00060 *)a)->f27C!=0) BMP_WIN_Delete(*(struct Descriptor * *)&((struct Obj00060 *)a)->f27C);
 if(*(unsigned *)&((struct Obj00060 *)a)->f280!=0) BMP_WIN_Delete(*(struct Descriptor * *)&((struct Obj00060 *)a)->f280);
 *(unsigned *)&((struct Obj00060 *)a)->f27C=0;
 *(unsigned *)&((struct Obj00060 *)a)->f280=0;
}
