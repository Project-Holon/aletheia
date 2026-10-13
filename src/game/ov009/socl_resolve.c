/*
 * file:     socl_resolve.c
 * unit:     yes
 * function: func_0215EDD0, func_0215EE98, func_0215EEE0, func_0215EF48
 * address:  0x0215EDD0
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MI_CpuFill8    0x02082BCC  arm
 *   CPS_SocRegister  0x0215AA5C  arm  ov009
 *   CPS_Resolve  0x0215C910  arm  ov009
 *   CPS_SocUnRegister  0x0215AA70  arm  ov009
 *   g_021A1CD8     0x021A1CD8  data
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   g_021A82DC     0x021A82DC  data
 *   func_0215EF48  0x0215EF48  arm  ov009
 *   g_021A8278     0x021A8278  data
 *   CPSMyIp            0x021a82bc data
 *   SOCLiDhcpState     0x021aa448 data
 *   SOCLiRequestedIP   0x021aa444 data
 *   OS_GetProcMode     0x020879ec arm
 *   OS_Sleep           0x02085a38 arm
 */
#include "../../matched/include/G_021A1CD8.h"

typedef struct {
    unsigned char pad0[0x48];
    unsigned long buf_size;
    unsigned char *buf;
    unsigned long work_size;
    unsigned long work;
    unsigned char *work_end;
    unsigned char pad5c[0xa0 - 0x5c];
} CpsSoc;

extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void CPS_SocRegister(int v);
extern unsigned long CPS_Resolve(char *name);
extern void CPS_SocUnRegister(void);
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern unsigned long func_0215EF48(void);
extern int OS_GetProcMode(void);
extern void OS_Sleep(unsigned long msec);
unsigned long func_0215EDD0(char *hostname);
unsigned long func_0215EE98(char *hostname);
int func_0215EEE0(unsigned long dns1, unsigned long dns2);
unsigned long SOCL_GetHostID(void);
extern struct G_021A1CD8 *g_021A1CD8;
extern unsigned long g_021A82DC[2];
extern unsigned long g_021A8278;
extern unsigned long CPSMyIp;
extern unsigned long SOCLiDhcpState;
extern unsigned long SOCLiRequestedIP;


unsigned long func_0215EDD0(char *hostname)
{
    unsigned char *buffers;
    CpsSoc soc;
    unsigned long hostip;

    if (g_021A1CD8 == 0)
        return 0;
    if (hostname == 0)
        return 0;
    buffers = g_021A1CD8->alloc(0x1708);
    if (buffers == 0)
        return 0;
    MI_CpuFill8(&soc, 0, sizeof(soc));
    soc.buf = buffers;
    soc.buf_size = 0xb68;
    soc.work_end = buffers + 0xb68;
    soc.work = 0xb9e;
    CPS_SocRegister((int)(&soc));
    hostip = CPS_Resolve(hostname);
    CPS_SocUnRegister();
    g_021A1CD8->free(buffers);
    return hostip;
}


/*
 * sdk:      SOCL_InetAtoH (libsoc.TWL.HYB.a(socl_resolve.o))
 */
unsigned long func_0215EE98(char *hostname)
{
    unsigned long hostip;
    unsigned long enable;
    unsigned long dns0;
    unsigned long dns1;

    enable = OS_DisableInterrupts();
    dns0 = g_021A82DC[0];
    dns1 = g_021A82DC[1];
    g_021A82DC[0] = 0;
    g_021A82DC[1] = 0;
    hostip = CPS_Resolve(hostname);
    g_021A82DC[0] = dns0;
    g_021A82DC[1] = dns1;
    OS_RestoreInterrupts(enable);
    return hostip;
}


/*
 * sdk:      SOCL_SetResolver (libsoc.TWL.HYB.a(socl_resolve.o))
 */
int func_0215EEE0(unsigned long dns1, unsigned long dns2)
{
    if (func_0215EF48() == 0)
        return -0x27;
    g_021A82DC[0] = dns1;
    if (dns1 == 0) {
        g_021A8278 &= ~2;
        g_021A82DC[1] = 0;
    } else {
        g_021A8278 |= 2;
        g_021A82DC[1] = dns2;
    }
    return 0;
}


unsigned long SOCL_GetHostID(void)
{
    if (CPSMyIp == 0) {
        if ((SOCLiDhcpState & 3) == 1 && OS_GetProcMode() != 0x12)
            OS_Sleep(10);
    } else {
        if (SOCLiRequestedIP == 0)
            SOCLiRequestedIP = CPSMyIp;
    }
    return CPSMyIp;
}
