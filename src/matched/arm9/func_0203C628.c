/*
 * function: func_0203C628
 * address:  0x0203C628
 * packet:   pkt_0203C628
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Unlabelled ARM predicate: the callback at +8 of the card task object is func_0203C0F4 or func_0203C464.
 *
 * symbols:
 *   g_021469DC     0x021469DC  data
 *   func_0203C0F4  0x0203C0F4  arm
 *   func_0203C464  0x0203C464  arm
 */

struct Card0203C628 {
    unsigned char pad[8];
    void *cb;
};

extern struct Card0203C628 *g_021469DC;
extern void func_0203C0F4(void);
extern void func_0203C464(void);

int func_0203C628(void)
{
    void *cb = g_021469DC->cb;
    return cb == (void *)func_0203C0F4 || cb == (void *)func_0203C464;
}
