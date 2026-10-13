/*
 * function: FIELD_WFBC_DATA_LOCAL_UpdateTalkMessage
 * address:  0x02187508
 * packet:   pkt_ov020_02187508
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_MSGBG_TalkWinMain  0x02191388  thumb  ov021
 *   KEY_GetTrg  0x020362DC  arm
 *   FIELD_MSGBG_CreateYesNoMenu  0x02190BE4  thumb  ov021
 *   FIELD_MSGBG_YesNoMenuMain  0x02190C78  thumb  ov021
 *   FIELD_MSGBG_DeleteMenuFunc  0x021909BC  thumb  ov021
 *   FIELD_MSGBG_DeleteTalkWin  0x021912D8  thumb  ov021
 *   FIELD_MSGBG_WaitTalkWinClose  0x021912F8  thumb  ov021
 */
#include "../include/Obj00128.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Handle;
extern u32 FIELD_MSGBG_TalkWinMain(u32 *a);
extern u32 KEY_GetTrg(void);
extern u32 *FIELD_MSGBG_CreateYesNoMenu(u16 *a, u32 b);
extern int FIELD_MSGBG_YesNoMenuMain(struct Handle *h);
extern int FIELD_MSGBG_DeleteMenuFunc(void *a);
extern int FIELD_MSGBG_DeleteTalkWin(u32 a);
extern int FIELD_MSGBG_WaitTalkWinClose(int);

int FIELD_WFBC_DATA_LOCAL_UpdateTalkMessage(char *p)
{
    int r;

    switch (((struct Obj00128 *)p)->f52) {
    case 0:
        if (FIELD_MSGBG_TalkWinMain((u32 *)(*(int *)&((struct Obj00128 *)p)->f10)) == 0)
            break;
        ((struct Obj00128 *)p)->f52 = ((struct Obj00128 *)p)->f52 + 1;
        break;
    case 1:
        if ((KEY_GetTrg() & 0xf3) == 0)
            break;
        if (((struct Obj00128 *)p)->f55 == 0)
            ((struct Obj00128 *)p)->f52 = 4;
        else
            ((struct Obj00128 *)p)->f52 = 2;
        break;
    case 2:
        *(int *)&((struct Obj00128 *)p)->f14 = (int)FIELD_MSGBG_CreateYesNoMenu((u16 *)(((struct Obj00128 *)p)->fC), 0);
        ((struct Obj00128 *)p)->f52 = ((struct Obj00128 *)p)->f52 + 1;
        break;
    case 3:
        r = FIELD_MSGBG_YesNoMenuMain((struct Handle *)(*(int *)&((struct Obj00128 *)p)->f14));
        if (r == 2)
            break;
        if (r == 0)
            ((struct Obj00128 *)p)->f54 = 1;
        else
            ((struct Obj00128 *)p)->f54 = 0;
        ((struct Obj00128 *)p)->f52 = 4;
        FIELD_MSGBG_DeleteMenuFunc((void *)(*(int *)&((struct Obj00128 *)p)->f14));
        *(int *)&((struct Obj00128 *)p)->f14 = 0;
        break;
    case 4:
        FIELD_MSGBG_DeleteTalkWin(*(int *)&((struct Obj00128 *)p)->f10);
        ((struct Obj00128 *)p)->f52 = ((struct Obj00128 *)p)->f52 + 1;
        break;
    case 5:
        if (FIELD_MSGBG_WaitTalkWinClose(*(int *)&((struct Obj00128 *)p)->f10) != 0) {
            *(int *)&((struct Obj00128 *)p)->f10 = 0;
            return 1;
        }
        break;
    }
    return 0;
}
