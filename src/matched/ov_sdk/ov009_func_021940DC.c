/*
 * function: func_021940DC
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
 *   func_02193FD0 0x02193FD0  arm
 *   func_020964E0 0x020964E0  arm
 *   func_0219405C 0x0219405C  arm
 *   func_02184208 0x02184208  arm
 *   func_0219451C 0x0219451C  arm
 *   g_021A5898   0x021A5898  data
 *   g_021A58A0   0x021A58A0  data
 *   g_021A58A4   0x021A58A4  data
 *   g_021ADFE0   0x021ADFE0  data
 */

extern char *func_02193FD0(char *s, char *key);
typedef unsigned int   u32;
extern int func_020964E0(u32 a0);
extern int func_0219405C(int reqtype, int localid, int profileid);
extern int *func_02184208(void *array, int n);
extern void func_0219451C(int reqindex, int success, long modified, char *data, int length);
extern char g_021A5898[];
extern char g_021A58A0[];
extern char g_021A58A4[];
extern int g_021ADFE0[];

void func_021940DC(char *buf)
{
    int reqindex;
    char *errmsg;
    int pid;
    int lid;

    pid = func_020964E0((u32)func_02193FD0(buf, g_021A5898));
    lid = func_020964E0((u32)func_02193FD0(buf, g_021A58A0));
    errmsg = func_02193FD0(buf, g_021A58A4);
    reqindex = func_0219405C(0, lid, 0);
    if (reqindex == -1)
        return;
    func_02184208((void *)g_021ADFE0[5], reqindex)[2] = pid;
    func_0219451C(reqindex, pid > 0, 0, errmsg, 0);
}
