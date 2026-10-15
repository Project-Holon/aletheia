/*
 * function: MONOLITH_TOOL_LIST_InitBackgrounds
 * address:  0x021B9560
 * packet:   pkt_ov071_021B9560
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
 *   d_021BAB28     0x021BAB28  data  ov071  a4
 *   d_021BAB48     0x021BAB48  data  ov071  a4
 *   d_021BAB68     0x021BAB68  data  a4
 */

#include "../include/G_Config.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern char d_021BAB28[];
extern char d_021BAB48[];
extern struct Config d_021BAB68;
struct BgTemplate;
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02041300(u32 a, u32 b, u32 c, u32 d, u8 e, u8 f, u8 g);

void MONOLITH_TOOL_LIST_InitBackgrounds(void)
{
    BG_SYS_InitBgLayer(4, (const struct BgTemplate *)d_021BAB28, 0);
    BG_SYS_InitBgLayer(5, (const struct BgTemplate *)d_021BAB48, 0);
    BG_SYS_InitBgLayer(6, (const struct BgTemplate *)((char *)&d_021BAB68), 0);
    func_02041300(4, 0, 0, 0, 0x20, 0x20, 0x11);
    func_02041300(5, 0, 0, 0, 0x20, 0x20, 0x11);
    func_02041300(6, 0, 0, 0, 0x20, 0x20, 0x11);
}
