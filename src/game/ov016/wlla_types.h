#ifndef GAME_OV016_WLLA_TYPES_H
#define GAME_OV016_WLLA_TYPES_H

/* Wireless LAN link types of the AOSS library. */

typedef struct wlla_ssid {
    unsigned long Len;
    unsigned char Ssid[32];
} WLLA_SSID;

typedef struct wlla_key {
    unsigned long Len;
    unsigned char Key[16];
} WLLA_KEY;

typedef struct wlla_connect_param {
    WLLA_SSID     Ssid;
    unsigned long AuthAlgo;
    WLLA_KEY      Key;
} WLLA_CONNECT_PARAM;

typedef struct wlla_rateset {
    unsigned long Count;
    unsigned char Rate[16];
} WLLA_RATESET;

typedef struct wlla_bss_info {
    WLLA_SSID     Ssid;
    unsigned long Channel;
    unsigned long Noise;
    unsigned long Signal;
    unsigned char Bssid[6];
    WLLA_RATESET  SupportRates;
    unsigned long BeaconPeriod;
    unsigned long Capability;
} WLLA_BSS_INFO;

typedef struct wlla_bss_list {
    unsigned long Num;
    WLLA_BSS_INFO BssInfo[1];
} WLLA_BSS_LIST;

typedef struct wlla_link_stat {
    unsigned long LinkStat;
    WLLA_BSS_INFO BssInfo;
} WLLA_LINK_STAT;

#endif
