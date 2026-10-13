/*
 * function: func_021DDFBC
 * address: 0x021DDFBC
 * packet: pkt_ov171_021DDFBC
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 */
#include "../include/Obj08250.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Descriptor;
struct CharBuf;
extern void BMP_WIN_ClearScreen(struct Descriptor *);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *);
extern void func_02041B6C(u32);
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *,u8);
extern void BMP_WIN_TransferChars(struct Descriptor *);
void func_021DDFBC(u8 *p)
{
    BMP_WIN_ClearScreen(*(struct Descriptor * *)&((struct Obj08250 *)p)->fB50);
    func_02041B6C(BMP_WIN_GetBgLayer(*(struct Descriptor * *)&((struct Obj08250 *)p)->fB50));
    BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj08250 *)p)->fB50),0);
    BMP_WIN_TransferChars(*(struct Descriptor * *)&((struct Obj08250 *)p)->fB50);
}
