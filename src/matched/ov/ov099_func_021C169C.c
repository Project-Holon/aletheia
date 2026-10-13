/*
 * function: WIFICLUB_StateExitNetwork
 * address: 0x021C169C
 * packet: pkt_ov099_021C169C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two zero alignment bytes at 0x021C16EA.
 * lever: GFL_NET_Exit receives the live zero in r0.
 * symbols:
 *   WIFICLUB_UpdateTalkStream 0x021BA928 thumb ov099
 *   WIFICLUB_ShowStreamedMessage 0x021BAAB8 thumb ov099
 *   GFL_NET_Exit 0x0203CEAC arm
 *   GFL_NET_GetRunState 0x0203CD98 arm
 */
#include "../include/Obj00008.h"
extern int WIFICLUB_UpdateTalkStream(char *, int);
extern void WIFICLUB_ShowStreamedMessage(char *, int, int);
struct Sub020097BCObj;
extern int GFL_NET_Exit(int a0);
extern int GFL_NET_GetRunState(void);
extern void func_02009B3C(struct Sub020097BCObj *obj);
int WIFICLUB_StateExitNetwork(char *p, int ret)
{
    if (WIFICLUB_UpdateTalkStream(p, ret) == 0) return ret;
    if (((struct Obj00008 *)p)->f1E0 == 1) {
        ((struct Obj00008 *)p)->f1E0 = 0;
        GFL_NET_Exit(0);
    }
    if (GFL_NET_GetRunState() == 0) {
        func_02009B3C(((struct Obj00008 *)p)->f4);
        WIFICLUB_ShowStreamedMessage(p, 27, 1);
        ((struct Obj00008 *)p)->f1CC = 52;
        ((struct Obj00008 *)p)->f1E0 = 30;
    }
    return ret;
}
