/*
 * function: WORLDTRADE_SEARCH_DeleteWindows
 * address: 0x021FE0BC
 * packet: pkt_ov135_021FE0BC
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_ADAPTER_DeletePrintStream 0x02202940 thumb ov135
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BG_SYS_FreeTiles 0x02040DA8 arm
 */
#include "../include/Obj14174.h"
struct Obj;
extern void WORLDTRADE_ADAPTER_DeletePrintStream(struct Obj *p);
typedef unsigned int   u32;
struct Descriptor;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void BG_SYS_FreeTiles(u32 idx, u32 count, u32 tile);
void WORLDTRADE_SEARCH_DeleteWindows(unsigned char *p)
{
    int i;
    WORLDTRADE_ADAPTER_DeletePrintStream((struct Obj *)(p + 0xfa0));
    BMP_WIN_Delete(((struct Obj14174 *)p)->fDE0);
    BMP_WIN_Delete(((struct Obj14174 *)p)->fD40);
    for (i = 0; i < 9; ++i)
        BMP_WIN_Delete(*(void **)(p + i * 4 + 0xd90));
    for (i = 0; i < 2; ++i)
        BMP_WIN_Delete(*(void **)(p + i * 4 + 0xdd8));
    BG_SYS_FreeTiles(3, 1, 0);
}
