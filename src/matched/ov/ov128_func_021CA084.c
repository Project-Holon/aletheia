/*
 * function: WF2DMAP_TOUCH_GetConfirmInput
 * address: 0x021CA084
 * packet: pkt_ov128_021CA084
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two trailing bytes of zero alignment padding.
 * symbols:
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   UI_SetInputMode 0x020355D8 arm
 *   KEY_GetTrg 0x020362DC arm
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
extern int TOUCHPANEL_GetTrg(void);
extern void UI_SetInputMode(u8 v);
extern u32 KEY_GetTrg(void);
int WF2DMAP_TOUCH_GetConfirmInput(int *p) { if(TOUCHPANEL_GetTrg()==1) {UI_SetInputMode(1);*p=1;return 1;} if(KEY_GetTrg()&3) {UI_SetInputMode(0);*p=0;return 1;} return 0; }
