/*
 * function: POKETRADE_NEGO_StepSendOfferIndex
 * address:  0x021DE70C
 * packet:   pkt_ov119_021DE70C
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKETRADE_PROC_IsNetSession  0x021D8A24  thumb  ov119
 *   POKETRADE_PROC_GetSideValue  0x021D8F20  thumb  ov119
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   POKE_TOOL_GetPartyParamSize  0x020173EC  thumb
 *   GFL_NET_SendToHandle  0x0203D3A8  arm
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb  ov119
 *   POKETRADE_NEGO_StepSendOfferMon  0x021DE6AC  thumb  ov119
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int POKETRADE_PROC_IsNetSession(void *p);
extern int POKETRADE_PROC_GetSideValue(void *p, int idx);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 POKE_TOOL_GetPartyParamSize(void);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
extern void POKETRADE_PROC_SetStep(void *p, int next);
extern void POKETRADE_NEGO_StepSendOfferMon(char *p);

void POKETRADE_NEGO_StepSendOfferIndex(void *p)
{
    u8 v;
    if (POKETRADE_PROC_IsNetSession(p) != 0) {
        v = POKETRADE_PROC_GetSideValue(p, 0);
        if (GFL_NET_SendToHandle((struct Entry *)((u32)GFL_NET_HANDLE_GetCurrentHandle()), (u16)0xC16, (u16)POKE_TOOL_GetPartyParamSize(), (u32)(&v)) == 0) {
            return;
        }
    }
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_NEGO_StepSendOfferMon);
}
