/*
 * function: FIELD_GIMMICK_MODELS_B_InitModels
 * address:  0x021F383C
 * packet:   pkt_ov050_021F383C
 * region:   ov050
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb
 *   FLD_EXP_OBJ_AddUnitFromArchive  0x021BE760  thumb
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb
 *   FIELD_GIMMICK_MODELS_B_StopModel0Anime  0x021F3744  thumb  ov050
 *   FIELD_GIMMICK_MODELS_B_HideModel1  0x021F3788  thumb  ov050
 *   gGimmick50Setup     0x021F38A4  data  a4
 *   gGimmick50ModelPos     0x021F38B4  data  a4
 */

typedef struct { int a; int b; int c; } T12;

extern int FIELDMAP_GetExpObj(int a);
extern void FLD_EXP_OBJ_AddUnitFromArchive(int a, void *b, int c);
extern T12 *FLD_EXP_OBJ_GetModelStatus(int a, int b, unsigned short c);
extern void FIELD_GIMMICK_MODELS_B_StopModel0Anime(int *p);
extern void FIELD_GIMMICK_MODELS_B_HideModel1(int *p);
extern int gGimmick50Setup;
extern const T12 gGimmick50ModelPos[];

void FIELD_GIMMICK_MODELS_B_InitModels(int unused, int b)
{
    int r4;
    int i;
    T12 *p;
    const T12 *s;

    r4 = FIELDMAP_GetExpObj(b);
    FLD_EXP_OBJ_AddUnitFromArchive(r4, &gGimmick50Setup, 0);
    for (i = 0; i < 2; i++) {
        p = FLD_EXP_OBJ_GetModelStatus(r4, 0, i);
        s = &gGimmick50ModelPos[i];
        p->a = s->a;
        p->b = s->b;
        p->c = s->c;
    }
    FIELD_GIMMICK_MODELS_B_StopModel0Anime((int *)b);
    FIELD_GIMMICK_MODELS_B_HideModel1((int *)b);
}
