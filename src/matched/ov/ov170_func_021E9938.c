/*
 * function: BOX2_SEQ_StatePmVoiceOpen
 * address: 0x021E9938
 * packet: pkt_ov170_021E9938
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_SEQ_DrawFrameList 0x021EB988 thumb ov170
 *   BOX2_UI_PutListFrames 0x021EF4E4 thumb ov170
 *   BOX2_SEQ_PrintPrompt 0x021EBC58 thumb ov170
 *   BOX2_SEQ_RefreshCursorSlot 0x021ED588 thumb ov170
 *   d_021EF9B4 0x021EF9B4 data a1
 */
#include "../include/Obj00000.h"
#include "../include/Obj23951.h"
extern void BOX2_SEQ_DrawFrameList(unsigned char *,const void *,unsigned); extern void BOX2_UI_PutListFrames(int); extern void BOX2_SEQ_PrintPrompt(unsigned char *,int,int,int); extern void BOX2_SEQ_RefreshCursorSlot(unsigned char *); extern const unsigned char d_021EF9B4[];
int BOX2_SEQ_StatePmVoiceOpen(unsigned char *p){BOX2_SEQ_DrawFrameList(p,d_021EF9B4,5);BOX2_UI_PutListFrames(((struct Obj23951 *)(*(unsigned char * *)&((struct Obj00000 *)p)->f2C))->f74);BOX2_SEQ_PrintPrompt(p,p[22],1,24);BOX2_SEQ_RefreshCursorSlot(p);return 44;}
