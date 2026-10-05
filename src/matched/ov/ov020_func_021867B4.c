/*
 * function: func_021867B4
 * address:  0x021867B4
 * packet:   pkt_ov020_021867B4
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf (saves nothing, so disasm.py prints it as .word data);
 * filed as the blocker of func_02186D48 (ov020).
 */

typedef unsigned char  u8;
typedef unsigned short u16;

int func_021867B4(u8 *p)
{
    return p[2] <= 20;
}
