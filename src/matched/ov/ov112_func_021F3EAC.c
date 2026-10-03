/*
 * function: func_021F3EAC
 * address: 0x021F3EAC
 * packet: pkt_ov112_021F3EAC
 * region: ov112
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
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(u32,u32);
extern void func_020414AC(u32);
extern void func_020409B4(u32);
void func_021F3EAC(const void *a,u32 b,u32 c) { func_0203FCA0(b,a,c); func_02040588(b,1); func_020414AC(b); func_020409B4(b); }
