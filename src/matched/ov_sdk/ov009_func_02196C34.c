/*
 * function: gti2HandlePong
 * address:  0x02196C34
 * packet:   pkt_ov009_02196C34
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2HandlePong (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 *
 * symbols:
 *   func_020923F0  0x020923F0  arm
 *   current_time  0x0217F264  arm  ov009
 *   func_021951E8  0x021951E8  arm  ov009
 *   gGti2TimeKey  0x021A5940  data
 */

typedef struct Conn {
	unsigned char pad0[0x34];
	void *ping;
} Conn;

typedef unsigned char  u8;
extern int func_020923F0(const u8 *a, const u8 *b, int n);
extern unsigned int current_time(void);
extern int func_021951E8(Conn *c, int latency);
extern unsigned char gGti2TimeKey[];

int gti2HandlePong(Conn *c, unsigned char *message, int len)
{
	unsigned int startTime;
	unsigned char *d;

	if (!c->ping)
		return 1;
	if (len != 8)
		return 1;
	if (func_020923F0(message, gGti2TimeKey, 4))
		return 1;
	d = (unsigned char *)&startTime;
	d[0] = message[4];
	d[1] = message[5];
	d[2] = message[6];
	d[3] = message[7];
	if (!func_021951E8(c, current_time() - startTime))
		return 0;
	return 1;
}
