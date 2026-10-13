#ifndef OV099_WIFI_CLUB_TYPES_H
#define OV099_WIFI_CLUB_TYPES_H

/* Types shared by the Wi-Fi club state handlers (the part of wifi_club.c that
 * drives the menu state machine and the screen setup/teardown).  The work
 * object itself (WifiClubWork) lives in wifi_club_work.h. */

#include "wifi_club_work.h"




/* Friend request record handed to the accept-friend callback. */
typedef struct WifiClubFriendRequest {
    u8 pad00[8];
    WifiClubPlayerStatus *status;  /* 0x08 */
} WifiClubFriendRequest;

/* Message the local console sends to the peer when it picks a seat (command 0xA03). */
typedef struct WifiClubSeatRequest {
    u16 phase;
    u16 peerSeat;
} WifiClubSeatRequest;

/* Display registers set up by the club screen: filled from rodata and passed to the BG system. */
typedef struct WifiClubDispConfig {
    u32 mainMode;
    u32 mainBgMode;
    u32 subMode;
    u32 subBgMode;
} WifiClubDispConfig;

typedef struct WifiClubBgTemplate {
    u32 x;
    u32 y;
    u32 bufferSize;
    u32 baseTile;
    u8 screenSize;
    u8 colorMode;
    u8 screenBase;
    u8 charBase;
    u32 charSize;
    u8 priority;
    u8 areaOver;
    u8 dummy;
    u8 mosaic;
    u32 affineParam;
} WifiClubBgTemplate;

/* Parameter block passed to the net session start (d_021C3B9C), only the heap size is written here. */
typedef struct WifiClubNetInit {
    u8 pad00[0x48];
    int heapSize;                  /* 0x48 */
} WifiClubNetInit;

#define WIFICLUB_HEAP_ID 0x21
#define WIFICLUB_PEER_SLOT_COUNT 33
#define WIFICLUB_SLOT_COUNT 32

/* Choice message the peer sends when it picks a member (command 0xA05). */
/* Message sent to the peer in command 0xA03: the local phase, the seat and a value. */
typedef struct WifiClubChoiceMessage {
    u16 phase;
    u16 seat;
    u32 value;
} WifiClubChoiceMessage;

typedef struct WifiClubPeerChoice {
    u16 memberId;
    u16 voiceChat;
    u32 value;
} WifiClubPeerChoice;

typedef struct WifiClubMessageTable {
    int v[5];
} WifiClubMessageTable;

typedef struct WifiClubRuleTable {
    u32 v[8];
} WifiClubRuleTable;

#endif
