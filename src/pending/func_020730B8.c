/*
 * function: func_020730B8
 * address:  0x020730B8
 * packet:   pkt_020730B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * note:     status corrected 2026-09-21 from EXACT to DIFF by re-verification (22 concrete bytes out)
 */

typedef struct Struct_020730B8 {
    char pad[0x34];
    unsigned short f34;
    char pad36[2];
    unsigned short f38;
} Struct_020730B8;

void func_020730B8(Struct_020730B8 **ptr, unsigned short val)
{
    if (*ptr != 0) {
        (*ptr)->f34 = 1;
        (*ptr)->f38 = val;
    }
}
