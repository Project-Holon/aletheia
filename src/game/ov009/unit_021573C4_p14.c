/*
 * file:     unit_021573C4_p14.c
 * unit:     yes
 * function: func_021590BC, func_02159190
 * address:  0x021590BC
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
 *   g_02150FEC  0x02150FEC  data
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

struct _CPSSoc {
	unsigned char pad0[8];
	unsigned char state;
	unsigned char pad1;
	unsigned short local_port;
	unsigned char pad2[0xc];
	unsigned short remote_port;
	unsigned long remote_ip;
};

struct Soc *func_021590BC(unsigned char *iphdr, unsigned char *tcphdr);
extern struct ThreadInfo g_02150FEC;


/*
 * sdk:      check_listener (libcps.TWL.HYB.a network.o)
 */
struct Soc *func_021590BC(unsigned char *iphdr, unsigned char *tcphdr)
{
	struct Soc *soc;
	struct Thread *t;

	for (t = g_02150FEC.list; t != 0; t = t->next) {
		soc = t->soc;
		if (soc != 0 && soc->first != 0 && soc->state == 1 &&
		    soc->local_port == SWAP16(*(unsigned short *)(tcphdr + 2)) &&
		    (soc->remote_port == 0 || soc->remote_port == SWAP16(*(unsigned short *)tcphdr)) &&
		    (soc->remote_ip == 0 || soc->remote_ip == BE32(iphdr, 0xc)))
			return soc;
	}
	return 0;
}


static unsigned long check_socket(unsigned char *iphdr, unsigned char *tcphdr, struct _CPSSoc *soc)
{
	return (soc->state != 0xa && soc->state != 0xb) &&
	       soc->local_port == (unsigned short)((*(unsigned short *)(tcphdr + 2) >> 8) | (*(unsigned short *)(tcphdr + 2) << 8)) &&
	       soc->remote_port == (unsigned short)((*(unsigned short *)tcphdr >> 8) | (*(unsigned short *)tcphdr << 8)) &&
	       soc->remote_ip == (((unsigned long)(unsigned short)((*(unsigned short *)(iphdr + 0xc) >> 8) | (*(unsigned short *)(iphdr + 0xc) << 8)) << 16) |
	                          (unsigned short)((*(unsigned short *)(iphdr + 0xe) >> 8) | (*(unsigned short *)(iphdr + 0xe) << 8)));
}
