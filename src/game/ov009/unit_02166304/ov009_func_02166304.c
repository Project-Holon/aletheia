/*
 * function: func_02166304
 * address:  0x02166304
 * packet:   pkt_ov009_02166304
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCMi_InitCpsif (libwcm.TWL.HYB.a cpsif.o)
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   OS_InitMutex  0x02086004  arm
 *   g_021AA7DC  0x021AA7DC  data ov009
 *   g_021AA80C  0x021AA80C  data ov009
 *   g_021AA7E8  0x021AA7E8  data ov009
 *
 * One-time initialisation of the CPS interface work: clears the MAC address and the state words, then initialises the send mutex.
 */

#include "../../../matched/include/G_ov009_021AA7DC.h"

extern struct G_ov009_021AA7DC g_021AA7DC;
extern unsigned char g_021AA80C[];
extern unsigned char g_021AA7E8[];
extern void MI_CpuFill8(void *dst, unsigned char data, unsigned long size);
extern void OS_InitMutex(void *mutex);

void func_02166304(void)
{
    if (g_021AA7DC.inited != 0) {
        return;
    }
    g_021AA7DC.inited = 1;
    g_021AA7DC.field24 = 0;
    MI_CpuFill8(g_021AA80C, 0, 6);
    g_021AA7DC.field8 = 0;
    g_021AA7DC.field4 = 0;
    OS_InitMutex(g_021AA7E8);
}
