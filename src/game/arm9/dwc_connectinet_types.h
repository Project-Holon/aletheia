#ifndef GAME_ARM9_DWC_CONNECTINET_TYPES_H
#define GAME_ARM9_DWC_CONNECTINET_TYPES_H

typedef struct DWCApInfo {
    int aptype;
    int area;
    int security;
    char spotinfo[10];
    char essid[33];
    unsigned char bssid[6];
} DWCApInfo;

typedef struct DWCstInetControl {
    int ac_state;
    unsigned short state;
    unsigned short online;
    unsigned short dmaNo;
    unsigned short powerMode;
    long rwin;
    unsigned char wontExecuteEULACheck;
    unsigned char wontExecuteWDS;
    int processWDSstate;
    struct {
        unsigned char ssid[32];
        unsigned char wep[32];
        int wepMode;
        unsigned short mtu;
        char apSpotInfo[10];
    } nspotInfo;
} DWCstInetControl;

#endif
