/*
 * function: COMM_ENTRY_RunLeaveConfirm
 * address:  0x021CF068
 * packet:   pkt_ov021_021CF068
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   KEY_GetTrg  0x020362DC  arm
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELD_MSGBG_CreateYesNoMenu  0x02190BE4  thumb  ov021
 *   COMM_ENTRY_MENU_PrintMessage  0x021CE9E4  thumb  ov021
 *   FIELD_MSGBG_YesNoMenuMain  0x02190C78  thumb  ov021
 *   FIELD_MSGBG_IsPrintQueFinished  0x0219049C  thumb  ov021
 *   FIELD_MSGBG_DeleteMenuFunc  0x021909BC  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00011.h"
#include "../include/Obj04295.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 KEY_GetTrg(void);
struct Handle;
extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern u32 *FIELD_MSGBG_CreateYesNoMenu(u16 *a, u32 b);
extern void COMM_ENTRY_MENU_PrintMessage(u8 *p, u32 m);
extern int FIELD_MSGBG_YesNoMenuMain(struct Handle *h);
extern int FIELD_MSGBG_IsPrintQueFinished(u8 *p);
extern int FIELD_MSGBG_DeleteMenuFunc(void *a);

int COMM_ENTRY_RunLeaveConfirm(u8 *p)
{
    u8 *q = p + 0x130;
    u32 r;

    switch (q[8]) {
    case 0:
        if (KEY_GetTrg() & 2) {
            ((struct Obj04295 *)q)->f0 = (u32)FIELD_MSGBG_CreateYesNoMenu((u16 *)FIELDMAP_GetMsgBg((u8 *)(((struct Obj00011 *)p)->f0)), 0);
            COMM_ENTRY_MENU_PrintMessage(p, 0x23);
            q[8] = 1;
        }
        break;
    case 1:
        r = FIELD_MSGBG_YesNoMenuMain((struct Handle *)(((struct Obj04295 *)q)->f0));
        if (FIELD_MSGBG_IsPrintQueFinished((u8 *)FIELDMAP_GetMsgBg((u8 *)(((struct Obj00011 *)p)->f0))) == 1 && p[0x576] == 1)
            r = 1;
        if (r != 2) {
            FIELD_MSGBG_DeleteMenuFunc((void *)(((struct Obj04295 *)q)->f0));
            ((struct Obj04295 *)q)->f0 = 0;
            if (r == 1) {
                q[8] = 0;
                COMM_ENTRY_MENU_PrintMessage(p, 0x22);
            } else {
                return 2;
            }
        }
        return 1;
    }
    return 0;
}
