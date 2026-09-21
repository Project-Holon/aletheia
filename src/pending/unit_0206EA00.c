/*
 * function: func_0206EA00
 * address:  0x0206EA00
 * packet:   pkt_0206EA00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,s
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * note:     status corrected 2026-09-21 from EXACT to DIFF by re-verification (58 concrete bytes out)
 *
 * function: func_0206EA2C
 * address:  0x0206EA2C
 * packet:   pkt_0206EA00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,s
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * note:     status corrected 2026-09-21 from EXACT to DIFF by re-verification (58 concrete bytes out)
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

char *func_0206EA00(char *ptr, u32 idx)
{
    if (ptr != 0) {
        if (idx < *(u8 *)(ptr + 6)) {
            return ptr + *(u16 *)(ptr + 8) + (idx << 4);
        }
    }
    return 0;
}

char *func_0206EA2C(char *ptr, u32 idx)
{
    if (ptr != 0) {
        if (idx < *(u8 *)(ptr + 7)) {
            return ptr + *(u16 *)(ptr + 0xa) + (idx << 4);
        }
    }
    return 0;
}
