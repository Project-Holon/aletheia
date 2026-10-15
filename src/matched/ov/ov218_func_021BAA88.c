/*
 * function: UN_SELECT_GRAPHIC_VBlank, UN_SELECT_GRAPHIC_GetValue
 * address: 0x021BAA88
 * packet: pkt_ov218_021BAA88
 * region: ov218
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
void UN_SELECT_GRAPHIC_VBlank(void *p){CLACT_VBlankSystem();}
u32 UN_SELECT_GRAPHIC_GetValue(u32 *p){return *p;}
