/*
 * function: FIELD_GIMMICK_BSUBWAY_Init
 * address:  0x021F36C0
 * packet:   pkt_ov053_021F36C0
 * region:   ov053
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FLD_EXP_OBJ_AddUnitFromArchive  0x021BE760  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeLoop  0x021BE6B8  thumb  ov021
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   GIMMICK53_CreateSoundObjs  0x021F3828  thumb  ov053
 *   GIMMICK53_RestoreAnimeFrames  0x021F3A04  thumb  ov053
 *   ISS_3DS_SYS_SetVolume  0x0202B914  thumb
 *   sGimmick53UnitSetup     0x021F3D60  data  a4
 */

typedef unsigned int u32;
typedef unsigned char u8;

extern char sGimmick53UnitSetup[];

typedef unsigned short u16;
struct Obj;
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern int FIELDMAP_GetExpObj(int *p);
extern void FLD_EXP_OBJ_AddUnitFromArchive(int a, void *b, int c);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *p, int i, int j, int k, int flag);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern void FLD_EXP_OBJ_SetAnimePaused(u8 *p, int v);
extern void FLD_EXP_OBJ_SetAnimeLoop(u8 *p, int v);
extern void *FIELDMAP_AllocCommonWork(unsigned char *p, int id, int a, int b);
struct O;
extern void GIMMICK53_CreateSoundObjs(struct O *o, u32 q);
extern void GIMMICK53_RestoreAnimeFrames(char *a, int b);
extern void ISS_3DS_SYS_SetVolume(struct Obj *o, u32 v);

void FIELD_GIMMICK_BSUBWAY_Init(u32 a)
{
    u32 r6;
    u32 r5;
    u8 *e;
    int *p;

    r6 = FIELDMAP_GetHeapId((u8 *)a);
    r5 = FIELDMAP_GetExpObj((int *)a);
    FLD_EXP_OBJ_AddUnitFromArchive(r5, sGimmick53UnitSetup, 0);
    FLD_EXP_OBJ_SetAnimeEnabled((void *)r5, 0, 4, 0, 1);
    e = FLD_EXP_OBJ_GetAnime((char *)r5, 0, 4, 0);
    FLD_EXP_OBJ_SetAnimePaused(e, 0);
    FLD_EXP_OBJ_SetAnimeLoop(e, 1);
    p = FIELDMAP_AllocCommonWork((unsigned char *)a, 0, r6, 0xf8);
    GIMMICK53_CreateSoundObjs((struct O *)p, a);
    GIMMICK53_RestoreAnimeFrames((char *)p, a);
    ISS_3DS_SYS_SetVolume((struct Obj *)p[1], 0x7f);
}
