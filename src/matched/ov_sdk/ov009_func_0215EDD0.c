/*
 * function: SOCL_Resolve
 * address:  0x0215EDD0
 * packet:   pkt_ov009_0215EDD0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCL_Resolve (libsoc.TWL.HYB.a(socl_resolve.o))
 *
 * symbols:
 *   MI_CpuFill8    0x02082BCC  arm
 *   CPS_SocRegister  0x0215AA5C  arm  ov009
 *   CPS_Resolve  0x0215C910  arm  ov009
 *   CPS_SocUnRegister  0x0215AA70  arm  ov009
 *   gSoclConfig     0x021A1CD8  data
 */

#include "../include/G_021A1CD8.h"

typedef struct {
    unsigned char pad0[0x48];
    unsigned long buf_size;
    unsigned char *buf;
    unsigned long work_size;
    unsigned long work;
    unsigned char *work_end;
    unsigned char pad5c[0xa0 - 0x5c];
} CpsSoc;

extern struct G_021A1CD8 *gSoclConfig;
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void CPS_SocRegister(int v);
extern unsigned long CPS_Resolve(char *name);
extern void CPS_SocUnRegister(void);

unsigned long SOCL_Resolve(char *hostname)
{
    unsigned char *buffers;
    CpsSoc soc;
    unsigned long hostip;

    if (gSoclConfig == 0)
        return 0;
    if (hostname == 0)
        return 0;
    buffers = gSoclConfig->alloc(0x1708);
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
    gSoclConfig->free(buffers);
    return hostip;
}
