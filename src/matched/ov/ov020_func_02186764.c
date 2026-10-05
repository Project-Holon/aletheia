/*
 * function: func_02186764
 * address:  0x02186764
 * packet:   pkt_02186764
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Clear bit 0 of the byte at +3.
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct {
u8 a;
u8 b;
u8 c;
u8 flag : 1;
} S;

void func_02186764(S *p)
{
p->flag = 0;
}
