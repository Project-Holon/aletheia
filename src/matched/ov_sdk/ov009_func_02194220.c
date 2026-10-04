/*
 * function: func_02194220
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
 *   func_02193FD0 0x02193FD0  arm
 *   func_020964E0 0x020964E0  arm
 *   func_0219405C 0x0219405C  arm
 *   func_02094B20 0x02094B20  arm
 *   func_0219451C 0x0219451C  arm
 *   g_021A58B4   0x021A58B4  data
 *   g_021A58A0   0x021A58A0  data
 *   g_021A58BC   0x021A58BC  data
 *   g_021A58C0   0x021A58C0  data
 *   g_021A58C4   0x021A58C4  data
 *   g_021A58CC   0x021A58CC  data
 *   g_021A5890   0x021A5890  data
 */

extern char *func_02193FD0(char *s, char *key);
typedef unsigned int   u32;
extern int func_020964E0(u32 a0);
extern int func_0219405C(int reqtype, int localid, int profileid);
extern char *func_02094B20(const char *s, const char *sub);
extern void func_0219451C(int reqindex, int success, long modified, char *data, int length);
extern char g_021A58B4[];
extern char g_021A58A0[];
extern char g_021A58BC[];
extern char g_021A58C0[];
extern char g_021A58C4[];
extern char g_021A58CC[];
extern char g_021A5890[];

void func_02194220(char *buf)
{
    int reqindex;
    int pid;
    int lid;
    int success;
    int length;
    long modified;
    char *data;

    success = func_020964E0((u32)func_02193FD0(buf, g_021A58B4));
    lid = func_020964E0((u32)func_02193FD0(buf, g_021A58A0));
    pid = func_020964E0((u32)func_02193FD0(buf, g_021A58BC));
    modified = func_020964E0((u32)func_02193FD0(buf, g_021A58C0));
    reqindex = func_0219405C(1, lid, pid);
    if (reqindex == -1)
        return;
    length = func_020964E0((u32)func_02193FD0(buf, g_021A58C4));
    data = func_02094B20(buf, g_021A58CC);
    if (data == 0) {
        data = g_021A5890;
        length = 0;
    } else
        data += 6;
    func_0219451C(reqindex, success, modified, data, length);
}
