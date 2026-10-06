/*
 * function: func_021D4534
 * address: 0x021D4534
 * packet: pkt_ov124_021D4534
 * region: ov124
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   func_020414AC 0x020414AC arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct BgTemplate;
extern void func_0203FCA0(u32,const struct BgTemplate *,u32);
extern void func_02040588(u32,u32);
extern void func_020414AC(u32);
extern void func_020409B4(u32);
/* 020414AC's legacy asm prototype says void, but its body forwards entry r0. */
void func_021D4534(const struct BgTemplate *p, int layer, int type) {func_0203FCA0(layer,p,type);func_02040588(layer,1);func_020414AC(layer);func_020409B4(layer);}
