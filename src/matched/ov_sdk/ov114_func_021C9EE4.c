/*
 * function: DWCi_EncSessionInitialize
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
 *   DWCi_EncValidateKey  0x021C98E0  arm  ov114
 *   DWC_InitGHTTP  0x021BF558  arm  ov114
 *   gDwcEncSession  0x021CF7AC  data
 *   gDwcEncServerUrl  0x021CF7A8  data
 *   sDwcEncSessionHttpGamestatsGsNintendowifiNet  0x021CF85C  data
 *   sDwcEncSessionHttpSdkdevGamespyComGames  0x021CF884  data
 *   sDwcEncSessionHttpIshikawaServebeerComGames  0x021CF8A8  data
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
extern int DWCi_EncValidateKey(char *gamename, const char *secretkey, unsigned long key1, unsigned long key2, unsigned long key3, unsigned long key4);
extern int DWC_InitGHTTP();
extern struct Session gDwcEncSession;
extern char *gDwcEncServerUrl;
extern char sDwcEncSessionHttpGamestatsGsNintendowifiNet[];
extern char sDwcEncSessionHttpSdkdevGamespyComGames[];
extern char sDwcEncSessionHttpIshikawaServebeerComGames[];

void DWCi_EncSessionInitialize(int server, char *initdata)
{
    u32 randkey_1;
    u32 randkey_2;
    u32 randkey_3;
    u32 randkey_4;
    InitData *ptr;
    char secretkey[21];
    char buf[9] = {0};

    gDwcEncSession.reqid = -1;
    gDwcEncSession.request = 0;
    gDwcEncSession.hash = 0;
    gDwcEncSession.data = 0;
    gDwcEncSession.resbuf = 0;
    gDwcEncSession.resbuflen = 0;

    switch (server) {
    case 0:
        gDwcEncServerUrl = sDwcEncSessionHttpGamestatsGsNintendowifiNet;
        break;
    case 1:
        gDwcEncServerUrl = sDwcEncSessionHttpSdkdevGamespyComGames;
        break;
    case 2:
        gDwcEncServerUrl = sDwcEncSessionHttpIshikawaServebeerComGames;
        break;
    }

    ptr = (InitData *)initdata;
    func_02094860((u8 *)secretkey, (const u8 *)ptr->info.secretkey, 20);
    secretkey[20] = '\0';
    randkey_1 = func_02095EAC((u32)func_02094860((u8 *)buf, (const u8 *)ptr->info.key1, 8), 0, 16);
    randkey_2 = func_02095EAC((u32)func_02094860((u8 *)buf, (const u8 *)ptr->info.key2, 8), 0, 16);
    randkey_3 = func_02095EAC((u32)func_02094860((u8 *)buf, (const u8 *)ptr->info.key3, 8), 0, 16);
    randkey_4 = func_02095EAC((u32)func_02094860((u8 *)buf, (const u8 *)ptr->info.key4, 8), 0, 16);
    DWCi_EncValidateKey(ptr->info.gamename, secretkey, randkey_1, randkey_2, randkey_3, randkey_4);
    DWC_InitGHTTP(0);
    gDwcEncSession.state = 3;
    gDwcEncSession.isinitialized = 1;
}
