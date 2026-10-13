/*
 * function: func_021BE0E8
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
void func_021BE0E8(u8 *a0) { CLACT_VBlankSystem(); }
