/*
 * function: BTLV_CAMERA_UpdateMove
 * address:  0x021F6ED4
 * packet:   pkt_021F6ED4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_CAMERA_StepMove  0x021F723C  thumb  ov094
 */

void BTLV_CAMERA_StepMove(int *p);

void BTLV_CAMERA_UpdateMove(int *p)
{
    BTLV_CAMERA_StepMove(p);
}
