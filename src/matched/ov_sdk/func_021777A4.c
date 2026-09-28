/*
 * function: func_021777A4
 * address:  0x021777A4
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Byte at +0x1d of the record the index selects.
 *
 * symbols:
 *   g_021AB180  0x021AB180  data
 */

extern char g_021AB180[];

unsigned char func_021777A4(int i)
{
    return *(unsigned char *)(*(char **)g_021AB180 + i * 0x38 + 0x1d);
}

