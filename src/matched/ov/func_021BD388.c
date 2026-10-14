/*
 * function: ZKND_TBAR_GetButtonVisible
 * address:  0x021BD388
 * packet:   pkt_021BD368
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZKND_TBAR_IsKeyAnimActive 0x021BD43C  thumb  ov208
 *   ZKND_TBAR_GetActorDrawEnable 0x021BD808  thumb  ov208

 * Calls ZKND_TBAR_IsKeyAnimActive then ZKND_TBAR_GetActorDrawEnable.
 */


extern void *ZKND_TBAR_IsKeyAnimActive(void *mgr, int key);
extern void ZKND_TBAR_GetActorDrawEnable(int *p);

void ZKND_TBAR_GetButtonVisible(void *mgr, int key)
{
    ZKND_TBAR_GetActorDrawEnable(ZKND_TBAR_IsKeyAnimActive(mgr, key));
}

