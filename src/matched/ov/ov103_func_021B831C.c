/*
 * function: func_021B831C
 * address: 0x021B831C
 * packet: pkt_ov103_021B831C
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 */
#include "../include/Obj10244.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
extern void *func_02045770(struct Descriptor *); extern void BMP_Clear(int,u8); extern void BMP_WIN_TransferChars(struct Descriptor *);
void func_021B831C(u8 *p) {BMP_Clear((int)func_02045770((struct Descriptor *)((struct Obj10244 *)p)->f0),((struct Obj10244 *)p)->f10);BMP_WIN_TransferChars((struct Descriptor *)((struct Obj10244 *)p)->f0);}
