/*
 * function: VIEWER_ACTOR_UpdateMain
 * address:  0x021C79D0
 * packet:   pkt_ov111_021C79D0
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PRINTSYS_QUE_IsFinished  0x0201C6B4  thumb
 *   VIEWER_ACTOR_HandleInput  0x021C7E48  thumb
 *   VIEWER_ACTOR_RefreshRows  0x021C8364  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef struct {
    unsigned char pad0[0x14];
    void *f14;
} Work;

typedef unsigned int   u32;
struct PrintSys;
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern void VIEWER_ACTOR_HandleInput(Work *p);
extern void VIEWER_ACTOR_RefreshRows(Work *p);

int VIEWER_ACTOR_UpdateMain(Work *p)
{
    if (PRINTSYS_QUE_IsFinished(p->f14) == 0) {
        return 1;
    }
    VIEWER_ACTOR_HandleInput(p);
    VIEWER_ACTOR_RefreshRows(p);
    return 1;
}
