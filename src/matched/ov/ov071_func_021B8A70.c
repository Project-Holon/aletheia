/*
 * function: func_021B8A70
 * address:  0x021B8A70
 * packet:   pkt_ov071_021B8A70
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   func_02041300  0x02041300  arm
 *   d_021BAAB8     0x021BAAB8  data  ov071  a4
 *   d_021BAAD8     0x021BAAD8  data  ov071  a4
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern char d_021BAAB8[];
extern char d_021BAAD8[];
struct BgTemplate;
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02041300(u32 a, u32 b, u32 c, u32 d, u8 e, u8 f, u8 g);

void func_021B8A70(void)
{
    BG_SYS_InitBgLayer(4, (const struct BgTemplate *)d_021BAAB8, 0);
    BG_SYS_InitBgLayer(6, (const struct BgTemplate *)d_021BAAD8, 0);
    func_02041300(4, 0, 0, 0, 0x20, 0x20, 0x11);
    func_02041300(6, 0, 0, 0, 0x20, 0x20, 0x11);
}
