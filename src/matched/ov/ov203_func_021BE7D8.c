/*
 * function: DEMO3D_ENGINE_GetAnimeKind
 * address: 0x021BE7D8
 * packet: pkt_ov203_021BE7D8
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DEMO3D_ENGINE_ClampDemoId 0x021BE79C thumb ov203
 *   d_021C186C 0x021C186C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Owner;struct TcblNode;
typedef struct Config {unsigned words[11];} Config;
extern unsigned DEMO3D_ENGINE_ClampDemoId(unsigned);
extern char d_021C186C[];
u8 DEMO3D_ENGINE_GetAnimeKind(unsigned x) { return *(u32 *)(d_021C186C+DEMO3D_ENGINE_ClampDemoId(x)*20); }
