/*
 * function: gpiProfilesTableCompare
 * address:  0x0218FA0C
 * packet:   pkt_ov009_0218FA0C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
*/

int gpiProfilesTableCompare(void *a, void *b)
{
	return *(int *)a - *(int *)b;
}

