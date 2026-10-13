/*
 * function: NHTTP_SetVerifyOption
 * address:  0x021BE8B8
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NHTTPi_GetRequest  0x021BEC10  arm  ov114
 *   NHTTPi_GetSystemInfoP  0x021BEF08  arm  ov114
 *   NHTTPi_GetMutexInfoP  0x021BEF58  arm  ov114
 *
 *
 * Keyed word store at +0xd0; -1 when the key is unknown.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *NHTTPi_GetSystemInfoP(void);
extern void *NHTTPi_GetMutexInfoP(int p);
extern int NHTTPi_GetRequest(int, int);

int NHTTP_SetVerifyOption(int a, int v)
{
    u8 *p = (u8 *)NHTTPi_GetRequest((int)NHTTPi_GetMutexInfoP((int)NHTTPi_GetSystemInfoP()), a);
    if (p == 0)
        return -1;
    *(u32 *)(p + 0xd0) = v;
    return 0;
}
