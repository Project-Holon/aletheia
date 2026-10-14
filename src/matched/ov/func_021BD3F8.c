/*
 * function: ZKND_TBAR_GetButtonActorRaw
 * address:  0x021BD3F8
 * packet:   pkt_021BD3F8
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZKND_TBAR_FindButtonActor 0x021BD404  thumb  ov208
 */

extern char *ZKND_TBAR_FindButtonActor(void *mgr, int key);

void ZKND_TBAR_GetButtonActorRaw(void *mgr, int key)
{
    *(int *)(ZKND_TBAR_FindButtonActor(mgr, key) + 0x34) = 1;
}

