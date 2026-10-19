#ifndef GAME_SDK_DWC_H
#define GAME_SDK_DWC_H

#include "types.h"

/*
 * DWC library (Nintendo WFC): the authentication, HTTP and network check
 * records shared between the connection modules.  Member names follow
 * auth/dwc_auth.h, auth/dwc_http.h, auth/dwc_svl.h and auth/dwc_netcheck.h.
 */

typedef void *(*DWCAuthAlloc)(unsigned long name, long size);
typedef void (*DWCAuthFree)(unsigned long name, void *ptr, long size);

typedef struct DWCAuthParam {
    unsigned short ingamesn[26];
    char gsbrcd[12];
    DWCAuthAlloc alloc;
    DWCAuthFree free;
} DWCAuthParam;

typedef struct DWCAuthResult {
    int returncode;
    char retcode[3 + 1];
    char datetime[14 + 1];
    char locator[50 + 1];
    char token[300 + 1];
    char challenge[8 + 1];
    char cookie[64 + 1];
} DWCAuthResult;

typedef struct DWCAuthHttpParam {
    char *url;
} DWCAuthHttpParam;

typedef struct DWCAuthWiFiId {
    unsigned long long uId;
    unsigned long long notAttestedId;
    unsigned long flg;
} DWCAuthWiFiId;

typedef struct DWCHttpBuffer {
    char *buffer;
    char *write_index;
    char *buffer_tail;
    unsigned long length;
} DWCHttpBuffer;

typedef struct DWCHttpLabelValue {
    char *label;
    char *value;
} DWCHttpLabelValue;

typedef struct DWCHttpParam {
    char *url;
    int action;
    unsigned long len_recvbuf;
    DWCAuthAlloc alloc;
    DWCAuthFree free;
    int ignoreca;
    int timeout;
} DWCHttpParam;

typedef struct DWCSvlResult {
    int status;
    char svlhost[64 + 1];
    char svltoken[300 + 1];
} DWCSvlResult;

typedef struct DWCNetcheckParam {
    DWCAuthAlloc alloc;
    DWCAuthFree free;
    void *bmworkarea;
} DWCNetcheckParam;

typedef struct DWCCalInfo {
    char userid[14];
    char passwd[7];
    char gamecd[5];
    char makercd[3];
    char unitcd[2];
    char macadr[13];
    char lang[3];
    char birth[5];
    char devtime[13];
    char bssid[13];
    char ssid[33];
    char apinfo[14];
    unsigned short devname[11];
} DWCCalInfo;

typedef struct tagDWCWiFiInfo {
    u64 attestedUserId;
    u64 notAttestedId;
    u16 pass;
    u16 randomHistory;
} DWCWiFiInfo;

#endif
