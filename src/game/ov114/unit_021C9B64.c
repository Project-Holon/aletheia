/*
 * file:     unit_021C9B64.c
 * unit:     yes
 * function: func_021C9B64, func_021C9D9C, func_021C9EE4, func_021CA06C, func_021CA0A0, func_021CA188, func_021CA1B4, DWCi_EncSessionGetResponse, func_021CA240, func_021CA470
 * address:  0x021C9B64
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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
 *   func_0205A16C  0x0205A16C  arm
 *   func_0205A1B0  0x0205A1B0  arm
 *   func_021C9890  0x021C9890  arm  ov114
 *   func_021C98A4  0x021C98A4  arm  ov114
 *   func_021C9858  0x021C9858  arm  ov114
 *   func_0217FA90  0x0217FA90  arm  ov009
 *   func_02095EAC  0x02095EAC  arm
 *   func_021C98E0  0x021C98E0  arm  ov114
 *   func_021BF558  0x021BF558  arm  ov114
 *   g_021CF7A8  0x021CF7A8  data
 *   g_021CF85C  0x021CF85C  data
 *   g_021CF884  0x021CF884  data
 *   g_021CF8A8  0x021CF8A8  data
 *   CTRDGi_IsTaskAvailable  0x02059F38  arm
 *   func_021BF6C4  0x021BF6C4  arm  ov114
 *   func_021BF5B8  0x021BF5B8  arm  ov114
 *   func_021C9B60  0x021C9B60  arm  ov114
 *   g_021CF248  0x021CF248  data
 *   g_021D3C20  0x021D3C20  data
 *   g_021D3B9C  0x021D3B9C  data
 *   func_021BF880  0x021BF880  arm  ov114
 *   DWC_Free       0x0205A1B0  arm
 *   DWCi_GsFree    0x0205A29C  arm
 *   func_021BF57C  0x021BF57C  arm  ov114
 *   d_021CF7AC   0x021CF7AC  data
 *   func_02084F80  0x02084F80  arm
 *   func_02084F40  0x02084F40  arm
 *   g_021CF8D0  0x021CF8D0  data
 *   g_021CF8D8  0x021CF8D8  data
 *   g_021CF8DC  0x021CF8DC  data
 *   g_021CF900  0x021CF900  data
 *   g_021CF92C  0x021CF92C  data
 *   g_021CF8E4  0x021CF8E4  data
 */
#include "../../matched/arm9_sdk/libc/string.h"

typedef unsigned char u8;

typedef unsigned int u32;

typedef struct { char c[20]; } Key20;

struct Session {
    int state;
    int isinitialized;
    int reqid;
    int validated;
    char gamename[32];
    char secretkey[20];
    unsigned int key1;
    unsigned int key2;
    unsigned int key3;
    unsigned int key4;
    char *request;
    char *hash;
    char *data;
    void *resbuf;
    unsigned int resbuflen;
    void *decodedbuf;
    unsigned int decodedbuflen;
    int (*callback)(unsigned int *, int);
    char lastHash[41];
};

typedef union {
    char data[84];
    struct {
        char secretkey[20];
        char key1[8];
        char key2[8];
        char key3[8];
        char key4[8];
        char gamename[32];
    } info;
} InitData;

typedef struct {
    long pid;
    u32  size;
} PutHeader;

extern void *func_02092344();
extern void func_020816B8(void *digest, void *data, u32 len);
extern unsigned long strlen(const char *s);
extern char *func_02094860();
extern int func_020949F4();
extern void func_021CA06C(void);
extern void func_0205A29C(void *ptr);
extern int func_021C99D0(char *buf, int len);
extern void *func_0205A16C(int name, u32 size);
extern void func_0205A1B0(int name, void *ptr, u32 size);
extern void func_021C9890(u32 seed);
extern u8 func_021C98A4(void);
extern void func_0217FA90(const char *input, char *output, int inlen, int encodingType);
extern u32 func_021C9858(u32 len);
extern u32 func_02095EAC(u32 a0, u32 *a1, u32 mode);
extern int func_021C98E0(char *gamename, const char *secretkey, unsigned long key1, unsigned long key2, unsigned long key3, unsigned long key4);
extern int func_021BF558();
extern int CTRDGi_IsTaskAvailable(void);
extern void DWCi_SetError(int mode, long value);
extern int func_021BF6C4(char *url, int bufferlen, int buffer_clear, void (*progress)(void), void (*completed)(void), void *param);
extern int func_021BF5B8(void);
extern void func_021C9B60(void);
extern void func_021BF880(int);
extern void DWC_Free(int name, void *ptr, int size);
extern void DWCi_GsFree(void *ptr);
extern int func_021BF57C(void);
extern int func_02084F80(char *dst, u32 len, const char *fmt, ...);
extern int func_02084F40(char *dst, const char *fmt, ...);
void func_021C9B64(char *buf, int len, int result);
int func_021C9D9C(u8 *outbuf, u8 *header, u32 headerlen, u8 *srcbuf, u32 srclen);
void func_021C9EE4(int server, char *initdata);
void DWCi_EncSetError(void);
int func_021CA0A0(void);
void func_021CA188(void);
void func_021CA1B4(void);
u32 DWCi_EncSessionGetResponse(u32 *out);
int func_021CA240(char *url, long pid, void *data, u32 size, int (*cb)(u32 *, int), int reuseHash);
int func_021CA470(void *a, u32 b, void *c, u32 d, u32 e);
extern struct Session g_021CF7AC;
extern char g_021CF84C[];
extern char g_021CF854[];
extern char *g_021CF7A8;
extern char g_021CF85C[];
extern char g_021CF884[];
extern char g_021CF8A8[];
extern char g_021CF8D0[];
extern char g_021CF8D8[];
extern char g_021CF8DC[];
extern char g_021CF900[];
extern char g_021CF92C[];
extern char g_021CF8E4[];








/*
 * sdk:      DWCi_EncSessionCompleteCallback (libdwcenc.TWL.HYB.a dwc_encsession.o)
 *
 * Closed (U58): the 20-byte secretkey copy is memcpy(tmpbuf, g_021CF7AC.secretkey, 20)
 * declared through a string.h header, so mwccarm inlines it as the rolled two-byte loop
 * and picks the object's source/dest pointer registers (r3 pool load, ip = stack+0x11).
 * A struct assignment spelled the same copy but swapped them, leaving 6 bytes differing.
 */
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
            if (g_021CF7AC.callback != 0 && !g_021CF7AC.callback((unsigned int *)buf, len)) {
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








/*
 * sdk:      DWCi_EncSessionEncrypt (libdwcenc.TWL.HYB.a(dwc_encsession.o))
 */
int func_021C9D9C(u8 *outbuf, u8 *header, u32 headerlen, u8 *srcbuf, u32 srclen)
{
    u8 *tmpbuf;
    u32 sum = 0;
    int i;

    tmpbuf = func_0205A16C(8, srclen + headerlen + 4);
    if (tmpbuf == 0)
        return 2;
    for (i = 0; i < (int)headerlen; i++)
        tmpbuf[4 + i] = header[i];
    for (i = 0; i < (int)srclen; i++)
        tmpbuf[4 + headerlen + i] = srcbuf[i];
    for (i = 0; i < (int)(srclen + headerlen); i++)
        sum += tmpbuf[4 + i];
    func_021C9890(sum);
    for (i = 0; i < (int)(srclen + headerlen); i++)
        tmpbuf[4 + i] ^= func_021C98A4();
    sum ^= g_021CF7AC.key4;
    tmpbuf[0] = (u8)(sum >> 24);
    tmpbuf[1] = (u8)(sum >> 16);
    tmpbuf[2] = (u8)(sum >> 8);
    tmpbuf[3] = (u8)sum;
    func_0217FA90((char *)tmpbuf, (char *)outbuf, srclen + headerlen + 4, 2);
    func_0205A1B0(8, tmpbuf, 0);
    outbuf[func_021C9858(srclen + headerlen + 4)] = 0;
    return 0;
}







/*
 * sdk:      DWCi_EncSessionInitialize (libdwcenc.TWL.HYB.a(dwc_encsession.o))
 */
void func_021C9EE4(int server, char *initdata)
{
    u32 randkey_1;
    u32 randkey_2;
    u32 randkey_3;
    u32 randkey_4;
    InitData *ptr;
    char secretkey[21];
    char buf[9] = {0};

    g_021CF7AC.reqid = -1;
    g_021CF7AC.request = 0;
    g_021CF7AC.hash = 0;
    g_021CF7AC.data = 0;
    g_021CF7AC.resbuf = 0;
    g_021CF7AC.resbuflen = 0;

    switch (server) {
    case 0:
        g_021CF7A8 = g_021CF85C;
        break;
    case 1:
        g_021CF7A8 = g_021CF884;
        break;
    case 2:
        g_021CF7A8 = g_021CF8A8;
        break;
    }

    ptr = (InitData *)initdata;
    func_02094860((u8 *)secretkey, (const u8 *)ptr->info.secretkey, 20);
    secretkey[20] = '\0';
    randkey_1 = func_02095EAC((u32)func_02094860((u8 *)buf, (const u8 *)ptr->info.key1, 8), 0, 16);
    randkey_2 = func_02095EAC((u32)func_02094860((u8 *)buf, (const u8 *)ptr->info.key2, 8), 0, 16);
    randkey_3 = func_02095EAC((u32)func_02094860((u8 *)buf, (const u8 *)ptr->info.key3, 8), 0, 16);
    randkey_4 = func_02095EAC((u32)func_02094860((u8 *)buf, (const u8 *)ptr->info.key4, 8), 0, 16);
    func_021C98E0(ptr->info.gamename, secretkey, randkey_1, randkey_2, randkey_3, randkey_4);
    func_021BF558(0);
    g_021CF7AC.state = 3;
    g_021CF7AC.isinitialized = 1;
}







void DWCi_EncSetError(void)
{
    if (!CTRDGi_IsTaskAvailable())
        DWCi_SetError(6, 0xFFFEA048);
    *(u32 *)0x021CF7AC = 1;
}







/*
 * The ProgressCallback pointer 0x021C9B60 (DWCi_EncSessionProgressCallback) was the
 * last blocker; it now has a catalog row and a matched body (w3_tools, 2026-09-29).
 *
 * sdk:      DWCi_EncSessionProcess (dwc_encsession.o)
 */
int func_021CA0A0(void)
{
    switch (g_021CF7AC.state) {
    case 1:
        func_021CA06C();
        break;
    case 4:
        g_021CF7AC.reqid = func_021BF6C4(g_021CF7AC.request, 0, 0, func_021C9B60, (void (*)(void))func_021C9B64, 0);
        if (g_021CF7AC.reqid >= 0) {
            g_021CF7AC.state = 5;
        } else {
            func_021CA06C();
        }
        break;
    case 5:
        if (func_021BF5B8() == 0) {
            func_021CA06C();
        }
        break;
    case 6:
        g_021CF7AC.reqid = func_021BF6C4(g_021CF7AC.request, 0, 0, func_021C9B60, (void (*)(void))func_021C9B64, 0);
        if (g_021CF7AC.reqid >= 0) {
            g_021CF7AC.state = 7;
        } else {
            func_021CA06C();
        }
        break;
    case 7:
        if (func_021BF5B8() == 0) {
            func_021CA06C();
        }
        break;
    case 8:
        break;
    }
    return g_021CF7AC.state;
}





/*
 * Cancels the armed resource and clears the 0x021CF7AC head word.
 */
void func_021CA188(void)
{
    int v = g_021CF7AC.reqid;
    if (v >= 0)
        func_021BF880(v);
    g_021CF7AC.state = 0;
}




/*
 * sdk:      DWCi_EncSessionShutdown (dwc_encsession.o)
 */
void func_021CA1B4(void)
{
    if (g_021CF7AC.isinitialized == 0) {
        return;
    }
    if (g_021CF7AC.request != 0) {
        DWC_Free(8, g_021CF7AC.request, 0);
        g_021CF7AC.request = 0;
    }
    if (g_021CF7AC.resbuf != 0) {
        DWCi_GsFree(g_021CF7AC.resbuf);
        g_021CF7AC.resbuflen = 0;
        g_021CF7AC.resbuf = 0;
    }
    func_021BF57C();
    g_021CF7AC.state = 2;
    g_021CF7AC.isinitialized = 0;
}




u32 DWCi_EncSessionGetResponse(u32 *out)
{
    *out = g_021CF7AC.decodedbuflen;
    return (u32)g_021CF7AC.decodedbuf;
}




/*
 * notes:    the block-scoped `p` (request pointer loaded once before strlen) is not a DWARF local; it is the spelling that keeps the load in r6 across the call. strlen is declared returning unsigned long, which gives the `strb r2, [r1, -r0]` form.
 *
 * sdk:      DWCi_EncSessionGetPrivateAsync (libdwcenc.TWL.HYB.a(dwc_encsession.o))
 */
int func_021CA240(char *url, long pid, void *data, u32 size, int (*cb)(u32 *, int), int reuseHash)
{
    PutHeader putheader;
    char buf[16];
    int res;

    if (g_021CF7AC.validated != 1)
        return 3;
    if (g_021CF7AC.request != 0) {
        func_0205A1B0(8, g_021CF7AC.request, 0);
        g_021CF7AC.request = 0;
    }
    g_021CF7AC.request = func_0205A16C(8,
        strlen(g_021CF7A8) + strlen(g_021CF7AC.gamename) + strlen(url)
        + strlen(g_021CF8DC) + func_02084F80(buf, 16, g_021CF8D8, pid)
        + strlen(g_021CF84C) + 40 + 1 + strlen(g_021CF8D0) + func_021C9858(size + 12));
    if (g_021CF7AC.request == 0)
        return 2;
    func_02084F40(g_021CF7AC.request, g_021CF8E4, g_021CF7A8, g_021CF7AC.gamename, url, pid, g_021CF900, g_021CF92C);
    {
        char *p = g_021CF7AC.request;
        g_021CF7AC.data = p + strlen(p);
    }
    g_021CF7AC.hash = g_021CF7AC.data - strlen(g_021CF8D0) - 40;
    putheader.pid = pid;
    putheader.size = size;
    res = func_021C9D9C((u8 *)g_021CF7AC.data, (u8 *)&putheader, 8, data, size);
    if (res == 2) {
        func_0205A1B0(8, g_021CF7AC.request, 0);
        g_021CF7AC.request = 0;
        return 2;
    }
    if (reuseHash) {
        func_02092344(g_021CF7AC.hash, g_021CF7AC.lastHash, 40);
        g_021CF7AC.state = 6;
    } else {
        g_021CF7AC.hash[-strlen(g_021CF84C)] = '\0';
        g_021CF7AC.state = 4;
    }
    g_021CF7AC.callback = cb;
    return 0;
}


/*
 * Forwards five arguments and a zero tail to func_021CA240.
 */
int func_021CA470(void *a, u32 b, void *c, u32 d, u32 e)
{
    return func_021CA240((char *)a, b, (void *)c, d, (int (*)(u32 *, int))e, 0);
}
