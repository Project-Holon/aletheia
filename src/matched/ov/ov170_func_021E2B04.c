/*
 * function: BOX2_SEQ_StateOpenSummary
 * address: 0x021E2B04
 * packet: pkt_ov170_021E2B04
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_MAIN_UpdateBoxSlots 0x021DD530 thumb ov170
 *   BOX2_SEQ_Delete 0x021EA1E8 thumb ov170
 *   func_020260E4 0x020260E4 thumb
 *   BOX2_UI_SetCursorPos 0x021EE3E4 thumb ov170
 *   BOX2_SEQ_SetCursorDraw 0x021ED55C thumb ov170
 *   BOX2_UI_DeleteSlotObjects 0x021EE038 thumb ov170
 *   BOX2_SEQ_PrintPrompt 0x021EBC58 thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23892.h"
extern void BOX2_MAIN_UpdateBoxSlots(unsigned char *);
extern void BOX2_SEQ_Delete(char *p);
typedef unsigned char  u8;
struct Sound;
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void BOX2_UI_SetCursorPos(char **, unsigned);
extern void BOX2_SEQ_SetCursorDraw(char **, int);
extern void BOX2_UI_DeleteSlotObjects(char *, int, int, int);
extern void BOX2_SEQ_PrintPrompt(unsigned char *, int, int, int);
int BOX2_SEQ_StateOpenSummary(unsigned char *p)
{
    BOX2_MAIN_UpdateBoxSlots(p);
    BOX2_SEQ_Delete((char *)p);
    func_020260E4(((struct Obj23892 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f70, 0x24);
    BOX2_UI_SetCursorPos((char **)p, 0x24);
    BOX2_SEQ_SetCursorDraw((char **)p, 1);
    BOX2_UI_DeleteSlotObjects((char *)p, 0, 0, 1);
    BOX2_SEQ_PrintPrompt(p, p[0x16], 1, 0x18);
    return 0x11;
}
