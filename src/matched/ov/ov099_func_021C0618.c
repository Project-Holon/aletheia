/*
 * function: func_021C0618
 * address: 0x021C0618
 * packet: pkt_ov099_021C0618
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BA928 0x021BA928 thumb ov099
 *   KEY_GetTrg 0x020362DC arm
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   GFL_NET_STATE_WifiDisconnect 0x0203C554 arm
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_021C2408 0x021C2408 thumb ov099
 */
#include "../include/Obj00008.h"

typedef unsigned int u32;
extern int func_021BA928(char *,int);
extern u32 KEY_GetTrg(void);
extern void func_021BA8EC(char *);
extern void GFL_NET_STATE_WifiDisconnect(u32 a);
extern void func_021C18C8(char *p, int kind, int value);
extern void func_021C2408(char *);
int func_021C0618(char *p,int ret) {
    if (!func_021BA928(p,ret)) return ret;
    if(KEY_GetTrg()) {
        func_021BA8EC(p);
        GFL_NET_STATE_WifiDisconnect(1);
        func_021C18C8(p,1,2);
        ((struct Obj00008 *)p)->f1F0=-1;
        func_021C2408(p);
        ((struct Obj00008 *)p)->f1CC=11;
    }
    return ret;
}
