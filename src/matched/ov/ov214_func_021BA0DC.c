/*
 * function: func_021BA0DC
 * address: 0x021BA0DC
 * packet: pkt_ov214_021BA0DC
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Tail: two zero alignment bytes at 021BA106.
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj14700.h"
struct Descriptor;struct Cfg;struct CharBuf;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *,unsigned char),BMP_WIN_TransferChars(struct Descriptor *),BMP_WIN_MakeScreen(struct Cfg *),func_02041B6C(unsigned);
extern unsigned char BMP_WIN_GetBgLayer(struct Descriptor *);
void func_021BA0DC(int unused,char *p){struct Descriptor *d;BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj14700 *)p)->f6C),0);d=*(struct Descriptor * *)&((struct Obj14700 *)p)->f6C;BMP_WIN_TransferChars(d);BMP_WIN_MakeScreen((struct Cfg *)d);func_02041B6C(BMP_WIN_GetBgLayer(d));}
