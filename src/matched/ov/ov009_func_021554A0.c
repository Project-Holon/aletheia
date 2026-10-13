/*
 * function: DWC_RAP_DestroyWork
 * address: 0x021554A0
 * packet: pkt_ov009_021554A0
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * DWC_RAP_FreeRecvBuffers receives the preceding call's live r0 result; its older
 * source declares no arguments. This caller preserves that register payload.
 * symbols:
 *   _pRapWork 0x021A8264 data ov009 a4
 *   GFL_NET_GetInitParam 0x0203D798 arm
 *   DWC_RAP_FreeRecvBuffers 0x02156C60 thumb ov009
 *   GFL_NET_FreeAligned 0x0203D7FC arm
 *   func_02059F18 0x02059F18 arm
 */
extern void *_pRapWork;
extern void *GFL_NET_GetInitParam(void);
extern void DWC_RAP_FreeRecvBuffers(void *);
extern void GFL_NET_FreeAligned(void *);
extern void func_02059F18(void);
void DWC_RAP_DestroyWork(void)
{
    if (_pRapWork) {
        DWC_RAP_FreeRecvBuffers(GFL_NET_GetInitParam());
        GFL_NET_FreeAligned(_pRapWork);
        _pRapWork = 0;
    }
    func_02059F18();
}
