/*
 * function: func_021867A8
 * address:  0x021867A8
 * packet:   pkt_ov020_021867A8
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

typedef struct {
    u8 lo : 4;
    u8 hi : 4;
} Nib;

int func_021867A8(Nib *p)
{
    return p->hi;
}
