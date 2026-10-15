/*
 * function: CPS_SocGetEport
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
 *   gMslRefToken  0x02150FEC  data
 *   gCpsNetVars  0x021A826C  data
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

extern struct ThreadInfo gMslRefToken;
extern struct NetVars gCpsNetVars;

unsigned short CPS_SocGetEport(void)
{
	unsigned long conflict;
	struct Soc *soc;
	struct Thread *t;

	do {
		conflict = 0;
		gCpsNetVars.eport++;
		if (gCpsNetVars.eport < 0x400 || gCpsNetVars.eport >= 5000)
			gCpsNetVars.eport = 0x400;
		for (t = gMslRefToken.list; t != 0; t = t->next) {
			soc = t->soc;
			if (soc != 0 && soc->thread != 0 && soc->local_port == gCpsNetVars.eport) {
				conflict = 1;
				break;
			}
		}
	} while (conflict);
	return gCpsNetVars.eport;
}
