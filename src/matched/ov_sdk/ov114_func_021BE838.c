/*
 * function: NHTTP_GetHeaderAll
 * address:  0x021BE838
 * packet:   pkt_ov114_021BE838
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTP_GetHeaderAll (libnhttp.TWL.HYB.a(d_nhttp.o))
 *
 * symbols:
 *   NHTTPi_GetSystemInfoP 0x021BEF08 arm ov114
 *   NHTTPi_GetBgnEndInfoP 0x021BEF3C arm ov114
 *   NHTTPi_GetMutexInfoP 0x021BEF58 arm ov114
 *   NHTTPi_GetResponse 0x021BEC2C arm ov114
 *   NHTTPi_GetResponseHeaderAll 0x021BBDFC arm ov114
 */

typedef unsigned char  u8;
extern u8 *NHTTPi_GetSystemInfoP(void);
extern void *NHTTPi_GetBgnEndInfoP(void);
extern void *NHTTPi_GetMutexInfoP(int p);
extern int NHTTPi_GetResponse(int a, int d);
extern int NHTTPi_GetResponseHeaderAll(void *bgnEndInfo_p, void *res_p, char **value_pp);

int NHTTP_GetHeaderAll(void *handle, char **value_pp)
{
    void *sysInfo_p = NHTTPi_GetSystemInfoP();
    void *bgnEndInfo_p = NHTTPi_GetBgnEndInfoP();
    void *mutexInfo_p = NHTTPi_GetMutexInfoP((int)sysInfo_p);
    void *res_p = (void *)NHTTPi_GetResponse((int)mutexInfo_p, (int)handle);
    if (res_p == 0) {
        return -1;
    }
    return NHTTPi_GetResponseHeaderAll(bgnEndInfo_p, res_p, value_pp);
}
