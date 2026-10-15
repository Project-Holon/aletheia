/*
 * function: gti2RemoveHoldMessage
 * address:  0x0219681C
 * packet:   pkt_ov009_0219681C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2RemoveHoldMessage (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 *
 * symbols:
 *   func_0218437C  0x0218437C  arm  ov009
 *   func_02184200  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   func_02194E80  0x02194E80  arm  ov009
 */

typedef struct Hold {
	int start;
	int len;
} Hold;

typedef struct Conn {
	unsigned char pad0[0x44];
	unsigned char buffer[0x18];
	void *holds;
} Conn;

extern void func_0218437C(int a, int b);
extern int func_02184200(const int *p);
extern void *func_02184208(void *array, int n);
extern void func_02194E80(void *buffer, int start, int shortenBy);

void gti2RemoveHoldMessage(Conn *c, Hold *message, int index)
{
	int moveAfter;
	int shortenBy;
	int num;
	int i;
	int moveEnd;
	Hold *m;

	moveAfter = message->start;
	shortenBy = message->len;
	moveEnd = 0;
	func_0218437C((int)c->holds, index);
	num = func_02184200(c->holds);
	for (i = 0; i < num; i++) {
		m = (Hold *)func_02184208(c->holds, i);
		if (m->start > moveAfter) {
			m->start -= shortenBy;
			if (moveEnd <= m->start + m->len)
				moveEnd = m->start + m->len;
		}
	}
	func_02194E80(c->buffer, moveAfter, shortenBy);
}
