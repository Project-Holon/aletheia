/*
 * function: func_0220B908
 * address: 0x0220B908
 * packet: pkt_ov207_0220B908
 * region: ov207
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201F73C 0x0201F73C thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj06677.h"
struct Descriptor;struct Cfg;extern void func_0201F73C(void *,int,unsigned short,int);extern void BMP_WIN_TransferChars(struct Descriptor *);extern void BMP_WIN_MakeScreen(struct Cfg *);extern unsigned char BMP_WIN_GetBgLayer(struct Descriptor *);extern void func_02041B6C(unsigned);
void func_0220B908(char *p){if(!((struct Obj06677 *)p)->f3C){struct Descriptor *d;unsigned flag=1;func_0201F73C(((struct Obj06677 *)p)->f24,1,((struct Obj06677 *)p)->f30,8);d=*(struct Descriptor * *)&((struct Obj06677 *)p)->f24;BMP_WIN_TransferChars(d);BMP_WIN_MakeScreen((struct Cfg *)d);func_02041B6C(BMP_WIN_GetBgLayer(d));((struct Obj06677 *)p)->f3C=flag;}}
