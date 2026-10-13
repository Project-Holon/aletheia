/*
 * function: FIELD_GIMMICK_CART_LANES_TransferSound
 * address: 0x021F3D74
 * packet: pkt_ov039_021F3D74
 * region: ov039
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetBgmInfo 0x02012A30 thumb
 *   FIELD_SOUND_SYSTEM_ClaimSlot 0x02028A7C thumb
 *   FIELD_SOUND_SYSTEM_TransferSlot 0x02028B18 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct SoundSys2;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct BigObj;
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *p);
extern void FIELD_SOUND_SYSTEM_ClaimSlot(struct SoundSys2 *p, u32 id);
extern void FIELD_SOUND_SYSTEM_TransferSlot(struct SoundSys2 *p, u32 id, u32 who);
void FIELD_GIMMICK_CART_LANES_TransferSound(u32 a) { struct SoundSys2 *p; p = (struct SoundSys2 *)GAME_DATA_GetBgmInfo((const struct BigObj *)GAMESYSTEM_GetGameData((const struct Ctx *)a)); FIELD_SOUND_SYSTEM_ClaimSlot(p, 0x68a); FIELD_SOUND_SYSTEM_TransferSlot(p, 0x68a, 0); }
