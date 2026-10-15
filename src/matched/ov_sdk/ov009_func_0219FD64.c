/*
 * function: BufferAddInt
 * address:  0x0219FD64
 * packet:   pkt_ov009_0219FD64
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      BufferAddInt (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   (none)
 */

void BufferAddInt(unsigned char **buffer, int ival, int *len)
{
	unsigned char *d = *buffer;
	unsigned char *src = (unsigned char *)&ival;
	d[0] = src[0]; d[1] = src[1]; d[2] = src[2]; d[3] = src[3];
	*len += 4;
	*buffer += 4;
}
