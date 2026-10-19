/*
 * function: VIEWER_ACTOR_StepWaitWipeIn
 * address:  0x021C79B8
 * packet:   pkt_ov111_021C79B8
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef struct {
    unsigned char pad0[0x10C];
    int state;
} Work;

typedef unsigned int   u32;
extern u32 WIPE_SYS_EndCheck(void);

int VIEWER_ACTOR_StepWaitWipeIn(Work *p)
{
    if (WIPE_SYS_EndCheck()) {
        p->state = 1;
    }
    return 1;
}
