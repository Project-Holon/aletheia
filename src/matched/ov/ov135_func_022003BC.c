/*
 * function: WORLDTRADE_TITLE_DeleteWindows
 * address: 0x022003BC
 * packet: pkt_ov135_022003BC
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_ADAPTER_DeletePrintStream 0x02202940 thumb ov135
 *   BMP_WIN_Delete 0x020452E8 arm
 */
#include "../include/Obj08194.h"
typedef unsigned char u8;
struct Obj;
extern void WORLDTRADE_ADAPTER_DeletePrintStream(struct Obj *p);
struct Descriptor;
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
void WORLDTRADE_TITLE_DeleteWindows(u8 *p)
{
    int i;
    WORLDTRADE_ADAPTER_DeletePrintStream((struct Obj *)(p + 0xFA0));
    BMP_WIN_Delete(((struct Obj08194 *)p)->fDE0);
    BMP_WIN_Delete(((struct Obj08194 *)p)->fDD0);
    BMP_WIN_Delete(((struct Obj08194 *)p)->fD40);
    for (i = 0; i < 3; i++) BMP_WIN_Delete(*(void **)(p + i * 4 + 0xD50));
    BMP_WIN_Delete(((struct Obj08194 *)p)->fD48);
}
