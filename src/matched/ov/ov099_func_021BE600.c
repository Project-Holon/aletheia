/*
 * function: WIFICLUB_StateEnterClub
 * address: 0x021BE600
 * packet: pkt_ov099_021BE600
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFICLUB_InitBgmVolume 0x021C24D4 thumb ov099
 *   DWC_RAP_GetTargetFriendIndex 0x02156A3C thumb ov009
 *   func_02009B80 0x02009B80 thumb
 *   DWC_RAP_IsDisconnected 0x02156D84 thumb ov009
 *   DWC_RAP_StopVchat 0x021563D0 thumb ov009
 *   WIFICLUB_ResetClubScreen 0x021BEEBC thumb ov099
 *   WIFICLUB_SetOwnStatusAndPublish 0x021C18C8 thumb ov099
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   GFL_USE_GetTargetBgmNo 0x02005C4C thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 */
#include "../include/Obj03733.h"
#include "../include/Obj22044.h"
#include "../include/Obj22045.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
extern void WIFICLUB_InitBgmVolume(u8 *p, int v);
extern int DWC_RAP_GetTargetFriendIndex(void);
struct Sub020097BCObj;
extern void func_02009B80(struct Sub020097BCObj *obj, int i);
extern int DWC_RAP_IsDisconnected(void);
extern void DWC_RAP_StopVchat(void);
extern void WIFICLUB_ResetClubScreen(char *);
extern void WIFICLUB_SetOwnStatusAndPublish(char *p, int kind, int value);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *, unsigned int, unsigned int);
extern u32 GFL_USE_GetTargetBgmNo(void);
extern void GFL_USE_CancelChangeAndPlayBgm(int, int);
int WIFICLUB_StateEnterClub(char *p, int ret)
{
    if (((struct Obj22044 *)(*(char * *)&((struct Obj03733 *)p)->f248))->fC) {
        WIFICLUB_InitBgmVolume((u8 *)p, 4);
        func_02009B80(((struct Obj03733 *)p)->f4, DWC_RAP_GetTargetFriendIndex());
        if ((unsigned)(((struct Obj03733 *)p)->f135C - 3) <= 1 && !DWC_RAP_IsDisconnected()) {
            DWC_RAP_StopVchat();
            WIFICLUB_ResetClubScreen(p);
            ((struct Obj03733 *)p)->f242 = ((struct Obj22045 *)(*(char * *)&((struct Obj03733 *)p)->f248))->f47;
            WIFICLUB_SetOwnStatusAndPublish(p, 4, 3);
            GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x18, 0xa);
            ((struct Obj03733 *)p)->f1CC = 0xac;
        } else {
            GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x12, 0xa);
            ((struct Obj03733 *)p)->f1CC = 0x93;
        }
    } else {
        ((struct Obj03733 *)p)->f1CC = 9;
        WIFICLUB_InitBgmVolume((u8 *)p, 1);
    }
    if (GFL_USE_GetTargetBgmNo() != 0x424) GFL_USE_CancelChangeAndPlayBgm(0x424, 0xffff);
    return ret;
}
