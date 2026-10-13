/*
 * function: WIFICLUB_StateRuleMenu
 * address: 0x021BC868
 * packet: pkt_ov099_021BC868
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_MENULIST_Main 0x020200CC thumb
 *   WIFICLUB_ClearTalkWindow 0x021BA8EC thumb ov099
 *   WIFICLUB_DeleteWindow 0x021BA8BC thumb ov099
 *   BMP_MENULIST_Delete 0x0202020C thumb
 *   BMP_MENUWORK_Delete 0x0201F868 thumb
 *   WIFICLUB_SetPartnerNameWord 0x021BA874 thumb ov099
 *   WIFICLUB_ShowStreamedMessage 0x021BAAB8 thumb ov099
 */
#include "../include/Obj00977.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int     s32;
struct Descriptor;
struct Obj;
struct PrintSys;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern s32 BMP_MENULIST_Main(struct Obj *o);
extern void WIFICLUB_ClearTalkWindow(char *);
extern int WIFICLUB_DeleteWindow(void *p);
extern void BMP_MENULIST_Delete(struct Obj *o, u16 *a, u16 *b);
extern u32 BMP_MENUWORK_Delete(void *p);
extern void WIFICLUB_SetPartnerNameWord(void *, int);
extern void WIFICLUB_ShowStreamedMessage(char *, int, int);
int WIFICLUB_StateRuleMenu(char *p, int v)
{
    int r;
    void *q;
    q = ((struct Obj00977 *)p)->f1B8;
    if (((struct Obj00977 *)p)->f1B0 != 0) {
        if (PRINTSYS_QUE_IsExistTarget(q, BMP_WIN_GetBmp(((struct Obj00977 *)p)->f1AC)) == 0) {
            BMP_WIN_TransferChars(((struct Obj00977 *)p)->f1AC);
            ((struct Obj00977 *)p)->f1B0 = 0;
        }
    }
    r = BMP_MENULIST_Main(((struct Obj00977 *)p)->fBC);
    if (r == -1) return v;
    WIFICLUB_ClearTalkWindow(p);
    ((struct Obj00977 *)p)->f1A4 = (void *)WIFICLUB_DeleteWindow(((struct Obj00977 *)p)->f1A4);
    BMP_MENULIST_Delete(((struct Obj00977 *)p)->fBC, 0, (u16 *)(p + 0x234));
    BMP_MENUWORK_Delete(((struct Obj00977 *)p)->fB8);
    if (r == -2) {
        if (((struct Obj00977 *)p)->f135C == 3 || ((struct Obj00977 *)p)->f135C == 4) {
            WIFICLUB_SetPartnerNameWord(p, ((struct Obj00977 *)p)->f242 - 1);
            WIFICLUB_ShowStreamedMessage(p, 0x60, 0);
            ((struct Obj00977 *)p)->f1CC = 0x45;
        } else {
            ((struct Obj00977 *)p)->f1CC = 0x1c;
        }
    } else {
        if (((struct Obj00977 *)p)->f135C == 3 || ((struct Obj00977 *)p)->f135C == 4) {
            ((struct Obj00977 *)p)->f1CC = r;
        } else if (r == 0x5b) {
            ((struct Obj00977 *)p)->f1CC = 0x75;
        } else {
            ((struct Obj00977 *)p)->f1CC = r;
        }
    }
    return v;
}
