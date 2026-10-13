/*
 * function: func_021DD8BC
 * address: 0x021DD8BC
 * packet: pkt_ov171_021DD8BC
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 */
#include "../include/Obj08249.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Descriptor;
extern u32 func_020452E8(struct Descriptor *d);
extern void BMP_WIN_Exit(void);
void func_021DD8BC(int *p)
{
    func_020452E8(*(struct Descriptor * *)&((struct Obj08249 *)p)->fB48);
    func_020452E8(*(struct Descriptor * *)&((struct Obj08249 *)p)->fB50);
    BMP_WIN_Exit();
}
