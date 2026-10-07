/*
 * file:     unit_02193FF4_p01.c
 * unit:     yes
 * function: func_02193FF4, func_0219405C, func_021940DC, func_02194184, func_02194220
 * address:  0x02193FF4
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02184200 0x02184200  arm
 *   func_02184208 0x02184208  arm
 *   g_021ADFE0   0x021ADFE0  data
 *   func_02193FD0 0x02193FD0  arm
 *   func_020964E0 0x020964E0  arm
 *   func_0219451C 0x0219451C  arm
 *   g_021A5898   0x021A5898  data
 *   g_021A58A0   0x021A58A0  data
 *   g_021A58A4   0x021A58A4  data
 *   g_021A58AC   0x021A58AC  data
 *   func_02094B20 0x02094B20  arm
 *   g_021A58B4   0x021A58B4  data
 *   g_021A58BC   0x021A58BC  data
 *   g_021A58C0   0x021A58C0  data
 *   g_021A58C4   0x021A58C4  data
 *   g_021A58CC   0x021A58CC  data
 *   g_021A5890   0x021A5890  data
 */
#include "../../matched/include/G_StatsConn.h"

typedef unsigned int   u32;

extern int func_02184200(const int *p);
extern int *func_02184208(void *array, int n);
extern char *func_02193FD0(char *s, char *key);
extern int func_020964E0(u32 a0);
extern void func_0219451C(int reqindex, int success, long modified, char *data, int length);
extern char *func_02094B20(const char *s, const char *sub);
char *func_02193FF4(char *buff, int len);
int func_0219405C(int reqtype, int localid, int profileid);
void func_021940DC(char *buf);
void func_02194184(char *buf);
void func_02194220(char *buf);
extern struct StatsConn g_021ADFE0;
extern char g_021A5898[];
extern char g_021A58A0[];
extern char g_021A58A4[];
extern char g_021A58AC[];
extern char g_021A58B4[];
extern char g_021A58BC[];
extern char g_021A58C0[];
extern char g_021A58C4[];
extern char g_021A58CC[];
extern char g_021A5890[];

/*
 * sdk:      FindFinal (gstats.o)
 */
char *func_02193FF4(char *buff, int len)
{
    char *pos = buff;

    while (pos - buff < len - 6) {
        if (pos[0] == 0x5c && pos[1] == 'f' && pos[2] == 'i' && pos[3] == 'n' &&
            pos[4] == 'a' && pos[5] == 'l' && pos[6] == 0x5c)
            return pos;
        pos++;
    }
    return 0;
}


/*
 * sdk:      FindRequest (gstats.o)
 */
int func_0219405C(int reqtype, int localid, int profileid)
{
    int *req;
    int i;

    if (((int *)&g_021ADFE0)[5] == 0)
        return -1;
    for (i = 0; i < func_02184200((void *)((int *)&g_021ADFE0)[5]); i++) {
        req = func_02184208((void *)((int *)&g_021ADFE0)[5], i);
        if (req[0] == reqtype && req[1] == localid && req[2] == profileid)
            return i;
    }
    return -1;
}


/*
 * sdk:      ProcessPlayerAuth (gstats.o)
 */
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
    func_02184208((void *)((int *)&g_021ADFE0)[5], reqindex)[2] = pid;
    func_0219451C(reqindex, pid > 0, 0, errmsg, 0);
}


/*
 * sdk:      ProcessGetPid (gstats.o)
 */
void func_02194184(char *buf)
{
    int lid;
    int pid;
    int reqindex;

    pid = func_020964E0((u32)func_02193FD0(buf, g_021A58AC));
    lid = func_020964E0((u32)func_02193FD0(buf, g_021A58A0));
    reqindex = func_0219405C(3, lid, 0);
    if (reqindex == -1)
        return;
    func_02184208((void *)((int *)&g_021ADFE0)[5], reqindex)[2] = pid;
    func_0219451C(reqindex, pid > 0, 0, 0, 0);
}


/*
 * sdk:      ProcessGetData (gstats.o)
 */
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
