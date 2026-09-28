/*
 * function: func_02177770
 * address:  0x02177770
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Indexes the record array at +0x38 a record.
 *
 * symbols:
 *   g_021AB180  0x021AB180  data
 */

extern char g_021AB180[];

int func_02177770(int i)
{
    return *(int *)g_021AB180 + i * 0x38;
}

