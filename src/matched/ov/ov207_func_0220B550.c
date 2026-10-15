/*
 * function: ZUKAN_TOROKU_GRAPHIC_VBlankActors, ZUKAN_TOROKU_GRAPHIC_GetWord
 * address: 0x0220B550
 * packet: pkt_ov207_0220B550
 * region: ov207
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * unit: yes
 * symbols:
 *   CLACT_VBlankSystem 0x0204A648 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void CLACT_VBlankSystem(void);
void ZUKAN_TOROKU_GRAPHIC_VBlankActors(void*p){CLACT_VBlankSystem();}
u32 ZUKAN_TOROKU_GRAPHIC_GetWord(u32*p){return *p;}
