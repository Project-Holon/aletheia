/*
 * function: POKETRADE_SAVE_StepWaitSyncRange24
 * address: 0x021E0BC4
 * packet: pkt_ov119_021E0BC4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_SAVE_StepStartSave 0x021E0BE8 thumb ov119
 */
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern unsigned GFL_NET_HANDLE_IsTimingSyncRange(struct Link *, unsigned, unsigned);
extern void POKETRADE_PROC_SetStep(void *, int);
extern void POKETRADE_SAVE_StepStartSave(char *p);
void POKETRADE_SAVE_StepWaitSyncRange24(void *p)
{
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x18, 8)) {
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_SAVE_StepStartSave);
    }
}
