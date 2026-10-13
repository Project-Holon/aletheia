/*
 * function: GIMMICK60_ShowEffect
 * address:  0x021F399C
 * packet:   pkt_ov060_021F399C
 * region:   ov060
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLD_EXP_OBJ_SetModelHidden  0x021BE4B4  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeFrame  0x021BE6CC  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    int a;
    int b;
    int c;
} V;

extern void FLD_EXP_OBJ_SetModelHidden(char *p, int i, int j, int v);
extern void FLD_EXP_OBJ_SetAnimeFrame(int a, int b, int c, int d, int e);
extern V *FLD_EXP_OBJ_GetModelStatus(void *p, int i, int j);

void GIMMICK60_ShowEffect(u8 *o, void *p, V *v)
{
    int i;

    FLD_EXP_OBJ_SetModelHidden(p, 0, 0x14, 0);
    for (i = 0; i < 3; i++) {
        FLD_EXP_OBJ_SetAnimeFrame((int)p, 0, 0x14, (u16)i, 0);
    }
    *FLD_EXP_OBJ_GetModelStatus(p, 0, 0x14) = *v;
    o[1] = 1;
}
