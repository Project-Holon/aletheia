/*
 * function: GFL_NET_SYSTEM_StartParent
 * address:  0x02037894
 * packet:   pkt_02037894
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
 *   GFL_NET_SYSTEM_ParentConnectHook   0x0203781C  arm
 *   GFL_NET_SYSTEM_RecvChildData   0x020387A0  arm
 *   GFL_NET_SYSTEM_InitWork   0x02037288  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_StartParent.c \
 *       --func GFL_NET_SYSTEM_StartParent --addr 0x02037894 --cc 1.1p1 --arm
 */
#include "../include/Obj05734.h"
#include "../include/Obj11352.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef signed int     s32;
extern void *func_0203D798(void);
extern void *GFL_NET_GetSession(void);
extern void GFL_NET_SYSTEM_ParentConnectHook(u32 arg);
extern int GFL_NET_SYSTEM_RecvChildData(u32 i, u8 *p, s32 n);
extern int GFL_NET_SYSTEM_InitWork(u32 a0, u32 heap, u32 c);

void GFL_NET_SYSTEM_StartParent(u8 a0, u16 a1, u32 a2, u32 a3)
{
    char *a = func_0203D798();
    char *b = GFL_NET_GetSession();
    u32 flag;
    u16 val;
    void (*f1)(void *);
    void (*f2)(void *);
    void (*f3)(u32, u32);

    ((struct Obj11352 *)a)->f66 = a0;

    f1 = *(void (**)(void *))(*(char * *)&((struct Obj05734 *)b)->f340 + 0x3C);
    f1(GFL_NET_SYSTEM_ParentConnectHook);

    f2 = *(void (**)(void *))(*(char * *)&((struct Obj05734 *)b)->f340 + 0x68);
    f2(GFL_NET_SYSTEM_RecvChildData);

    if (((struct Obj05734 *)b)->f64 != 0 && ((struct Obj05734 *)b)->f6C != 0) {
        flag = 1;
    } else {
        flag = 0;
    }

    a = func_0203D798();
    val = ((struct Obj11352 *)a)->f56;
    GFL_NET_SYSTEM_InitWork(a1, val, flag);

    f3 = *(void (**)(u32, u32))(*(char * *)&((struct Obj05734 *)b)->f340 + 0x40);
    f3(a2, a3);
}
