/*
 * function: func_0215EDD0
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
 *   func_0215AA5C  0x0215AA5C  arm  ov009
 *   func_0215C910  0x0215C910  arm  ov009
 *   func_0215AA70  0x0215AA70  arm  ov009
 *   g_021A1CD8     0x021A1CD8  data
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

extern struct G_021A1CD8 *g_021A1CD8;
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void func_0215AA5C(int v);
extern unsigned long func_0215C910(char *name);
extern void func_0215AA70(void);

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
    func_0215AA5C((int)(&soc));
    hostip = func_0215C910(hostname);
    func_0215AA70();
    g_021A1CD8->free(buffers);
    return hostip;
}
