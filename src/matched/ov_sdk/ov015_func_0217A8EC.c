/*
 * function: func_0217A8EC
 * address:  0x0217A8EC
 * packet:   pkt_ov015_0217A8EC
 * region:   ov015
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      IRCi_Write (libirc.a irc_internal.o)
 *
 * symbols:
 *   func_02075E9C  0x02075E9C  arm
 *   func_02084DF4  0x02084DF4  arm
 *   func_0217A674  0x0217A674  arm  ov015
 *   func_0217A5B4  0x0217A5B4  arm  ov015
 *   OS_UnLockCard  0x02084E2C  arm
 *   func_02075EAC  0x02075EAC  arm
 *   g_0217AD58     0x0217AD58  data
 *   g_0217AC90     0x0217AC90  data
 *   g_0217AC90_b   0x0217AC90  data
 *   g_0217AAB4     0x0217AAB4  data
 */

#include "../include/G_IRCParam.h"

typedef struct {
    int unk0;
    unsigned char *wp;
    unsigned char *rp;
} IRCParam;

extern void func_02075E9C(unsigned short lock_id);
extern long func_02084DF4(unsigned short lockID);
extern unsigned char func_0217A674(IRCParam *p);
extern void func_0217A5B4(void);
extern void OS_UnLockCard();
extern void func_02075EAC(unsigned short lock_id);
extern unsigned char g_0217AD58[181];
extern struct IRCParam g_0217AC90;
extern struct IRCParam g_0217AC90_b;
extern unsigned short g_0217AAB4;

void func_0217A8EC(unsigned char *data, unsigned char size)
{
    int i;
    int n;

    g_0217AC90.send = g_0217AD58;
    g_0217AC90.recv = 0;
    g_0217AD58[0] = 2;
    func_02075E9C(g_0217AAB4);
    func_02084DF4(g_0217AAB4);
    while (*(volatile unsigned short *)0x040001A0 & 0x80)
        ;
    *(volatile unsigned short *)0x040001A0 = 0xA042;
    func_0217A674(((IRCParam *)&g_0217AC90_b));
    func_0217A5B4();
    g_0217AC90.send = data;
    n = size;
    for (i = 0; (i < size) ? 1 : 0; i++) {
        if (i == n - 1)
            *(volatile unsigned short *)0x040001A0 = 0xA002;
        func_0217A674(((IRCParam *)&g_0217AC90_b));
    }
    while (*(volatile unsigned short *)0x040001A0 & 0x80)
        ;
    OS_UnLockCard(g_0217AAB4);
    func_02075EAC(g_0217AAB4);
}
