/*
 * file:     unit_0219FBB8_p01.c
 * unit:     yes
 * function: func_0219FD40, func_0219FD64, func_0219FDB8
 * address:  0x0219FD40
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#define SWAP32(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | (((x) << 8) & 0xff0000) | (((x) << 24) & 0xff000000))
void func_0219FD40(unsigned char **p, unsigned char v, int *n);
void func_0219FD64(unsigned char **buffer, int ival, int *len);
void func_0219FDB8(char **buffer, int ival, int *len);

/*
 * Stores a byte through the pointer in *p, then advances the pointer and the counter.
 */
void func_0219FD40(unsigned char **p, unsigned char v, int *n)
{
    **p = v;
    (*n)++;
    (*p)++;
}

/*
 * sdk:      BufferAddInt (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void func_0219FD64(unsigned char **buffer, int ival, int *len)
{
	unsigned char *d = *buffer;
	unsigned char *src = (unsigned char *)&ival;
	d[0] = src[0]; d[1] = src[1]; d[2] = src[2]; d[3] = src[3];
	*len += 4;
	*buffer += 4;
}

/*
 * sdk:      BufferAddIntLE (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void func_0219FDB8(char **buffer, int ival, int *len)
{
	unsigned int ivalNBO;
	unsigned int ivalBE = 0;
	ivalNBO = SWAP32((unsigned int)ival);
	ivalBE |= ivalNBO << 24;
	ivalBE |= (ivalNBO & 0xff00) << 8;
	ivalBE |= (ivalNBO & 0xff0000) >> 8;
	ivalBE |= (ivalNBO & 0xff000000) >> 24;
	func_0219FD64((unsigned char **)buffer, ivalBE, len);
}
