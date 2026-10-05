/*
 * function: func_0203CB00
 * address:  0x0203CB00
 * packet:   pkt_0203CB00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Unlabelled ARM predicate: the card task object exists and its callback at +8 is func_0203CADC.
 * MATCH only because 0x0203CADC (func_0203CADC.c, EXACT) is not yet a labelled
 * function start: the pool word has no outside witness until the seed lands.
 *
 * symbols:
 *   g_021469DC     0x021469DC  data
 *   func_0203CADC  0x0203CADC  arm
 */

struct Card0203CB00 {
    unsigned char pad[8];
    void *cb;
};

extern struct Card0203CB00 *g_021469DC;
extern void func_0203CADC(void);

int func_0203CB00(void)
{
    struct Card0203CB00 *c = g_021469DC;
    if (c != 0 && c->cb == (void *)func_0203CADC) {
        return 1;
    }
    return 0;
}
