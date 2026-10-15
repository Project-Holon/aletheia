/*
 * function: WF2DMAP_SCENE_ShowMessage
 * address:  0x021DA610
 * packet:   pkt_021DA610
 * region:   ov129
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WF2DMAP_SCENE_DrawMessage  0x021DA578  thumb
 */

extern void WF2DMAP_SCENE_DrawMessage(void *p, int a, void *b, unsigned int c);

void WF2DMAP_SCENE_ShowMessage(void *p, int sel, void *b, unsigned int c)
{
    if (sel == 1) {
        WF2DMAP_SCENE_DrawMessage(p, 5, b, c);
        return;
    }
    if (sel == 2)
        WF2DMAP_SCENE_DrawMessage(p, 6, b, c);
}
