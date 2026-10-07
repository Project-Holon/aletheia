/*
 * file:     unit_021BF04C_p03.c
 * unit:     yes
 * function: func_021BF488, func_021BF4B0
 * address:  0x021BF488
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
 *   func_021BEC00  0x021BEC00  arm  ov114
 *   func_021BEF08  0x021BEF08  arm  ov114
 *   func_021BEF58  0x021BEF58  arm  ov114
 *   NHTTPi_GetSystemInfoP       0x021bef08 arm
 *   NHTTPi_GetMutexInfoP        0x021bef58 arm
 *   NHTTPi_GetConnection        0x021bec00 arm
 *   NHTTPi_Connection2Response  0x021bebc8 arm
 */
struct Conn;
struct _NHTTPSysInfo;
struct _NHTTPMutexInfo;
typedef unsigned char u8;

typedef unsigned int u32;

struct _NHTTPRes {
    u32 field_0x00;
    u32 field_0x04;
    u32 field_0x08;
    volatile u32 field_0x0c;
};

extern u8 *func_021BEF08(void);
extern void *func_021BEF58(int p);
extern struct Conn *func_021BEC00(int a, int b);
extern struct _NHTTPSysInfo *NHTTPi_GetSystemInfoP(void);
extern struct _NHTTPMutexInfo *NHTTPi_GetMutexInfoP(void);
extern void *NHTTPi_GetConnection(struct _NHTTPMutexInfo *, void *);
extern struct _NHTTPRes *NHTTPi_Connection2Response(struct _NHTTPMutexInfo *, void *);
int func_021BF488(int a);
int NHTTP_GetConnectionProgress(void *handle, unsigned long *received_p, unsigned long *contentlen_p);


/*
 * Keyed +0x04 read of record `a`; -1 when the key is unknown.
 */
int func_021BF488(int a)
{
    u8 *p = (u8 *)func_021BEC00((int)func_021BEF58((int)func_021BEF08()), a);
    if (p != 0)
        return *(u32 *)(p + 4);
    return -1;
}


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
