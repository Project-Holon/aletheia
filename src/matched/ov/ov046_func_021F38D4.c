/*
 * function: FIELD_GIMMICK_ROTATING_ROOM_InitUnitPose
 * address:  0x021F38D4
 * packet:   pkt_ov046_021F38D4
 * region:   ov046
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Levers: case 0 spelled k = 1 like default (cross-jumped onto the default's
 * copy, giving the table's leading b); n1/n2 named and assigned between the
 * "= 1" default and its if (before it, n + 1 is copy-propagated into every
 * call and the frame grows a slot).
 *
 * symbols:
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeFrame  0x021BE6CC  thumb  ov021
 *   FLD_EXP_OBJ_GetAnimeLastFrame  0x021BE748  thumb  ov021
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

extern void FLD_EXP_OBJ_SetAnimeEnabled(void *p, int i, int j, int k, int flag);
extern u8 *FLD_EXP_OBJ_GetAnime(u32 a, int b, u16 c, u16 d);
extern void FLD_EXP_OBJ_SetAnimePaused(u8 *p, int v);
extern void FLD_EXP_OBJ_SetAnimeFrame(u32 a, int b, u16 c, u16 d, int e);
extern int FLD_EXP_OBJ_GetAnimeLastFrame(u32 a);

void FIELD_GIMMICK_ROTATING_ROOM_InitUnitPose(u8 *base, u32 t, int idx)
{
    int *e;
    int n;
    int k;
    u8 *p;
    int m;
    int n1;
    u8 *q;
    int k3;
    int n2;
    u8 *r;

    e = (int *)(base + idx * 12);
    switch (e[0]) {
    case 0:
        k = 1;
        break;
    case 1:
        k = 5;
        break;
    case 3:
        k = 0;
        break;
    case 2:
        k = 2;
        break;
    default:
        k = 1;
        break;
    }
    n = idx * 5;
    p = FLD_EXP_OBJ_GetAnime(t, 0, n, k);
    FLD_EXP_OBJ_SetAnimePaused(p, 0);
    FLD_EXP_OBJ_SetAnimeEnabled((void *)t, 0, (u16)n, (u16)k, 1);
    FLD_EXP_OBJ_SetAnimeFrame(t, 0, n, k, FLD_EXP_OBJ_GetAnimeLastFrame((u32)p));
    m = 1;
    n1 = n + 1;
    if (e[1] == 0)
        m = 0;
    q = FLD_EXP_OBJ_GetAnime(t, 0, n1, m);
    FLD_EXP_OBJ_SetAnimePaused(q, 0);
    FLD_EXP_OBJ_SetAnimeEnabled((void *)t, 0, (u16)n1, (u16)m, 1);
    FLD_EXP_OBJ_SetAnimeFrame(t, 0, n1, m, FLD_EXP_OBJ_GetAnimeLastFrame((u32)q));
    k3 = 1;
    n2 = n + 2;
    if (e[2] == 0)
        k3 = 0;
    r = FLD_EXP_OBJ_GetAnime(t, 0, n2, k3);
    FLD_EXP_OBJ_SetAnimePaused(r, 0);
    FLD_EXP_OBJ_SetAnimeEnabled((void *)t, 0, (u16)n2, (u16)k3, 1);
    FLD_EXP_OBJ_SetAnimeFrame(t, 0, n2, k3, FLD_EXP_OBJ_GetAnimeLastFrame((u32)r));
}
