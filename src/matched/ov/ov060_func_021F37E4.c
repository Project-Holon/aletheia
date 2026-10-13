/*
 * function: GIMMICK60_PlaceModels
 * address:  0x021F37E4
 * packet:   pkt_ov060_021F37E4
 * region:   ov060
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_SetModelCullDraw  0x021BE4A4  thumb  ov021
 *   FLD_EXP_OBJ_SetModelHidden  0x021BE4B4  thumb  ov021
 *   GIMMICK60_ShowGauges  0x021F3880  thumb  ov060
 */

typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    int a;
    int b;
    int c;
} V;

extern int FIELDMAP_GetExpObj(int *p);
extern V *FLD_EXP_OBJ_GetModelStatus(void *p, int i, u16 j);
extern void FLD_EXP_OBJ_SetModelCullDraw(char *p, int i, int j, int v);
extern void FLD_EXP_OBJ_SetModelHidden(void *p, int i, u16 j, int v);
extern u8 GIMMICK60_ShowGauges(void *a, void *b, void *c);

void GIMMICK60_PlaceModels(u8 *out, void *b, void *c, void *d)
{
    void *s;
    int i;
    V *p;

    s = (void *)FIELDMAP_GetExpObj(b);
    for (i = 0; i < 0x15; i++) {
        p = FLD_EXP_OBJ_GetModelStatus(s, 0, i);
        p->a = 0x1F8000;
        p->b = 0x20000;
        p->c = 0x1B8000;
        FLD_EXP_OBJ_SetModelCullDraw(s, 0, (u16)i, 1);
        FLD_EXP_OBJ_SetModelHidden(s, 0, i, 1);
    }
    *out = GIMMICK60_ShowGauges(c, s, d);
}
