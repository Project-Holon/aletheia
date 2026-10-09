/*
 * file:     unit_021573C4_p05.c
 * unit:     yes
 * function: func_02157C28
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
 *   func_02157A44  0x02157A44  arm  ov009
 *   func_0208574C  0x0208574C  arm
 *   func_02085868  0x02085868  arm
 *   g_021A826C  0x021A826C  data
 * note: volatile in this file is a matching device (it forces the reload the
 *   original performs); the vendor DWARF declares the object without volatile.
 */

struct net_vars {
    char pad0[0x54];
    void *volatile thread;
};

extern struct net_vars g_021A826C;
extern void func_02157A44(unsigned char *src, unsigned char *dst, unsigned char *buf1, unsigned long size1, unsigned char *buf2, unsigned long size2);
extern int func_0208574C(void *thread);
extern void func_02085868(void *thread);

/*
 * sdk:      CPSi_RecvCallbackFunc (libcps.TWL.HYB.a(network.o))
 *
 * note: volatile in this file is a matching device (it forces the reload the
 *   original performs); the vendor DWARF declares the object without volatile.
 */
void func_02157C28(unsigned char *srcAddr, unsigned char *dstAddr, unsigned char *buf, unsigned int size)
{
    func_02157A44(srcAddr, dstAddr, buf, size, 0, 0);
    if (g_021A826C.thread != 0 && !func_0208574C(g_021A826C.thread))
        func_02085868(g_021A826C.thread);
}
