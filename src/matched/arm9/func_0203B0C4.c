/*
 * unit:     no
 * function: GFL_NET_STATE_ConnectMacAddress
 * address:  0x0203B0C4
 * packet:   pkt_0203B0C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   _pNetState     0x021469DC  data
 *   s_020A7BA8     0x020A7BA8  data
 *   s_020A7BC8     0x020A7BC8  data
 *   func_02034714  0x02034714  arm
 *   func_02082D44  0x02082D44  arm
 *   GFL_NET_STATE_ChangeStateDebug  0x0203AD80  arm
 *   GFL_NET_STATE_StartConnectMac  0x0203B084  arm
 *   GFL_NET_STATE_ConnectMac  0x0203B038  arm
 *
 * The two guards and the load/store pair: 0x021469DC holds a pointer whose
 * +0x40 address is both bit-tested (with the file/line/message triple at
 * 0x020A7BA8) and handed to func_02082D44 together with a length of 6,
 * then the two entry points GFL_NET_STATE_StartConnectMac and GFL_NET_STATE_ConnectMac are registered
 * at sizes 400 and 403.
 */

#include "../include/G_Sys.h"

extern struct Sys *_pNetState;
extern char s_020A7BA8[];
extern char s_020A7BC8[];
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02082D44(int a0, int a1, int a2);
typedef unsigned short u16;
struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);
extern void GFL_NET_STATE_StartConnectMac(void);
extern void GFL_NET_STATE_ConnectMac(u8 *a0);

void GFL_NET_STATE_ConnectMacAddress(int a0, int a1)
{
    if (((*(int *)&_pNetState) + 0x40) & 1) {
        func_02034714(s_020A7BA8, 395, s_020A7BC8);
    }
    if (a0 != 0) {
        func_02082D44(a0, (*(int *)&_pNetState) + 0x40, 6);
    }
    if (a1 != 0) {
        GFL_NET_STATE_ChangeStateDebug((struct NetState *)(*(int *)&_pNetState), (void *)GFL_NET_STATE_StartConnectMac, 0, 400);
    } else {
        GFL_NET_STATE_ChangeStateDebug((struct NetState *)(*(int *)&_pNetState), (void *)GFL_NET_STATE_ConnectMac, 0, 403);
    }
}
