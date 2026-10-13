/*
 * function: WIFICLUB_SetStatusSeatFlag
 * address:  0x021C27E8
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Writes the one-bit field at bit 1 of the byte at +0x1B.  The value argument
 * is a byte: as an `int` the compiler truncates it first and the entry comes out
 * two instructions long.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed short   s16;
typedef int BOOL;

typedef struct {
    char pad[0x1B];
    u8 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1;
} S;

void WIFICLUB_SetStatusSeatFlag(S *s, u8 v)
{
    s->b1 = v;
}
