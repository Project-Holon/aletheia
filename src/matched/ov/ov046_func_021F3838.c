/*
 * function: FIELD_GIMMICK_ROTATING_ROOM_InitModel
 * address:  0x021F3838
 * packet:   pkt_ov046_021F3838
 * region:   ov046
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FX_SinCosTable_     0x020A1B38  data  a2
 *   func_0207AF1C  0x0207AF1C  thumb
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_SetModelCullDraw  0x021BE4A4  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeLoop  0x021BE6B8  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 */

typedef unsigned short u16;
typedef signed short s16;

typedef struct {
    int a;
    int b;
    int c;
} V;

extern s16 FX_SinCosTable_[];

extern int FLD_EXP_OBJ_GetModelStatus(char *p, unsigned i, int j);
extern void  FLD_EXP_OBJ_SetModelCullDraw(void *p, int i, u16 j, int v);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern void FLD_EXP_OBJ_SetAnimeLoop(unsigned char *p, int v);
extern void FLD_EXP_OBJ_SetAnimePaused(unsigned char *p, int v);
extern void  FLD_EXP_OBJ_SetAnimeEnabled(void *p, int i, u16 j, u16 k, int flag);
extern void  func_0207AF1C(void *m, int a, int b);

void FIELD_GIMMICK_ROTATING_ROOM_InitModel(void *a0, int a1, V *a2, u16 *a3, int a4, int a5)
{
    char *e;
    void *b;
    int i;
    int k;

    e = (char *)FLD_EXP_OBJ_GetModelStatus(a0, (int)0, (u16)a1);
    *(V *)e = *a2;
    if (a3) {
        k = (*a3 >> 4) * 2;
        func_0207AF1C(e + 0x18, FX_SinCosTable_[k], FX_SinCosTable_[k + 1]);
    }
    FLD_EXP_OBJ_SetModelCullDraw(a0, 0, a1, a5);
    for (i = 0; i < a4; i++) {
        b = FLD_EXP_OBJ_GetAnime(a0, 0, (u16)a1, (u16)i);
        FLD_EXP_OBJ_SetAnimeLoop(b, 0);
        FLD_EXP_OBJ_SetAnimePaused(b, 1);
        FLD_EXP_OBJ_SetAnimeEnabled(a0, 0, a1, i, 0);
    }
}
