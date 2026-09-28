/*
 * function: DWCi_InitTransport
 * address:  0x021772F8
 * packet:   pkt_ov009_021772F8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_InitTransport (libdwcmatch.TWL.HYB.a dwc_transport.o)
 * symbols:
 *   MI_CpuFill8                    0x02082BCC arm
 *   DWC_SetConnectionKeepAliveTime 0x021772B8 arm
 *   DWCi_InitReliableQueue         0x02176B68 arm
 *   g_021AB180                     0x021AB180 data
 */

extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern int DWC_SetConnectionKeepAliveTime(unsigned long time);
extern void DWCi_InitReliableQueue(void);
extern char g_021AB180[];

void DWCi_InitTransport(char *info)
{
    *(char **)g_021AB180 = info;
    MI_CpuFill8(info, 0, 0x728);
    *(unsigned short *)(*(char **)g_021AB180 + 0x720) = 0x5b9;
    DWC_SetConnectionKeepAliveTime(0x4e20);
    DWCi_InitReliableQueue();
}
