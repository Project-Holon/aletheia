/*
 * function: func_0215F650
 * address:  0x0215F650
 * packet:   pkt_ov009_0215F650
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOC_GetHostByName (libsoc.TWL.HYB.a(soc.o))
 *
 * symbols:
 *   func_0215EDD0  0x0215EDD0  arm  ov009
 *   func_02082BCC  0x02082BCC  arm
 *   func_0208CB10  0x0208CB10  arm
 *   g_021AA544     0x021AA544  data
 *   g_021AA4BC     0x021AA4BC  data
 *   g_021AA4BC_ip  0x021AA4BC  data
 *   g_021AA4D4     0x021AA4D4  data
 *   g_021AA4DC     0x021AA4DC  data
 */

#define SWAP32(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | (((x) << 8) & 0xff0000) | (((x) << 24) & 0xff000000))

typedef struct {
	char *name;
	char **aliases;
	short addrType;
	short length;
	unsigned char **addrList;
} HostEnt;

extern unsigned long func_0215EDD0(const char *hostname);
extern void func_02082BCC(void *dstp, unsigned char data, unsigned long size);
extern int func_0208CB10(char *destp, const char *srcp, int siz);

typedef struct {
	unsigned long hostip;
	unsigned char gap[0x14];
	unsigned char *addrList[2];
	HostEnt hostent;
} Statics;

extern Statics g_021AA4BC;
extern unsigned long g_021AA4BC_ip;
extern unsigned char *g_021AA4D4[2];
extern HostEnt g_021AA4DC;
extern char g_021AA544[0x101];

HostEnt *func_0215F650(const char *name)
{
	unsigned long h;

	h = func_0215EDD0(name);
	if (h == 0) {
		return 0;
	}
	func_02082BCC(g_021AA544, 0, 0x101);
	func_0208CB10(g_021AA544, name, 0x101);
	g_021AA4BC.hostent.name = g_021AA544;
	g_021AA4BC.hostent.aliases = 0;
	g_021AA4BC.hostent.addrType = 2;
	g_021AA4BC.hostent.length = 4;
	g_021AA4BC.hostent.addrList = g_021AA4D4;
	g_021AA4BC.addrList[0] = (unsigned char *)&g_021AA4BC_ip;
	g_021AA4BC.addrList[1] = 0;
	g_021AA4BC.hostip = SWAP32(h);
	return &g_021AA4DC;
}
