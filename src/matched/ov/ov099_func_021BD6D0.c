/*
 * function: func_021BD6D0
 * address: 0x021BD6D0
 * packet: pkt_ov099_021BD6D0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   GFL_NET_SetAutoExit 0x0203D7B0 arm
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 *   GFL_NET_IsParentAid 0x0203D378 arm
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 */
#include "../include/Obj22038.h"
typedef unsigned int u32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *, unsigned int, unsigned int);
typedef unsigned char  u8;
extern void GFL_NET_SetAutoExit(u8 a0);
extern int GFL_NET_SetLoginOption(int);
extern int GFL_NET_IsParentAid(int);
extern void func_021BAAB8(char *, int, int);
int func_021BD6D0(char *p, int v)
{
    int zero;
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x19, 10) == 0) return v;
    zero = 0;
    GFL_NET_SetAutoExit(0);
    if (GFL_NET_IsParentAid(GFL_NET_SetLoginOption(0)) != 0) {
        func_021BAAB8(p, 0x7c, zero);
    } else {
        func_021BAAB8(p, 0x7d, zero);
    }
    ((struct Obj22038 *)p)->f1CC = 0x8e;
    return v;
}
