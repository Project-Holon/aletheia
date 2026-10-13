/*
 * function: FIELD_G3D_MAPPER_SetOriginOffset
 * address:  0x0218DC4C
 * packet:   pkt_ov021_0218DC4C
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: copies the 12-byte vector at r1 into the object at +0x54.
 * Filed as the only blocker of ov052 FIELD_GIMMICK_BSUBWAY_UpdateTrainSway.
 */

typedef struct { int x, y, z; } V3;

void FIELD_G3D_MAPPER_SetOriginOffset(char *o, V3 *v)
{
    *(V3 *)(o + 0x54) = *v;
}
