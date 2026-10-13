/*
 * function: GFL_NET_SYSTEM_ConnectToParent
 * address:  0x02037A6C
 * packet:   pkt_02037A6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_GetSession   0x0203D788  arm
 *   GFL_NET_GetInitParam   0x0203D798  arm
 *   GFL_NET_SYSTEM_RecvParentData   0x02038924  arm
 *   GFL_NET_SYSTEM_InitWork   0x02037288  arm
 *   g_020A7A20      0x020A7A20  data
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_ConnectToParent.c \
 *       --func GFL_NET_SYSTEM_ConnectToParent --addr 0x02037A6C --cc 1.1p1 --arm
 */
#include "../include/Obj06938.h"
#include "../include/Obj15931.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *GFL_NET_GetSession(void);
extern void *GFL_NET_GetInitParam(void);
extern void  GFL_NET_SYSTEM_RecvParentData(void);
extern int GFL_NET_SYSTEM_InitWork(u32 a0, u32 heap, u32 c);
extern u8    g_020A7A20[];

void GFL_NET_SYSTEM_ConnectToParent(u32 a0, u32 a1, u16 a2, u32 a3)
{
    char *b = GFL_NET_GetSession();
    char *a = GFL_NET_GetInitParam();
    void (*f1)(void *);
    u32 flag;
    u16 val;
    void (*f2)(u32, u32, u32, u32, u32);

    f1 = *(void (**)(void *))(*(char * *)&((struct Obj06938 *)b)->f340 + 0x68);
    f1(GFL_NET_SYSTEM_RecvParentData);

    if (a0 != 0) {
        if (((struct Obj06938 *)b)->f64 != 0 && ((struct Obj06938 *)b)->f6C != 0) {
            flag = 1;
        } else {
            flag = 0;
        }

        a = GFL_NET_GetInitParam();
        val = ((struct Obj15931 *)a)->f56;
        GFL_NET_SYSTEM_InitWork(a2, val, flag);

        g_020A7A20[1] = 4;
    }

    f2 = *(void (**)(u32, u32, u32, u32, u32))(*(char * *)&((struct Obj06938 *)b)->f340 + 0x48);
    f2(a0, a1, 0, 0, a3);
}
