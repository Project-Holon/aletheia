/*
 * function: BOX2_SEQ_LoadBoxGraphics
 * address: 0x021EBE24
 * packet: pkt_ov170_021EBE24
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_SEQ_RegisterBoxChars 0x021EC0DC thumb ov170
 *   BOX2_SEQ_RegisterBoxCharsB 0x021EC1E8 thumb ov170
 *   BOX2_SEQ_RegisterIconRes 0x021EC254 thumb ov170
 *   BOX2_SEQ_LoadIconPalette 0x021ED058 thumb ov170
 *   BOX2_SEQ_InitIconSlots 0x021ECCA4 thumb ov170
 *   BOX2_SEQ_LoadBoxScreen 0x021ECDF4 thumb ov170
 */
extern void BOX2_SEQ_RegisterBoxChars(char *);extern void BOX2_SEQ_RegisterBoxCharsB(char *);extern void BOX2_SEQ_RegisterIconRes(char *);extern void BOX2_SEQ_LoadIconPalette(char *);extern void BOX2_SEQ_InitIconSlots(char *);extern void BOX2_SEQ_LoadBoxScreen(char *);
void BOX2_SEQ_LoadBoxGraphics(char *p){BOX2_SEQ_RegisterBoxChars(p);BOX2_SEQ_RegisterBoxCharsB(p);BOX2_SEQ_RegisterIconRes(p);BOX2_SEQ_LoadIconPalette(p);BOX2_SEQ_InitIconSlots(p);BOX2_SEQ_LoadBoxScreen(p);}
