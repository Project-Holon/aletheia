/*
 * function: ClosePendingCallbacks
 * address:  0x02194614
 * packet:   pkt_ov009_02194614
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ClosePendingCallbacks (gstats.o)
 *
 * Byte-correct (224/224); the connerror\ninitializer copies from the vendor template @14079 at 0x021A1A54 in ov009 data,\nattested by the `template` class (unique in ov009).\nA struct copy from an extern spelling was tried: one copy instead of two, DIFF.
 *
 * symbols:
 *   ArrayLength 0x02184200  arm
 *   xcode_buf 0x02193EB8  arm
 *   CallReqCallback 0x0219451C  arm
 *   func_021841B0 0x021841B0  arm
 *   gGstatsConn   0x021ADFE0  data
 *   @14079       0x021A1A54  data
 *   gGstatsCryptKey   0x021A5800  data
 *   gGstatsSocket   0x021A57C8  data
 */

#include "../include/G_StatsSocket.h"
#include "../include/G_StatsConn.h"

extern int ArrayLength(const int *p);
extern void xcode_buf(char *buf, int len);
extern void CallReqCallback(int reqindex, int success, long modified, char *data, int length);
extern void func_021841B0(void *array);
extern struct StatsConn gGstatsConn;
extern struct StatsSocket gGstatsSocket;
extern char gGstatsCryptKey[];

void ClosePendingCallbacks(void)
{
    int i;

    if (((int *)&gGstatsConn)[5] == 0)
        return;
    for (i = ArrayLength((void *)((int *)&gGstatsConn)[5]) - 1; i >= 0; i--) {
        char connerror[16] = {0x13, 0x1d, 0x01, 0x04, 0, 0, 0, 0x28, 0x1f, 0x06, 0x45, 0x34, 0x3f, 0x01, 0x1b, 0};
        (*(char * *)&gGstatsSocket) = gGstatsCryptKey;
        xcode_buf(connerror, 15);
        CallReqCallback(i, 0, 0, connerror, 0);
    }
    func_021841B0((void *)((int *)&gGstatsConn)[5]);
    ((int *)&gGstatsConn)[5] = 0;
}
