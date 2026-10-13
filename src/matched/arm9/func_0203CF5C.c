/*
 * function: GFL_NET_Main
 * address:  0x0203CF5C
 * packet:   pkt_0203CF5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *           --suggest-split offers nothing (single function, all four
 *           unresolved sites' only witnesses are inside this range).
 * blocker:  GFL_NET_LOWER_DATA_MainSend, GFL_NET_IRC_WIRELESS_Main, GFL_NET_HANDLE_Main, GFL_NET_SYSTEM_Main (label,
 *           all four) -- each has no witness outside 0203CF5C..0203CFA0; every
 *           branch to them in the image is this function's own call. Four of
 *           the eight sites resolve. Every concrete byte of the body
 *           reproduces. Note the chain is two levels deep: GFL_NET_STATE_Main,
 *           also called here, is itself a documented DIFF
 *           (docs/notes/pkt_0203B1D8.c.txt) and GFL_NET_WM_ICON_EasyMain is a pending
 *           MATCH park.
 * symbols:
 *   GFL_NET_GetSession 0x0203D788  arm
 *   GFL_NET_LOWER_DATA_MainSend 0x0203EA9C  arm
 *   GFL_NET_IRC_WIRELESS_Main 0x0203DC70  arm
 *   GFL_NET_STATE_Main 0x0203B1D8  arm
 *   GFL_NET_WM_ICON_EasyMain 0x02037154  arm
 *   GFL_NET_HANDLE_Main 0x02039D94  arm
 *   GFL_NET_SYSTEM_Main 0x02037C10  arm
 *   GFL_NET_SYSTEM_IsSendEnable 0x02039594  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *GFL_NET_GetSession(void);
extern void GFL_NET_LOWER_DATA_MainSend(void);
extern void GFL_NET_IRC_WIRELESS_Main(void);
extern u32 GFL_NET_STATE_Main(void);
extern void GFL_NET_WM_ICON_EasyMain(void);
extern void GFL_NET_HANDLE_Main(void);
extern int GFL_NET_SYSTEM_Main(void);
extern int GFL_NET_SYSTEM_IsSendEnable(void);

u32 GFL_NET_Main(void)
{
    u8 *p = GFL_NET_GetSession();

    GFL_NET_LOWER_DATA_MainSend();
    GFL_NET_IRC_WIRELESS_Main();
    if (GFL_NET_STATE_Main() != 0) {
        return 1;
    }
    if (p == 0) {
        return 1;
    }
    GFL_NET_WM_ICON_EasyMain();
    GFL_NET_HANDLE_Main();
    GFL_NET_SYSTEM_Main();
    return GFL_NET_SYSTEM_IsSendEnable();
}
