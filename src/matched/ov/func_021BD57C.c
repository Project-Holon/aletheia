/*
 * function: PLACE_NAME_LETTER_ClearBmp
 * address:  0x021BD57C
 * packet:   pkt_021BD57C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call on the word at +8 with a zero second argument.
 *
 * symbols:
 *   BMP_Clear  0x02043B5C  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18234.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);

void PLACE_NAME_LETTER_ClearBmp(u8 *p)
{
    BMP_Clear((struct CharBuf *)(((struct Obj18234 *)p)->f8), 0);
}
