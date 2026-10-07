/*
 * function: func_021C9EE4
 * address:  0x021C9EE4
 * packet:   pkt_ov114_021C9EE4
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_EncSessionInitialize (libdwcenc.TWL.HYB.a(dwc_encsession.o))
 *
 * symbols:
 *   func_02094860  0x02094860  arm
 *   func_02095EAC  0x02095EAC  arm
 *   func_021C98E0  0x021C98E0  arm  ov114
 *   func_021BF558  0x021BF558  arm  ov114
 *   g_021CF7AC  0x021CF7AC  data
 *   g_021CF7A8  0x021CF7A8  data
 *   g_021CF85C  0x021CF85C  data
 *   g_021CF884  0x021CF884  data
 *   g_021CF8A8  0x021CF8A8  data
 */

#include "../include/G_Session.h"

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

extern u8 *func_02094860(u8 *dest, const u8 *src, u32 n);
extern u32 func_02095EAC(u32 a0, u32 *a1, u32 mode);
extern int func_021C98E0(char *gamename, const char *secretkey, unsigned long key1, unsigned long key2, unsigned long key3, unsigned long key4);
extern int func_021BF558();
extern struct Session g_021CF7AC;
extern char *g_021CF7A8;
extern char g_021CF85C[];
extern char g_021CF884[];
extern char g_021CF8A8[];

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
