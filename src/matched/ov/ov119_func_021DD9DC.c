/*
 * function: func_021DD9DC
 * address: 0x021DD9DC
 * packet: pkt_ov119_021DD9DC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj00001.h"

struct Descriptor;
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern unsigned int BMP_WIN_Delete(struct Descriptor *d);
typedef unsigned int   u32;
extern void func_02041B6C(u32 bit);

void func_021DD9DC(unsigned char *p)
{
    if(((struct Obj00001 *)p)->f5BC){BMP_WIN_ClearScreen((struct Descriptor *)(((struct Obj00001 *)p)->f5BC));BMP_WIN_Delete((struct Descriptor *)(((struct Obj00001 *)p)->f5BC));((struct Obj00001 *)p)->f5BC=0;}if(((struct Obj00001 *)p)->f5C0){BMP_WIN_ClearScreen((struct Descriptor *)(((struct Obj00001 *)p)->f5C0));BMP_WIN_Delete((struct Descriptor *)(((struct Obj00001 *)p)->f5C0));((struct Obj00001 *)p)->f5C0=0;}if(((struct Obj00001 *)p)->f5D4){BMP_WIN_ClearScreen((struct Descriptor *)(((struct Obj00001 *)p)->f5D4));BMP_WIN_Delete((struct Descriptor *)(((struct Obj00001 *)p)->f5D4));((struct Obj00001 *)p)->f5D4=0;}if(((struct Obj00001 *)p)->f5D8){BMP_WIN_ClearScreen((struct Descriptor *)(((struct Obj00001 *)p)->f5D8));BMP_WIN_Delete((struct Descriptor *)(((struct Obj00001 *)p)->f5D8));((struct Obj00001 *)p)->f5D8=0;}func_02041B6C(3);
}
