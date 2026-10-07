/*
 * function: func_02165B68
 * address:  0x02165B68
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Two when the word call is non-zero, one otherwise.
 *
 * symbols:

 */

extern int func_02085D3C(int a);

int func_02165B68(int a)
{
    return func_02085D3C(a) ? 2 : 1;
}

