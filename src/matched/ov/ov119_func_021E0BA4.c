/*
 * function: POKETRADE_SAVE_StepBeginSyncRange24
 * address: 0x021E0BA4
 * packet: pkt_ov119_021E0BA4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_SAVE_StepWaitSyncRange24 0x021E0BC4 thumb ov119
 */
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *, unsigned, unsigned);
extern void POKETRADE_PROC_SetStep(void *, int);
extern void POKETRADE_SAVE_StepWaitSyncRange24(void *);
void POKETRADE_SAVE_StepBeginSyncRange24(void *p)
{
    GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x18, 8);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_SAVE_StepWaitSyncRange24);
}
