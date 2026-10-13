/*
 * unit: no
 * function: func_021E0304
 * address: 0x021E0304
 * packet: pkt_ov137_021E0304
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj02869.h"
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
struct Descriptor;struct Cfg;struct CharBuf;struct Bank;struct Util;struct Setup;struct Ctx;
extern void func_0201F7A8(void *,u32);
extern void *func_02045770(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *,u8);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *);
extern u8 func_02045730(struct Descriptor *);
extern void func_02041B6C(u32);
void func_021E0304(u8 *p){struct Descriptor *w=*(struct Descriptor * *)&((struct Obj02869 *)p)->fCF0;func_0201F7A8(w,0);BMP_Clear(func_02045770(w),0);BMP_WIN_TransferChars(w);BMP_WIN_MakeScreen((struct Cfg *)w);func_02041B6C(func_02045730(w));}
