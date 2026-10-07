/*
 * function: func_0272FB28
 * address:  0x0272FB28
 * packet:   twl_audio
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   data_02732EFC 0x02732EFC data twl
 *   func_0272F8A8 0x0272F8A8 arm twl
 */

#include "../include/G_twl_data_02732EFC.h"

extern struct G_twl_data_02732EFC data_02732EFC;
void func_0272F8A8(int a0, int a1, int a2, int a3, int a4, int a5, void *a6, int a7, unsigned int a8);

void func_0272FB28(int a0, int a1, int a2, int a3)
{
    func_0272F8A8(0, a0, 0, a1, a2, a3, (void *)(((char *)&data_02732EFC) + (a0 << 4)), -1, 0x80000000);
}
