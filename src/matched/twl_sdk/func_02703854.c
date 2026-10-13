/*
 * function: NWM_UnsetReceivingFrameBuffer
 * address:  0x02703854
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NWMi_GetSystemWork  0x027026DC  arm twl a2
 *   NWMi_CheckState  0x027028E4  arm twl a2
 *   NWMi_SetCallbackTable  0x02703A34  arm twl a2
 *   NWMi_SetReceiveCallbackTable  0x02703A54  arm twl a2
 *   NWMi_SendCommand  0x02703A74  arm twl a2
 */

typedef unsigned int u32;

extern u32 NWMi_GetSystemWork(void);
extern u32 NWMi_CheckState(u32, u32, u32);
extern void NWMi_SetCallbackTable(u32, u32);
extern void NWMi_SetReceiveCallbackTable(u32, u32);
extern u32 NWMi_SendCommand(u32, u32, u32);

u32 NWM_UnsetReceivingFrameBuffer(u32 a0, u32 a1) {
    u32 st;
    u32 res;

    NWMi_GetSystemWork();
    st = NWMi_CheckState(2, 3, 4);
    if (st != 0 && st != 2) {
        return st;
    }
    NWMi_SetCallbackTable(0xC, a0);
    NWMi_SetReceiveCallbackTable(a1, 0);
    res = NWMi_SendCommand(0xC, 1, a1);
    if (res == 0) {
        return 2;
    }
    return res;
}
