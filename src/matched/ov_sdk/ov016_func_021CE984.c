/*
 * function: func_021CE984
 * address:  0x021CE984
 * packet:   pkt_ov016_021CE984
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Unlabelled ARM leaf (saves nothing, so disasm.py prints the run as a
 * `.word` block).  Getter: byte at +0x1a of the object published at
 * 0x021DE63C.  Matched bottom-up (recursive MATCH unblocker) to witness the
 * two `bl 0x021CE984` sites in src/pending/ov016_func_021C57E4.c and
 * src/pending/ov016_func_021C8C88.c via the `matched` class.
 *
 * symbols:
 *   dat_021DE63C  0x021DE63C  data
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

extern u8 *dat_021DE63C;

u8 func_021CE984(void)
{
    return dat_021DE63C[0x1a];
}
