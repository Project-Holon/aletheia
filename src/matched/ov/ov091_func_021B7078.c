/*
 * function: POKELIST_LoadBgPlane
 * address: 0x021B7078
 * packet: pkt_ov091_021B7078
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned int   u32;
struct BgTemplate;
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(u32 which, unsigned char enable);
extern void BG_SYS_FreeSlot(unsigned);
extern void func_020409B4(u32 index);
void POKELIST_LoadBgPlane(const void *p, unsigned id,unsigned type) { BG_SYS_InitBgLayer(id,p,type); func_02040588(id,1); BG_SYS_FreeSlot(id); func_020409B4(id); }
