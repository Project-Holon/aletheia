/*
 * function: func_02194308
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
 *   func_02193FD0 0x02193FD0  arm
 *   func_020964E0 0x020964E0  arm
 *   func_0219405C 0x0219405C  arm
 *   func_0219451C 0x0219451C  arm
 *   g_021A58D4   0x021A58D4  data
 *   g_021A58BC   0x021A58BC  data
 *   g_021A58A0   0x021A58A0  data
 *   g_021A58C0   0x021A58C0  data
 */

extern char *func_02193FD0(char *s, char *key);
typedef unsigned int   u32;
extern int func_020964E0(u32 a0);
extern int func_0219405C(int reqtype, int localid, int profileid);
extern void func_0219451C(int reqindex, int success, long modified, char *data, int length);
extern char g_021A58D4[];
extern char g_021A58BC[];
extern char g_021A58A0[];
extern char g_021A58C0[];

void func_02194308(char *buf)
{
    int success;
    int pid;
    int lid;
    int modified;
    int reqindex;

    success = func_020964E0((u32)func_02193FD0(buf, g_021A58D4));
    pid = func_020964E0((u32)func_02193FD0(buf, g_021A58BC));
    lid = func_020964E0((u32)func_02193FD0(buf, g_021A58A0));
    modified = func_020964E0((u32)func_02193FD0(buf, g_021A58C0));
    reqindex = func_0219405C(2, lid, pid);
    if (reqindex == -1)
        return;
    func_0219451C(reqindex, success, modified, 0, 0);
}
