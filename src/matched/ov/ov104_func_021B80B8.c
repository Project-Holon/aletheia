/*
 * function: IRC_RHYTHM_ClearTextWindow
 * address: 0x021B80B8
 * packet: pkt_ov104_021B80B8
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 */
#include "../include/Obj10245.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct CharBuf;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
void IRC_RHYTHM_ClearTextWindow(u8 *p) { BMP_Clear(BMP_WIN_GetBmp(((struct Obj10245 *)p)->f0),((struct Obj10245 *)p)->f10); BMP_WIN_TransferChars(((struct Obj10245 *)p)->f0); }
