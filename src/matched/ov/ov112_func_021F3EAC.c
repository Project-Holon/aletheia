/*
 * function: MUSICAL_SHOT_SYS_LoadBg
 * address: 0x021F3EAC
 * packet: pkt_ov112_021F3EAC
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct BgTemplate;
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(u32 which, unsigned char enable);
extern void BG_SYS_FreeSlot(u32);
extern void func_020409B4(u32);
void MUSICAL_SHOT_SYS_LoadBg(const void *a,u32 b,u32 c) { BG_SYS_InitBgLayer(b,a,c); func_02040588(b,1); BG_SYS_FreeSlot(b); func_020409B4(b); }
