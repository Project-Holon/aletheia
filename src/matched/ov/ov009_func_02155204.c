/*
 * function: GFL_NET_DEVWIFI_Cleanup
 * address:  0x02155204
 * packet:   pkt_ov009_02155204
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   DWC_RAP_Shutdown  0x0215677C  thumb  ov009
 *   func_020307B0  0x020307B0  arm
 *   DWC_RAPCOMMON_DestroyHeap  0x021570B8  thumb  ov009
 *   _pSetupParam     0x021A8260  data  ov009  a4
 */

extern int *_pSetupParam;
void DWC_RAP_Shutdown(void);
typedef unsigned int   u32;
u32 func_020307B0(void *p);
void DWC_RAPCOMMON_DestroyHeap(void);

int GFL_NET_DEVWIFI_Cleanup(void (*cb)(int))
{
    if (_pSetupParam != 0) {
        DWC_RAP_Shutdown();
        if (cb != 0)
            cb(1);
        func_020307B0(_pSetupParam);
        _pSetupParam = 0;
    }
    DWC_RAPCOMMON_DestroyHeap();
    return 1;
}
