/*
 * function: func_021C1724
 * address: 0x021C1724
 * packet: pkt_ov099_021C1724
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two bytes of zero alignment padding at 0x021C1766.
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   GFL_NET_SetAutoExit 0x0203D7B0 arm
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_021BA828 0x021BA828 thumb ov099
 */
#include "../include/Obj00008.h"
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *, unsigned int, unsigned int);
typedef unsigned char  u8;
extern void GFL_NET_SetAutoExit(u8 a0);
extern void GFL_NET_SetLoginOption(u8 a0);
extern int func_021BA928(char *);
extern void func_021BA828(char *);
int func_021C1724(char *p, int ret)
{
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 16, 10) == 0) return ret;
    GFL_NET_SetAutoExit(0);
    GFL_NET_SetLoginOption(1);
    if (func_021BA928(p) != 0) {
        func_021BA828(p);
        ((struct Obj00008 *)p)->f1CC = 54;
    }
    return ret;
}
