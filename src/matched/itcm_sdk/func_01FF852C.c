/*
 * function: OSi_CpuClear32
 * address:  0x01FF852C
 * packet:   pkt_01FF852C
 * region:   arm9_autoload0_ITCM
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   OSi_CpuClear32     0x01FF852C  arm
 *   OSi_DoBoot         0x01FF8460  arm
 *   OSi_ReloadRomData  0x01FF8540  arm
 */

typedef unsigned int u32;

/* hand-written in the original: SDK inline-asm stm fill loop (os_reset.o) */
asm void OSi_CpuClear32(u32 data, void *destp, u32 size)
{
    add ip, r1, r2
_loop:
    cmp r1, ip
    stmltia r1!, {r0}
    blt _loop
    bx lr
}
