/*
 * function: func_021B8308
 * address: 0x021B8308
 * packet: pkt_ov071_021B8308
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02041300 0x02041300 arm
 *   func_02040588 0x02040588 arm
 *   d_021BA984 0x021BA984 data a4
 */

typedef unsigned char u8;
extern const char d_021BA984[];
typedef unsigned int   u32;
struct BgTemplate;
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02041300(unsigned,int,int,int,u8,u8,u8);
extern void func_02040588(unsigned char which, unsigned char enable);
void func_021B8308(void) { func_0203FCA0(5,(const struct BgTemplate *)d_021BA984,0); func_02041300(5,0,0,0,0x20,0x20,0x11); func_02040588(5,0); }
