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
 *   func_02082BCC 0x02082BCC arm
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb  arm9
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Big;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern void func_02082BCC(void *,int,int);
void FIELD_GIMMICK_BRIDGE_ResetSave(u32 a) { func_02082BCC(func_0200B3A4((struct Rec94 *)GAME_DATA_GetFieldSave(func_020120F4((const struct Ctx *)a)),31),0,4); }
