/*
 * function: func_0219FDB8
 * address:  0x0219FDB8
 * packet:   pkt_ov009_0219FDB8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      BufferAddIntLE (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   func_0219FD64  0x0219FD64  arm  ov009
 */

extern void func_0219FD64(char **buffer, int ival, int *len);
#define SWAP32(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | (((x) << 8) & 0xff0000) | (((x) << 24) & 0xff000000))
void func_0219FDB8(char **buffer, int ival, int *len)
{
	unsigned int ivalNBO;
	unsigned int ivalBE = 0;
	ivalNBO = SWAP32((unsigned int)ival);
	ivalBE |= ivalNBO << 24;
	ivalBE |= (ivalNBO & 0xff00) << 8;
	ivalBE |= (ivalNBO & 0xff0000) >> 8;
	ivalBE |= (ivalNBO & 0xff000000) >> 24;
	func_0219FD64(buffer, ivalBE, len);
}
