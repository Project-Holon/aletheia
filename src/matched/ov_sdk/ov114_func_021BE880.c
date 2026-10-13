/*
 * function: NHTTP_GetResultCode
 * address:  0x021BE880
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NHTTPi_GetResponse  0x021BEC2C  arm  ov114
 *   NHTTPi_GetSystemInfoP  0x021BEF08  arm  ov114
 *   NHTTPi_GetMutexInfoP  0x021BEF58  arm  ov114
 *
 *
 * Keyed field read: -1 unknown key, -1 when unset, else the +0x18 word.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *NHTTPi_GetSystemInfoP(void);
extern void *NHTTPi_GetMutexInfoP(int p);
extern int NHTTPi_GetResponse(int, int);

int NHTTP_GetResultCode(int a)
{
    u8 *p = (u8 *)NHTTPi_GetResponse((int)NHTTPi_GetMutexInfoP((int)NHTTPi_GetSystemInfoP()), a);
    if (p == 0)
        return -1;
    if (*(u32 *)(p + 0x14) != 0)
        return *(u32 *)(p + 0x18);
    return -1;
}
