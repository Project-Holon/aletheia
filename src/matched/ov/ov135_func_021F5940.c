/*
 * function: WORLDTRADE_BOX_DeleteWindows
 * address: 0x021F5940
 * packet: pkt_ov135_021F5940
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_ADAPTER_DeletePrintStream 0x02202940 thumb ov135
 *   BMP_WIN_Delete 0x020452E8 arm
 */
#include "../include/Obj00287.h"
typedef unsigned char u8;
struct Obj;
extern void WORLDTRADE_ADAPTER_DeletePrintStream(struct Obj *p);
struct Descriptor;
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
void WORLDTRADE_BOX_DeleteWindows(u8 *p)
{
    WORLDTRADE_ADAPTER_DeletePrintStream((struct Obj *)(p + 0xfa0));
    BMP_WIN_Delete(((struct Obj00287 *)p)->fDE0);
    BMP_WIN_Delete(((struct Obj00287 *)p)->fDD0);
    BMP_WIN_Delete(((struct Obj00287 *)p)->fD54);
    BMP_WIN_Delete(((struct Obj00287 *)p)->fD40);
    BMP_WIN_Delete(((struct Obj00287 *)p)->fD4C);
}
