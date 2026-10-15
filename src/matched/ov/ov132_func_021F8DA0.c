/*
 * function: STA_ACTING_SetupBg
 * address: 0x021F8DA0
 * packet: pkt_ov132_021F8DA0
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_PushTile 0x020409B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct BgTemplate;
extern void BG_SYS_InitBgLayer(u32,const struct BgTemplate *,u32);
extern void func_02040588(u32 which, unsigned char enable);
extern void BG_SYS_FreeSlot(u32);
extern void BG_SYS_PushTile(u32);
void STA_ACTING_SetupBg(const struct BgTemplate *p,u32 id,u32 type) { BG_SYS_InitBgLayer(id,p,type); func_02040588(id,1); BG_SYS_FreeSlot(id); BG_SYS_PushTile(id); }
