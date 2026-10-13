/*
 * function: func_021BFF9C
 * address: 0x021BFF9C
 * packet: pkt_ov099_021BFF9C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   KEY_GetTrg 0x020362DC arm
 *   GFL_NET_STATE_WifiDisconnect 0x0203C554 arm
 */
#include "../include/Obj00008.h"

typedef unsigned int u32;
extern int func_021BA928(char *,int);
extern void func_021BA8EC(char *);
extern void func_021C18C8(char *p, int kind, int value);
extern u32 KEY_GetTrg(void);
extern void GFL_NET_STATE_WifiDisconnect(u32 a);
int func_021BFF9C(char *p, int ret) {
    if (!func_021BA928(p, ret)) return ret;
    if (KEY_GetTrg() & 3) {
        func_021BA8EC(p);
        func_021C18C8(p, 1, 2);
        GFL_NET_STATE_WifiDisconnect(1);
        ((struct Obj00008 *)p)->f1E0=20;
        ((struct Obj00008 *)p)->f1CC=57;
    }
    return ret;
}
