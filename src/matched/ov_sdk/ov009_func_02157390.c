/*
 * function: OS_YieldThread__
 * address:  0x02157390
 * packet:   pkt_ov009_02157390
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * sdk:      OS_YieldThread__ (libcps.TWL.HYB.a network.o)
 * symbols:
 *   OS_YieldThread                   0x020858d8 arm
 *   OS_Sleep                         0x02085a38 arm
 *   wfailed                          0x021a826c data
 */

extern void OS_YieldThread(void);
extern void OS_Sleep(unsigned long msec);
extern unsigned char wfailed;

static void OS_YieldThread__(void)
{
	unsigned long w = *(unsigned long *)((char *)&wfailed + 0x24);

	if (w == 0)
		OS_YieldThread();
	else
		OS_Sleep(w);
}

