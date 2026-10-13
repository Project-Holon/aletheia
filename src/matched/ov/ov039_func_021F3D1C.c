/*
 * function: GIMMICK39_SaveCartFrames
 * address:  0x021F3D1C
 * packet:   pkt_ov039_021F3D1C
 * region:   ov039
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetExpObj 0x02188D2C thumb ov021
 *   FIELDMAP_GetCommonWork 0x021897BC thumb
 *   FIELDMAP_GetGameSystem 0x02188C80 thumb
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetFieldSave 0x02012EC4 thumb
 *   GIMMICK_WORK_GetSaveArea 0x0200B3A4 thumb
 *   FLD_EXP_OBJ_UpdateAnimes 0x021BE580 thumb ov021
 *   GIMMICK39_GetAnimeFrame 0x021F3DE4 thumb ov039
 */

typedef unsigned char  u8;
struct Big;
struct Ctx;
extern int FIELDMAP_GetExpObj(int *p);
extern unsigned char *FIELDMAP_GetCommonWork(int, int);
extern int FIELDMAP_GetGameSystem(int);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
typedef unsigned int   u32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern void FLD_EXP_OBJ_UpdateAnimes(int);
typedef unsigned short u16;
extern int GIMMICK39_GetAnimeFrame(void *p, u16 delta, u16 i);

void GIMMICK39_SaveCartFrames(int a)
{
    int *r7;
    int r6;
    int i;
    unsigned char *r5;

    r6 = FIELDMAP_GetExpObj((int *)a);
    r5 = FIELDMAP_GetCommonWork(a, 1);
    r7 = GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData((const struct Ctx *)FIELDMAP_GetGameSystem(a))), 2);
    FLD_EXP_OBJ_UpdateAnimes(r6);
    for (i = 0; i < 4; i++)
        r7[i] = GIMMICK39_GetAnimeFrame((void *)r6, (unsigned char)i, (unsigned char)(r5[i + 0x21EC] + 1));
}
