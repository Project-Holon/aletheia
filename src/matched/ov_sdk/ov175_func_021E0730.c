/*
 * function: sciWsDestroy
 * address:  0x021E0730
 * packet:   pkt_021E0730
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   (none)
 *
 * ARM leaf reset: clear the eleven words of the state block, in the order
 * the image writes them.
 */

void sciWsDestroy(char *p)
{
    *(int *)(p + 0x48) = 0;
    *(int *)(p + 4) = 0;
    *(int *)(p + 8) = 0;
    *(int *)(p + 0xc) = 0;
    *(int *)(p + 0x2c) = 0;
    *(int *)(p + 0x28) = 0;
    *(int *)(p + 0x30) = 0;
    *(int *)(p + 0x14) = 0;
    *(int *)(p + 0x10) = 0;
    *(int *)(p + 0x18) = 0;
    *(int *)(p + 0) = 0;
}

