/*
 * function: func_02178678
 * address:  0x02178678
 * packet:   pkt_ov009_02178678
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Auth_ParseHttp (libdwcauth.TWL.HYB.a dwc_auth.o)
 *
 * symbols:
 *   func_0217A484  0x0217A484  arm  ov009
 *   func_02178814  0x02178814  arm  ov009
 *   func_02058DD0  0x02058DD0  arm
 *   func_02058E20  0x02058E20  arm
 *   func_02058D88  0x02058D88  arm
 *   g_021AB184  0x021AB184  data  ov009
 *   g_021AB190  0x021AB190  data  ov009
 */

typedef struct DWCAuthParam
{
    unsigned short ingamesn[26];
    char gsbrcd[12];
    void *(*alloc)(unsigned long name, long size);
    void (*free)(unsigned long name, void *ptr, long size);
} DWCAuthParam;

typedef struct DWCAuth
{
    char pad0[0x1004];
    int result;
    int error;
    char pad100c[0x11cc - 0x100c];
    DWCAuthParam param;
    char pad1214[0x1314 - 0x1214];
    void *http;
    char pad1318[0x13f4 - 0x1318];
} DWCAuth;

typedef struct DWCWFCUtil
{
    int f0;
    DWCAuth *auth;
    int state;
} DWCWFCUtil;

struct DWCHttp;
extern int func_0217A484(struct DWCHttp *http, int noparsebody);
extern int func_02178814(void);
extern int func_02058DD0(void *wifiinfo, void *work);
extern int func_02058E20(void *wifiinfo);
extern int func_02058D88(void *work);

extern DWCWFCUtil g_021AB184;
extern char g_021AB190[];

int func_02178678(void)
{
    void *(*alloc)(unsigned long, long) = g_021AB184.auth->param.alloc;
    void (*free)(unsigned long, void *, long) = g_021AB184.auth->param.free;
    unsigned char *bmwork;

    if (func_0217A484(g_021AB184.auth->http, 0) != 1)
    {
        g_021AB184.auth->error = 20100;
        return 14;
    }
    if (func_02178814() != 0)
        return 14;

    if (g_021AB184.auth->error < 20100)
    {
        if (g_021AB184.auth->error == 20002)
        {
            bmwork = (unsigned char *)alloc(0, 0x101f);
            if (bmwork == 0)
            {
                g_021AB184.auth->error = 20100;
                return 2;
            }
            if (func_02058DD0(g_021AB190, (void *)(((unsigned long)bmwork + 31) & ~31)) != 1)
            {
                free(0, bmwork, 0);
                g_021AB184.auth->error = 20100;
                return 15;
            }
            free(0, bmwork, 0);
        }
        return 21;
    }
    switch (g_021AB184.auth->error)
    {
    case 20104:
        func_02058E20(g_021AB190);
        g_021AB184.auth->error = 20104;
        return 16;
    case 20108:
        bmwork = (unsigned char *)alloc(0, 0x1000);
        if (bmwork == 0)
        {
            g_021AB184.auth->error = 20108;
            return 17;
        }
        func_02058D88((void *)(((unsigned long)bmwork + 31) & ~31));
        free(0, bmwork, 0);
        g_021AB184.auth->error = 20108;
        return 17;
    default:
        return 18;
    }
}
