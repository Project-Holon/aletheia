/*
 * function: CPSi_SslConsume
 * address:  0x02162A94
 * packet:   pkt_ov009_02162A94
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_SslConsume (libssl.TWL.HYB.a ssl.o)
 * symbols:
 *   CPSiFree                         0x021a82b0 data
 */

struct _CPSSslConnection {
	unsigned char pad[0x824];
	void *buf;
	unsigned long avail;
	unsigned long acked;
};

struct _CPSSoc {
	unsigned char pad[0xc];
	struct _CPSSslConnection *con;
};

extern void (*CPSiFree)(void *ptr);

void CPSi_SslConsume(unsigned long len, struct _CPSSoc *soc)
{
	struct _CPSSslConnection *con = soc->con;

	if (len >= con->avail - con->acked) {
		if (con->buf != 0)
			CPSiFree(con->buf);
		con->buf = 0;
	} else {
		con->acked += len;
	}
}

