/*
 * function: ghiHandleStatus
 * address:  0x021C1D30
 * packet:   pkt_ov114_021C1D30
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiHandleStatus (libdwcgsghttp.TWL.HYB.a(ghttpmain.o))
 */

typedef struct GHIConnection {
	unsigned char pad0[0x40];
	int state;
	unsigned char pad1[0xd4];
	int statusCode;
} GHIConnection;

void ghiHandleStatus(GHIConnection *connection)
{
	switch (connection->statusCode / 100) {
	case 1:
	case 2:
	case 3:
		return;
	case 4:
		switch (connection->statusCode) {
		case 401:
			connection->state = 9;
			break;
		case 403:
			connection->state = 10;
			break;
		case 404:
		case 410:
			connection->state = 11;
			break;
		default:
			connection->state = 8;
			break;
		}
		break;
	case 5:
		connection->state = 12;
		break;
	}
}
