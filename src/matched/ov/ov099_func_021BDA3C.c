/*
 * function: func_021BDA3C
 * address: 0x021BDA3C
 * packet: pkt_ov099_021BDA3C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_NotifyUserEvent 0x0203D1E8 arm
 *   GFL_NET_IsParentAid 0x0203D378 arm
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_021BC090 0x021BC090 thumb ov099
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 */
#include "../include/Obj07952.h"
typedef unsigned short u16;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int GFL_NET_NotifyUserEvent(int, int);
extern int GFL_NET_IsParentAid(int);
extern void func_021BA874(void *, int);
extern void func_021BAAB8(char *, int, int);
extern void func_021BC090(char *);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *, unsigned int, unsigned int);
int func_021BDA3C(char *p, int v)
{
    int zero;
    zero = 0;
    if (GFL_NET_IsParentAid(GFL_NET_NotifyUserEvent((int)GFL_NET_HANDLE_GetCurrentHandle(), 0)) == 0) {
        func_021BA874(p, ((struct Obj07952 *)p)->f242 - 1);
        func_021BAAB8(p, 0x77, zero);
        ((struct Obj07952 *)p)->f1CC = 0xaa;
    } else {
        func_021BA874(p, ((struct Obj07952 *)p)->f242 - 1);
        func_021BAAB8(p, 0x4c, zero);
        func_021BC090(p);
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1b, 10);
        ((struct Obj07952 *)p)->f1CC = 0x49;
    }
    return v;
}
