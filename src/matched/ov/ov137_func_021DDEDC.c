/*
 * function: func_021DDEDC
 * address: 0x021DDEDC
 * packet: pkt_ov137_021DDEDC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   func_021DE37C 0x021DE37C thumb ov137
 *   GFL_NET_SetAutoExit 0x0203D7B0 arm
 *   WIPE_SYS_Start 0x0202208C thumb
 *   func_021DD924 0x021DD924 thumb ov137
 */
#include "../include/Obj14218.h"
typedef unsigned short u16;
typedef unsigned int   u32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *, unsigned int, unsigned int);
extern unsigned func_021DE37C(void *p);
typedef unsigned char  u8;
extern void GFL_NET_SetAutoExit(u8 a0);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_021DD924(char *);
int func_021DDEDC(char *p, int state) {
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0xcf, 0x28) != 0 ||
        ((struct Obj14218 *)p)->f4814 != (func_021DE37C(p) ^ ((struct Obj14218 *)p)->f480C)) {
        GFL_NET_SetAutoExit(0);
        WIPE_SYS_Start(0,0,0,0,0x10,1,0x72);
        state = 3;
    }
    func_021DD924(p);
    return state;
}
