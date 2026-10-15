/*
 * function: DEMO3D_GRAPHIC_VBlankClact
 * address: 0x021BE0E8
 * packet: pkt_ov203_021BE0E8
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_VBlankSystem 0x0204A648 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Owner;struct TcblNode;
typedef struct Config {unsigned words[11];} Config;
extern void CLACT_VBlankSystem(void);
void DEMO3D_GRAPHIC_VBlankClact(u8 *a0) { CLACT_VBlankSystem(); }
