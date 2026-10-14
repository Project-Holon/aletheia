/*
 * function: DENDOU_VIEW_StateChangeRow
 * address: 0x021DD0E8
 * packet: pkt_ov171_021DD0E8
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DENDOU_VIEW_SwitchRowActors 0x021DE388 thumb ov171
 *   DENDOU_VIEW_DrawTitle 0x021DD964 thumb ov171
 *   DENDOU_VIEW_DrawPageCounter 0x021DDAF0 thumb ov171
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void DENDOU_VIEW_SwitchRowActors(char *p);
extern void DENDOU_VIEW_DrawTitle(u8*);
extern void DENDOU_VIEW_DrawPageCounter(u8*);
int DENDOU_VIEW_StateChangeRow(u8*p){p[0xc5c]=0;DENDOU_VIEW_SwitchRowActors((char *)p);DENDOU_VIEW_DrawTitle(p);DENDOU_VIEW_DrawPageCounter(p);return 4;}
