/*
 * file:     cps_network_1.c
 * unit:     yes
 * function: func_02157280, func_02157290, func_02157390
 * address:  0x02157280
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
 *   MI_CpuFill8              0x02082BCC  arm
 *   OS_WakeupThreadDirect    0x02085868  arm
 *   CPSi_SslCleanup          0x02162FA4  arm  ov009
 *   wfailed                  0x021A826C  data
 *   checkNConfig_callback    0x021A82B4  data
 *   g_021A8384               0x021A8384  data
 *   g_02150FEC               0x02150FEC  data
 *   g_021A8A64               0x021A8A64  data
 *   OS_YieldThread                   0x020858d8 arm
 *   OS_Sleep                         0x02085a38 arm
 */
#include "../../matched/include/G_ArpEntry.h"
#include "../../matched/include/G_CPSFragTable.h"

struct _OSThread;
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void OS_WakeupThreadDirect(struct _OSThread *thread);
extern void CPSi_SslCleanup(void);
extern void OS_YieldThread(void);
extern void OS_Sleep(unsigned long msec);
void func_02157290(int reason);
extern struct ArpEntry g_021A8384;
extern int g_02150FEC;
extern struct CPSFragTable g_021A8A64[8];
extern unsigned char wfailed;

static unsigned char wfailed = 0;

static unsigned char ip_conflict = 0;

static unsigned short eport = 0;

static unsigned short mymss = 0;

static unsigned short pingseq = 0;

static unsigned short ipid = 0;

static unsigned long CPSMyIp = 0;

static int CPSNoIpReason = 0;

static void *checkNConfig_callback = 0;

static void (*CPSiFree)(void *) = 0;

static unsigned long sleep_save = 0;

static unsigned long lease_time = 0;

static void *scavenger_callback = 0;

static unsigned long offered_myip = 0;

static int scavenger_force_exit = 0;

static unsigned long wlan_buflen = 0;

static void *dhcp_callback = 0;

static int yield_wait = 0;

static void *wlan_buf = 0;

static unsigned long CPSDhcpServerIp = 0;

static int link_is_on = 0;

static unsigned long CPSGatewayIp = 0;

static void *receiver_thread = 0;

static unsigned long wlan_putpnt = 0;

static unsigned long CPSDhcpMode = 0;

static unsigned long CPSNetMask = 0;

static unsigned long xid = 0;

static unsigned long wlan_getpnt = 0;

static void *(*CPSiAlloc)(unsigned long) = 0;

static unsigned char CPSMyMac[6] = {0};

static unsigned long CPSDnsIp[2] = {0};


/*
 * Stores a word at +0x48 of the module state block.
 */
void func_02157280(void *callback)
{
	checkNConfig_callback = callback;
}

/*
 * closed (2026-10-01, ov SDK wave 2): network.o .bss is separate objects, not one
 *   struct: every small .bss variable is a zero-initialised file static (real names;
 *   pingseq/sleep_save are function-local statics of other functions, stand-ins here)
 *   whose definition order yields the vendor layout under 1.1p1's .bss reorder
 *   (order measured from a --keep object). With non-aliasing objects the reason store
 *   directly after the had_ip read schedules into the myip load delay as in the image.
 *
 * sdk:      reset_network_vars (libcps.TWL.HYB.a network.o)
 */
void func_02157290(int reason)
{
	struct _OSThread *t;
	unsigned char *soc;
	int i;
	int had_ip;

	had_ip = CPSMyIp != 0;
	CPSNoIpReason = reason;
	CPSMyIp = 0;
	CPSNetMask = 0;
	CPSGatewayIp = 0;
	CPSDnsIp[0] = 0;
	CPSDnsIp[1] = 0;
	CPSDhcpServerIp = 0;
	if (!had_ip)
		return;
	MI_CpuFill8(((unsigned char *)&g_021A8384), 0, 0x60);
	for (t = *(struct _OSThread **)((char *)&g_02150FEC + 8); t != 0; t = *(struct _OSThread **)((char *)t + 0x68)) {
		soc = *(unsigned char **)((char *)t + 0xa4);
		if (soc != 0 && *(struct _OSThread **)soc != 0) {
			if (soc[8] != 0xa && soc[8] != 0xb)
				soc[8] = 0;
			if (*(unsigned long *)(soc + 4) != 0) {
				*(unsigned long *)(soc + 4) = 0;
				OS_WakeupThreadDirect(*(struct _OSThread **)soc);
			}
		}
	}
	for (i = 0; i < 8; i++) {
		if (g_021A8A64[i].count != 0) {
			CPSiFree(g_021A8A64[i].buf);
			g_021A8A64[i].count = 0;
		}
	}
	CPSi_SslCleanup();
}


static void OS_YieldThread__(void)
{
	unsigned long w = *(unsigned long *)((char *)&wfailed + 0x24);

	if (w == 0)
		OS_YieldThread();
	else
		OS_Sleep(w);
}
