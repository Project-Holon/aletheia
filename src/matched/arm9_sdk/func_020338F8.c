/*
 * function: FLASH_ACCESS_GetBusyFlag
 * address:  0x020338F8
 * packet:   pkt_0203331C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Accessor for the singleton pointer at 0x02146998.
 *
 * symbols:
 *   g_02146998  0x02146998  data
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FLASH_ACCESS_GetBusyFlag.c \
 *       --func FLASH_ACCESS_GetBusyFlag --addr 0x020338F8 --cc 1.1p1 --arm
 */

extern void *g_02146998;

void *FLASH_ACCESS_GetBusyFlag(void)
{
    return g_02146998;
}
