/*
 * function: func_02175ED8
 * address:  0x02175ED8
 * packet:   pkt_ov011_02175ED8
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Flag getter: bit 4 of the byte at 0x1A5 (the lsls #27 / lsrs #31 pair is
 * a one-bit bitfield read).  A leaf with no lr save, so disasm.py left it as
 * .word data; filed for ov011 func_02172D70, whose only unresolved call
 * site besides arm9 0x02008494 it was.
 */

typedef unsigned char u8;

typedef struct Sub {
    u8 pad000[0x1a5];
    u8 bit0 : 1;
    u8 bit1 : 1;
    u8 bit2 : 1;
    u8 bit3 : 1;
    u8 bit4 : 1;
} Sub;

int func_02175ED8(Sub *s)
{
    return s->bit4;
}
