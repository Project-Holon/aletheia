/*
 * function: NHTTP_GetHeaderField
 * address:  0x021BE7FC
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NHTTP_GetResponseHeaderField  0x021BBCF0  arm  ov114
 *   NHTTPi_GetResponse  0x021BEC2C  arm  ov114
 *   NHTTPi_GetSystemInfoP  0x021BEF08  arm  ov114
 *   NHTTPi_GetMutexInfoP  0x021BEF58  arm  ov114
 *
 *
 * Keyed lookup then dispatch; -1 when the key is unknown.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *NHTTPi_GetSystemInfoP(void);
extern void *NHTTPi_GetMutexInfoP(int p);
extern int NHTTPi_GetResponse(int, int);
extern int NHTTP_GetResponseHeaderField(u8 *, int, int);

int NHTTP_GetHeaderField(int a, int b, int c)
{
    u8 *p = (u8 *)NHTTPi_GetResponse((int)NHTTPi_GetMutexInfoP((int)NHTTPi_GetSystemInfoP()), a);
    if (p == 0)
        return -1;
    return NHTTP_GetResponseHeaderField(p, b, c);
}
