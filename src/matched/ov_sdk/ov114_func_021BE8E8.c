/*
 * function: NHTTP_SetBasicAuthorization
 * address:  0x021BE8E8
 * packet:   pkt_ov114_021BE8E8
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTP_SetBasicAuthorization (libnhttp.TWL.HYB.a(d_nhttp.o))
 *
 * symbols:
 *   NHTTPi_GetSystemInfoP 0x021BEF08 arm ov114
 *   NHTTPi_GetMutexInfoP 0x021BEF58 arm ov114
 *   NHTTPi_GetRequest 0x021BEC10 arm ov114
 *   NHTTPi_strnlen 0x021BA124 arm ov114
 *   NHTTPi_memclr 0x021BA13C arm ov114
 *   NHTTPi_memcpy 0x021BA100 arm ov114
 *   NHTTPi_Base64Encode 0x021BA714 arm ov114
 *   sNHTTPBasicAuthColon 0x021CE53C data
 */

typedef struct {
    char pad[0x4c];
    char auth[0x5c];
    int authLen;
} Req;

extern char sNHTTPBasicAuthColon[];

typedef unsigned char  u8;
extern u8 *NHTTPi_GetSystemInfoP(void);
extern void *NHTTPi_GetMutexInfoP(void);
extern int NHTTPi_GetRequest(int a, int d);
extern int NHTTPi_strnlen(char *s, int max);
extern void NHTTPi_memclr(int a, int b);
extern void NHTTPi_memcpy(void *dst_p, void *src_p, int size);
extern int NHTTPi_Base64Encode(char *dst_p, const char *src_p);

int NHTTP_SetBasicAuthorization(void *handle, char *username_p, char *password_p)
{
    char tmpbuf[65];
    int password_len;
    int username_len;
    Req *req_p;
    void *mutexInfo_p;

    NHTTPi_GetSystemInfoP();
    mutexInfo_p = NHTTPi_GetMutexInfoP();
    req_p = (Req *)NHTTPi_GetRequest((int)mutexInfo_p, (int)handle);
    if (req_p == 0 || username_p == 0 || password_p == 0) {
        return -1;
    }
    username_len = NHTTPi_strnlen(username_p, 0x21);
    password_len = NHTTPi_strnlen(password_p, 0x21);
    if (username_len <= 0x20 && password_len <= 0x20) {
        NHTTPi_memclr((int)tmpbuf, 0x41);
        NHTTPi_memcpy(tmpbuf, username_p, username_len);
        NHTTPi_memcpy(tmpbuf + username_len, sNHTTPBasicAuthColon, 1);
        NHTTPi_memcpy(tmpbuf + (username_len + 1), password_p, password_len);
        req_p->authLen = NHTTPi_Base64Encode(req_p->auth, tmpbuf);
    } else {
        return -1;
    }
    return 0;
}
