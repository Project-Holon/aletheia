/*
 * function: NHTTPi_DeleteConnection
 * address:  0x021BF1B0
 * packet:   pkt_ov114_021BF1B0
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_DeleteConnection (libnhttp.TWL.HYB.a d_nhttp_private.)
 *
 * symbols:
 *   NHTTPi_GetSystemInfoP      0x021bef08 arm
 *   NHTTPi_GetMutexInfoP       0x021bef58 arm
 *   NHTTPi_GetThreadInfoP      0x021bef50 arm
 *   NHTTPi_CancelRequestAsync  0x021bba14 arm
 *   NHTTPi_decRef              0x021bf018 arm
 *   NHTTPi_DestroyRequest      0x021bb8b4 arm
 *   NHTTP_WaitForConnection    0x021bf288 arm
 *   NHTTPi_DestroyResponse     0x021bbb28 arm
 *   NHTTPi_OmitConnectionList  0x021beba8 arm
 *   NHTTPi_free                0x021ba850 arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct _NHTTPSysInfo;
struct _NHTTPMutexInfo;
struct _NHTTPThreadInfo;

struct _NHTTPReq {
    char pad_0x00[4];
    int field_0x04;
};

struct _NHTTPConnection {
    char pad_0x00[0x10];
    struct _NHTTPReq *field_0x10;
    void *field_0x14;
    int field_0x18;
    char pad_0x1c[0x8048 - 0x1c];
    int field_0x8048;
};

extern struct _NHTTPSysInfo *NHTTPi_GetSystemInfoP(void);
extern struct _NHTTPMutexInfo *NHTTPi_GetMutexInfoP(void);
extern struct _NHTTPThreadInfo *NHTTPi_GetThreadInfoP(struct _NHTTPSysInfo *);
extern int NHTTPi_CancelRequestAsync(struct _NHTTPSysInfo *, int);
extern int NHTTPi_decRef(struct _NHTTPMutexInfo *, struct _NHTTPConnection *);
extern void NHTTPi_DestroyRequest(struct _NHTTPSysInfo *, struct _NHTTPReq *);
extern int NHTTP_WaitForConnection(void *);
extern void NHTTPi_DestroyResponse(struct _NHTTPMutexInfo *, void *);
extern int NHTTPi_OmitConnectionList(struct _NHTTPMutexInfo *, struct _NHTTPConnection *);
extern void NHTTPi_free(void *);

int NHTTPi_DeleteConnection(struct _NHTTPConnection *connection_p)
{
    struct _NHTTPSysInfo *sysInfo_p = NHTTPi_GetSystemInfoP();
    struct _NHTTPMutexInfo *mutexInfo_p = NHTTPi_GetMutexInfoP();

    NHTTPi_GetThreadInfoP(sysInfo_p);
    if (connection_p == 0)
        return -1;
    if (connection_p->field_0x8048 > 0 && connection_p->field_0x18 >= 0) {
        NHTTPi_CancelRequestAsync(sysInfo_p, connection_p->field_0x18);
        connection_p->field_0x18 = -1;
    }
    if (NHTTPi_decRef(mutexInfo_p, connection_p) > 0)
        return 0;
    if (connection_p->field_0x10 != 0 && connection_p->field_0x10->field_0x04 == 0)
        NHTTPi_DestroyRequest(sysInfo_p, connection_p->field_0x10);
    if (connection_p->field_0x14 != 0) {
        if (connection_p->field_0x10 != 0)
            NHTTP_WaitForConnection(connection_p);
        NHTTPi_DestroyResponse(mutexInfo_p, connection_p->field_0x14);
    }
    NHTTPi_OmitConnectionList(mutexInfo_p, connection_p);
    NHTTPi_free(connection_p);
    return 0;
}
