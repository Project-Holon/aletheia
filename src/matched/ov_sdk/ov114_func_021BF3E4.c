/*
 * function: NHTTP_GetBodyBuffer
 * address:  0x021BF3E4
 * packet:   pkt_ov114_021BF3E4
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTP_GetBodyBuffer (libnhttp.TWL.HYB.a d_nhttp_private.)
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
    char pad_0x08[0x1c - 0x08];
    u32 field_0x1c;
    char pad_0x20[0x28 - 0x20];
    char *field_0x28;
};

extern struct _NHTTPSysInfo *NHTTPi_GetSystemInfoP(void);
extern struct _NHTTPMutexInfo *NHTTPi_GetMutexInfoP(void);
extern void *NHTTPi_GetConnection(struct _NHTTPMutexInfo *, void *);
extern struct _NHTTPRes *NHTTPi_Connection2Response(struct _NHTTPMutexInfo *, void *);

int NHTTP_GetBodyBuffer(void *handle, char **value_pp, unsigned long *size_p)
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
        return -1;
    *value_pp = res_p->field_0x28;
    *size_p = res_p->field_0x1c;
    return res_p->field_0x04;
fail:
    return -1;
}
