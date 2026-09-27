/*
 * function: SOCLi_SocketRegisterList
 * address:  0x0215F2F4
 * packet:   pkt_ov009_0215F2F4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
*/

void SOCLi_SocketRegisterList(void **next, char *socket)
{
	*(void **)(socket + 0xb8) = *next;
	*next = socket;
}

