/*
 * function: BOX2_SEQ_StateOpenItemB
 * address: 0x021E4944
 * packet: pkt_ov170_021E4944
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_MAIN_UpdateBoxSlots 0x021DD530 thumb ov170
 *   BOX2_SEQ_Delete 0x021EA1E8 thumb ov170
 *   BOX2_UI_SetCursorPos 0x021EE3E4 thumb ov170
 *   BOX2_UI_DeleteSlotObjects 0x021EE038 thumb ov170
 *   BOX2_SEQ_PrintPrompt 0x021EBC58 thumb ov170
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj00000.h"
#include "../include/Obj23901.h"
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
extern void BOX2_MAIN_UpdateBoxSlots(unsigned char *);
extern void BOX2_SEQ_Delete(char *p);
typedef unsigned char  u8;
struct Sound;
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void BOX2_UI_SetCursorPos(char **, unsigned);
extern void BOX2_UI_DeleteSlotObjects(char *, int, int, int);
extern void BOX2_SEQ_PrintPrompt(unsigned char *, int, int, int);
int BOX2_SEQ_StateOpenItemB(unsigned char *p)
{
    GFL_USE_PlaySeDefaultVolume(0x667);
    BOX2_MAIN_UpdateBoxSlots(p);
    BOX2_SEQ_Delete((char *)p);
    func_020260E4(((struct Obj23901 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f70, 0x24);
    BOX2_UI_SetCursorPos((char **)p, 0x24);
    BOX2_UI_DeleteSlotObjects((char *)p, 0, 0, 1);
    BOX2_SEQ_PrintPrompt(p, p[0x16], 1, 0x18);
    return 0x23;
}
