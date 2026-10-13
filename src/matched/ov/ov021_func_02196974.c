/*
 * function: IRCBATTLEMENU_TouchTopMenu
 * address:  0x02196974
 * packet:   pkt_ov021_02196974
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_GetNonEggCount  0x0201AA1C  thumb
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   IRCBATTLEMENU_SetSeq  0x02196034  thumb  ov021
 *   IRCBATTLEMENU_PrintMessage  0x02197644  thumb  ov021
 *   IRCBATTLEMENU_SeqPressTopButton  0x021968DC  thumb  ov021
 *   IRCBATTLEMENU_SeqWaitNotEnoughMsg  0x02196944  thumb  ov021
 */
#include "../include/Obj03115.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

extern void GFL_USE_PlaySeDefaultVolume(u32 a);
struct BigObj;
struct Obj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u32 POKEPARTY_GetNonEggCount(void *p);
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void IRCBATTLEMENU_SetSeq(u8 *p, void *fn, u32 n);
extern void IRCBATTLEMENU_PrintMessage(u8 *p, u32 b);
extern void IRCBATTLEMENU_SeqPressTopButton(struct Obj *a);
extern void IRCBATTLEMENU_SeqWaitNotEnoughMsg(u8 *a);

int IRCBATTLEMENU_TouchTopMenu(u32 s, u8 *p)
{
    int r = 0;

    ((struct Obj03115 *)p)->f300 = s;
    switch (s) {
    case 0:
    case 5:
        GFL_USE_PlaySeDefaultVolume(0x73B);
        IRCBATTLEMENU_SetSeq(p, (void *)IRCBATTLEMENU_SeqPressTopButton, 0x3DE);
        r = 1;
        ((struct Obj03115 *)p)->f8 = 1;
        break;
    case 1:
    case 6:
        if ((int)POKEPARTY_GetNonEggCount(GAME_DATA_GetMyParty(((struct Obj03115 *)p)->f30)) < 2) {
            MSGDATA_ReadString((struct MsgBank *)(((struct Obj03115 *)p)->f28), 0x2C, (void *)(((struct Obj03115 *)p)->f38));
            IRCBATTLEMENU_PrintMessage(p, 0);
            IRCBATTLEMENU_SetSeq(p, (void *)IRCBATTLEMENU_SeqWaitNotEnoughMsg, 0x3EA);
        } else {
            GFL_USE_PlaySeDefaultVolume(0x73B);
            ((struct Obj03115 *)p)->f8 = 6;
            IRCBATTLEMENU_SetSeq(p, (void *)IRCBATTLEMENU_SeqPressTopButton, 0x3F0);
            r = 1;
        }
        break;
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x73B);
        ((struct Obj03115 *)p)->f8 = 8;
        IRCBATTLEMENU_SetSeq(p, (void *)IRCBATTLEMENU_SeqPressTopButton, 0x3F6);
        r = 1;
        break;
    case 3:
    case 7:
        GFL_USE_PlaySeDefaultVolume(0x73B);
        ((struct Obj03115 *)p)->f8 = 7;
        IRCBATTLEMENU_SetSeq(p, (void *)IRCBATTLEMENU_SeqPressTopButton, 0x3FD);
        r = 1;
        break;
    case 4:
        GFL_USE_PlaySeDefaultVolume(0x73C);
        ((struct Obj03115 *)p)->f8 = 0xC;
        IRCBATTLEMENU_SetSeq(p, (void *)IRCBATTLEMENU_SeqPressTopButton, 0x404);
        break;
    }
    return r;
}
