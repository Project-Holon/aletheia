/*
 * function: MIi_CardNDmaRecv32
 * address:  0x0272FDDC
 * packet:   twl_audio
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   data_02732EFC 0x02732EFC data twl
 *   func_02087988 0x02087988 arm
 *   func_0208799C 0x0208799C arm
 *   MIi_Wait 0x0272FD40 arm twl
 */

#include "../include/G_twl_data_02732EFC.h"

extern struct G_twl_data_02732EFC data_02732EFC[];
unsigned int func_02087988(void);
void func_0208799C(unsigned int);
void MIi_Wait(int a0);

void MIi_CardNDmaRecv32(int ch, const void *src, void *dst)
{
    unsigned int irq = func_02087988();
    unsigned int base;
    struct G_twl_data_02732EFC *e;
    MIi_Wait(ch);
    base = 0x04000000 + ch * 0x1C;
    e = &data_02732EFC[ch];
    *(volatile unsigned int *)(base + 0x4104) = (unsigned int)src;
    *(volatile unsigned int *)(base + 0x4108) = (unsigned int)dst;
    *(volatile unsigned int *)(base + 0x410C) = 1;
    *(volatile unsigned int *)(base + 0x4110) = 1;
    *(volatile unsigned int *)(base + 0x411C) = e->unk8 | 0x4000 | 0xA4000000;
    func_0208799C(irq);
}
