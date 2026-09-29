/*
 * function: func_021869B8
 * address:  0x021869B8
 * packet:   pkt_ov020_021869B8
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (saves nothing, so disasm.py prints it as .word data);
 * filed as the blocker of func_02186D48 (ov020).
 */

typedef unsigned char  u8;
typedef unsigned short u16;

u16 func_021869B8(u16 *p)
{
    return p[1];
}
