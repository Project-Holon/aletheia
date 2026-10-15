/*
 * function: BOX2_SEQ_StatePmVoiceOpenB
 * address: 0x021E9968
 * packet: pkt_ov170_021E9968
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_SEQ_DrawFrameList 0x021EB988 thumb ov170
 *   BOX2_UI_PutListFrames 0x021EF4E4 thumb ov170
 *   BOX2_SEQ_PrintPrompt 0x021EBC58 thumb ov170
 *   BOX2_SEQ_SetSlotActors 0x021ECB20 thumb ov170
 *   BOX2_UI_ToggleSlotPair 0x021ED888 thumb ov170
 *   BOX2_SEQ_StopLeftBar 0x021EA75C thumb ov170
 *   BOX2_SEQ_RefreshCursorSlot 0x021ED588 thumb ov170
 *   d_021EF950 0x021EF950 data a1
 */
#define WORK(p) (*(char **)((p)+0x2C))
struct WinMgr;
extern void BOX2_SEQ_DrawFrameList(unsigned char *, const void *, unsigned);
extern void BOX2_UI_PutListFrames(struct WinMgr *mgr);
extern void BOX2_SEQ_PrintPrompt(unsigned char *, int, int, int);
extern void BOX2_SEQ_SetSlotActors(char *p, int f, int c);
extern void BOX2_UI_ToggleSlotPair(char *, int);
extern void BOX2_SEQ_StopLeftBar(int p);
extern void BOX2_SEQ_RefreshCursorSlot(char *p);
extern const unsigned char d_021EF950[];
int BOX2_SEQ_StatePmVoiceOpenB(unsigned char *p) {
 BOX2_SEQ_DrawFrameList(p,d_021EF950,5);
 BOX2_UI_PutListFrames(*(struct WinMgr **)(WORK(p)+0x74));
 BOX2_SEQ_PrintPrompt(p,p[0x16],1,0x18);
 BOX2_SEQ_SetSlotActors((char *)p,1,1); BOX2_UI_ToggleSlotPair(WORK(p),0);
 BOX2_SEQ_StopLeftBar((int)p); BOX2_SEQ_RefreshCursorSlot((char *)p); return 0x31;
}
