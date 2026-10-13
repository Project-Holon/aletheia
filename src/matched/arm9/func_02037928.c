/*
 * function: GFL_NET_SYSTEM_StartBeaconScan
 * address:  0x02037928
 * packet:   pkt_02037894
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_GetSession   0x0203D788  arm
 *   GFL_NET_SYSTEM_ChildConnectHook   0x02037858  arm
 *   GFL_NET_SYSTEM_RecvParentData   0x02038924  arm
 *   func_0203D798   0x0203D798  arm
 *   GFL_NET_SYSTEM_InitWork   0x02037288  arm
 *   g_020A7A20      0x020A7A20  data
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_StartBeaconScan.c \
 *       --func GFL_NET_SYSTEM_StartBeaconScan --addr 0x02037928 --cc 1.1p1 --arm
 */
#include "../include/Obj05735.h"
#include "../include/Obj15929.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *GFL_NET_GetSession(void);
extern void *func_0203D798(void);
extern void GFL_NET_SYSTEM_ChildConnectHook(u32 arg);
extern void  GFL_NET_SYSTEM_RecvParentData(void);
extern int GFL_NET_SYSTEM_InitWork(u32 a0, u32 heap, u32 c);

extern u8 g_020A7A20[];

u32 GFL_NET_SYSTEM_StartBeaconScan(u32 a0, u16 a1)
{
    char *b = GFL_NET_GetSession();
    void (*f1)(void *);
    u32 (*f2)(u32, u32);
    void (*f3)(void *);
    u32 res;
    u32 flag;
    char *a;
    u16 val;

    f1 = *(void (**)(void *))(*(char * *)&((struct Obj05735 *)b)->f340 + 0x3C);
    f1(GFL_NET_SYSTEM_ChildConnectHook);

    f2 = *(u32 (**)(u32, u32))(*(char * *)&((struct Obj05735 *)b)->f340 + 0x44);
    res = f2(a0, 0);

    if (res == 1) {
        f3 = *(void (**)(void *))(*(char * *)&((struct Obj05735 *)b)->f340 + 0x68);
        f3(GFL_NET_SYSTEM_RecvParentData);

        if (((struct Obj05735 *)b)->f64 != 0 && ((struct Obj05735 *)b)->f6C != 0) {
            flag = 1;
        } else {
            flag = 0;
        }

        a = func_0203D798();
        val = ((struct Obj15929 *)a)->f56;
        GFL_NET_SYSTEM_InitWork(a1, val, flag);

        g_020A7A20[1] = 4;
    }

    return res;
}
