/*
 * function: func_021DD4B0
 * address:  0x021DD4B0
 * packet:   pkt_021DD4B0
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021E4C08  0x021E4C08  data
 *
 * Flush gate, second queue: a null destination or source is refused with 0,
 * otherwise the 0x021E4C08 block is released and 1 comes back.
 */

typedef unsigned long u32;

extern u32 g_021E4C08[];
extern void func_02094798(u32);

int func_021DD4B0(char *a, char *b)
{
    if (a == 0 || b == 0)
        return 0;
    func_02094798((u32)g_021E4C08);
    return 1;
}

