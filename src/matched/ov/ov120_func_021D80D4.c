/*
 * function: func_021D80D4
 * address: 0x021D80D4
 * packet: pkt_ov120_021D80D4
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two zero padding bytes at 021D8116.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020452E8 0x020452E8 arm
 */
#include "../include/Obj05352.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void func_02041B6C(u32 bit);
extern u32 func_020452E8(struct Descriptor *d);
void func_021D80D4(char *p)
{
    if (((struct Obj05352 *)p)->f84) {
        BMP_Clear(func_02045770(((struct Obj05352 *)p)->f84),0);
        BMP_WIN_TransferChars(((struct Obj05352 *)p)->f84);
        BMP_WIN_ClearScreen(((struct Obj05352 *)p)->f84);
        func_02041B6C(1);
        func_020452E8(((struct Obj05352 *)p)->f84);
        ((struct Obj05352 *)p)->f84=0;
    }
}
