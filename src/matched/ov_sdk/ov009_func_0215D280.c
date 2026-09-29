/*
 * function: func_0215D280
 * address:  0x0215D280
 * packet:   pkt_ov009_0215D280
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_GetSizeCommandPipe (libsoc.TWL.HYB.a(socl_create.o))
 *
 * symbols:
 *   func_0215F0C8  0x0215F0C8  arm  ov009
 */

typedef struct {
	unsigned short a;
	unsigned char b;
	unsigned char c;
} Param;

extern unsigned long func_0215F0C8(unsigned long size);

unsigned long func_0215D280(Param *param)
{
	unsigned long size;

	size = func_0215F0C8(param->c << 2);
	size += func_0215F0C8(param->a);
	return size;
}
