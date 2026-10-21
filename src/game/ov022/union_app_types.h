/*
 * Types of the union room application (ov022 union_app.c).  The work is
 * allocated by UNION_APP_Create and stored in UnionRoomWork.app; the ov023
 * Oekaki code and the ov012 union main code call into it.
 * Needs u8, u32 from the including file.
 */
#ifndef UNION_APP_TYPES_H
#define UNION_APP_TYPES_H

#include "../types.h"

#define UNION_APP_WORK_SIZE        0x100
#define UNION_APP_MEMBER_MAX       5
#define UNION_APP_NO_MEMBER        0xFF

/* Phase of the application (UnionAppWork.phase). */
#define UNION_APP_PHASE_OPEN       0   /* joins are accepted */
#define UNION_APP_PHASE_CLOSED     1   /* joins are refused */
#define UNION_APP_PHASE_LIMITED    2   /* joins are accepted until limitedMax members joined */

/* Status block of a trainer, as copied by value (0x20 bytes, a MyStatus). */
typedef struct UnionAppStatusCopy {
    u32 word[8];
} UnionAppStatusCopy;

/* What one member sent when joining (0x28 bytes, same layout as UnionAppMessage in union_comm.c). */
typedef struct UnionAppEntry {
    UnionAppStatusCopy status; /* 0x00 MyStatus of the member */
    u8  mac[8];         /* 0x20 MAC address of the member */
} UnionAppEntry;

/* Called with the net id of a member and its entry. */
typedef void (*UnionAppMemberCallback)(int netId, UnionAppEntry *entry, void *arg);

/* The union application work (0x100 bytes, heap given to UNION_APP_Create). */
typedef struct UnionAppWork {
    u8  maxMembers;                 /* 0x00 how many members may join */
    u8  joinedBits;                 /* 0x01 one bit per net id: member is in the group */
    u8  pad02[2];
    u8  pendingBits;                /* 0x04 accepted, waiting for its entry */
    u8  pad05[2];
    u8  confirmBits;                /* 0x07 members whose join is to be confirmed */
    u8  pad08;
    u8  phase;                      /* 0x09 UNION_APP_PHASE_* */
    u8  limitedCount;               /* 0x0A members accepted in the limited phase */
    u8  limitedMax;                 /* 0x0B limit of the limited phase */
    u8  settingSendBits;            /* 0x0C net ids that get the setting block */
    u8  dataSendBits;               /* 0x0D net ids that get the own entry */
    u8  entryReceivedBits;          /* 0x0E net ids whose entry arrived */
    u8  quitRequestBits;            /* 0x0F net ids that asked to quit */
    u8  quitRequester;              /* 0x10 net id being served, 0xFF none */
    u8  quitAcceptTarget;           /* 0x11 net id to send the quit accept to, 0xFF none */
    u8  quitAccepted;               /* 0x12 the parent accepted the quit */
    u8  pad13;
    u32 ready;                      /* 0x14 set after UNION_APP_Create */
    u8  pad18[8];
    u32 resetRequest;               /* 0x20 the user asked to end */
    u32 resetRunning;               /* 0x24 the union room reset is running */
    u32 resetDone;                  /* 0x28 the union room reset has finished */
    UnionAppEntry entry[UNION_APP_MEMBER_MAX]; /* 0x2C, indexed by net id */
    UnionAppMemberCallback joinCallback;  /* 0xF4 a member joined */
    UnionAppMemberCallback leaveCallback; /* 0xF8 a member left */
    void *callbackArg;              /* 0xFC passed to both callbacks */
} UnionAppWork;

#endif
