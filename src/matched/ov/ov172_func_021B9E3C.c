/*
 * function: func_021B9E3C
 * address:  0x021B9E3C
 * packet:   pkt_021B6868
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Seeds the two +0x30 bytes and releases the +0x2c block.
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj10664.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Descriptor;
extern void *func_02045770(struct Descriptor *a);
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);

void func_021B9E3C(void *p, char *q)
{
    q[0x30] = 3;
    q[0x31] = 0x20;
    BMP_Clear((struct CharBuf *)((int)func_02045770((struct Descriptor *)((struct Obj10664 *)q)->f2C)), 0);
}
