/*
 * file:     unit_0215CA8C_p01.c
 * unit:     yes
 * function: func_0215CCA0, func_0215CD0C, func_0215CD24
 * address:  0x0215CCA0
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
 *   g_021A1CD8  0x021A1CD8  data
 *   g_021A82BC  0x021A82BC  data
 *   g_021A827C  0x021A827C  data
 *   g_021A8298  0x021A8298  data
 *   g_021A82DC  0x021A82DC  data
 *   g_021AA440  0x021AA440  data
 *   func_02166384  0x02166384  arm  ov009
 */
#include "../../matched/include/G_021A1CD8.h"

extern unsigned char *func_02166384(void);
void func_0215CCA0(void);
asm void SOCLi_DhcpTimeout(void);
int func_0215CD24(void);
extern struct G_021A1CD8 *g_021A1CD8;
extern unsigned long g_021A82BC;
extern unsigned long g_021A827C;
extern unsigned long g_021A8298;
extern unsigned long g_021A82DC[2];
extern unsigned long g_021AA440[3];


/*
 * sdk:      SOCLi_SetMyIP (libsoc.TWL.HYB.a(socl_startup.o))
 */
void func_0215CCA0(void)
{
	g_021A82BC = g_021A1CD8->myIp;
	g_021A827C = g_021A1CD8->netMask;
	g_021A8298 = g_021A1CD8->gatewayIp;
	g_021A82DC[0] = g_021A1CD8->dnsIp[0];
	g_021A82DC[1] = g_021A1CD8->dnsIp[1];
	g_021AA440[2] |= 2;
}

asm void SOCLi_DhcpTimeout(void)
{
	ldr r0, =0x021AA440
	ldr r1, [r0, #8]
	orr r1, r1, #2
	str r1, [r0, #8]
	bx lr
}


/*
 * Non-zero test on the word call.
 */
int func_0215CD24(void)
{
    return func_02166384() != 0;
}
