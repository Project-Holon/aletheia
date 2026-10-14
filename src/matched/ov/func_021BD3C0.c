/*
 * function: ZKND_TBAR_GetButtonActor
 * address:  0x021BD3C0
 * packet:   pkt_021BD368
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ZKND_TBAR_FindButtonActor 0x021BD404  thumb  ov208
 */

extern void *ZKND_TBAR_FindButtonActor(void *mgr, int key);

int ZKND_TBAR_GetButtonActor(void *mgr, int key)
{
    return *(int *)ZKND_TBAR_FindButtonActor(mgr, key);
}

