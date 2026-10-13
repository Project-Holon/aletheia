/*
 * function: GIMMICK46_ApplyPoseLines
 * address:  0x021F4078
 * packet:   pkt_ov046_021F4078
 * region:   ov046
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The table row is indexed inside the loop; the compiler hoists the
 * invariant row address (b's register reused for it). A `t = d[b][c]`
 * local before the loop colours b and the counter apart.
 * FIELD_NOGRID_MAPPER_SetLineEnable is ov021's thunk (reads r0-r2); ov214's label at the same
 * address is a different two-argument function.
 *
 * symbols:
 *   FIELDMAP_GetNogridMapper  0x02188C5C  thumb  ov021
 *   FIELD_NOGRID_MAPPER_SetLineEnable  0x021BB3DC  thumb  ov021
 *   sGimmick46PoseLines  0x021F4430  data  ov046  a4
 */

typedef unsigned int u32;
typedef unsigned char  u8;
extern u32 FIELDMAP_GetNogridMapper(u8 *p);
extern void FIELD_NOGRID_MAPPER_SetLineEnable(u32 *p, int b, int c);
extern int sGimmick46PoseLines[][4][6];

void GIMMICK46_ApplyPoseLines(u32 a, int b, int c)
{
    int v1[6];
    int v2[6];
    u32 h = FIELDMAP_GetNogridMapper((u8 *)a);
    int i;

    for (i = 0; i < 6; i++) {
        v1[i] = sGimmick46PoseLines[b][c][i];
        v2[i] = 0;
    }
    if (c != 1) {
        v2[0] = 1;
        v2[1] = 1;
    }
    for (i = 0; i < 6; i++)
        FIELD_NOGRID_MAPPER_SetLineEnable((u32 *)h, v1[i], v2[i]);
}
