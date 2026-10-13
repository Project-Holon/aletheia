/*
 * function: NET_WHPIPE_TaskStartParent
 * address: 0x02177CE4
 * packet: pkt_ov014_02177CE4
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_pWhPipeWork 0x021797A4 data ov014 a4
 *   func_02178E4C 0x02178E4C thumb ov014
 *   func_02178E84 0x02178E84 thumb ov014
 *   func_0217727C 0x0217727C thumb ov014
 *   NET_WHPIPE_TaskConnectParent 0x02177C4C thumb ov014
 */

extern unsigned char *g_pWhPipeWork;
extern int func_02178E4C(void);
extern int func_02178E84(void);
extern void func_0217727C(unsigned int *p, unsigned int v);
extern void NET_WHPIPE_TaskConnectParent(unsigned char *p);
void NET_WHPIPE_TaskStartParent(void) { if (func_02178E4C() == 1 && func_02178E84() != 0) func_0217727C((unsigned int *)g_pWhPipeWork, (unsigned int)NET_WHPIPE_TaskConnectParent); }
