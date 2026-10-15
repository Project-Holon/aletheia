/*
 * function: SOCLi_InitSocketBuffer
 * address:  0x0215D3A0
 * packet:   pkt_ov009_0215D3A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_InitSocketBuffer (libsoc.TWL.HYB.a(socl_create.o))
 *
 * symbols:
 *   func_0215F0C8  0x0215F0C8  arm  ov009
 */

typedef struct {
	unsigned long size;
	unsigned char *data;
} Buf;

extern unsigned long func_0215F0C8(unsigned long size);

unsigned char *SOCLi_InitSocketBuffer(unsigned char *ptr, Buf *buf, unsigned long size)
{
	buf->data = size ? ptr : 0;
	buf->size = size;
	return ptr + func_0215F0C8(size);
}
