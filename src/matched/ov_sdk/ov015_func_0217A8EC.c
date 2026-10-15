/*
 * function: IRCi_Write
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
 *   OS_LockCard  0x02084DF4  arm
 *   IRCi_CommWrite  0x0217A674  arm  ov015
 *   IRCi_WaitCommand  0x0217A5B4  arm  ov015
 *   OS_UnLockCard  0x02084E2C  arm
 *   CARD_UnlockBackup  0x02075EAC  arm
 *   gIrcWriteBuffer     0x0217AD58  data
 *   gIrcCommParamAlias2     0x0217AC90  data
 *   g_0217AC90_b   0x0217AC90  data
 *   gIrcLockId     0x0217AAB4  data
 */

#include "../include/G_IRCParam.h"

typedef struct {
    int unk0;
    unsigned char *wp;
    unsigned char *rp;
} IRCParam;

extern void func_02075E9C(unsigned short lock_id);
extern long OS_LockCard(unsigned short lockID);
extern unsigned char IRCi_CommWrite(IRCParam *p);
extern void IRCi_WaitCommand(void);
extern void OS_UnLockCard();
extern void CARD_UnlockBackup(unsigned short lock_id);
extern unsigned char gIrcWriteBuffer[181];
extern struct IRCParam gIrcCommParamAlias2;
extern struct IRCParam g_0217AC90_b;
extern unsigned short gIrcLockId;

void IRCi_Write(unsigned char *data, unsigned char size)
{
    int i;
    int n;

    gIrcCommParamAlias2.send = gIrcWriteBuffer;
    gIrcCommParamAlias2.recv = 0;
    gIrcWriteBuffer[0] = 2;
    func_02075E9C(gIrcLockId);
    OS_LockCard(gIrcLockId);
    while (*(volatile unsigned short *)0x040001A0 & 0x80)
        ;
    *(volatile unsigned short *)0x040001A0 = 0xA042;
    IRCi_CommWrite(((IRCParam *)&g_0217AC90_b));
    IRCi_WaitCommand();
    gIrcCommParamAlias2.send = data;
    n = size;
    for (i = 0; (i < size) ? 1 : 0; i++) {
        if (i == n - 1)
            *(volatile unsigned short *)0x040001A0 = 0xA002;
        IRCi_CommWrite(((IRCParam *)&g_0217AC90_b));
    }
    while (*(volatile unsigned short *)0x040001A0 & 0x80)
        ;
    OS_UnLockCard(gIrcLockId);
    CARD_UnlockBackup(gIrcLockId);
}
