/*
 * function: func_021B9DB0
 * address: 0x021B9DB0
 * packet: pkt_ov181_021B9DB0
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 */
#include "../include/Obj14409.h"
struct Descriptor;
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void BMP_WIN_Exit(void);
void func_021B9DB0(char *p){BMP_WIN_Delete(*(struct Descriptor * *)&((struct Obj14409 *)p)->f2BC);BMP_WIN_Delete(*(struct Descriptor * *)&((struct Obj14409 *)p)->f2C4);BMP_WIN_Exit();}
