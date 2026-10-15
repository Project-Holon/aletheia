/*
 * function: SHA1_HMAC_HashRange
 * address:  0x02731770
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

asm void SHA1_HMAC_HashRange(void)
{
    swi     0x27
    bx      lr
}
