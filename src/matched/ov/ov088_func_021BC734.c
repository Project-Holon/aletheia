/*
 * function: STARTMENU_InitBgLayer
 * address: 0x021BC734
 * packet: pkt_ov088_021BC734
 * region: ov088
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   func_020414AC 0x020414AC arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned int   u32;
struct BgTemplate;
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(u32 which, unsigned char enable);
extern void func_020414AC(int a);
extern void func_020409B4(unsigned int a);
void STARTMENU_InitBgLayer(const void *p,int bg) { func_0203FCA0(bg,p,0);func_02040588(bg,1);func_020414AC(bg);func_020409B4(bg); }
