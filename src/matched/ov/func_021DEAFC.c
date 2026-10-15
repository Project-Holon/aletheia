/*
 * function: BOX2_MAIN_IsSwapScene
 * address:  0x021DEAFC
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_MAIN_CheckSceneMode  0x021DEA6C  thumb  ov170
 *
 * Set the flag on the object.
 */

extern int BOX2_MAIN_CheckSceneMode(char *p, int a);

int BOX2_MAIN_IsSwapScene(int a)
{
    return BOX2_MAIN_CheckSceneMode((char *)a, 1);
}

