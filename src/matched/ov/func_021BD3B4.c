/*
 * function: ZKND_TBAR_IsButtonAnimActive
 * address:  0x021BD3B4
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
 *   ZKND_TBAR_GetButtonSound 0x021BD868  thumb  ov208

 * Calls ZKND_TBAR_IsKeyAnimActive then ZKND_TBAR_GetButtonSound.
 */


extern void *ZKND_TBAR_IsKeyAnimActive(void *mgr, int key);
extern int ZKND_TBAR_GetButtonSound(const void *p);

int ZKND_TBAR_IsButtonAnimActive(void *mgr, int key)
{
    return ZKND_TBAR_GetButtonSound(ZKND_TBAR_IsKeyAnimActive(mgr, key));
}

