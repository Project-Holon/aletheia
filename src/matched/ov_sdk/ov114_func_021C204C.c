/*
 * function: ghttpCleanup
 * address:  0x021C204C
 * packet:   pkt_ov114_021C204C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghttpCleanup (libdwcgsghttp.TWL.HYB.a(ghttpmain.o))
 *
 * symbols:
 *   ghiLock  0x021C0370  arm  ov114
 *   ghiCleanupConnections  0x021C0FB0  arm  ov114
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   ghiUnlock  0x021C0374  arm  ov114
 *   ghiFreeLock  0x021C036C  arm  ov114
 *   gGhttpInitCount  0x021D3B64  data
 *   gGhttpProxyServer  0x021D3B2C  data
 */

extern void ghiLock(void);
extern void ghiCleanupConnections(void);
extern void func_0217EAE0(void *ptr);
extern void ghiUnlock(void);
extern void ghiFreeLock(void);
extern int gGhttpInitCount;
extern void *gGhttpProxyServer;

void ghttpCleanup(void)
{
	ghiLock();
	if (--gGhttpInitCount == 0) {
		ghiCleanupConnections();
		if (gGhttpProxyServer != 0) {
			func_0217EAE0(gGhttpProxyServer);
			gGhttpProxyServer = 0;
		}
		ghiUnlock();
		ghiFreeLock();
	} else {
		ghiUnlock();
	}
}
