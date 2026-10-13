/*
 * function: GIMMICK39_End
 * address:  0x021F3CD8
 * packet:   pkt_ov039_021F3CD8
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
 *   GAME_DATA_GetBgmInfo 0x02012A30 thumb
 *   FIELD_SOUND_SYSTEM_ReleaseSlot 0x02028B50 thumb
 *   func_02030EAC 0x02030EAC arm
 *   FIELDMAP_FreeCommonWork 0x021897A0 thumb
 *   FLD_EXP_OBJ_RemoveUnit 0x021BE418 thumb ov021
 */

typedef unsigned short u16;
typedef unsigned char  u8;
struct Ctx;
struct Node;
extern int FIELDMAP_GetExpObj(int *p);
extern int *FIELDMAP_GetCommonWork(int, int);
extern int FIELDMAP_GetGameSystem(int);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct BigObj;
extern unsigned int GAME_DATA_GetBgmInfo(const struct BigObj *p);
extern void FIELD_SOUND_SYSTEM_ReleaseSlot(u8 *p, int a0);
extern void func_02030EAC(struct Node *n);
extern void FIELDMAP_FreeCommonWork(int, int);
extern void FLD_EXP_OBJ_RemoveUnit(u8 *p, u16 i);

void GIMMICK39_End(int a)
{
    int r6 = FIELDMAP_GetExpObj((int *)a);
    int *r4 = FIELDMAP_GetCommonWork(a, 1);

    FIELD_SOUND_SYSTEM_ReleaseSlot((u8 *)GAME_DATA_GetBgmInfo((const struct BigObj *)GAMESYSTEM_GetGameData((const struct Ctx *)FIELDMAP_GetGameSystem(a))), 0x68A);
    func_02030EAC((struct Node *)(*r4));
    FIELDMAP_FreeCommonWork(a, 1);
    FLD_EXP_OBJ_RemoveUnit((u8 *)r6, 0);
}
