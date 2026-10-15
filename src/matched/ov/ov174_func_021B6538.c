/*
 * function: LOCAL_TVT_SYS_SetupBgLayer
 * address: 0x021B6538
 * packet: pkt_ov174_021B6538
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   func_020414AC 0x020414AC arm
 *   func_020409B4 0x020409B4 arm
 */
struct BgTemplate;extern void BG_SYS_InitBgLayer(unsigned,const struct BgTemplate *,unsigned);extern void func_02040588(unsigned,unsigned),func_020414AC(unsigned),func_020409B4(unsigned);
void LOCAL_TVT_SYS_SetupBgLayer(const struct BgTemplate *p, int i, int type) {BG_SYS_InitBgLayer(i,p,type);func_02040588(i,1);func_020414AC(i);func_020409B4(i);}
