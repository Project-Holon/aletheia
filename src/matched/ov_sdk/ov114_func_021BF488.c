/*
 * function: NHTTP_GetConnectionError
 * address:  0x021BF488
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NHTTPi_GetConnection  0x021BEC00  arm  ov114
 *   NHTTPi_GetSystemInfoP  0x021BEF08  arm  ov114
 *   NHTTPi_GetMutexInfoP  0x021BEF58  arm  ov114
 *
 *
 * Keyed +0x04 read of record `a`; -1 when the key is unknown.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *NHTTPi_GetSystemInfoP(void);
extern void *NHTTPi_GetMutexInfoP(int p);
struct Conn;
extern struct Conn *NHTTPi_GetConnection(int a, int b);

int NHTTP_GetConnectionError(int a)
{
    u8 *p = (u8 *)NHTTPi_GetConnection((int)NHTTPi_GetMutexInfoP((int)NHTTPi_GetSystemInfoP()), a);
    if (p != 0)
        return *(u32 *)(p + 4);
    return -1;
}
