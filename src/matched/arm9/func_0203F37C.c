/*
 * unit:     no
 * function: GF_STANDARD_ShuffleEx
 * address:  0x0203F37C
 * packet:   pkt_0203F32C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GF_STANDARD_Shuffle  0x0203F328  arm
 */

extern void GF_STANDARD_Shuffle(unsigned short *p, unsigned int size, unsigned int seed);
void GF_STANDARD_ShuffleEx(void *p, unsigned int size, unsigned int seed){ GF_STANDARD_Shuffle(p, size, seed); }
