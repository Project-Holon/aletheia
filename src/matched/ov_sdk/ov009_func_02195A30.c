/*
 * function: func_02195A30
 * address:  0x02195A30
 * packet:   pkt_ov009_02195A30
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2ConnectionCleanup (libdwcgsgt2.TWL.HYB.a(gt2connection.o))
 *
 * symbols:
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   func_021841B0  0x021841B0  arm  ov009
 */

typedef struct Conn {
	unsigned char pad0[0x38];
	void *msg;
	unsigned char pad1[8];
	void *buf44;
	unsigned char pad3[8];
	void *buf50;
	unsigned char pad4[8];
	void *arr5c;
	void *arr60;
	unsigned char pad5[0x34];
	void *arr98;
	void *arr9c;
} Conn;

extern void func_0217EAE0(void *ptr);
extern void func_021841B0(void *array);

void func_02195A30(Conn *c)
{
	if (c->msg)
		func_0217EAE0(c->msg);
	if (c->buf44)
		func_0217EAE0(c->buf44);
	if (c->buf50)
		func_0217EAE0(c->buf50);
	if (c->arr5c)
		func_021841B0(c->arr5c);
	if (c->arr60)
		func_021841B0(c->arr60);
	if (c->arr98)
		func_021841B0(c->arr98);
	if (c->arr9c)
		func_021841B0(c->arr9c);
	func_0217EAE0(c);
}
