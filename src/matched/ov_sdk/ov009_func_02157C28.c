/*
 * function: CPSi_RecvCallbackFunc
 * address:  0x02157C28
 * packet:   pkt_ov009_02157C28
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_RecvCallbackFunc (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   put_in_buffer  0x02157A44  arm  ov009
 *   OS_IsThreadTerminated  0x0208574C  arm
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   g_021A826C  0x021A826C  data
 * note: volatile in this file is a matching device (it forces the reload the
 *   original performs); the vendor DWARF declares the object without volatile.
 */

struct net_vars {
    char pad0[0x54];
    void *volatile thread;
};

extern struct net_vars g_021A826C;
extern void put_in_buffer(unsigned char *src, unsigned char *dst, unsigned char *buf1, unsigned long size1, unsigned char *buf2, unsigned long size2);
extern int OS_IsThreadTerminated(void *thread);
extern void OS_WakeupThreadDirect(void *thread);

void CPSi_RecvCallbackFunc(unsigned char *srcAddr, unsigned char *dstAddr, unsigned char *buf, unsigned int size)
{
    put_in_buffer(srcAddr, dstAddr, buf, size, 0, 0);
    if (g_021A826C.thread != 0 && !OS_IsThreadTerminated(g_021A826C.thread))
        OS_WakeupThreadDirect(g_021A826C.thread);
}
