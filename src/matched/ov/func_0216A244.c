/*
 * function: REPORT_EVENT_IsAvatarReady
 * address:  0x0216A244
 * packet:   pkt_0216A244
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * unblocked: FIELD_PLAYER_CheckAnimePaused (ov021 tail-call thunk) matched bottom-up and
 *   filed as pkt_021A3244; the `ov021` token resolves its call as
 *   `matched, overlay`.  Extent runs 32 against 30 compiled: the unlabelled
 *   follower.
 *
 * The overlay's own status call takes the arm9 handle; anything but one
 * reads as failure.
 *
 * symbols:
 *   FIELDMAP_GetFieldPlayer   0x02188CB4  thumb
 *   FIELD_PLAYER_CheckNotWaterForm   0x021A3208  thumb
 *   FIELD_PLAYER_CheckAnimePaused   0x021A3244  thumb  ov021
 */
#include "../include/Obj17754.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *FIELDMAP_GetFieldPlayer(unsigned char *p);
extern int FIELD_PLAYER_CheckNotWaterForm(void *);
extern int FIELD_PLAYER_CheckAnimePaused(void *);

int REPORT_EVENT_IsAvatarReady(void *a0)
{
    void *v = FIELDMAP_GetFieldPlayer(((struct Obj17754 *)a0)->f8);

    if (FIELD_PLAYER_CheckNotWaterForm(v) == 1)
        return FIELD_PLAYER_CheckAnimePaused(v);

    return 1;
}
