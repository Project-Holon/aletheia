/*
 * function: func_021F36C0
 * address:  0x021F36C0
 * packet:   pkt_ov061_021F36C0
 * region:   ov061
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   FLD_EXP_OBJ_AddUnitFromArchive  0x021BE760  thumb  ov021
 *   FLD_EXP_OBJ_SetModelHidden  0x021BE4B4  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeLoop  0x021BE6B8  thumb  ov021
 *   GIMMICK61_PlaceMarkers  0x021F388C  thumb  ov061
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   d_021F3974     0x021F3974  data  a4
 */

typedef unsigned short u16;
typedef unsigned char u8;

extern char d_021F3974[];

extern u16 FIELDMAP_GetHeapId(u8 *p);
extern int FIELDMAP_GetExpObj(int *p);
extern void *FIELDMAP_AllocCommonWork(unsigned char *p, int id, int a, int b);
extern void FLD_EXP_OBJ_AddUnitFromArchive(void *a, void *b, int c);
extern void FLD_EXP_OBJ_SetModelHidden(char *p, int i, int j, int v);
extern int FLD_EXP_OBJ_GetModelStatus(char *p, unsigned i, int j);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *p, int i, int j, int k, int flag);
extern void FLD_EXP_OBJ_SetAnimePaused(u8 *p, int v);
extern void FLD_EXP_OBJ_SetAnimeLoop(u8 *p, int v);
extern void GIMMICK61_PlaceMarkers(int *o, int a);
extern u16 FIELDMAP_GetZoneId(u8 *p);

void func_021F36C0(void *a)
{
    u16 w;
    void *s;
    int *o;
    int i;
    u8 *e;

    w = FIELDMAP_GetHeapId(a);
    s = (void *)FIELDMAP_GetExpObj(a);
    o = FIELDMAP_AllocCommonWork(a, 0, w, 0xc);
    FLD_EXP_OBJ_AddUnitFromArchive(s, d_021F3974, 0);
    for (i = 0; i < 9; i++) {
        FLD_EXP_OBJ_SetModelHidden(s, 0, (u16)i, 1);
    }
    o[1] = (int)FLD_EXP_OBJ_GetModelStatus(s, 0, 0);
    e = FLD_EXP_OBJ_GetAnime(s, 0, 0, 0);
    FLD_EXP_OBJ_SetAnimeEnabled(s, 0, 0, 0, 1);
    FLD_EXP_OBJ_SetAnimePaused(e, 1);
    FLD_EXP_OBJ_SetAnimeLoop(e, 0);
    GIMMICK61_PlaceMarkers(o, (int)a);
    o[2] = FIELDMAP_GetZoneId(a);
}
