/*
 * file:     unit_021B1488.c
 * function: OS_IsThreadAvailable
 * address:  0x021B1488
 * packet:   pkt_ov013_021B1488
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OS_IsThreadAvailable (libos.TWL.HYB.a(os_thread.o))
 *
 * symbols:
 *   OSi_IsThreadInitialized  0x021B4B98  data
 */

extern int OSi_IsThreadInitialized;

int OS_IsThreadAvailable(void)
{
    return OSi_IsThreadInitialized;
}
