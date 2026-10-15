/*
 * function: NAMEIN_GRAPHIC_BlitTexture
 * address: 0x021F513C
 * packet: pkt_ov194_021F513C
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   NAMEIN_GRAPHIC_CopyRows 0x021F51A4 thumb ov194
 *
 * Tile copy: for each row/column of the w x h block at (x, y), copy one
 * 8-line tile through NAMEIN_GRAPHIC_CopyRows.  The original copies dst from its
 * incoming stack slot into a frame slot of its own ([sp+0x18], frame
 * 0x24): holding it in an unsigned local gives that slot, where passing
 * dst (or a char * copy of it) directly is copy-propagated and reuses
 * [sp+0x40] in a 0x20 frame.  102 bytes; the last two of the 104-byte
 * extent are alignment padding before NAMEIN_GRAPHIC_CopyRows.
 */
extern void NAMEIN_GRAPHIC_CopyRows(const char *src, char *dst, unsigned *a, unsigned *b, unsigned n, unsigned step);
void NAMEIN_GRAPHIC_BlitTexture(const char *src, int width, int x, int y, int w, int h, char *dst)
{
    unsigned inOffset;
    unsigned outOffset;
    int i, j;
    unsigned step;
    unsigned target;
    step = width * 4;
    target = (unsigned)dst;
    outOffset = 0;
    for (j = y; j < y + h; j++) {
        for (i = x; i < x + w; i++) {
            inOffset = i * 4 + j * step * 8;
            NAMEIN_GRAPHIC_CopyRows(src, (char *)target, &inOffset, &outOffset, 4, step);
        }
    }
}
