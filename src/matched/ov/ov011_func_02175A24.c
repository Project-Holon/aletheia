/*
 * function: func_02175A24
 * address:  0x02175A24
 * packet:   pkt_ov011_02175A24
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (sole blocker of ov018 func_0217C4D0): bit 1 of the
 * flag byte at +0x1A5.
 *
 * symbols:
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
} Flags;

int func_02175A24(u8 *p)
{
    return ((Flags *)(p + 0x1A5))->b1;
}
