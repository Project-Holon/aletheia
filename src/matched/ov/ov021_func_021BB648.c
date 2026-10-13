/*
 * function: FLDEFF_GYOE_UpdateTask
 * address:  0x021BB648
 * packet:   pkt_ov021_021BB648
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_CheckCheckInfo  0x0216E1C4  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   FIELD_EFFECT_SetObjectPos  0x021AC1CC  thumb  ov021
 *   FLDEFF_GYOE_StepAnimation  0x021BB808  thumb  ov021
 */

int FLDMMDL_CheckCheckInfo(int a, int b);
struct Actor;
struct VecFx32;
void FLDMMDL_GetPos(const struct Actor *a, struct VecFx32 *out);
void FIELD_EFFECT_DeleteObject(int a);
void FIELD_EFFECT_SetObjectPos(int a, int *b);
struct Vec;
void FLDEFF_GYOE_StepAnimation(int *o, struct Vec *out);

void FLDEFF_GYOE_UpdateTask(int a, int *b)
{
    int v[3];

    if (b[9] == 1 || FLDMMDL_CheckCheckInfo(b[3], (int)(b + 4)) == 0) {
        FIELD_EFFECT_DeleteObject(a);
        return;
    }
    FLDMMDL_GetPos((const struct Actor *)b[3], (struct VecFx32 *)v);
    FLDEFF_GYOE_StepAnimation(b, (struct Vec *)v);
    FIELD_EFFECT_SetObjectPos(a, v);
}
