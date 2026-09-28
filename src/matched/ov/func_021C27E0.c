/*
 * function: func_021C27E0
 * address:  0x021C27E0
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * One-bit field at bit 1 of the byte at +0x1B: an `unsigned char` bitfield
 * container, which is why the read is `ldrb` + `lsls #0x1e` + `lsrs #0x1f`.
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

int func_021C27E0(S *s)
{
    return s->b1;
}
