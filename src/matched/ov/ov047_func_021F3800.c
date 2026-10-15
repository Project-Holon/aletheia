/*
 * function: FIELD_GIMMICK_BRIDGE_ResetSave
 * address: 0x021F3800
 * packet: pkt_ov047_021F3800
 * region: ov047
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb  arm9
 *   GIMMICK_WORK_GetWork  0x0200B3A4  thumb  arm9
 *   ICA_ANIME_GetField1C  0x020120F4  thumb  arm9
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Big;
struct Ctx;
extern void *ICA_ANIME_GetField1C(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetWork(struct Rec94 *p, u32 b);
extern void MI_CpuFill8(void *,int,int);
void FIELD_GIMMICK_BRIDGE_ResetSave(u32 a) { MI_CpuFill8(GIMMICK_WORK_GetWork((struct Rec94 *)GAME_DATA_GetFieldSave(ICA_ANIME_GetField1C((const struct Ctx *)a)),31),0,4); }
