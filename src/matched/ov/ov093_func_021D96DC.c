/*
 * function: func_021D96DC
 * address: 0x021D96DC
 * packet: pkt_ov093_021D96DC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D96FC 0x021D96FC thumb ov093
 */
extern int func_021D775C(int);
extern void func_021D96FC(void *a, int b, int c);
void func_021D96DC(int a,int b,int c) { if(b==func_021D775C(2)) func_021D96FC((void *)a,b,c); }
