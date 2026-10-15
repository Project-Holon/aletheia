/*
 * function: ProcessPlayerAuth
 * address:  0x021940DC
 * packet:   pkt_ov009_021940DC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ProcessPlayerAuth (gstats.o)
 *
 * symbols:
 *   value_for_key_safe 0x02193FD0  arm
 *   atoi 0x020964E0  arm
 *   FindRequest 0x0219405C  arm
 *   func_02184208 0x02184208  arm
 *   CallReqCallback 0x0219451C  arm
 *   gGstatsKeyPauthr   0x021A5898  data
 *   gGstatsKeyLid   0x021A58A0  data
 *   gGstatsKeyErrmsg   0x021A58A4  data
 *   gGstatsConn   0x021ADFE0  data
 */

#include "../include/G_StatsConn.h"

extern char *value_for_key_safe(char *s, char *key);
typedef unsigned int   u32;
extern int atoi(u32 a0);
extern int FindRequest(int reqtype, int localid, int profileid);
extern int *func_02184208(void *array, int n);
extern void CallReqCallback(int reqindex, int success, long modified, char *data, int length);
extern char gGstatsKeyPauthr[];
extern char gGstatsKeyLid[];
extern char gGstatsKeyErrmsg[];
extern struct StatsConn gGstatsConn;

void ProcessPlayerAuth(char *buf)
{
    int reqindex;
    char *errmsg;
    int pid;
    int lid;

    pid = atoi((u32)value_for_key_safe(buf, gGstatsKeyPauthr));
    lid = atoi((u32)value_for_key_safe(buf, gGstatsKeyLid));
    errmsg = value_for_key_safe(buf, gGstatsKeyErrmsg);
    reqindex = FindRequest(0, lid, 0);
    if (reqindex == -1)
        return;
    func_02184208((void *)((int *)&gGstatsConn)[5], reqindex)[2] = pid;
    CallReqCallback(reqindex, pid > 0, 0, errmsg, 0);
}
