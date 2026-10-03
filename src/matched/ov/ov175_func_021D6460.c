/*
 * function: func_021D6460
 * address: 0x021D6460
 * packet: pkt_ov175_021D6460
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Unlabelled blocker leaf for func_021D5908; parent confirmed unowned.
 * symbols:
 *   func_021E777C 0x021E777C thumb ov177
 */
struct Work;
extern int func_021E777C(struct Work *);
int func_021D6460(char *p)
{
    return func_021E777C(*(struct Work **)(p + 0x1c));
}
