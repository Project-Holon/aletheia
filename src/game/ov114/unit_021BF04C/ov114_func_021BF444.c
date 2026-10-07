/*
 * function: NHTTP_GetUserParam
 * address:  0x021BF444
 * packet:   pkt_ov114_021BF444
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTP_GetUserParam (libnhttp.TWL.HYB.a d_nhttp_private.)
 *
 * symbols:
 *   NHTTPi_GetSystemInfoP       0x021bef08 arm
 *   NHTTPi_GetMutexInfoP        0x021bef58 arm
 *   NHTTPi_GetConnection        0x021bec00 arm
 *   NHTTPi_Connection2Response  0x021bebc8 arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct _NHTTPSysInfo;
struct _NHTTPMutexInfo;

struct _NHTTPRes {
    char pad_0x00[0x438];
    void *field_0x438;
};

extern struct _NHTTPSysInfo *NHTTPi_GetSystemInfoP(void);
extern struct _NHTTPMutexInfo *NHTTPi_GetMutexInfoP(void);
extern void *NHTTPi_GetConnection(struct _NHTTPMutexInfo *, void *);
extern struct _NHTTPRes *NHTTPi_Connection2Response(struct _NHTTPMutexInfo *, void *);

void *NHTTP_GetUserParam(void *handle)
{
    struct _NHTTPMutexInfo *mutexInfo_p;
    void *connection_p;
    struct _NHTTPRes *res_p;

    NHTTPi_GetSystemInfoP();
    mutexInfo_p = NHTTPi_GetMutexInfoP();
    connection_p = NHTTPi_GetConnection(mutexInfo_p, handle);
    if (connection_p == 0)
        goto fail;
    res_p = NHTTPi_Connection2Response(mutexInfo_p, connection_p);
    return res_p ? res_p->field_0x438 : 0;
fail:
    return 0;
}
