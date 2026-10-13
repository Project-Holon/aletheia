/*
 * function: FIELD_GIMMICK_LIFT_Init
 * address:  0x021F36C0
 * packet:   pkt_ov044_021F36C0
 * region:   ov044
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The `adds r7,r5,#0` before the loop is a zero, not a counter copy: it runs
 * once (the loop branches back past it) and holds the constant 0 passed as
 * BE674's i/j and BE6B8's v, rematerialised off the counter's zero.
 *
 * symbols:
 *   sGimmick44ExpObjUnitDesc     0x021F39E8  data  ov044
 *   sGimmick44LiftStartPos     0x021F3A1C  data  a4
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   FLD_EXP_OBJ_AddUnitFromArchive  0x021BE760  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_SetModelCullDraw  0x021BE4A4  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeLoop  0x021BE6B8  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FIELD_GIMMICK_LIFT_ShowIdleAnime  0x021F392C  thumb
 */

typedef unsigned short u16;

typedef struct {
    int a;
    int b;
    int c;
} V;

extern int sGimmick44ExpObjUnitDesc;
extern V sGimmick44LiftStartPos;

extern int FIELDMAP_GetExpObj(int *p);
typedef unsigned char  u8;
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern void *FIELDMAP_AllocCommonWork(unsigned char *p, int id, int a, int b);
extern void  FLD_EXP_OBJ_AddUnitFromArchive(void *p, void *a, int b);
extern int FLD_EXP_OBJ_GetModelStatus(char *p, unsigned i, int j);
extern void FLD_EXP_OBJ_SetModelCullDraw(char *p, int i, int j, int v);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern void FLD_EXP_OBJ_SetAnimeLoop(unsigned char *p, int v);
extern void FLD_EXP_OBJ_SetAnimePaused(unsigned char *p, int v);
extern void  FIELD_GIMMICK_LIFT_ShowIdleAnime(void *p);

void FIELD_GIMMICK_LIFT_Init(void *a0)
{
    void *r6;
    V *e;
    void *b;
    int i;

    r6 = (void *)FIELDMAP_GetExpObj(a0);
    FIELDMAP_AllocCommonWork(a0, 1, FIELDMAP_GetHeapId(a0), 0x14);
    FLD_EXP_OBJ_AddUnitFromArchive(r6, &sGimmick44ExpObjUnitDesc, 0);
    e = (V *)FLD_EXP_OBJ_GetModelStatus(r6, 0, 0);
    *e = sGimmick44LiftStartPos;
    FLD_EXP_OBJ_SetModelCullDraw(r6, 0, 0, 1);
    for (i = 0; i < 2; i++) {
        b = FLD_EXP_OBJ_GetAnime(r6, 0, (int)0, (u16)i);
        FLD_EXP_OBJ_SetAnimeLoop(b, 0);
        FLD_EXP_OBJ_SetAnimePaused(b, 1);
    }
    FIELD_GIMMICK_LIFT_ShowIdleAnime(r6);
}
