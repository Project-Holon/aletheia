/*
 * function: UI_SetSleepHook
 * address:  0x02035004
 * packet:   pkt_02035004
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:

 *
 * Setter: stores two values into an object at +0x14 and +0x28.
 */

typedef unsigned int u32;

void UI_SetSleepHook(char *o, u32 a, u32 b)
{
    *(u32 *)(o + 0x14) = a;
    *(u32 *)(o + 0x28) = b;
}
