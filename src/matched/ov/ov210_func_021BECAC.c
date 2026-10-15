/*
 * function: ZKNSEARCH_MAIN_TransferRowChars
 * address:  0x021BECAC
 * packet:   pkt_ov210_021BECAC
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_TransferChars  0x02045334  arm
 * Addresses are Black-image addresses.
 */

struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *v);

void ZKNSEARCH_MAIN_TransferRowChars(int a, unsigned *p)
{
    BMP_WIN_TransferChars((struct Descriptor *)*p);
}
