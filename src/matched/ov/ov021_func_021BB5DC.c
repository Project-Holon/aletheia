/*
 * function: FLDEFF_GYOE_InitHeldTask
 * address:  0x021BB5DC
 * packet:   pkt_ov021_021BB5DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_EFFECT_GetObjectParam  0x021AC1AC  thumb  ov021
 *   FIELD_EFFECT_UpdateObject  0x021AC178  thumb  ov021
 */

typedef struct {
    int w[7];
} Blk;

typedef struct {
    Blk b;
    char pad[0x10];
    int f2C;
} Out;

extern Blk *FIELD_EFFECT_GetObjectParam(int a);
extern void FIELD_EFFECT_UpdateObject(int a);

void FLDEFF_GYOE_InitHeldTask(int a, Out *out)
{
    out->b = *FIELD_EFFECT_GetObjectParam(a);
    out->f2C = 0x6000;
    FIELD_EFFECT_UpdateObject(a);
}
