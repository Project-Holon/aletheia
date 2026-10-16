/*
 * function: MICTEST_DeleteWindows
 * address: 0x02184360
 * packet: pkt_ov168_02184360
 * region: ov168
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 */
#include "../include/Obj14260.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bank; struct CharBuf; struct Descriptor; struct Rec; struct Node; struct Blk37;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *,u8);
extern void BMP_WIN_ClearScreen(struct Descriptor *);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 GF_FONT_Delete(void *ptr);
void MICTEST_DeleteWindows(char *p) { int i; for(i=0;i<3;i++) {BMP_Clear(BMP_WIN_GetBmp(*(void **)(p+i*4)),0);BMP_WIN_ClearScreen(*(struct Descriptor **)(p+i*4));BMP_WIN_Delete(*(struct Descriptor **)(p+i*4));} MSGDATA_Delete(*(struct Rec * *)&((struct Obj14260 *)p)->fC);GF_FONT_Delete(((struct Obj14260 *)p)->f10); }
