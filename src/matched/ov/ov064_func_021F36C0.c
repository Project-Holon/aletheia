/*
 * function: func_021F36C0
 * address:  0x021F36C0
 * packet:   pkt_ov064_021F36C0
 * region:   ov064
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   GPOWER_GetSpecialPowerId  0x020111E8  thumb
 *   FLD_EXP_OBJ_AddUnitFromArchive  0x021BE760  thumb  ov021
 *   FLD_EXP_OBJ_SetModelHidden  0x021BE4B4  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeLoop  0x021BE6B8  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   d_021F3C20     0x021F3C20  data  a4
 *   d_021F3C30     0x021F3C30  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;

extern char d_021F3C20[];
extern char d_021F3C30[];

extern int FIELDMAP_GetExpObj(int *p);
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern void *FIELDMAP_AllocCommonWork(unsigned char *p, int id, int a, int b);
typedef unsigned int   u32;
extern u32 GPOWER_GetSpecialPowerId(void);
extern void FLD_EXP_OBJ_AddUnitFromArchive(int a, void *b, int c);
extern void FLD_EXP_OBJ_SetModelHidden(char *p, int i, int j, int v);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern void FLD_EXP_OBJ_SetAnimeLoop(u8 *p, int v);
extern void FLD_EXP_OBJ_SetAnimePaused(u8 *p, int v);
extern void FLD_EXP_OBJ_SetAnimeEnabled(int a, int b, int c, u16 d, int e);

void func_021F36C0(int a)
{
    int s;
    int *o;
    int i;
    u8 *e;

    s = FIELDMAP_GetExpObj((int *)a);
    o = FIELDMAP_AllocCommonWork((unsigned char *)a, 1, FIELDMAP_GetHeapId((u8 *)a), 0x38);
    o[1] = 0;
    if (GPOWER_GetSpecialPowerId() == 0x14) {
        FLD_EXP_OBJ_AddUnitFromArchive(s, d_021F3C20, 0);
    } else {
        FLD_EXP_OBJ_AddUnitFromArchive(s, d_021F3C30, 0);
    }
    o[0] = 4;
    FLD_EXP_OBJ_SetModelHidden((char *)s, 0, 0, 1);
    FLD_EXP_OBJ_SetModelHidden((char *)s, 0, 1, 1);
    for (i = 0; i < 4; i++) {
        e = FLD_EXP_OBJ_GetAnime((char *)s, 0, (int)0, (u16)i);
        FLD_EXP_OBJ_SetAnimeLoop(e, 0);
        FLD_EXP_OBJ_SetAnimePaused(e, 1);
        FLD_EXP_OBJ_SetAnimeEnabled(s, 0, 0, i, 0);
    }
    for (i = 0; i < 3; i++) {
        e = FLD_EXP_OBJ_GetAnime((char *)s, 0, (int)1, (u16)i);
        FLD_EXP_OBJ_SetAnimeLoop(e, 0);
        FLD_EXP_OBJ_SetAnimePaused(e, 1);
        FLD_EXP_OBJ_SetAnimeEnabled(s, 0, 1, i, 0);
    }
}
