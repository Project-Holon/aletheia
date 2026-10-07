/*
 * file:     unit_02195E80_p06.c
 * unit:     yes
 * function: func_021968A0, func_02196920
 * address:  0x021968A0
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02184200  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   func_02196558  0x02196558  arm  ov009
 *   func_0219681C  0x0219681C  arm  ov009
 *   current_time  0x0217f264 arm
 */
struct GTI2Connection;
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

typedef unsigned char  u8;

struct GTI2Connection {
    unsigned char pad0[0x90];
    int field_90;
    unsigned int field_94;
};

extern int func_02184200(const int *p);
extern void *func_02184208(void *array, int n);
extern int func_02196558(struct GTI2Connection *connection, int type, u8 *message, int len);
extern void func_0219681C(Conn *c, Hold *m, int index);
extern unsigned int current_time(void);
int func_021968A0(Conn *c);


/*
 * sdk:      gti2DeliverHoldMessages (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 */
int func_021968A0(Conn *c)
{
	int i;
	Hold *m;

again:
	for (i = func_02184200(c->holds) - 1; i >= 0; i--) {
		m = (Hold *)func_02184208(c->holds, i);
		if (m->id == c->expectedId) {
			if (!func_02196558((struct GTI2Connection *)c, m->type, c->data + m->start, m->len))
				return 0;
			func_0219681C(c, m, i);
			goto again;
		}
	}
	return 1;
}


static void gti2SetPendingAck(struct GTI2Connection * connection)
{
    if (connection->field_90)
        return;
    connection->field_90 = 1;
    connection->field_94 = current_time();
}
