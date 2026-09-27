/*
 * function: DWCi_Http_CPSCallback
 * address:  0x0217A0C8
 * packet:   pkt_ov009_0217A0C8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
*/

int DWCi_Http_CPSCallback(int result)
{
	if (result & 0x8000)
		result &= ~0x8000;
	return result;
}

