/*
 * function: MI_NDmaFillAsync
 * address:  0x0272FBD0
 * packet:   twl_audio
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   data_02732EFC 0x02732EFC data twl
 *   MIi_NDmaAsync_withConfig_Dev 0x0272F9C4 arm twl
 */

#include "../include/G_twl_data_02732EFC.h"

extern struct G_twl_data_02732EFC data_02732EFC;
void MIi_NDmaAsync_withConfig_Dev(int mode, int ch, unsigned int src, unsigned int dst, unsigned int fill, unsigned int size, void (*cb)(), unsigned int arg, void *cfg, int words, unsigned int flags);

void MI_NDmaFillAsync(int ch, unsigned int a1, unsigned int a2, unsigned int size, void (*cb)(), unsigned int arg)
{
    MIi_NDmaAsync_withConfig_Dev(0, ch, 0, a1, a2, size, cb, arg, (void *)(((char *)&data_02732EFC) + (ch << 4)), -1, 0x80000000);
}
