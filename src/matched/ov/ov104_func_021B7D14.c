/*
 * function: IRC_RHYTHM_VBlankActorSystem
 * address: 0x021B7D14
 * packet: pkt_ov104_021B7D14
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_VBlankSystem 0x0204A648 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void CLACT_VBlankSystem(void);
void IRC_RHYTHM_VBlankActorSystem(void *p) { CLACT_VBlankSystem(); }
