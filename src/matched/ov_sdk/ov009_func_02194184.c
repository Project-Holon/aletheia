/*
 * function: ProcessGetPid
 * address:  0x02194184
 * packet:   pkt_ov009_02194184
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ProcessGetPid (gstats.o)
 *
 * symbols:
 *   value_for_key_safe 0x02193FD0  arm
 *   func_020964E0 0x020964E0  arm
 *   FindRequest 0x0219405C  arm
 *   func_02184208 0x02184208  arm
 *   CallReqCallback 0x0219451C  arm
 *   gGstatsKeyGetpidr   0x021A58AC  data
 *   gGstatsKeyLid   0x021A58A0  data
 *   gGstatsConn   0x021ADFE0  data
 */

#include "../include/G_StatsConn.h"

extern char *value_for_key_safe(char *s, char *key);
typedef unsigned int   u32;
extern int func_020964E0(u32 a0);
extern int FindRequest(int reqtype, int localid, int profileid);
extern int *func_02184208(void *array, int n);
extern void CallReqCallback(int reqindex, int success, long modified, char *data, int length);
extern char gGstatsKeyGetpidr[];
extern char gGstatsKeyLid[];
extern struct StatsConn gGstatsConn;

void ProcessGetPid(char *buf)
{
    int lid;
    int pid;
    int reqindex;

    pid = func_020964E0((u32)value_for_key_safe(buf, gGstatsKeyGetpidr));
    lid = func_020964E0((u32)value_for_key_safe(buf, gGstatsKeyLid));
    reqindex = FindRequest(3, lid, 0);
    if (reqindex == -1)
        return;
    func_02184208((void *)((int *)&gGstatsConn)[5], reqindex)[2] = pid;
    CallReqCallback(reqindex, pid > 0, 0, 0, 0);
}
