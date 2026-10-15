/*
 * function: GURU2_RECEIPT_SetStateFromParent
 * address: 0x021DE08C
 * packet: pkt_ov137_021DE08C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_RECEIPT_ClearMessageFrame 0x021DE5C0 thumb ov137
 *   GURU2_RECEIPT_PrintMessage 0x021DE4B4 thumb ov137
 *   GURU2_RECEIPT_IsMessageDone 0x021DE55C thumb ov137
 *   GURU2_RECEIPT_GetUnionApp 0x021DCF50 thumb ov137
 *   UNION_APP_GetMemberEntry 0x02184180 thumb ov022
 *   BMP_MENU_DeleteYesNo 0x0201FEF4 thumb
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   PRINTSYS_PrintStreamStop 0x0201CE0C thumb
 */
#include "../include/Obj01261.h"
#include "../include/Obj23728.h"
typedef unsigned char u8;
extern void GURU2_RECEIPT_ClearMessageFrame(u8 *);
extern void GURU2_RECEIPT_PrintMessage(char *,int,int);
extern int GURU2_RECEIPT_IsMessageDone(char *);
extern void *GURU2_RECEIPT_GetUnionApp(u8 *p);
typedef unsigned short u16;
typedef unsigned int   u32;
struct WordSet;
extern char *UNION_APP_GetMemberEntry(unsigned char *p, int i);
extern void BMP_MENU_DeleteYesNo(u8 *o);
extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void PRINTSYS_PrintStreamStop(void *);
void GURU2_RECEIPT_SetStateFromParent(char *p,int state,int player) {
    switch(state) {
    case 2:
        GURU2_RECEIPT_ClearMessageFrame((u8 *)p);
        break;
    case 13:
        if (((struct Obj01261 *)p)->fE8) {
            BMP_MENU_DeleteYesNo(((struct Obj01261 *)p)->fE8);
            ((struct Obj01261 *)p)->fE8=0;
        }
        break;
    case 25:
        GURU2_RECEIPT_PrintMessage(p,12,0);
        if (((struct Obj01261 *)p)->fE8) {
            BMP_MENU_DeleteYesNo(((struct Obj01261 *)p)->fE8);
            ((struct Obj01261 *)p)->fE8=0;
        }
        break;
    case 19:
        if (((struct Obj01261 *)p)->f4810==1) return;
        WORDSET_SetSlotMyStatus(((struct Obj01261 *)p)->f3C,0,UNION_APP_GetMemberEntry(GURU2_RECEIPT_GetUnionApp((u8 *)p),player));
        if (player==GFL_NET_SYSTEM_GetCurrentAid()) return;
        if (((struct Obj01261 *)p)->fE8) {
            BMP_MENU_DeleteYesNo(((struct Obj01261 *)p)->fE8);
            ((struct Obj01261 *)p)->fE8=0;
        }
        if (GFL_NET_SYSTEM_GetCurrentAid()==0)
            ((struct Obj23728 *)(*(char * *)&((struct Obj01261 *)p)->f10))->f30&=player^0xffff;
        break;
    case 27:
        if (!GURU2_RECEIPT_IsMessageDone(p)) PRINTSYS_PrintStreamStop(((struct Obj01261 *)p)->fF0);
        if (((struct Obj01261 *)p)->fE8) {
            BMP_MENU_DeleteYesNo(((struct Obj01261 *)p)->fE8);
            ((struct Obj01261 *)p)->fE8=0;
        }
        break;
    case 7:
    case 8:
        break;
    default:
        return;
    }
    ((struct Obj01261 *)p)->f118=state;
}
