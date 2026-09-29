/*
 * function: func_021B9C1C
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
 *   func_02088234 0x02088234 arm
 *   g_02150FEC 0x02150FEC data
 */

typedef struct {
    char pad[0x2c];
    int commThread;
} ThreadInfo;

typedef struct {
    int pad;
    int *current;
} OSInfo;

extern OSInfo g_02150FEC;
extern void func_02088234(void);

void func_021B9C1C(ThreadInfo *threadInfo_p, int is)
{
    int *commThread_p = &threadInfo_p->commThread;
    int *cur = g_02150FEC.current;

    if (cur) {
        if ((is == 0 && cur != commThread_p) || (is != 0 && cur == commThread_p)) {
            func_02088234();
        }
    }
}
