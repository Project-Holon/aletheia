/*
 * file:     unit_021573C4_p23.c
 * unit:     yes
 * function: func_0215A970
 * address:  0x0215A970
 * packet:   pkt_ov009_0215A970
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPS_SocGetEport (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   g_02150FEC  0x02150FEC  data
 *   g_021A826C  0x021A826C  data
 */

struct Soc {
	unsigned long thread;
	unsigned char pad0[6];
	unsigned short local_port;
};

struct Thread {
	unsigned char pad0[0x68];
	struct Thread *next;
	unsigned char pad1[0x38];
	struct Soc *soc;
};

struct ThreadInfo {
	unsigned long pad[2];
	struct Thread *list;
};

struct NetVars {
	unsigned char pad0[6];
	unsigned short eport;
};

extern struct ThreadInfo g_02150FEC;
extern struct NetVars g_021A826C;

unsigned short func_0215A970(void)
{
	unsigned long conflict;
	struct Soc *soc;
	struct Thread *t;

	do {
		conflict = 0;
		g_021A826C.eport++;
		if (g_021A826C.eport < 0x400 || g_021A826C.eport >= 5000)
			g_021A826C.eport = 0x400;
		for (t = g_02150FEC.list; t != 0; t = t->next) {
			soc = t->soc;
			if (soc != 0 && soc->thread != 0 && soc->local_port == g_021A826C.eport) {
				conflict = 1;
				break;
			}
		}
	} while (conflict);
	return g_021A826C.eport;
}
