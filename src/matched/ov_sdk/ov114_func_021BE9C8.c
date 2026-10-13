/*
 * function: NHTTP_SetRootCA
 * address:  0x021BE9C8
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NHTTP_SetRequestRootCA  0x021BE9F8  arm  ov114
 *   NHTTPi_GetRequest  0x021BEC10  arm  ov114
 *   NHTTPi_GetSystemInfoP  0x021BEF08  arm  ov114
 *   NHTTPi_GetMutexInfoP  0x021BEF58  arm  ov114
 *
 *
 * Keyed post of the b/c pair onto record `a`.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *NHTTPi_GetSystemInfoP(void);
extern void *NHTTPi_GetMutexInfoP(int p);
extern int NHTTPi_GetRequest(int, int);
extern int NHTTP_SetRequestRootCA(u8 *, int, int);

int NHTTP_SetRootCA(int a, int b, int c)
{
    return NHTTP_SetRequestRootCA((u8 *)NHTTPi_GetRequest((int)NHTTPi_GetMutexInfoP((int)NHTTPi_GetSystemInfoP()), a), b, c);
}
