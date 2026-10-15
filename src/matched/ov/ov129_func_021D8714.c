/*
 * function: WF2DMAP_SCENE_Draw
 * address:  0x021D8714
 * packet:   pkt_021D8714
 * region:   ov129
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WF2DMAP_SCENE_Dispatch  0x021D8F78  thumb
 *   CLACT_DrawSystem  0x0204A600  arm
 *
 * Addresses are Black-image addresses.
 */

extern int WF2DMAP_SCENE_Dispatch(char *p);
extern void CLACT_DrawSystem(void *);

int WF2DMAP_SCENE_Draw(int a, int b, int c, int d)
{
    void *r = (void *)WF2DMAP_SCENE_Dispatch((char *)d);

    CLACT_DrawSystem(r);
    return r != 0;
}
