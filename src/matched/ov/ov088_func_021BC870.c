/*
 * function: STARTMENU_ConfigPromptHighlightChoice
 * address: 0x021BC870
 * packet: pkt_ov088_021BC870
 * region: ov088
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 */
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);
void STARTMENU_ConfigPromptHighlightChoice(unsigned char *p) { unsigned char i; for(i=0;i<2;i++) { if(i==p[0]) BMP_MENUWORK_DrawWindow((void *)(*(unsigned *)(p+16+4*i)),0,1,3); else BMP_MENUWORK_DrawWindow((void *)(*(unsigned *)(p+16+4*i)),0,31,4); } }
