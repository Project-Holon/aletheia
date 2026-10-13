/*
 * function: WIFICLUB_StateOptionMenu
 * address:  0x021BCAD0
 * packet:   pkt_ov099_021BCAD0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_MENULIST_Main  0x020200CC  thumb
 *   WIFICLUB_ClearTalkWindow  0x021BA8EC  thumb  ov099
 *   WIFICLUB_DeleteWindow  0x021BA8BC  thumb  ov099
 *   BMP_MENULIST_Delete  0x0202020C  thumb
 *   BMP_MENUWORK_Delete  0x0201F868  thumb
 *
 * Twin of WIFICLUB_StateKindMenu: stores 1 - r at +0x20 of the record at +0x248 and
 * hands +0x23a to BMP_MENULIST_Delete.
 */
#include "../include/Obj02154.h"
#include "../include/Obj22031.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
typedef signed int     s32;
struct Obj;
struct PrintSys;
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern s32 BMP_MENULIST_Main(struct Obj *o);
extern void WIFICLUB_ClearTalkWindow(char *p);
extern int WIFICLUB_DeleteWindow(void *p);
extern void BMP_MENULIST_Delete(struct Obj *o, u16 *a, u16 *b);
extern u32 BMP_MENUWORK_Delete(void *p);

int WIFICLUB_StateOptionMenu(char *p, int v)
{
    int r;
    int q;

    q = ((struct Obj02154 *)p)->f1B8;
    if (((struct Obj02154 *)p)->f1B0 != 0) {
        if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)q, (void *)((int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj02154 *)p)->f1AC))) == 0) {
            BMP_WIN_TransferChars((struct Descriptor *)((struct Obj02154 *)p)->f1AC);
            ((struct Obj02154 *)p)->f1B0 = 0;
        }
    }
    r = BMP_MENULIST_Main((struct Obj *)(((struct Obj02154 *)p)->fBC));
    if (r != -2) {
        if (r == -1) {
            return v;
        }
        ((struct Obj22031 *)(*(char * *)&((struct Obj02154 *)p)->f248))->f20 = 1 - r;
    }
    ((struct Obj02154 *)p)->f1CC = 0x4e;
    WIFICLUB_ClearTalkWindow(p);
    ((struct Obj02154 *)p)->f1A4 = (void *)WIFICLUB_DeleteWindow(((struct Obj02154 *)p)->f1A4);
    BMP_MENULIST_Delete((struct Obj *)(((struct Obj02154 *)p)->fBC), 0, (u16 *)(p + 0x23a));
    BMP_MENUWORK_Delete((void *)(((struct Obj02154 *)p)->fB8));
    return v;
}
