/*
 * function: DWCi_RAKUlInit
 * address:  0x021C1488
 * packet:   pkt_ov016_021C1488
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_RAKUlInit (libdwcutil.TWL.HYB.a(rakuraku.o))
 *
 * symbols:
 *   DWCi_HEAPlAllocEx  0x021D6414  arm  ov016
 *   func_021BC63C  0x021BC63C  thumb  ov016
 *   OS_Terminate  0x02088234  arm
 *   OS_Sleep  0x02085A38  arm
 *   gRakuStatus  0x021DE594  data
 *   DWCi_RAKUl_memFree  0x021C1624  arm  ov016
 *   DWCi_RakurakuCbConfig  0x021C15FC  arm  ov016
 *   DWCi_RakurakuMemAlloc  0x021C1614  arm  ov016
 */

extern void *DWCi_HEAPlAllocEx(unsigned long size, int align);
extern int func_021BC63C(int prio, int maxap, void (*notify)(void *), void *(*alloc)(unsigned long), void (*free)(void *), unsigned long stack);
extern void OS_Terminate(void);
extern void OS_Sleep(unsigned long msec);
extern void DWCi_RAKUl_memFree(void *ptr);
extern void DWCi_RakurakuCbConfig(void *arg);
extern void *DWCi_RakurakuMemAlloc(unsigned long size);
extern void *gRakuStatus;

void DWCi_RAKUlInit(void)
{
	gRakuStatus = DWCi_HEAPlAllocEx(0xc, -4);
	if (func_021BC63C(0xf, 0x40, DWCi_RakurakuCbConfig, DWCi_RakurakuMemAlloc, DWCi_RAKUl_memFree, 0x800) != 1)
		OS_Terminate();
	OS_Sleep(10);
}
