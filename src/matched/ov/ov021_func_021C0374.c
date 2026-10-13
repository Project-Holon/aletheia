/*
 * function: EVENT_DISAPPEAR_CreateFadeOutAlt
 * address:  0x021C0374
 * packet:   pkt_ov021_021C0374
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls EVENT_FIELDMAP_CONTROL_StartFadeOut with mode 0 or 1 by the flag at +0x78.
 *
 * symbols:
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb  ov021
 */

typedef unsigned int u32;

extern int EVENT_FIELDMAP_CONTROL_StartFadeOut(void *a, int b, int sel, int d);

int EVENT_DISAPPEAR_CreateFadeOutAlt(u32 *p)
{
    u32 a = p[0];
    u32 b = p[1];

    if (p[30] != 0)
        EVENT_FIELDMAP_CONTROL_StartFadeOut((void *)a, b, 0, 0);
    else
        return EVENT_FIELDMAP_CONTROL_StartFadeOut((void *)a, b, 1, 0);
}
