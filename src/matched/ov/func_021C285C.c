/*
 * function: func_021C285C
 * address:  0x021C285C
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * One-bit field at bit 4 of the byte at +0x1B (`lsls #0x1b; lsrs #0x1f`).
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

int func_021C285C(S *s)
{
    return s->b4;
}
