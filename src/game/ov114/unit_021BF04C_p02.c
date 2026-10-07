/*
 * file:     unit_021BF04C_p02.c
 * unit:     yes
 * function: func_021BF374, func_021BF3BC, func_021BF3E4
 * address:  0x021BF374
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   NHTTPi_GetSystemInfoP      0x021bef08 arm
 *   NHTTPi_GetMutexInfoP       0x021bef58 arm
 *   NHTTPi_GetConnection       0x021bec00 arm
 *   NHTTPi_CancelRequestAsync  0x021bba14 arm
 *   func_021BEC00  0x021BEC00  arm  ov114
 *   func_021BEF08  0x021BEF08  arm  ov114
 *   func_021BEF58  0x021BEF58  arm  ov114
 *   NHTTPi_Connection2Response  0x021bebc8 arm
 */
struct _NHTTPSysInfo;
struct _NHTTPMutexInfo;
struct _NHTTPReq;
struct Conn;
typedef unsigned char u8;

typedef unsigned int u32;

struct _NHTTPConnection {
    u32 field_0x00;
    u32 field_0x04;
    u32 field_0x08;
    u32 field_0x0c;
    struct _NHTTPReq *field_0x10;
    u32 field_0x14;
    int field_0x18;
};

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
extern struct _NHTTPConnection *NHTTPi_GetConnection(struct _NHTTPMutexInfo *, void *);
extern int NHTTPi_CancelRequestAsync(struct _NHTTPSysInfo *, int);
extern u8 *func_021BEF08(void);
extern void *func_021BEF58(int p);
extern struct Conn *func_021BEC00(int a, int b);
extern struct _NHTTPRes *NHTTPi_Connection2Response(struct _NHTTPMutexInfo *, void *);
int NHTTP_CancelConnection(void *handle);
int func_021BF3BC(int a);
int NHTTP_GetBodyBuffer(void *handle, char **value_pp, unsigned long *size_p);


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


int func_021BF3BC(int a)
{
    u8 *p = (u8 *)func_021BEC00((int)func_021BEF58((int)func_021BEF08()), a);
    if (p == 0)
        return -1;
    return *(u32 *)p;
}


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
