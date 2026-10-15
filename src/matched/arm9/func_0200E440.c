/*
 * function: SYMBOL_SAVE_SetBitDescriptor
 * address:  0x0200E440
 * packet:   pkt_0200E440
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;

void SYMBOL_SAVE_SetBitDescriptor(u8 *p, int value, int index)
{
    (p + index)[640] = value;
}
