/*
 * function: NHTTP_CancelConnection
 * address:  0x021BF374
 * packet:   pkt_ov114_021BF374
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTP_CancelConnection (libnhttp.TWL.HYB.a d_nhttp_private.)
 *
 * symbols:
 *   NHTTPi_GetSystemInfoP      0x021bef08 arm
 *   NHTTPi_GetMutexInfoP       0x021bef58 arm
 *   NHTTPi_GetConnection       0x021bec00 arm
 *   NHTTPi_CancelRequestAsync  0x021bba14 arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct _NHTTPSysInfo;
struct _NHTTPMutexInfo;
struct _NHTTPReq;

struct _NHTTPConnection {
    u32 field_0x00;
    u32 field_0x04;
    u32 field_0x08;
    u32 field_0x0c;
    struct _NHTTPReq *field_0x10;
    u32 field_0x14;
    int field_0x18;
};

extern struct _NHTTPSysInfo *NHTTPi_GetSystemInfoP(void);
extern struct _NHTTPMutexInfo *NHTTPi_GetMutexInfoP(void);
extern struct _NHTTPConnection *NHTTPi_GetConnection(struct _NHTTPMutexInfo *, void *);
extern int NHTTPi_CancelRequestAsync(struct _NHTTPSysInfo *, int);

int NHTTP_CancelConnection(void *handle)
{
    struct _NHTTPSysInfo *sysInfo_p = NHTTPi_GetSystemInfoP();
    struct _NHTTPMutexInfo *mutexInfo_p = NHTTPi_GetMutexInfoP();
    struct _NHTTPConnection *connection_p = NHTTPi_GetConnection(mutexInfo_p, handle);

    if (connection_p == 0)
        return -1;
    if (connection_p->field_0x18 < 0)
        return -1;
    NHTTPi_CancelRequestAsync(sysInfo_p, connection_p->field_0x18);
    return 0;
}
