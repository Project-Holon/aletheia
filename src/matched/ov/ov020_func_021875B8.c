/*
 * function: FIELD_WFBC_DATA_LOCAL_FreeTalkMessage
 * address: 0x021875B8
 * packet: pkt_ov020_021875B8
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: duplicate the zero store in both arms to retain the original branch stub.
 * regargs: high r2/r3 rows are conservative SDK-depth flags in owner callee 0219131C.
 * interface: 0219131C forwards them to 02045808 -> 020307B0 only; 0203046C
 * overwrites r2/r3, while 02030164's 0202FBAC overwrites r2 and no path reads incoming r3.
 * symbols:
 *   FIELD_MSGBG_WaitTalkWinClose 0x021912F8 thumb ov021
 *   FIELD_MSGBG_ClearTalkWin 0x0219131C thumb ov021
 *   FIELD_MSGBG_DeleteMenuFunc 0x021909BC thumb ov021
 */
#include "../include/Obj00128.h"
typedef unsigned short u16;
extern int FIELD_MSGBG_WaitTalkWinClose(void *p);
extern int FIELD_MSGBG_ClearTalkWin(unsigned int a);
typedef unsigned int   u32;
extern int FIELD_MSGBG_DeleteMenuFunc(void *a);
int FIELD_WFBC_DATA_LOCAL_FreeTalkMessage(char *p)
{
    if (((struct Obj00128 *)p)->f10 != 0) {
        if (((struct Obj00128 *)p)->f52 == 5) {
            if (FIELD_MSGBG_WaitTalkWinClose(((struct Obj00128 *)p)->f10) == 0) return 0;
            ((struct Obj00128 *)p)->f10 = 0;
        } else {
            FIELD_MSGBG_ClearTalkWin((unsigned int)(((struct Obj00128 *)p)->f10));
            ((struct Obj00128 *)p)->f10 = 0;
        }
    }
    if (((struct Obj00128 *)p)->f14 != 0) {
        FIELD_MSGBG_DeleteMenuFunc((void *)(((struct Obj00128 *)p)->f14));
        ((struct Obj00128 *)p)->f14 = 0;
    }
    return 1;
}
