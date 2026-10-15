/*
 * function: func_021B6E4C
 * address: 0x021B6E4C
 * packet: pkt_ov133_021B6E4C
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned int   u32;
struct BgTemplate;
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type); extern void func_02040588(unsigned int,unsigned int); extern void BG_SYS_FreeSlot(unsigned int); extern void func_020409B4(unsigned int);
void func_021B6E4C(const void *t,unsigned int id) {BG_SYS_InitBgLayer(id,t,0);func_02040588(id,1);BG_SYS_FreeSlot(id);func_020409B4(id);}
