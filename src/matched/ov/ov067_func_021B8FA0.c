/*
 * function: FRAME_LIST_ClampBgFrameId
 * address:  0x021B8FA0
 * packet:   pkt_ov067_021B8FA0
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 */

int FRAME_LIST_ClampBgFrameId(int x)
{
    if (x == 0)
        return 0;
    if (x == 1)
        return 1;
    if (x == 2)
        return 2;
    if (x == 3)
        return 3;
    if (x == 4)
        return 4;
    if (x == 5)
        return 5;
    if (x == 6)
        return 6;
    if (x == 7)
        return 7;
    return 0;
}
