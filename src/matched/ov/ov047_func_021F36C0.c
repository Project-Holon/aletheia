/*
 * function: FIELD_GIMMICK_BRIDGE_Init
 * address:  0x021F36C0
 * packet:   pkt_ov047_021F36C0
 * region:   ov047
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 */

typedef unsigned short u16;
typedef unsigned char  u8;
struct Big;
struct Ctx;
extern void *FIELDMAP_GetGameSystem(void *p);
extern u16 FIELDMAP_GetHeapId(u8 *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELDMAP_AllocCommonWork(unsigned char *p, int id, int a, int b);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
typedef unsigned int   u32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);

void FIELD_GIMMICK_BRIDGE_Init(int a)
{
    void **p;

    GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem((void *)a))), 0x1f);
    FIELDMAP_AllocCommonWork((unsigned char *)a, 1, FIELDMAP_GetHeapId((u8 *)a), 0x14);
    p = (void **)FIELDMAP_GetCommonWork((char *)a, 1);
    p[0] = FIELDMAP_GetFieldPlayer((void *)a);
    p[1] = FIELD_PLAYER_GetMmdl(p[0]);
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
}
