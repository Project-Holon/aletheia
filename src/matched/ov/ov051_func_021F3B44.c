/*
 * function: FIELD_GIMMICK_D06_AddStone
 * address:  0x021F3B44
 * packet:   pkt_ov051_021F3B44
 * region:   ov051
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_GIMMICK_D06_AddStoneMmdl  0x021F3D38  thumb  ov051
 *   FIELD_GIMMICK_D06_IsStoneNextToPanel  0x021F3C98  thumb  ov051
 *   FLDMMDL_GetPos  0x0216D88C  thumb
 *   FIELDMAP_GetEffect  0x02188CD0  thumb
 *   FLDEFF_D06DENKI_StartFollow  0x021C9064  thumb
 *   FLDEFF_D06DENKI_FollowFreezeLoop  0x021C909C  thumb
 */

extern void *FIELD_GIMMICK_D06_AddStoneMmdl(int a, int x, int y);
extern int FIELD_GIMMICK_D06_IsStoneNextToPanel(int *a, int *b);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *a, struct VecFx32 *b);
extern int FIELDMAP_GetEffect(int a);
extern int FLDEFF_D06DENKI_StartFollow(int a, int *b, int c);
extern void FLDEFF_D06DENKI_FollowFreezeLoop(int a);

void FIELD_GIMMICK_D06_AddStone(int *a, int *out, int x, int y)
{
    int buf[3];

    out[0] = (int)FIELD_GIMMICK_D06_AddStoneMmdl(a[2], x, y);
    FLDMMDL_GetPos((const struct Actor *)out[0], (struct VecFx32 *)buf);
    out[1] = FLDEFF_D06DENKI_StartFollow(FIELDMAP_GetEffect(a[2]), buf, out[0]);
    if (FIELD_GIMMICK_D06_IsStoneNextToPanel(a, out) == 1)
        FLDEFF_D06DENKI_FollowFreezeLoop(out[1]);
}
