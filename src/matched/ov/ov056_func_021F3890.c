/*
 * function: FIELD_FK_DEMO_InitBuildAnime
 * address:  0x021F3890
 * packet:   pkt_ov056_021F3890
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_BUILDMODEL_CreateNodeNearPos  0x0218C7D8  thumb  ov021
 *   FIELD_BUILDMODEL_GetFirstEntryNearPos  0x0218C654  thumb  ov021
 *   gFkDemoHasBuildAnime  0x021F4290  data  ov056  a4
 *   gFkDemoBuildModelPos  0x021F42D8  data  ov056  a4
 */

typedef unsigned int u32;

typedef struct { u32 a, b, c; } Ent;

extern int FIELD_BUILDMODEL_CreateNodeNearPos(void *p, int b, int c);
extern int FIELD_BUILDMODEL_GetFirstEntryNearPos(int a, int b, int c);
extern u32 gFkDemoHasBuildAnime[];
extern Ent gFkDemoBuildModelPos[];

void FIELD_FK_DEMO_InitBuildAnime(u32 *out, int a, int idx)
{
    if (gFkDemoHasBuildAnime[idx] != 0) {
        out[0] = FIELD_BUILDMODEL_CreateNodeNearPos((void *)a, 0, (int)(&gFkDemoBuildModelPos[idx]));
        out[1] = FIELD_BUILDMODEL_GetFirstEntryNearPos(a, 0, (int)(&gFkDemoBuildModelPos[idx]));
        out[2] = a;
    } else {
        out[0] = 0;
        out[1] = 0;
    }
}
