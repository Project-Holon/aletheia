/*
 * function: func_02175560
 * address:  0x02175560
 * packet:   pkt_ov009_02175560
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SetConnectionAttemptParam (dwc_match.o)
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 */

#include "../arm9_sdk/libc/string.h"

extern char *func_02175F3C(void);

void func_02175560(void *attemptCallback, unsigned char *connectionUserData, void *attemptParam)
{
    *(void **)(func_02175F3C() + 0x7b8) = attemptCallback;
    if (connectionUserData)
        memcpy(func_02175F3C() + 0x7bc, connectionUserData, 4);
    else
        memset(func_02175F3C() + 0x7bc, 0, 4);
    *(void **)(func_02175F3C() + 0x7c0) = attemptParam;
}
