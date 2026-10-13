/*
 * function: WIPE_HBlankSlotsTask
 * address:  0x02022478
 * packet:   pkt_02022478
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

void WIPE_HBlankSlotsTask(int a0, int *p)
{
    int i;
    for (i = 0; i < 2; i++)
        ((void (*)(int))p[i + 2])(p[i]);
}
