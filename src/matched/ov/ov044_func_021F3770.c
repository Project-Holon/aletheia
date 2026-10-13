/*
 * function: FIELD_GIMMICK_LIFT_CallEvent
 * address:  0x021F3770
 * packet:   pkt_ov044_021F3770
 * region:   ov044
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   FIELD_GIMMICK_LIFT_LiftEventMain  0x021F37F0  thumb
 */

typedef unsigned int   u32;
struct Ctx;
struct Desc;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
extern int FIELDMAP_GetExpObj(int *p);
extern void  FLD_EXP_OBJ_SetAnimeEnabled(void *p, int i, int j, int k, int flag);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int FIELD_GIMMICK_LIFT_LiftEventMain(void *a, int *b);

void FIELD_GIMMICK_LIFT_CallEvent(void *a0, int a1)
{
    void *r6;
    int *r4;
    void *x;
    int d;

    r6 = GAMESYSTEM_GetFieldMap(a0);
    r4 = FIELDMAP_GetCommonWork(r6, 1);
    r4[4] = a1;
    if (a1) {
        r4[0] = 0;
        r4[1] = -0x50000;
    } else {
        r4[0] = -0x50000;
        r4[1] = 0;
        x = (void *)FIELDMAP_GetExpObj(r6);
        FLD_EXP_OBJ_SetAnimeEnabled(x, 0, 0, 0, 1);
        FLD_EXP_OBJ_SetAnimeEnabled(x, 0, 0, 1, 0);
    }
    d = r4[1] - r4[0];
    if (d < 0) {
        d = -0x2000;
    } else {
        d = 0x2000;
    }
    r4[2] = d;
    func_020122C0(a0, 0, FIELD_GIMMICK_LIFT_LiftEventMain, 0);
}
