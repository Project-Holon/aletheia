/*
 * function: func_0203D000
 * address:  0x0203D000
 * packet:   pkt_0203DC70
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail-call wrapper: func_0203B0C4(p, 0), the twin of func_0203CFF0.
 * NOTE: layout/symbols_sdk.txt lists this address as FATFS_FormatDrive
 * (thumb), a false signature match: the bytes are ARM.
 *
 * symbols:
 *   func_0203B0C4  0x0203B0C4  arm
 */

extern void func_0203B0C4(void *p, int flag);

void func_0203D000(void *p)
{
    func_0203B0C4(p, 0);
}
