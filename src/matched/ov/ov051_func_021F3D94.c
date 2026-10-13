/*
 * function: FIELD_GIMMICK_D06_GetGimmickId
 * address:  0x021F3D94
 * packet:   pkt_ov051_021F3D94
 * region:   ov051
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Maps the ids 0xC3..0xC5 to 0x19..0x1B (0x19 otherwise). Called from ov051 0x021F375C, 0x021F388C and 0x021F3D1E.
 */

int FIELD_GIMMICK_D06_GetGimmickId(int id)
{
    switch (id) {
    case 0xC3:
        return 0x19;
    case 0xC4:
        return 0x1A;
    case 0xC5:
        return 0x1B;
    }
    return 0x19;
}
