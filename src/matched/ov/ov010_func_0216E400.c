/*
 * function: func_0216E400
 * address:  0x0216E400
 * packet:   pkt_0216E400
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   d_021D5E04  0x021D5E04  data  ov021  a4
 *
 * note: un-hinted, sole-ref/data sees several overlays over 0x021D5E04 and
 * refuses.  ov021 is the only one with data there (a pointer table after a
 * zero word at 0x021D5E00); ov093, ov016 and the rest hold code.  ov021 is
 * resident with ov010: ov010 branches straight into 62 ov021 functions
 * (bl 0x021C3400 and others).  The ov021 hint fixes the choice.
 */

typedef unsigned int u32;

extern u32 d_021D5E04[];

u32 func_0216E400(int i)
{
    return d_021D5E04[i];
}
