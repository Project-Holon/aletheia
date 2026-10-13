/*
 * function: GFL_NET_SYSTEM_InitDevice
 * address:  0x02037700
 * packet:   pkt_02037700
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   GFL_NET_GetSession  0x0203D788  arm
 *   GFL_NET_SYSTEM_InitWork  0x02037288  arm
 *   g_020387A0     0x020387A0  data
 *
 * Filed on lane 1 as the single-caller callee of src/pending/GFL_NET_STATE_WifiMatchStart.c.
 * The 0x340 field is a table of function pointers reached through two
 * indirect calls; the third reaches a slot at +0x68 past two unread words at
 * +0x44 and +0x48, which is why the struct keeps them as padding.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_InitDevice.c \
 *       --func GFL_NET_SYSTEM_InitDevice --addr 0x02037700 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx {
    u8   pad00[0x64];
    u8   f64;          /* 0x64 */
    u8   pad65[0x6c - 0x65];
    u16  f6c;          /* 0x6c */
    u8   pad6e[0x340 - 0x6e];
    u32 *f340;         /* 0x340 */
    u32  pad344[2];    /* 0x344, 0x348 */
    u32  f34c;         /* 0x34c */
};

struct Oth {
    u8  pad0[0x56];
    u16 f56;           /* 0x56 */
};

extern void *GFL_NET_GetInitParam(void);
extern void *GFL_NET_GetSession(void);
extern int GFL_NET_SYSTEM_InitWork(u32 a0, u32 heap, u32 c);
extern u8   g_020387A0[];

int GFL_NET_SYSTEM_InitDevice(u32 a0, u32 a1)
{
    struct Oth *o = (struct Oth *)GFL_NET_GetInitParam();
    struct Ctx *c = GFL_NET_GetSession();
    u32 flag = 0;

    if (c->f64 != 0 && c->f6c != 0)
        flag = 1;
    GFL_NET_SYSTEM_InitWork(a0, a1, flag);
    ((void (*)(u16, struct Ctx *, u32, u32))c->f340[1])(o->f56, c, 0, c->f34c);
    ((void (*)(u32))c->f340[2])(0);
    ((void (*)(u8 *))c->f340[0x68 / 4])(g_020387A0);
    return 1;
}
