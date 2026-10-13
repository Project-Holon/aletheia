/*
 * function: GIMMICK54_ExitSoundObjs
 * address: 0x021F38E4
 * packet: pkt_ov054_021F38E4
 * region: ov054
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   FIELDMAP_GetGameSystem 0x02188C80 thumb ov021
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetFieldSave 0x02012EC4 thumb
 *   GIMMICK_WORK_GetSaveArea 0x0200B3A4 thumb
 *   SOUND_OBJ_SetAnimeFrame 0x021C4E08 thumb ov021
 */

typedef unsigned char  u8;
struct Big;
struct Ctx;
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
typedef unsigned int   u32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern int SOUND_OBJ_SetAnimeFrame(void *,int);
void GIMMICK54_ExitSoundObjs(char *p,int a) { int *q=GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem((void *)a))),11); int i; for(i=0;i<2;i++) SOUND_OBJ_SetAnimeFrame(*(void **)(p+8+4*i),(int)((unsigned)q[i]<<12)); }
