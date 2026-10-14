/*
 * function: WORLDTRADE_DETAIL_DeleteWindows
 * address: 0x021FC4E4
 * packet: pkt_ov135_021FC4E4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 021FC526..021FC528 is two zero alignment bytes.
 * symbols:
 *   WORLDTRADE_ADAPTER_DeletePrintStream 0x02202940 thumb ov135
 *   BMP_WIN_Delete 0x020452E8 arm
 */
#include "../include/Obj00287.h"
struct Obj;
extern void WORLDTRADE_ADAPTER_DeletePrintStream(struct Obj *p);
struct Descriptor;
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
void WORLDTRADE_DETAIL_DeleteWindows(char *p)
{
    int i;
    WORLDTRADE_ADAPTER_DeletePrintStream((struct Obj *)(p + 0xfa0));
    BMP_WIN_Delete(((struct Obj00287 *)p)->fDE0);
    BMP_WIN_Delete(((struct Obj00287 *)p)->fD40);
    BMP_WIN_Delete(((struct Obj00287 *)p)->fD50);
    for (i = 0; i < 14; i++) {
        BMP_WIN_Delete(*(void **)(p + i * 4 + 0xd90));
    }
}
