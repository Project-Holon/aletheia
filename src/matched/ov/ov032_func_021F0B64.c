/*
 * function: func_021F0B64
 * address: 0x021F0B64
 * packet: pkt_ov032_021F0B64
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 */
#include "../include/Obj00007.h"
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
void func_021F0B64(char *p) { BMP_Clear(((struct Obj00007 *)p)->f194,0x40); BMP_WIN_TransferChars(((struct Obj00007 *)p)->f190); }
