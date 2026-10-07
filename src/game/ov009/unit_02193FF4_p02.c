/*
 * file:     unit_02193FF4_p02.c
 * unit:     yes
 * function: func_02194494, func_0219451C, func_02194614
 * address:  0x02194494
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
 *   func_02193FF4 0x02193FF4  arm
 *   func_02193EB8 0x02193EB8  arm
 *   func_021943A4 0x021943A4  arm
 *   g_021A57F0   0x021A57F0  data
 *   g_021A57C8   0x021A57C8  data
 *   func_02184200 0x02184200  arm
 *   func_02184208 0x02184208  arm
 *   func_0218437C 0x0218437C  arm
 *   g_021ADFE0   0x021ADFE0  data
 *   func_021841B0 0x021841B0  arm
 *   @14079       0x021A1A54  data
 *   g_021A5800   0x021A5800  data
 */
#include "../../matched/include/G_StatsSocket.h"
#include "../../matched/include/G_StatsConn.h"

typedef struct {
    int type;
    int localid;
    int profileid;
    int extra0;
    int extra1;
    void *userdata;
    void *callback;
} serverreq_t;

extern char *func_02193FF4(char *buff, int len);
extern void func_02193EB8(char *buf, int len);
extern void func_021943A4(char *buff, int len);
extern int func_02184200(const int *p);
extern serverreq_t *func_02184208(void *array, int n);
extern void func_0218437C(int a, int b);
extern void func_021841B0(void *array);
int func_02194494(char *buff, int len);
void func_0219451C(int reqindex, int success, long modified, char *data, int length);
void func_02194614(void);
extern struct StatsSocket g_021A57C8;
extern char g_021A57F0[];
extern struct StatsConn g_021ADFE0;
extern char g_021A5800[];


/*
 * sdk:      ProcessInBuffer (gstats.o)
 */
int func_02194494(char *buff, int len)
{
    char *pos;
    int oldlen;

    oldlen = len;
    pos = func_02193FF4(buff, len);

    while (len > 0 && pos != 0) {
        (*(char * *)&g_021A57C8) = g_021A57F0;
        func_02193EB8(buff, pos - buff);
        func_021943A4(buff, pos - buff);
        len -= (pos - buff) + 7;
        buff = pos + 7;
        if (len > 0)
            pos = func_02193FF4(buff, len);
    }
    return oldlen - len;
}


/*
 * sdk:      CallReqCallback (gstats.o)
 */
void func_0219451C(int reqindex, int success, long modified, char *data, int length)
{
    serverreq_t *req;

    if (reqindex < 0 || reqindex >= func_02184200((void *)((int *)&g_021ADFE0)[5]))
        return;
    req = func_02184208((void *)((int *)&g_021ADFE0)[5], reqindex);
    if (req->callback != 0) {
        switch (req->type) {
        case 0:
            ((void (*)(int, int, int, char *, void *))req->callback)(req->localid, req->profileid, success, data, req->userdata);
            break;
        case 1:
            ((void (*)(int, int, int, int, int, long, char *, int, void *))req->callback)(req->localid, req->profileid, req->extra0, req->extra1, success, modified, data, length, req->userdata);
            break;
        case 2:
            ((void (*)(int, int, int, int, int, long, void *))req->callback)(req->localid, req->profileid, req->extra0, req->extra1, success, modified, req->userdata);
            break;
        case 3:
            ((void (*)(int, int, int, void *))req->callback)(req->localid, req->profileid, success, req->userdata);
            break;
        }
    }
    func_0218437C((int)((void *)((int *)&g_021ADFE0)[5]), reqindex);
}


/*
 * sdk:      ClosePendingCallbacks (gstats.o)
 *
 * Byte-correct (224/224); the connerror\ninitializer copies from the vendor template @14079 at 0x021A1A54 in ov009 data,\nattested by the `template` class (unique in ov009).\nA struct copy from an extern spelling was tried: one copy instead of two, DIFF.
 */
void func_02194614(void)
{
    int i;

    if (((int *)&g_021ADFE0)[5] == 0)
        return;
    for (i = func_02184200((void *)((int *)&g_021ADFE0)[5]) - 1; i >= 0; i--) {
        char connerror[16] = {0x13, 0x1d, 0x01, 0x04, 0, 0, 0, 0x28, 0x1f, 0x06, 0x45, 0x34, 0x3f, 0x01, 0x1b, 0};
        (*(char * *)&g_021A57C8) = g_021A5800;
        func_02193EB8(connerror, 15);
        func_0219451C(i, 0, 0, connerror, 0);
    }
    func_021841B0((void *)((int *)&g_021ADFE0)[5]);
    ((int *)&g_021ADFE0)[5] = 0;
}
