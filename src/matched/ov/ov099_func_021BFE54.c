/*
 * function: func_021BFE54
 * address: 0x021BFE54
 * packet: pkt_ov099_021BFE54
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   GFL_NET_HANDLE_GetNegotiationNum 0x020399EC arm
 *   GFL_NET_STATE_WifiDisconnect 0x0203C554 arm
 *   func_021BA8EC 0x021BA8EC thumb ov099
 */
#include "../include/Obj10209.h"
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern unsigned int func_02039CB4(struct Link *,unsigned int,unsigned int);
extern int GFL_NET_HANDLE_GetNegotiationNum(void);
typedef unsigned int   u32;
extern void GFL_NET_STATE_WifiDisconnect(u32 a);
extern void func_021BA8EC(char *);
int func_021BFE54(char *p, int ret) {
    if (func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),21,10) || GFL_NET_HANDLE_GetNegotiationNum()!=2) {
        GFL_NET_STATE_WifiDisconnect(1);
        ((struct Obj10209 *)p)->f1F0=-1;
        ((struct Obj10209 *)p)->f1E0=20;
        func_021BA8EC(p);
        ((struct Obj10209 *)p)->f1CC=57;
    }
    return ret;
}
