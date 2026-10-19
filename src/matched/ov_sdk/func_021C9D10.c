/*
 * function: calcColumnIdx
 * address:  0x021C9D10
 * packet:   pkt_021C9D10
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   calcColumnIdx   0x021C9D10  arm
 *   FX_DivS32   0x0207C958  arm
 *
 * Scan four consecutive halfword entries of the global table for the argument,
 * returning the index of the hit or -1.  Every concrete byte matches the image
 * (68 bytes, no register or constant residue).
 *
 * Promoted from MATCH by the recursive-unblocker lane: 0x0207C958 is the ARM
 * SDK symbol FX_DivS32 (also an EXACT sdk_calibration entry).  Declaring it
 * `arm` (the image's ISA) lets the `sdk`/`matched` class attest the +0x14
 * call; the old `thumb` declaration fought the image's ISA and suppressed it.
 * Verified EXACT, 68 bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/calcColumnIdx.c \
 *       --func calcColumnIdx --addr 0x021C9D10 --region ov016 --cc dsi/1.1p1 --arm
 */

extern int FX_DivS32(int, int);

int calcColumnIdx(int a)
{
    unsigned char *g = (unsigned char *)0x021DE5EC;
    int i;
    int v = FX_DivS32(*(unsigned short *)(g + 4), 0x1d);

    for (i = 0; i < 4; i++) {
        if (v == a)
            return i;
        v++;
    }
    return -1;
}
