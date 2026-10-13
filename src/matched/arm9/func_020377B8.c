/*
 * function: GFL_NET_SYSTEM_ConnectDevice
 * address:  0x020377B8
 * packet:   pkt_020377B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203D798   0x0203D798  arm
 *   GFL_NET_GetSession   0x0203D788  arm
 *   GFL_NET_SYSTEM_InitWork   0x02037288  arm
 *   GFL_NET_SYSTEM_ResetRecvBuffer   0x02037680  arm
 *   GFL_NET_SYSTEM_RecvCallback   0x020377AC  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_ConnectDevice.c \
 *       --func GFL_NET_SYSTEM_ConnectDevice --addr 0x020377B8 --cc 1.1p1 --arm
 */
#include "../include/Obj11351.h"
#include "../include/Obj15917.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0203D798(void);
extern void *GFL_NET_GetSession(void);
extern int GFL_NET_SYSTEM_InitWork(u32 a0, u32 heap, u32 c);
extern void GFL_NET_SYSTEM_ResetRecvBuffer(int i);
extern void  GFL_NET_SYSTEM_RecvCallback(void);

u32 GFL_NET_SYSTEM_ConnectDevice(u8 arg0)
{
    u32 zero;
    char *a = func_0203D798();
    char *b = GFL_NET_GetSession();
    u16 val;
    void (*f)(void *);

    ((struct Obj11351 *)a)->f66 = arg0;
    f = *(void (**)(void *))(*(char * *)&((struct Obj15917 *)b)->f340 + 0x68);
    f(GFL_NET_SYSTEM_RecvCallback);

    zero = 0;
    val = ((struct Obj11351 *)a)->f56;
    GFL_NET_SYSTEM_InitWork(0x80, val, zero);

    GFL_NET_SYSTEM_ResetRecvBuffer(zero);
    GFL_NET_SYSTEM_ResetRecvBuffer(1);
    GFL_NET_SYSTEM_ResetRecvBuffer(2);

    return 1;
}
