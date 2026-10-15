/*
 * function: SHINKA_DEMO_AreActorAnimsDone
 * address:  0x02205168
 * packet:   pkt_ov195_022040E0
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Leaf of the SHINKA_DEMO_Main dependency tree: probe all six +0x48 handles;
 * if every one is idle, hand the scene object to SHINKA_DEMO_DeleteActors.  A missing
 * +0x60 pointer reports success without probing.
 *
 * symbols:
 *   CLACT_IsActorAnimActive  0x0204B98C  arm
 *   SHINKA_DEMO_DeleteActors  0x02205100  thumb
 */
typedef unsigned int   u32;
struct Actor;
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void SHINKA_DEMO_DeleteActors(void *unused, char *p);

int SHINKA_DEMO_AreActorAnimsDone(int a, int *p)
{
    unsigned char i;

    if (p[0x18] != 0) {
        int ok = 1;

        for (i = 0; i < 6; i++) {
            if (CLACT_IsActorAnimActive((struct Actor *)p[0x12 + i]) != 0) {
                ok = 0;
                break;
            }
        }
        if (ok)
            SHINKA_DEMO_DeleteActors((void *)a, (char *)p);
        return ok;
    }
    return 1;
}
