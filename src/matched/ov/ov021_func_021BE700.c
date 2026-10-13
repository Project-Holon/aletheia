/*
 * function: FLD_EXP_OBJ_SetAnimeEnabled
 * address:  0x021BE700
 * packet:   pkt_ov021_021BE700
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb
 *   FLD_EXP_OBJ_GetModelObject  0x021BE4C4  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 *   G3D_SYSTEM_DisableObjectAnime  0x020477D4  arm
 */

typedef unsigned char u8;

extern void *FLD_EXP_OBJ_GetModelObject(void *a, int b, int c);
typedef unsigned int   u32;
struct G3dSys;
struct Owner;
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);
extern int G3D_SYSTEM_DisableObjectAnime(struct Owner *owner, u32 index);

void FLD_EXP_OBJ_SetAnimeEnabled(void *p, int i, int j, int k, int flag)
{
    void *r6 = FLD_EXP_OBJ_GetModelObject(p, i, j);
    u8 *e = FLD_EXP_OBJ_GetAnime(p, i, j, k);

    if (e == 0) {
        return;
    }
    if (flag != 0) {
        if (e[2] != 0) {
            return;
        }
        G3D_SYSTEM_EnableObjectAnime(r6, k);
    } else {
        if (e[2] == 0) {
            return;
        }
        G3D_SYSTEM_DisableObjectAnime(r6, k);
    }
    e[2] = flag;
}
