/*
 * function: PMSIV_EDIT_GetSlotRect
 * address:  0x021BC320
 * packet:   pkt_ov110_021BC320
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in a .word run.  Extent 0x021BC320..0x021BC340
 * (32 bytes).  Packs two s16 coordinates from a[n] into b.
 */

void PMSIV_EDIT_GetSlotRect(void *a, unsigned char *b, int n)
{
    int i = n * 4;

    b[2] = *(short *)((char *)a + i + 0x38) - 0x18;
    b[3] = b[2] + 0x60;
    b[0] = *(short *)((char *)a + i + 0x3a);
    b[1] = b[0] + 0x10;
}
