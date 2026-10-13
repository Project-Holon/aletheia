/*
 * function: NHTTP_AddPostDataAscii
 * address:  0x021BE748
 * packet:   pkt_ov114_021BE748
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTP_AddPostDataAscii (libnhttp.TWL.HYB.a(d_nhttp.o))
 *
 * symbols:
 *   NHTTPi_GetSystemInfoP 0x021BEF08 arm ov114
 *   NHTTPi_GetBgnEndInfoP 0x021BEF3C arm ov114
 *   NHTTPi_GetMutexInfoP 0x021BEF58 arm ov114
 *   NHTTPi_GetRequest 0x021BEC10 arm ov114
 *   NHTTPi_AddRequestPostDataAscii 0x021BAC58 arm ov114
 */

typedef unsigned char  u8;
extern u8 *NHTTPi_GetSystemInfoP(void);
extern void *NHTTPi_GetBgnEndInfoP(void);
extern void *NHTTPi_GetMutexInfoP(int p);
extern int NHTTPi_GetRequest(int a, int d);
extern int NHTTPi_AddRequestPostDataAscii(void *req_p, void *bgnEndInfo_p, char *label_p, char *value_p);

int NHTTP_AddPostDataAscii(void *handle, char *label_p, char *value_p)
{
    void *sysInfo_p = NHTTPi_GetSystemInfoP();
    void *bgnEndInfo_p = NHTTPi_GetBgnEndInfoP();
    void *mutexInfo_p = NHTTPi_GetMutexInfoP((int)sysInfo_p);
    void *req_p = (void *)NHTTPi_GetRequest((int)mutexInfo_p, (int)handle);
    return -(NHTTPi_AddRequestPostDataAscii(req_p, bgnEndInfo_p, label_p, value_p) == 0);
}
