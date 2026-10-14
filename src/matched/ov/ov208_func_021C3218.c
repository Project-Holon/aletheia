/*
 * function: ZUKAN_DETAIL_VOICE_CreateTimerWindow
 * address: 0x021C3218
 * packet: pkt_ov208_021C3218
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ARC_UTIL_UploadPaletteFromArchive 0x02049B90 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   ZUKAN_DETAIL_VOICE_ClearTimerWindow 0x021C32FC thumb ov208
 *   BMP_WIN_TransferChars 0x02045334 arm
 */
#include "../include/Obj00146.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void ARC_UTIL_UploadPaletteFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void ZUKAN_DETAIL_VOICE_ClearTimerWindow(u16 *,u8 *,int);
struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *);
void ZUKAN_DETAIL_VOICE_CreateTimerWindow(u16 *heap,u8 *p,int key)
{
    ARC_UTIL_UploadPaletteFromArchive(23,5,4,0,0,32,*heap);
    *(u32 *)&((struct Obj00146 *)p)->fC=BMP_WIN_Create(6,10,5,12,4,0,1);
    ((struct Obj00146 *)p)->f10=0;
    ZUKAN_DETAIL_VOICE_ClearTimerWindow(heap,p,key);
    BMP_WIN_TransferChars((struct Descriptor *)*(u32 *)&((struct Obj00146 *)p)->fC);
}
