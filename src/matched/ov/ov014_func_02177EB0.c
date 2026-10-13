/*
 * unit: yes
 * function: NET_WHPIPE_RequestEnd, NET_WHPIPE_AcceptChild, NET_WHPIPE_RejectChild
 * address: 0x02177EB0
 * packet: pkt_ov014_02177EB0
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_pWhPipeWork 0x021797A4 data ov014 a4
 *   func_02179570 0x02179570 thumb ov014
 *   func_0217727C 0x0217727C thumb ov014
 *   NET_WHPIPE_TaskFinishEnd 0x02177E9C thumb ov014
 */

extern unsigned char *g_pWhPipeWork;
extern int func_02179570(void (*cb)(int));
extern void func_0217727C(unsigned int *p, unsigned int v);
extern void NET_WHPIPE_TaskFinishEnd(void);
int NET_WHPIPE_RequestEnd(int a) { if (func_02179570((void (*)(int))a) != 0) { func_0217727C((unsigned int *)g_pWhPipeWork, (unsigned int)NET_WHPIPE_TaskFinishEnd); return 1; } return 0; }
int NET_WHPIPE_AcceptChild(void) { return 1; }
int NET_WHPIPE_RejectChild(void) { return 0; }
