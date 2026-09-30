/*
 * function: func_0219C5B8
 * address:  0x0219C5B8
 * packet:   pkt_ov009_0219C5B8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      qr2_process_ip_verify (libdwcgsqr2.TWL.HYB.a qr2.o)
 *
 * symbols:
 *   current_time       0x0217F264  arm  ov009
 *   qr2_buffer_add_int 0x0219B628  arm  ov009
 *   rand               0x02094694  arm  ov009
 *
 * The vendor's own spelling: the declarations carry their initialisers in the
 * vendor's order (i, now, firstFreeIndex, numDuplicates) and the loop's init is
 * empty, which is what puts i in r5 and numDuplicates in r0.
 */

typedef struct SOCInAddr {
	unsigned int addr;
} SOCInAddr;

typedef struct SOCSockAddrIn {
	unsigned char len;
	unsigned char family;
	unsigned short port;
	SOCInAddr addr;
} SOCSockAddrIn;

struct qr2_buffer_s;
struct qr2_keybuffer_s;

typedef struct qr2_ipverify_info_s {
	SOCSockAddrIn addr;
	unsigned int challenge;
	unsigned int time;
} qr2_ipverify_info_s;

typedef struct qr2_implementation_s {
	int hbsock;
	char gamename[64];
	char secret_key[64];
	char instance_key[4];
	void (*server_key_callback)(int, struct qr2_buffer_s *, void *);
	void (*player_key_callback)(int, int, struct qr2_buffer_s *, void *);
	void (*team_key_callback)(int, int, struct qr2_buffer_s *, void *);
	void (*key_list_callback)(int, struct qr2_keybuffer_s *, void *);
	int (*playerteam_count_callback)(int, void *);
	void (*adderror_callback)(int, char *, void *);
	void (*nn_callback)(int, void *);
	void (*cm_callback)(char *, int, void *);
	void (*pa_callback)(unsigned int, unsigned short, void *);
	void (*cc_callback)(int, SOCSockAddrIn *, void *);
	void (*hr_callback)(void *);
	unsigned int lastheartbeat;
	unsigned int lastka;
	int userstatechangerequested;
	int listed_state;
	int ispublic;
	int qport;
	int read_socket;
	int nat_negotiate;
	SOCSockAddrIn hbaddr;
	void (*cdkeyprocess)(char *, int, void *);
	int client_message_keys[10];
	int cur_message_key;
	unsigned int publicip;
	unsigned short publicport;
	void *udata;
	unsigned char backendoptions;
	qr2_ipverify_info_s ipverify[200];
} qr2_implementation_s;

extern unsigned int current_time(void);
extern int qr2_buffer_add_int(struct qr2_buffer_s *outbuf, int value);
extern int rand(void);

#define QR2_OPTION_USE_QUERY_CHALLENGE 0x80
#define QR2_IPVERIFY_ARRAY_SIZE 200
#define QR2_IPVERIFY_MAXDUPLICATES 5

/* SOC_HtoNl, nitroWiFi/soc.h */
#define SOC_HtoNl(hostlong) \
	( \
		(unsigned int) \
			( \
				(((unsigned int)(hostlong) >> 24) & 0x000000ff) | (((unsigned int)(hostlong) >> 8) & 0x0000ff00) | \
					(((unsigned int)(hostlong) << 8) & 0x00ff0000) | (((unsigned int)(hostlong) << 24) & 0xff000000) \
			) \
	)

int func_0219C5B8(qr2_implementation_s *qrec, struct qr2_buffer_s *buf, SOCSockAddrIn *sender)
{
	int i = 0;
	unsigned int now = current_time();
	int firstFreeIndex = -1;
	int numDuplicates = 0;

	/* if the query challenge is disabled, return 0 as the challenge */
	if ((qrec->backendoptions & QR2_OPTION_USE_QUERY_CHALLENGE) == 0)
	{
		qr2_buffer_add_int(buf, 0);
		return 1;
	}

	/* check if this ip/port combo is already in the list */
	for (; i < QR2_IPVERIFY_ARRAY_SIZE; i++)
	{
		/* Mark the first free index when/if found */
		if (firstFreeIndex == -1 && qrec->ipverify[i].addr.addr.addr == 0)
			firstFreeIndex = i;
		/* Count any indexes that match this IP/port */
		if (qrec->ipverify[i].addr.addr.addr == sender->addr.addr &&
			qrec->ipverify[i].addr.port == sender->port)
		{
			numDuplicates++;
		}
	}

	/* discard if too many duplicates or no index found */
	if (numDuplicates > QR2_IPVERIFY_MAXDUPLICATES)
		return 0;
	if (firstFreeIndex == -1)
		return 0; /* no free indexes */

	/* create a random challenge for this ip/port combo */
	qrec->ipverify[firstFreeIndex].addr = *sender;
	qrec->ipverify[firstFreeIndex].challenge = SOC_HtoNl((rand() << 16) | rand());
	qrec->ipverify[firstFreeIndex].time = now;

	qr2_buffer_add_int(buf, (int)qrec->ipverify[firstFreeIndex].challenge);
	return 1; /* buffer ready to be sent */
}
