/*
 * function: GFL_NET_ERR_WaitLinkClosed
 * address:  0x0200FBB0
 * packet:   pkt_0200FBB0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   GFL_NET_ClearExitFlag  0x0203CF04  arm
 *   GFL_NET_Exit  0x0203CEAC  arm
 *   GFL_NET_IRC_WIRELESS_Exit  0x0203D0D0  arm
 *   func_02178E4C  0x02178E4C  thumb
 *   GFL_NET_RequestDisconnect  0x0203CFA0  arm
 *   func_0201034C  0x0201034C  thumb
 *   func_0208459C  0x0208459C  arm
 *   GFL_NET_IsSessionNull  0x0203CDBC  arm
 *
 * A polling loop, gated on GFL_NET_GetRunState(): returns 1 immediately if it is
 * zero. Otherwise fetches the same status object GFL_NET_ERR_CheckNetError reads
 * (GFL_NET_GetInitParam, offset +0x65), resets three link-state counters, then
 * polls GFL_NET_IsSessionNull() once per iteration, quitting the moment it stops
 * returning zero. Each iteration checks the status byte first: 0 or 5
 * means "ready to ask", and if func_02178E4C() then answers 0xa the
 * function returns 0 straight out of the loop.
 *
 * Every concrete byte matches; GFL_NET_RequestDisconnect is called from exactly this
 * one site in the whole ROM, so that relocation stays unresolved under
 * the honesty rule. The other nine calls all resolve.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/GFL_NET_ERR_WaitLinkClosed.c \
 *       --func GFL_NET_ERR_WaitLinkClosed --addr 0x0200FBB0 --cc 1.1p1
 *
 * The `matched` class does not reach it: GFL_NET_RequestDisconnect is not matched, so
 * no EXACT entry covers that address. Closes to EXACT the day either
 * GFL_NET_RequestDisconnect gets a second caller elsewhere in the image, or is itself
 * matched.
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int GFL_NET_GetRunState(void);
extern void *GFL_NET_GetInitParam(void);
extern void GFL_NET_ClearExitFlag(void);
extern int GFL_NET_Exit(int a0);
extern void GFL_NET_IRC_WIRELESS_Exit(void);
extern u32  func_02178E4C(void);
extern void GFL_NET_RequestDisconnect(void);
extern int func_0201034C(void);
extern void func_0208459C(int clear, u32 irqFlags);
extern int GFL_NET_IsSessionNull(void);

u32 GFL_NET_ERR_WaitLinkClosed(void)
{
    u8 *obj;
    u32 flag;

    if (GFL_NET_GetRunState() != 0) {
        obj = GFL_NET_GetInitParam();
        GFL_NET_ClearExitFlag();
        GFL_NET_Exit(0);
        GFL_NET_IRC_WIRELESS_Exit();
        flag = 1;

        for (;;) {
            if (obj != 0) {
                u8 v = obj[0x65];
                if (v == 0 || v == 5) {
                    if (func_02178E4C() == 0xa) {
                        return 0;
                    }
                }
            }
            GFL_NET_RequestDisconnect();
            func_0201034C();
            func_0208459C(flag, flag);
            if (GFL_NET_IsSessionNull() == 0) {
                continue;
            }
            break;
        }
    }

    return 1;
}
