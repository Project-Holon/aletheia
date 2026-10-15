/*
 * function: BOX2_SEQ_CreateBox2UiScene
 * address: 0x021EBD94
 * packet: pkt_ov170_021EBD94
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two-byte zero alignment padding at 0x021EBDD6.
 * symbols:
 *   BOX2_SEQ_InitClact 0x021EBDF4 thumb ov170
 *   BOX2_SEQ_LoadBoxGraphics 0x021EBE24 thumb ov170
 *   BOX2_SEQ_CreateBox2Actors 0x021EBEAC thumb ov170
 *   BOX2_UI_DeleteSlotObjects 0x021EE038 thumb ov170
 *   BOX2_UI_CreateBmpOam 0x021EE120 thumb ov170
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 */
#include "../include/Obj00000.h"
extern void BOX2_SEQ_InitClact(void *);
extern void BOX2_SEQ_LoadBoxGraphics(char *p);
extern void BOX2_SEQ_CreateBox2Actors(unsigned char *);
extern void BOX2_UI_DeleteSlotObjects(char *, int, int, int);
extern void BOX2_UI_CreateBmpOam(char *p);
extern void BG_SYS_SetMainPlaneVisible(unsigned, unsigned);
extern void BG_SYS_SetSubPlaneVisible(unsigned, unsigned);
void BOX2_SEQ_CreateBox2UiScene(unsigned char *p)
{
    BOX2_SEQ_InitClact(((struct Obj00000 *)p)->f2C);
    BOX2_SEQ_LoadBoxGraphics(((struct Obj00000 *)p)->f2C);
    BOX2_SEQ_CreateBox2Actors(p);
    BOX2_UI_DeleteSlotObjects((char *)p, p[0x1f], p[0x20], p[0x21]);
    BOX2_UI_CreateBmpOam(((struct Obj00000 *)p)->f2C);
    BG_SYS_SetMainPlaneVisible(16, 1);
    BG_SYS_SetSubPlaneVisible(16, 1);
}
