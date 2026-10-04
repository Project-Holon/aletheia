/*
 * function: func_0215E794
 * address:  0x0215E794
 * packet:   pkt_ov009_0215E794
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCL_IsClosed (libsoc.TWL.HYB.a(socl_close.o))
 *
 * symbols:
 *   func_0215F3D0  0x0215F3D0  arm  ov009
 *   func_0215F404  0x0215F404  arm  ov009
 */

extern int func_0215F3D0(void *s);
extern int func_0215F404(int b);

int func_0215E794(int s)
{
	void *socket;

	if (s >= 0) {
		socket = (void *)s;
		if (func_0215F3D0(socket) != 0 && func_0215F404((int)socket) == 0)
			return 1;
	}
	return 0;
}
