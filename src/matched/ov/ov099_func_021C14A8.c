/*
 * function: func_021C14A8
 * address: 0x021C14A8
 * packet: pkt_ov099_021C14A8
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C1154 0x021C1154 thumb ov099
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   GFL_NET_SetAutoExit 0x0203D7B0 arm
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 */
#include "../include/Obj22056.h"
extern int func_021C1154(char *p);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern unsigned GFL_NET_HANDLE_IsTimingSyncRange(struct Link *, unsigned, unsigned);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *, unsigned, unsigned);
typedef unsigned char  u8;
extern void GFL_NET_SetAutoExit(u8 a0);
extern void GFL_NET_SetLoginOption(u8 a0);
int func_021C14A8(char *p, int ret)
{
    if (func_021C1154(p) == 0) {
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 15, 10) != 0) {
            GFL_NET_SetAutoExit(1);
            GFL_NET_SetLoginOption(1);
            GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 18, 10);
            ((struct Obj22056 *)p)->f1CC = 45;
        }
    }
    return ret;
}
