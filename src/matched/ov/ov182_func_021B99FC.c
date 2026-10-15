/*
 * function: THE_END_GRAPHIC_VBlankTask
 * address:  0x021B99FC
 * packet:   pkt_021B99FC
 * region:   ov182
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   THE_END_GRAPHIC_RefreshDisplay  0x021B9AAC  thumb  ov182
 *   THE_END_GRAPHIC_VBlankActors  0x021B9B18  thumb  ov182
 */

extern void THE_END_GRAPHIC_RefreshDisplay(void *);
extern void THE_END_GRAPHIC_VBlankActors(void *);

void THE_END_GRAPHIC_VBlankTask(int a0, char *p)
{
    THE_END_GRAPHIC_RefreshDisplay(p);
    THE_END_GRAPHIC_VBlankActors(p + 4);
}
