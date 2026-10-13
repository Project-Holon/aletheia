/*
 * function: func_021BE600
 * address: 0x021BE600
 * packet: pkt_ov099_021BE600
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C24D4 0x021C24D4 thumb ov099
 *   DWC_RAP_GetTargetFriendIndex 0x02156A3C thumb ov009
 *   func_02009B80 0x02009B80 thumb
 *   DWC_RAP_IsDisconnected 0x02156D84 thumb ov009
 *   DWC_RAP_StopVchat 0x021563D0 thumb ov009
 *   func_021BEEBC 0x021BEEBC thumb ov099
 *   func_021C18C8 0x021C18C8 thumb ov099
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
extern void func_021C24D4(u8 *p, int v);
extern int DWC_RAP_GetTargetFriendIndex(void);
struct Sub020097BCObj;
extern void func_02009B80(struct Sub020097BCObj *obj, int i);
extern int DWC_RAP_IsDisconnected(void);
extern void DWC_RAP_StopVchat(void);
extern void func_021BEEBC(char *);
extern void func_021C18C8(char *p, int kind, int value);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *, unsigned int, unsigned int);
extern u32 GFL_USE_GetTargetBgmNo(void);
extern void GFL_USE_CancelChangeAndPlayBgm(int, int);
int func_021BE600(char *p, int ret)
{
    if (((struct Obj22044 *)(*(char * *)&((struct Obj03733 *)p)->f248))->fC) {
        func_021C24D4((u8 *)p, 4);
        func_02009B80(((struct Obj03733 *)p)->f4, DWC_RAP_GetTargetFriendIndex());
        if ((unsigned)(((struct Obj03733 *)p)->f135C - 3) <= 1 && !DWC_RAP_IsDisconnected()) {
            DWC_RAP_StopVchat();
            func_021BEEBC(p);
            ((struct Obj03733 *)p)->f242 = ((struct Obj22045 *)(*(char * *)&((struct Obj03733 *)p)->f248))->f47;
            func_021C18C8(p, 4, 3);
            GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x18, 0xa);
            ((struct Obj03733 *)p)->f1CC = 0xac;
        } else {
            GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x12, 0xa);
            ((struct Obj03733 *)p)->f1CC = 0x93;
        }
    } else {
        ((struct Obj03733 *)p)->f1CC = 9;
        func_021C24D4((u8 *)p, 1);
    }
    if (GFL_USE_GetTargetBgmNo() != 0x424) GFL_USE_CancelChangeAndPlayBgm(0x424, 0xffff);
    return ret;
}
