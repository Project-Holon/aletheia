/*
 * function: func_021C9B64
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
 * Closed (U58): the 20-byte secretkey copy is memcpy(tmpbuf, g_021CF7AC.secretkey, 20)
 * declared through a string.h header, so mwccarm inlines it as the rolled two-byte loop
 * and picks the object's source/dest pointer registers (r3 pool load, ip = stack+0x11).
 * A struct assignment spelled the same copy but swapped them, leaving 6 bytes differing.
 *
 * symbols:
 *   func_02092344  0x02092344  arm
 *   func_020816B8  0x020816B8  arm
 *   strlen  0x0209477C  arm
 *   func_02094860  0x02094860  arm
 *   func_020949F4  0x020949F4  arm
 *   func_0205A29C  0x0205A29C  arm
 *   func_021CA06C  0x021CA06C  arm  ov114
 *   func_021C99D0  0x021C99D0  arm  ov114
 *   g_021CF7AC  0x021CF7AC  data
 *   g_021CF84C  0x021CF84C  data
 *   g_021CF854  0x021CF854  data
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
extern char *func_02094860();
extern int func_020949F4();
extern void func_021CA06C(void);
extern void func_0205A29C(void *ptr);
extern int func_021C99D0(char *buf, int len);
extern Session g_021CF7AC;
extern char g_021CF84C[];
extern char g_021CF854[];

void func_021C9B64(char *buf, int len, int result)
{
    g_021CF7AC.reqid = -1;
    if (g_021CF7AC.state == 1)
        return;
    if (result == 0) {
        switch (g_021CF7AC.state) {
        case 5:
            if (len == 32) {
                int i;
                u8 *hash = (u8 *)g_021CF7AC.hash + 20;
                char tmpbuf[52];
                char hextbl[17] = "0123456789abcdef";

                memcpy(tmpbuf, g_021CF7AC.secretkey, 20);
                func_02092344(tmpbuf + 20, buf, 32);
                func_020816B8(hash, tmpbuf, 52);
                for (i = 0; i < 20; i++) {
                    g_021CF7AC.hash[i * 2] = hextbl[hash[i] >> 4];
                    g_021CF7AC.hash[i * 2 + 1] = hextbl[hash[i] & 15];
                }
                g_021CF7AC.hash[-strlen(g_021CF84C)] = '&';
                func_02094860(g_021CF7AC.lastHash, g_021CF7AC.hash, 41);
                g_021CF7AC.state = 6;
            } else {
                func_021CA06C();
            }
            func_0205A29C(buf);
            break;
        case 7:
            if (func_020949F4(buf, g_021CF854, strlen(g_021CF854)) == 0) {
                func_0205A29C(buf);
                func_021CA06C();
                return;
            }
            if (g_021CF7AC.resbuf != 0) {
                func_0205A29C(g_021CF7AC.resbuf);
                g_021CF7AC.resbuf = 0;
            }
            if (!func_021C99D0(buf, len)) {
                func_0205A29C(buf);
                func_021CA06C();
                return;
            }
            if (g_021CF7AC.callback != 0 && !g_021CF7AC.callback((u32 *)buf, len)) {
                func_0205A29C(buf);
                func_021CA06C();
                return;
            }
            g_021CF7AC.resbuf = buf;
            g_021CF7AC.resbuflen = len;
            g_021CF7AC.state = 8;
            break;
        }
    } else {
        func_021CA06C();
    }
}
