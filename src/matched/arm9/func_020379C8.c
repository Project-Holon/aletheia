/*
 * function: GFL_NET_SYSTEM_EndDevice
 * address:  0x020379C8
 * packet:   pkt_02037288
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_GetSession   0x0203D788  arm
 *   func_0203D798   0x0203D798  arm
 *   GFL_NET_SYSTEM_ChildConnectHook   0x02037858  arm
 *   GFL_NET_SYSTEM_RecvParentData   0x02038924  arm
 *   GFL_NET_SYSTEM_InitWork   0x02037288  arm
 *   g_020A7A20      0x020A7A20  data
 *
 * Context teardown through three vtable slots at +0x3c, +0xbc and +0x68 of the
 * object the context's word at +0x340 names.  The first and third are handed a
 * function address as their argument (0x02037858 and 0x02038924), which is why
 * the pool holds two code pointers; the +0xbc slot's answer decides whether the
 * rest runs, and the byte at +1 of the object at 0x020A7A20 is set to 4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_EndDevice.c \
 *       --func GFL_NET_SYSTEM_EndDevice --addr 0x020379C8 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *GFL_NET_GetSession(void);
extern char *func_0203D798(void);
extern void  GFL_NET_SYSTEM_ChildConnectHook(u32 arg);
extern void  GFL_NET_SYSTEM_RecvParentData(u32 arg);
extern int GFL_NET_SYSTEM_InitWork(u32 a0, u32 heap, u32 c);
extern u8    g_020A7A20[];

int GFL_NET_SYSTEM_EndDevice(u32 p)
{
    int   r;
    char *c = GFL_NET_GetSession();

    (*(void (**)(u32))(*(char **)(c + 0x340) + 0x3C))((u32)GFL_NET_SYSTEM_ChildConnectHook);
    r = (*(int (**)(void))(*(char **)(c + 0x340) + 0xBC))();
    if (r == 1) {
        (*(void (**)(u32))(*(char **)(c + 0x340) + 0x68))((u32)GFL_NET_SYSTEM_RecvParentData);
        GFL_NET_SYSTEM_InitWork(p, *(u16 *)(func_0203D798() + 0x56), 0);
        g_020A7A20[1] = 4;
    }
    return r;
}
