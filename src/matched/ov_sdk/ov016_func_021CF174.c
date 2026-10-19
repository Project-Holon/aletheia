/*
 * function: callback
 * address:  0x021CF174
 * packet:   pkt_ov016_021CF174
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      callback (libdwcutil.TWL.HYB.a(search.o))
 *
 * symbols:
 *   func_021CF1D4  0x021CF1D4  arm  ov016
 *   func_021CF04C  0x021CF04C  arm  ov016
 *   OS_Terminate  0x02088234  arm
 *   gSearchWork  0x021DE640  data
 */

typedef struct {
	char pad0[0x20];
	unsigned char essid[6];
	char pad1[4];
} APINFO;

typedef struct {
	char pad0[0x1300];
	APINFO ap[20];
	char scan[0x1e5c - 0x1300 - 20 * 0x2a];
	unsigned char flag;
	char pad1[3];
} MS;

typedef struct {
	unsigned short api;
	unsigned short err;
	unsigned short pad[2];
	unsigned short state;
} SCANCB;

extern void func_021CF1D4(SCANCB *prm);
extern int func_021CF04C(void);
extern void OS_Terminate(void);
extern MS *gSearchWork;

void callback(void *arg)
{
	SCANCB *prm = (SCANCB *)arg;

	if (prm->err != 0 || gSearchWork->flag != 0 || prm->api != 0x26)
		return;
	switch (prm->state) {
	case 5:
		func_021CF1D4(prm);
		func_021CF04C();
		break;
	case 4:
		func_021CF04C();
		break;
	default:
		OS_Terminate();
		break;
	}
}
