/*
 * unit: yes
 * function: GIMMICK49_ExitExtra, FIELD_GIMMICK_D06_Update
 * address: 0x021F3868
 * packet: pkt_ov051_021F3868
 * region: ov051
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: extent follower at 0x021F38A0 is an empty return stub; no existing same-region source or shard was found.
 * symbols:
 *   FIELDMAP_GetHeapId 0x02188C84 thumb ov021
 *   FIELDMAP_GetGameSystem 0x02188C80 thumb ov021
 *   FIELDMAP_GetEffect 0x02188CD0 thumb ov021
 *   FIELDMAP_GetZoneId 0x02188C9C thumb ov021
 *   FIELD_GIMMICK_D06_GetGimmickId 0x021F3D94 thumb ov051
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetFieldSave 0x02012EC4 thumb
 *   GIMMICK_WORK_GetSaveArea 0x0200B3A4 thumb
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
extern unsigned short FIELDMAP_GetHeapId(u8 *);
struct Big;
struct Ctx;
extern void *FIELDMAP_GetGameSystem(void *p);
extern unsigned FIELDMAP_GetEffect(u8 *);
extern unsigned short FIELDMAP_GetZoneId(u8 *);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
extern int FIELD_GIMMICK_D06_GetGimmickId(int);
extern char *GIMMICK_WORK_GetSaveArea(unsigned,int);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void GIMMICK49_ExitExtra(u8 *p)
{
    unsigned h;
    FIELDMAP_GetHeapId(p);
    h=(unsigned int)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(p)));
    FIELDMAP_GetEffect(p);
    func_020307B0(*(void **)(GIMMICK_WORK_GetSaveArea(h,FIELD_GIMMICK_D06_GetGimmickId(FIELDMAP_GetZoneId(p)))+4));
}

void FIELD_GIMMICK_D06_Update(void)
{
}
