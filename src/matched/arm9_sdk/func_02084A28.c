/*
 * function: func_02084A28
 * address:  0x02084A28
 * packet:   pkt_02084A28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OS_IsResetOccurred (os_pxi.o)
 *
 * symbols:
 *   g_02150FC8    0x02150FC8  data
 */

typedef unsigned short u16;
typedef int BOOL;

/* os_pxi.o .bss from 0x02150FC8, addressed from one pool word. */
typedef struct OsPxiBss {
    u16 OSi_IsResetOccurred;
    u16 OSi_IsTerminateOccurred;
} OsPxiBss;

extern OsPxiBss g_02150FC8;

BOOL func_02084A28(void)
{
    return g_02150FC8.OSi_IsResetOccurred;
}
