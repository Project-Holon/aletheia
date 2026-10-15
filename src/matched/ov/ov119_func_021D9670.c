/*
 * function: POKETRADE_PROC_BuildPartyPacket
 * address: 0x021D9670
 * packet: pkt_ov119_021D9670
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_IsSelfMonReady 0x021D94D4 thumb ov119
 *   POKETRADE_PROC_IsHostSideAlt 0x021D95D0 thumb ov119
 *   POKETRADE_PROC_IsGuestSide 0x021D95F0 thumb ov119
 *   POKETRADE_PROC_IsMonTradeable 0x021D9610 thumb ov119
 *   POKETRADE_SAVE_IsMessagePrintDone 0x021E12AC thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   POKETRADE_PROC_StepResolveCursorResult 0x021DA798 thumb ov119
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int POKETRADE_PROC_IsNetSession(void *p);
extern void POKETRADE_PROC_SetStep(void *p, int v);
struct Entry;
extern int POKETRADE_PROC_IsSelfMonReady(char *p);
extern int POKETRADE_PROC_IsHostSideAlt(void *p);
extern u32 POKETRADE_PROC_IsGuestSide(void *p);
extern int POKETRADE_PROC_IsMonTradeable(unsigned char *p);
extern int POKETRADE_SAVE_IsMessagePrintDone(char *p);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *h, u32 a, u32 b);
extern void POKETRADE_PROC_StepResolveCursorResult(char *p);

void POKETRADE_PROC_BuildPartyPacket(char *p)
{
    u8 b[5];
    int r;
    int kind = POKETRADE_PROC_IsNetSession(p);

    if (POKETRADE_SAVE_IsMessagePrintDone(p) == 0)
        return;
    if (kind != 0) {
        if (POKETRADE_PROC_IsSelfMonReady(p)) {
            b[4] = 5;
            r = GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xc00, 1, (u32)(&b[4]));
        } else if (POKETRADE_PROC_IsHostSideAlt(p)) {
            b[3] = 7;
            r = GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xc00, 1, (u32)(&b[3]));
        } else if (POKETRADE_PROC_IsGuestSide(p)) {
            b[2] = 8;
            r = GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xc00, 1, (u32)(&b[2]));
        } else if (POKETRADE_PROC_IsMonTradeable((unsigned char *)p)) {
            b[1] = 6;
            r = GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xc00, 1, (u32)(&b[1]));
        } else {
            b[0] = 2;
            r = GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xc00, 1, (u32)(&b[0]));
        }
        if (r == 0)
            return;
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1b, 8);
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_StepResolveCursorResult);
        return;
    }
    p[0x11e0] = 2;
    p[0x11e1] = 2;
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_StepResolveCursorResult);
}
