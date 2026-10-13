/*
 * function: NHTTP_WaitForConnection
 * address:  0x021BF288
 * packet:   pkt_ov114_021BF288
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NHTTPi_GetSystemInfoP 0x021BEF08  arm
 *   NHTTPi_GetThreadInfoP 0x021BEF50  arm
 *   NHTTPi_GetMutexInfoP 0x021BEF58  arm
 *   NHTTPi_GetConnection 0x021BEC00  arm
 *   NHTTP_GetConnectionStatus 0x021BF3BC  arm
 *   NHTTPi_CheckCurrentThread 0x021B9C1C  arm
 *   NHTTP_GetConnectionError 0x021BF488  arm
 *   NHTTPi_WaitForCompletion 0x021BEA64  arm
 */

typedef unsigned char  u8;
extern u8 *NHTTPi_GetSystemInfoP(void);
extern int NHTTPi_GetThreadInfoP(void);
extern void *NHTTPi_GetMutexInfoP(int p);
struct Conn;
extern struct Conn *NHTTPi_GetConnection(int a, int b);
extern int NHTTP_GetConnectionStatus(int);
extern void NHTTPi_CheckCurrentThread(int, int);
extern int NHTTP_GetConnectionError(int);
extern void NHTTPi_WaitForCompletion(u8 *p);

int NHTTP_WaitForConnection(int x)
{
    int a = (int)NHTTPi_GetSystemInfoP();
    int b = NHTTPi_GetThreadInfoP();
    int c;
    int d;

    c = (int)NHTTPi_GetConnection((int)NHTTPi_GetMutexInfoP(a), x);
    if (c == 0)
        return -1;
    d = NHTTP_GetConnectionStatus(x);
    NHTTPi_CheckCurrentThread(b, 1);
    if (d != -1 && d != 0) {
        if (NHTTP_GetConnectionError(x) == 0xf)
            NHTTPi_WaitForCompletion((u8 *)c);
    }
    return 0;
}
