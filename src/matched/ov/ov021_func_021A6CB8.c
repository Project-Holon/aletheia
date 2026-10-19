/*
 * function: FIELDMAP_CTRL_NOGRID_WORK_Create
 * address:  0x021A6CB8
 * packet:   pkt_ov021_021A6CB8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELDMAP_GetNogridMapper  0x02188C5C  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_CTRL_NOGRID_WORK_CreateWork  0x021A6D58  thumb  ov021
 *   FIELDMAP_SetCtrlWork  0x02188CAC  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_GetPosPtr  0x0216D888  thumb  ov010
 *   FIELDMAP_SetTargetPos  0x02188D40  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetPlayerRailLocation  0x02012AB8  thumb
 *   FIELD_PLAYER_SetNogridRailLocation  0x021A36B0  thumb  ov021
 *   FIELD_PLAYER_GetNogridRailPos  0x021A36D4  thumb  ov021
 *   FIELD_PLAYER_SetPos  0x021A3044  thumb  ov021
 *   FIELD_PLAYER_SetDirDisp  0x021A305C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *FIELDMAP_GetCamera(void *p);
extern u32 FIELDMAP_GetNogridMapper(u8 *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern u32 *FIELDMAP_CTRL_NOGRID_WORK_CreateWork(void *a, u32 heap);
extern void FIELDMAP_SetCtrlWork(u8 *p, u32 v);
extern void *FIELD_PLAYER_GetMmdl(u8 *p);
extern void *FLDMMDL_GetPosPtr(void *p);
extern void FIELDMAP_SetTargetPos(u8 *p, u32 v);
extern void *FIELDMAP_GetGameSystem(void *p);
struct Ctx;
struct H4;
struct Rec44;
struct SaveBlock;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
extern struct H4 *GAME_DATA_GetPlayerRailLocation(struct Rec44 *p);
extern void FIELD_PLAYER_SetNogridRailLocation(u8 *p, void *v);
extern void FIELD_PLAYER_GetNogridRailPos(u8 *p, u32 v);
extern void FIELD_PLAYER_SetPos(u8 *p, void *v);
extern void FIELD_PLAYER_SetDirDisp(char *p, u32 b);

void FIELDMAP_CTRL_NOGRID_WORK_Create(struct Obj00020 *a, u32 b, u32 c)
{
    u8 *r4;

    FIELDMAP_GetCamera(a);
    FIELDMAP_GetNogridMapper((u8 *)a);
    r4 = FIELDMAP_GetFieldPlayer(a);
    FIELDMAP_SetCtrlWork((u8 *)a, (u32)FIELDMAP_CTRL_NOGRID_WORK_CreateWork(a, FIELDMAP_GetHeapId((u8 *)a)));
    FIELDMAP_SetTargetPos((u8 *)a, (u32)FLDMMDL_GetPosPtr(FIELD_PLAYER_GetMmdl(r4)));
    FIELD_PLAYER_SetNogridRailLocation(r4, GAME_DATA_GetPlayerRailLocation(GAME_DATA_GetMyPlayerWork(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(a)))));
    FIELD_PLAYER_GetNogridRailPos(r4, b);
    FIELD_PLAYER_SetPos(r4, (void *)b);
    FIELD_PLAYER_SetDirDisp((char *)r4, c);
}
