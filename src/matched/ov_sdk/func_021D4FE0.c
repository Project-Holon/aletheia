/*
 * function: func_021D4FE0
 * address:  0x021D4FE0
 * packet:   pkt_021D4FE0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D4FE0   0x021D4FE0  arm
 *
 * Index into the i-th 8-byte record of the table at p+8.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021D4FE0.c \
 *       --func func_021D4FE0 --addr 0x021D4FE0 --region ov016 --cc dsi/1.1p1 --arm
 */

char *func_021D4FE0(char *p, unsigned int i)
{
    return *(char **)(p + 8) + (i << 3);
}
