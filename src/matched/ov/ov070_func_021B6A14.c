/*
 * function: ITEMMENU_TaskWaitMessage
 * address:  0x021B6A14
 * packet:   pkt_ov070_021B6A14
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ITEMMENU_IsMessageFinished  0x021BADF0  thumb  ov070
 *   KEY_GetTrg  0x020362DC  arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   func_020414EC  0x020414EC  arm
 *   ITEMMENU_RedrawList  0x021B6138  thumb  ov070
 *   ITEMMENU_MoveCursorToRow  0x021BA6A4  thumb  ov070
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   ITEMMENU_UpdateSideButtons  0x021BB3F4  thumb  ov070
 *   ITEMMENU_ReturnToBagMain  0x021B8AF4  thumb  ov070
 */
#include "../include/Obj00002.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int ITEMMENU_IsMessageFinished(int p);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
struct Obj;
extern void func_020414EC(u32 i);
extern void ITEMMENU_RedrawList(char *p);
extern void ITEMMENU_MoveCursorToRow(char *p);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void ITEMMENU_UpdateSideButtons(int p, int mode);
extern void ITEMMENU_ReturnToBagMain(void *o);

void ITEMMENU_TaskWaitMessage(u8 *p)
{
    if (ITEMMENU_IsMessageFinished((int)p) == 0)
        return;
    if ((KEY_GetTrg() & 3) == 0 && TOUCHPANEL_GetTrg() == 0)
        return;
    func_020414EC(3);
    *(u32 *)&((struct Obj00002 *)p)->f818 = 0xFFFF;
    ITEMMENU_RedrawList((char *)p);
    ((struct Obj00002 *)p)->f83E = 1;
    ITEMMENU_MoveCursorToRow((char *)p);
    CLACT_SetActorAutoAnim(((struct Obj00002 *)p)->f6A8, 1);
    ITEMMENU_UpdateSideButtons((int)p, 1);
    ITEMMENU_ReturnToBagMain(p);
}
