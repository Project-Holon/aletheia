/*
 * function: get48bits_2
 * address:  0x02164490
 * packet:   pkt_ov009_02164490
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   PENDING
 *
 * w4_nm tried (all DIFF): | and + of the (u64)s[0]<<32 term with (u32)(s[-1]<<16),
 * a u64/u32 union, shift-accumulate, xor. MWCC keeps an `orr hi, x, #0` or adds with
 * carry; the object has no such op. Sibling get48bits_3 is an asm body.
 *
 * symbols:
*/

unsigned long long get48bits_2(unsigned short *s)
{
	return ((unsigned long long)s[0] << 32) | ((unsigned long long)s[-1] << 16);
}

