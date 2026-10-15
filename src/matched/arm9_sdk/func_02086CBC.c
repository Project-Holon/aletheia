/*
 * function: OS_IsOnVram
 * address:  0x02086CBC
 * packet:   pkt_02086CBC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     os_alloc.o OS_IsOnVram.
 */

int OS_IsOnVram(void *ptr)
{
    unsigned int p = (unsigned int)ptr;

    if (p >= 0x05000000u && p < 0x07000800u) {
        return 1;
    }
    return 0;
}
