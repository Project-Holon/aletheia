/*
 * function: func_021D9B9C
 * address: 0x021D9B9C
 * packet: pkt_ov121_021D9B9C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: two trailing zero alignment bytes.
 * symbols:
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj08092.h"
typedef unsigned char u8;
struct Descriptor;
struct Cfg;
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_02041B6C(unsigned);
struct Descriptor;
extern u8 func_02045730(struct Descriptor *p);
void func_021D9B9C(u8 *p) {
    BMP_WIN_TransferChars(((struct Obj08092 *)p)->fC);
    if(((struct Obj08092 *)p)->f24==1) {
        BMP_WIN_MakeScreen(((struct Obj08092 *)p)->fC);
        func_02041B6C(func_02045730(((struct Obj08092 *)p)->fC));
    }
}
