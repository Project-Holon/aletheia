/*
 * function: NHTTP_GetConnectionProgress
 * address:  0x021BF4B0
 * packet:   pkt_ov114_021BF4B0
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTP_GetConnectionProgress (libnhttp.TWL.HYB.a d_nhttp_private.)
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
    u32 field_0x00;
    u32 field_0x04;
    u32 field_0x08;
    volatile u32 field_0x0c;
};

extern struct _NHTTPSysInfo *NHTTPi_GetSystemInfoP(void);
extern struct _NHTTPMutexInfo *NHTTPi_GetMutexInfoP(void);
extern void *NHTTPi_GetConnection(struct _NHTTPMutexInfo *, void *);
extern struct _NHTTPRes *NHTTPi_Connection2Response(struct _NHTTPMutexInfo *, void *);

int NHTTP_GetConnectionProgress(void *handle, unsigned long *received_p, unsigned long *contentlen_p)
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
    if (res_p == 0)
        goto fail2;
    *received_p = res_p->field_0x08;
    *contentlen_p = (res_p->field_0x0c == 0xffffffff) ? 0 : res_p->field_0x0c;
    return 0;
fail2:
    return -1;
fail:
    return -1;
}
