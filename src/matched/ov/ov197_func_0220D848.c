/*
 * function: B_BAG_MAIN_SwitchPage
 * address: 0x0220D848
 * packet: pkt_ov197_0220D848
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   B_BAG_MAIN_ResetBgSlot 0x0220D7F0 thumb ov197
 *   BG_SYS_ClearLayerEx 0x02041570 arm
 *   B_BAG_MAIN_ShowWindows 0x0220B990 thumb ov197
 *   B_BAG_MAIN_LayoutFrames 0x0220BD24 thumb ov197
 *   B_BAG_MAIN_RecreateCursor 0x0220D924 thumb ov197
 *   B_BAG_MAIN_SetDisplayMode 0x0220C4EC thumb ov197
 */
typedef unsigned short u16;
extern void B_BAG_MAIN_ResetBgSlot(void *,int);
extern void BG_SYS_ClearLayerEx(int channel, u16 val);
extern void B_BAG_MAIN_LayoutFrames(char *,int);
extern void B_BAG_MAIN_RecreateCursor(unsigned char *,int,int);
extern void B_BAG_MAIN_SetDisplayMode(char *,int);
extern unsigned B_BAG_MAIN_ShowWindows(unsigned char *);
void B_BAG_MAIN_SwitchPage(char *p,int mode){B_BAG_MAIN_ResetBgSlot(p,mode);BG_SYS_ClearLayerEx(4,0);BG_SYS_ClearLayerEx(5,0);B_BAG_MAIN_ShowWindows((unsigned char *)p);B_BAG_MAIN_LayoutFrames(p,mode);B_BAG_MAIN_RecreateCursor((unsigned char *)p,mode,0);B_BAG_MAIN_SetDisplayMode(p,mode);}
