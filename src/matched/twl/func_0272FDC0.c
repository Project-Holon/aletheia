/*
 * function: MI_GetNDmaConfig
 * address:  0x0272FDC0
 * packet:   twl_audio
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   data_02732EFC 0x02732EFC data twl
 *   MIi_CpuCopy32 0x02082A90 arm
 */

#include "../include/G_twl_data_02732EFC.h"

extern struct G_twl_data_02732EFC data_02732EFC[];
void MIi_CpuCopy32(void *dst, const void *src, unsigned int n);

void MI_GetNDmaConfig(int a0, const void *src)
{
    MIi_CpuCopy32(&data_02732EFC[a0], src, 16);
}
