/*
 * function: PLIST_MESSAGE_RedrawWindow
 * address: 0x021BBA28
 * packet: pkt_ov091_021BBA28
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj03681.h"
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
typedef unsigned int   u32;
extern void func_02041B6C(u32 bit);
void PLIST_MESSAGE_RedrawWindow(int a,int b) {unsigned int q; BMP_Clear((struct CharBuf *)((int)func_02045770((struct Descriptor *)((struct Obj03681 *)b)->f4)),15); q=((struct Obj03681 *)b)->f4; BMP_WIN_TransferChars((struct Descriptor *)q);BMP_WIN_MakeScreen((struct Cfg *)q);func_02041B6C(func_02045730((struct Descriptor *)q));}
