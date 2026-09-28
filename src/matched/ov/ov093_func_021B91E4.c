/*
 * function: func_021B91E4
 * address:  0x021B91E4
 * packet:   pkt_ov093_021B91E4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in a .word run.  If bit 3 of p[0x473] is clear,
 * adds `add` to the word at p+0x434 and clamps it to 0x1869f.
 * The bit test is a lsls #0x1c / lsrs #0x1f pair, so the promoted value
 * must stay unsigned.
 */

typedef unsigned char u8;
typedef unsigned int u32;

void func_021B91E4(void *p, int add)
{
    if (((unsigned int)*(u8 *)((char *)p + 0x473) << 28 >> 31) != 0)
        return;
    *(u32 *)((char *)p + 0x434) += add;
    if (*(u32 *)((char *)p + 0x434) > 0x1869f)
        *(u32 *)((char *)p + 0x434) = 0x1869f;
}
