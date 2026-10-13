/*
 * function: FIELD_GIMMICK_ROTATING_ROOM_CalcUnitPose
 * address:  0x021F3BC8
 * packet:   pkt_021F3BC8
 * region:   ov046
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

int FIELD_GIMMICK_ROTATING_ROOM_CalcUnitPose(int *p)
{
    if (p[1] == 0) {
        if (p[2] == 0)
            return 0;
        return 3;
    }
    if (p[2] == 0)
        return 2;
    return 1;
}
