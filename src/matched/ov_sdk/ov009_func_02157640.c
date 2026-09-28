/*
 * function: func_02157640
 * address:  0x02157640
 * packet:   pkt_ov009_02157640
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPS_Cleanup (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   func_021575DC  0x021575DC  arm  ov009
 *   func_02085710  0x02085710  arm
 *   func_020855BC  0x020855BC  arm
 *   func_020873F8  0x020873F8  arm
 *   func_02087988  0x02087988  arm
 *   func_0208574C  0x0208574C  arm
 *   func_02085868  0x02085868  arm
 *   func_0208799C  0x0208799C  arm
 *   func_02157290  0x02157290  arm  ov009
 *   g_021A85E4  0x021A85E4  data
 *   g_021A86A4  0x021A86A4  data
 *   g_021A82FC  0x021A82FC  data
 *   g_021A8524  0x021A8524  data
 *   g_021A826C  0x021A826C  data
 */

extern char g_021A85E4[];
extern char g_021A86A4[];
extern char g_021A82FC[];
extern char g_021A8524[];
extern char g_021A826C[];
extern int func_021575DC(void);
extern void func_02085710(void *thread);
extern void func_020855BC(void *thread);
extern void func_020873F8(void *alarm);
extern unsigned long func_02087988(void);
extern int func_0208574C(void *thread);
extern void func_02085868(void *thread);
extern unsigned long func_0208799C(unsigned long state);
extern void func_02157290(int arg);

void func_02157640(void)
{
    unsigned long enable;

    func_021575DC();
    func_02085710(g_021A85E4);
    func_020855BC(g_021A86A4);
    func_020873F8(g_021A82FC);
    enable = func_02087988();
    if (!func_0208574C(g_021A8524))
        func_02085868(g_021A8524);
    func_0208799C(enable);
    func_02085710(g_021A8524);
    *(unsigned long *)(g_021A826C + 0x54) = 0;
    func_02157290(0);
    *(unsigned long *)(g_021A826C + 0x20) = 0;
    *(unsigned long *)(g_021A826C + 0x5c) = 0;
}
