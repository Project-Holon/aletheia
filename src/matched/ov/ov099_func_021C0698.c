/*
 * function: WIFICLUB_StateSelectionMenu
 * address: 0x021C0698
 * packet: pkt_ov099_021C0698
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFICLUBACTOR_TickBlink 0x021B9B64 thumb ov099
 *   WIFICLUB_UpdateTalkStream 0x021BA928 thumb ov099
 *   BMP_MENULIST_Main 0x020200CC thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   WIFICLUB_SetOwnStatusAndPublish 0x021C18C8 thumb ov099
 *   WIFICLUB_ClearTalkWindow 0x021BA8EC thumb ov099
 *   WIFICLUB_AddNetCommandsAndCheckFriend 0x021C23C8 thumb ov099
 *   WIFICLUB_EnableTouchBar 0x021C23D8 thumb ov099
 *   WIFICLUB_DeleteWindow 0x021BA8BC thumb ov099
 *   BMP_MENULIST_Delete 0x0202020C thumb
 *   BMP_MENUWORK_Delete 0x0201F868 thumb
 */
#include "../include/Obj00008.h"
extern void WIFICLUBACTOR_TickBlink(char *);
extern int WIFICLUB_UpdateTalkStream(char *);
typedef signed int     s32;
typedef unsigned short u16;
struct Obj;
extern s32 BMP_MENULIST_Main(struct Obj *o);
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void WIFICLUB_SetOwnStatusAndPublish(char *p, int kind, int value);
extern void WIFICLUB_ClearTalkWindow(char *);
extern int WIFICLUB_AddNetCommandsAndCheckFriend(void *a, void *b);
extern void WIFICLUB_EnableTouchBar(char *,int);
extern int WIFICLUB_DeleteWindow(void *p);
extern void BMP_MENULIST_Delete(struct Obj *o, u16 *a, u16 *b);
extern u32 BMP_MENUWORK_Delete(void *p);
typedef enum { K274=0x274 } Off;
int WIFICLUB_StateSelectionMenu(char *p,int ret) {
    int r;
    Off o=K274;
    WIFICLUBACTOR_TickBlink(p+o);
    if(!WIFICLUB_UpdateTalkStream(p))return ret;
    r=BMP_MENULIST_Main((struct Obj *)(*(int *)&((struct Obj00008 *)p)->fBC));
    switch(r) {
    case -1: return ret;
    case -2:
        GFL_USE_PlaySeDefaultVolume(1356);
        *(int *)(p+(o-0xa8))=28;
        break;
    default:
        GFL_USE_PlaySeDefaultVolume(1356);
        WIFICLUB_SetOwnStatusAndPublish(p,2,r);
        *(int *)(p+(o-0xa8))=11;
        WIFICLUB_ClearTalkWindow(p);
        break;
    }
    if(((struct Obj00008 *)p)->f1CC==11){WIFICLUB_AddNetCommandsAndCheckFriend(p,(void *)(-1));WIFICLUB_EnableTouchBar(p,1);}
    ((struct Obj00008 *)p)->f1A4=(void *)WIFICLUB_DeleteWindow(((struct Obj00008 *)p)->f1A4);
    BMP_MENULIST_Delete((struct Obj *)(*(int *)&((struct Obj00008 *)p)->fBC),0,(u16 *)(p+0x234+2* ((struct Obj00008 *)p)->f240));
    BMP_MENUWORK_Delete((void *)(*(int *)&((struct Obj00008 *)p)->fB8));
    return ret;
}
