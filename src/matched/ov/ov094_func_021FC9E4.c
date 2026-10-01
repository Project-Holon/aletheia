/*
 * function: func_021FC9E4
 * address:  0x021FC9E4
 * packet:   pkt_ov094_021FC9E4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Wait callback: done once flag bit 7 of the state word is clear.
 */
typedef struct {
    unsigned lo : 7;
    unsigned bit : 1;
} Flags;

int func_021FC9E4(void *a, Flags *s)
{
    if (s->bit)
        return 0;
    return 1;
}
