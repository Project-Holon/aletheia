/*
 * function: DWCi_EncSessionCompleteCallback
 * address:  0x021C9B64
 * packet:   pkt_ov114_021C9B64
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_EncSessionCompleteCallback (libdwcenc.TWL.HYB.a dwc_encsession.o)
 *
 * Closed (U58): the 20-byte secretkey copy is memcpy(tmpbuf, gDwcEncSession.secretkey, 20)
 * declared through a string.h header, so mwccarm inlines it as the rolled two-byte loop
 * and picks the object's source/dest pointer registers (r3 pool load, ip = stack+0x11).
 * A struct assignment spelled the same copy but swapped them, leaving 6 bytes differing.
 *
 * symbols:
 *   func_02092344  0x02092344  arm
 *   func_020816B8  0x020816B8  arm
 *   strlen  0x0209477C  arm
 *   strncpy  0x02094860  arm
 *   strncmp  0x020949F4  arm
 *   func_0205A29C  0x0205A29C  arm
 *   DWCi_EncSetError  0x021CA06C  arm  ov114
 *   DWCi_EncSessionValidateResponse  0x021C99D0  arm  ov114
 *   gDwcEncSession  0x021CF7AC  data
 *   sDwcEncSessionHash  0x021CF84C  data
 *   sDwcEncSessionError  0x021CF854  data
 *   @16117  0x021CE1CC  data
 */

#include "../arm9_sdk/libc/string.h"
typedef unsigned char u8;
typedef unsigned long u32;

typedef struct {
    int   state;
    int   isinitialized;
    int   reqid;
    int   validated;
    char  gamename[32];
    char  secretkey[20];
    u32   key1;
    u32   key2;
    u32   key3;
    u32   key4;
    char *request;
    char *hash;
    char *data;
    void *resbuf;
    u32   resbuflen;
    void *decodedbuf;
    u32   decodedbuflen;
    int (*callback)(u32 *, int);
    char  lastHash[41];
} Session;

typedef struct { char c[20]; } Key20;

extern void *func_02092344();
extern void func_020816B8(void *digest, void *data, u32 len);
extern unsigned long strlen(const char *s);
extern char *strncpy();
extern int strncmp();
extern void DWCi_EncSetError(void);
extern void func_0205A29C(void *ptr);
extern int DWCi_EncSessionValidateResponse(char *buf, int len);
extern Session gDwcEncSession;
extern char sDwcEncSessionHash[];
extern char sDwcEncSessionError[];

void DWCi_EncSessionCompleteCallback(char *buf, int len, int result)
{
    gDwcEncSession.reqid = -1;
    if (gDwcEncSession.state == 1)
        return;
    if (result == 0) {
        switch (gDwcEncSession.state) {
        case 5:
            if (len == 32) {
                int i;
                u8 *hash = (u8 *)gDwcEncSession.hash + 20;
                char tmpbuf[52];
                char hextbl[17] = "0123456789abcdef";

                memcpy(tmpbuf, gDwcEncSession.secretkey, 20);
                func_02092344(tmpbuf + 20, buf, 32);
                func_020816B8(hash, tmpbuf, 52);
                for (i = 0; i < 20; i++) {
                    gDwcEncSession.hash[i * 2] = hextbl[hash[i] >> 4];
                    gDwcEncSession.hash[i * 2 + 1] = hextbl[hash[i] & 15];
                }
                gDwcEncSession.hash[-strlen(sDwcEncSessionHash)] = '&';
                strncpy(gDwcEncSession.lastHash, gDwcEncSession.hash, 41);
                gDwcEncSession.state = 6;
            } else {
                DWCi_EncSetError();
            }
            func_0205A29C(buf);
            break;
        case 7:
            if (strncmp(buf, sDwcEncSessionError, strlen(sDwcEncSessionError)) == 0) {
                func_0205A29C(buf);
                DWCi_EncSetError();
                return;
            }
            if (gDwcEncSession.resbuf != 0) {
                func_0205A29C(gDwcEncSession.resbuf);
                gDwcEncSession.resbuf = 0;
            }
            if (!DWCi_EncSessionValidateResponse(buf, len)) {
                func_0205A29C(buf);
                DWCi_EncSetError();
                return;
            }
            if (gDwcEncSession.callback != 0 && !gDwcEncSession.callback((u32 *)buf, len)) {
                func_0205A29C(buf);
                DWCi_EncSetError();
                return;
            }
            gDwcEncSession.resbuf = buf;
            gDwcEncSession.resbuflen = len;
            gDwcEncSession.state = 8;
            break;
        }
    } else {
        DWCi_EncSetError();
    }
}
