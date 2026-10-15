/*
 * function: ProcessSetData
 * address:  0x02194308
 * packet:   pkt_ov009_02194308
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ProcessSetData (gstats.o)
 *
 * symbols:
 *   value_for_key_safe 0x02193FD0  arm
 *   atoi 0x020964E0  arm
 *   FindRequest 0x0219405C  arm
 *   CallReqCallback 0x0219451C  arm
 *   gGstatsKeySetpdr   0x021A58D4  data
 *   gGstatsKeyPid   0x021A58BC  data
 *   gGstatsKeyLid   0x021A58A0  data
 *   gGstatsKeyMod   0x021A58C0  data
 */

extern char *value_for_key_safe(char *s, char *key);
typedef unsigned int   u32;
extern int atoi(u32 a0);
extern int FindRequest(int reqtype, int localid, int profileid);
extern void CallReqCallback(int reqindex, int success, long modified, char *data, int length);
extern char gGstatsKeySetpdr[];
extern char gGstatsKeyPid[];
extern char gGstatsKeyLid[];
extern char gGstatsKeyMod[];

void ProcessSetData(char *buf)
{
    int success;
    int pid;
    int lid;
    int modified;
    int reqindex;

    success = atoi((u32)value_for_key_safe(buf, gGstatsKeySetpdr));
    pid = atoi((u32)value_for_key_safe(buf, gGstatsKeyPid));
    lid = atoi((u32)value_for_key_safe(buf, gGstatsKeyLid));
    modified = atoi((u32)value_for_key_safe(buf, gGstatsKeyMod));
    reqindex = FindRequest(2, lid, pid);
    if (reqindex == -1)
        return;
    CallReqCallback(reqindex, success, modified, 0, 0);
}
