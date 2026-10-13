/*
 * function: GIMMICK_INIT_SetGimmick40Flag
 * address: 0x021F36E8
 * packet: pkt_ov037_021F36E8
 * region: ov037
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of alignment padding at 021F3722.
 * interface: retain r1=3 at 0200B3A4 despite its accessor not reading r1.
 * symbols:
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetFieldSave 0x02012EC4 thumb
 *   GIMMICK_WORK_GetSaveArea 0x0200B3A4 thumb
 *   GAME_DATA_GetMyPlayerWork 0x020127A4 thumb
 */
typedef unsigned char  u8;
struct Big;
struct Ctx;
struct SaveBlock;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
typedef unsigned int   u32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
void GIMMICK_INIT_SetGimmick40Flag(void *a, int v)
{
    void *save;
    int *p;
    save = GAMESYSTEM_GetGameData(a);
    p = GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(save), 3);
    GAME_DATA_GetMyPlayerWork(save);
    if (v) p[0] = 1;
    else p[0] = 0;
    if (p[0]) *((unsigned char *)p + 4) = 1;
    else *((unsigned char *)p + 4) = 0;
}
