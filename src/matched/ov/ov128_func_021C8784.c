/*
 * function: func_021C8784
 * address:  0x021C8784
 * packet:   pkt_021C8784
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14040.h"

typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);

void func_021C8784(char *p)
{
    BMP_Clear(func_02045770(((struct Obj14040 *)p)->f108), 0xf);
    BMP_WIN_TransferChars(((struct Obj14040 *)p)->f108);
}
