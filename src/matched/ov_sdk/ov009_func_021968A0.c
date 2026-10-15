/*
 * function: gti2DeliverHoldMessages
 * address:  0x021968A0
 * packet:   pkt_ov009_021968A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2DeliverHoldMessages (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 *
 * symbols:
 *   func_02184200  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   gti2DeliverReliableMessage  0x02196558  arm  ov009
 *   gti2RemoveHoldMessage  0x0219681C  arm  ov009
 */

typedef struct Hold {
	int start;
	int len;
	int type;
	unsigned short id;
} Hold;

typedef struct Conn {
	unsigned char pad0[0x44];
	unsigned char *data;
	unsigned char pad1[0x14];
	void *holds;
	unsigned char pad2[6];
	unsigned short expectedId;
} Conn;

extern int func_02184200(const int *p);
extern void *func_02184208(void *array, int n);
typedef unsigned char  u8;
struct GTI2Connection;
extern int gti2DeliverReliableMessage(struct GTI2Connection *connection, int type, u8 *message, int len);
extern void gti2RemoveHoldMessage(Conn *c, Hold *m, int index);

int gti2DeliverHoldMessages(Conn *c)
{
	int i;
	Hold *m;

again:
	for (i = func_02184200(c->holds) - 1; i >= 0; i--) {
		m = (Hold *)func_02184208(c->holds, i);
		if (m->id == c->expectedId) {
			if (!gti2DeliverReliableMessage((struct GTI2Connection *)c, m->type, c->data + m->start, m->len))
				return 0;
			gti2RemoveHoldMessage(c, m, i);
			goto again;
		}
	}
	return 1;
}
