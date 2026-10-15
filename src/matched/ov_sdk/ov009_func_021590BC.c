/*
 * function: check_listener
 * address:  0x021590BC
 * packet:   pkt_ov009_021590BC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      check_listener (libcps.TWL.HYB.a network.o)
 *
 * symbols:
 *   gMslRefToken  0x02150FEC  data
 */

#define SWAP16(x) ((unsigned short)(((x) >> 8) | ((x) << 8)))
#define BE32(p, o) (((unsigned long)SWAP16(*(unsigned short *)((p) + (o))) << 16) | SWAP16(*(unsigned short *)((p) + (o) + 2)))

struct Soc {
	unsigned long first;
	unsigned char pad0[4];
	unsigned char state;
	unsigned char pad1;
	unsigned short local_port;
	unsigned char pad2[0xc];
	unsigned short remote_port;
	unsigned long remote_ip;
};

struct Thread {
	unsigned char pad0[0x68];
	struct Thread *next;
	unsigned char pad1[0x38];
	struct Soc *soc;
};

struct ThreadInfo {
	unsigned char pad0[8];
	struct Thread *list;
};

extern struct ThreadInfo gMslRefToken;

struct Soc *check_listener(unsigned char *iphdr, unsigned char *tcphdr)
{
	struct Soc *soc;
	struct Thread *t;

	for (t = gMslRefToken.list; t != 0; t = t->next) {
		soc = t->soc;
		if (soc != 0 && soc->first != 0 && soc->state == 1 &&
		    soc->local_port == SWAP16(*(unsigned short *)(tcphdr + 2)) &&
		    (soc->remote_port == 0 || soc->remote_port == SWAP16(*(unsigned short *)tcphdr)) &&
		    (soc->remote_ip == 0 || soc->remote_ip == BE32(iphdr, 0xc)))
			return soc;
	}
	return 0;
}
