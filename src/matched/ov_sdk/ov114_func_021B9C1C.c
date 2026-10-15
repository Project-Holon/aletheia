/*
 * function: NHTTPi_CheckCurrentThread
 * address:  0x021B9C1C
 * packet:   pkt_ov114_021B9C1C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_CheckCurrentThread (libnhttp.TWL.HYB.a(nhttp_os_ntr.o))
 *
 * symbols:
 *   OS_Terminate 0x02088234 arm
 *   gMslRefToken 0x02150FEC data
 */

typedef struct {
    char pad[0x2c];
    int commThread;
} ThreadInfo;

typedef struct {
    int pad;
    int *current;
} OSInfo;

extern OSInfo gMslRefToken;
extern void OS_Terminate(void);

void NHTTPi_CheckCurrentThread(ThreadInfo *threadInfo_p, int is)
{
    int *commThread_p = &threadInfo_p->commThread;
    int *cur = gMslRefToken.current;

    if (cur) {
        if ((is == 0 && cur != commThread_p) || (is != 0 && cur == commThread_p)) {
            OS_Terminate();
        }
    }
}
