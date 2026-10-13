/*
 * unit:     no
 * function: GFL_NET_RestartByNetType
 * address:  0x0203D2CC
 * packet:   pkt_0203D1B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_020A7CA0     0x020A7CA0  data
 *   g_020A7CE8     0x020A7CE8  data
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   GFL_NET_GetSession  0x0203D788  arm
 *   FLASH_ACCESS_GetBusyFlag  0x020338F8  arm
 *   func_02034714  0x02034714  arm
 *   GFL_NET_WM_ICON_EasyStart  0x02037010  arm
 *   GFL_NET_WM_ICON_EasyEnd  0x020370C8  arm
 *
 * TU: net.c.  This is the function that names it: the assert call at
 * 0x0203D2EC passes the string at 0x020A7CA0, which reads "net.c", with
 * line 0x364 (868) and the message string "0" at 0x020A7CE8.
 *
 * Refresh of the on-screen connection indicator.  Both accessors are
 * called even though they return the same singleton field (GFL_NET_GetInitParam
 * null-checks it, GFL_NET_GetSession does not); the original keeps both results
 * live in r4 and r5 and uses r4 only for the mode test, so the two calls
 * are in the source, not an artefact.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_RestartByNetType.c \
 *       --func GFL_NET_RestartByNetType --addr 0x0203D2CC --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct NetState {
    u8  pad_00[0x56];
    u16 unk_56;
    u8  pad_58[4];
    u16 unk_5c;
    u16 unk_5e;
    u8  pad_60[5];
    u8  mode;
};

extern char g_020A7CA0[];
extern char g_020A7CE8[];

extern void *GFL_NET_GetInitParam(void);
extern void *GFL_NET_GetSession(void);
extern u32  FLASH_ACCESS_GetBusyFlag(void);
extern void func_02034714(const char *file, u32 line, const char *msg);
extern void GFL_NET_WM_ICON_EasyStart(u32 a, u32 b, u32 c, u32 d);
extern void GFL_NET_WM_ICON_EasyEnd(void);

void GFL_NET_RestartByNetType(void)
{
    struct NetState *a = GFL_NET_GetInitParam();
    struct NetState *b = GFL_NET_GetSession();

    if (FLASH_ACCESS_GetBusyFlag() == 1) {
        func_02034714(g_020A7CA0, 868, g_020A7CE8);
        return;
    }
    if (b != 0 && a->mode != 3) {
        u32 flag = 0;

        if ((u8)(b->mode + 0xff) <= 1) {
            flag = 1;
        }
        GFL_NET_WM_ICON_EasyStart(b->unk_5c, b->unk_5e, flag, b->unk_56);
    } else {
        GFL_NET_WM_ICON_EasyEnd();
    }
}
