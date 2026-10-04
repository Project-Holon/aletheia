/*
 * function: func_0203C5EC
 * address:  0x0203C5EC
 * packet:   pkt_0203C5EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Unlabelled ARM leaf: byte at +0x4a of the card task object.
 *
 * symbols:
 *   g_021469DC  0x021469DC  data
 */

struct Card0203C5EC {
    unsigned char pad[0x4a];
    unsigned char f4a;
};

extern struct Card0203C5EC *g_021469DC;

unsigned int func_0203C5EC(void)
{
    return g_021469DC->f4a;
}
