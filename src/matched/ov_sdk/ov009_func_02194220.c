/*
 * function: ProcessGetData
 * address:  0x02194220
 * packet:   pkt_ov009_02194220
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ProcessGetData (gstats.o)
 *
 * symbols:
 *   value_for_key_safe 0x02193FD0  arm
 *   func_020964E0 0x020964E0  arm
 *   FindRequest 0x0219405C  arm
 *   func_02094B20 0x02094B20  arm
 *   CallReqCallback 0x0219451C  arm
 *   gGstatsKeyGetpdr   0x021A58B4  data
 *   gGstatsKeyLid   0x021A58A0  data
 *   gGstatsKeyPid   0x021A58BC  data
 *   gGstatsKeyMod   0x021A58C0  data
 *   gGstatsKeyLength   0x021A58C4  data
 *   gGstatsKeyData   0x021A58CC  data
 *   gGstatsEmptyString   0x021A5890  data
 */

extern char *value_for_key_safe(char *s, char *key);
typedef unsigned int   u32;
extern int func_020964E0(u32 a0);
extern int FindRequest(int reqtype, int localid, int profileid);
extern char *func_02094B20(const char *s, const char *sub);
extern void CallReqCallback(int reqindex, int success, long modified, char *data, int length);
extern char gGstatsKeyGetpdr[];
extern char gGstatsKeyLid[];
extern char gGstatsKeyPid[];
extern char gGstatsKeyMod[];
extern char gGstatsKeyLength[];
extern char gGstatsKeyData[];
extern char gGstatsEmptyString[];

void ProcessGetData(char *buf)
{
    int reqindex;
    int pid;
    int lid;
    int success;
    int length;
    long modified;
    char *data;

    success = func_020964E0((u32)value_for_key_safe(buf, gGstatsKeyGetpdr));
    lid = func_020964E0((u32)value_for_key_safe(buf, gGstatsKeyLid));
    pid = func_020964E0((u32)value_for_key_safe(buf, gGstatsKeyPid));
    modified = func_020964E0((u32)value_for_key_safe(buf, gGstatsKeyMod));
    reqindex = FindRequest(1, lid, pid);
    if (reqindex == -1)
        return;
    length = func_020964E0((u32)value_for_key_safe(buf, gGstatsKeyLength));
    data = func_02094B20(buf, gGstatsKeyData);
    if (data == 0) {
        data = gGstatsEmptyString;
        length = 0;
    } else
        data += 6;
    CallReqCallback(reqindex, success, modified, data, length);
}
