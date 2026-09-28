/*
 * function: func_02177EE8
 * address:  0x02177EE8
 * packet:   pkt_ov009_02177EE8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Auth_Create (libdwcauth.TWL.HYB.a dwc_auth.o)
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_021782B4  0x021782B4  arm  ov009
 *   func_02177FFC  0x02177FFC  arm  ov009
 *   g_021AB184  0x021AB184  data  ov009
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

extern void func_02082BCC(void *dstp, unsigned char data, unsigned long size);
extern int func_021782B4(int getwifiinfofromflash);
extern void func_02177FFC(void);

extern DWCWFCUtil g_021AB184;

int func_02177EE8(DWCAuthParam *param, void *http)
{
    void *(*alloc)(unsigned long, long) = param->alloc;

    if (g_021AB184.auth != 0)
        return 2;
    g_021AB184.auth = (DWCAuth *)alloc(0, sizeof(DWCAuth));
    if (g_021AB184.auth == 0)
        return 2;
    func_02082BCC(g_021AB184.auth, 0, sizeof(DWCAuth));
    g_021AB184.auth->http = http;
    g_021AB184.state = 0;
    func_02082BCC((char *)g_021AB184.auth + 0x1008, 0, 0x1c4);
    g_021AB184.auth->error = 20100;
    g_021AB184.auth->param = *param;
    g_021AB184.auth->param.ingamesn[25] = 0;
    g_021AB184.auth->param.gsbrcd[11] = 0;
    g_021AB184.auth->result = func_021782B4(1);
    if (g_021AB184.auth->result != 0)
        return g_021AB184.auth->result;
    g_021AB184.f0 = 0;
    func_02177FFC();
    return 0;
}
