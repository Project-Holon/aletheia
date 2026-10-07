/*
 * file:     unit_02195E80_p02.c
 * unit:     yes
 * function: func_02196098, func_02196118
 * address:  0x02196098
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
 *   func_02195340  0x02195340  arm  ov009
 *   func_021950B4  0x021950B4  arm  ov009
 *   func_02195F5C  0x02195F5C  arm  ov009
 */
typedef struct Conn {
	unsigned char pad0[0xc];
	int state;
	unsigned char pad1[0x8c];
	void *filters;
} Conn;

extern int func_02184200(const int *p);
extern int func_02195340(Conn *c, int filterID, unsigned char *msg, int len, int reliable);
extern int func_021950B4(Conn *c, unsigned char *msg, int len, int reliable);
extern int func_02195F5C(Conn *c);
int func_02196098(Conn *c, unsigned char *msg, int len);
int func_02196118(Conn *c, unsigned char *message, int len);


/*
 * sdk:      gti2HandleAppUnreliable (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 */
int func_02196098(Conn *c, unsigned char *msg, int len)
{
	int ret;

	if (c->state != 5 && c->state != 6)
		return 1;
	if (func_02184200(c->filters)) {
		ret = 0;
		if (func_02195340(c, 0, msg, len, 0))
			ret = 1;
		return ret;
	}
	ret = 0;
	if (func_021950B4(c, msg, len, 0))
		ret = 1;
	return ret;
}


/*
 * sdk:      gti2HandleAppReliable (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 */
int func_02196118(Conn *c, unsigned char *message, int len)
{
	int ret;

	if (c->state != 5 && c->state != 6) {
		if (!func_02195F5C(c))
			return 0;
	} else if (func_02184200(c->filters)) {
		ret = 1;
		if (!func_02195340(c, 0, message, len, 1))
			ret = 0;
		return ret;
	} else {
		if (!func_021950B4(c, message, len, 1))
			return 0;
	}
	return 1;
}
