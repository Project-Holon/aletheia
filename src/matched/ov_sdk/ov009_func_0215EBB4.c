/*
 * function: func_0215EBB4
 * address:  0x0215EBB4
 * packet:   pkt_ov009_0215EBB4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_TrashSocket (libsoc.TWL.HYB.a(socl_close.o))
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   func_0215EA1C  0x0215EA1C  arm  ov009
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   g_021AA4B8  0x021AA4B8  data
 */

extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void func_0215EA1C(void *socket);
extern void *g_021AA4B8;

void func_0215EBB4(void)
{
	unsigned long enable;

	enable = OS_DisableInterrupts();
	while (g_021AA4B8 != 0)
		func_0215EA1C(g_021AA4B8);
	OS_RestoreInterrupts(enable);
}
