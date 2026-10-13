/*
 * function: TIME_ICON_NodeMain
 * address:  0x0202F0A4
 * packet:   pkt_0202EF98
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * notes:    unlabelled Thumb leaf after TIME_ICON_TaskMain; seeded in
 *           layout/function_starts.txt.
 *
 * symbols:
 *   TIME_ICON_Update  0x0202F0B0  thumb
 */

typedef unsigned char u8;

extern void TIME_ICON_Update(u8 *work);

void TIME_ICON_NodeMain(void *node, u8 *work)
{
    TIME_ICON_Update(work);
}
