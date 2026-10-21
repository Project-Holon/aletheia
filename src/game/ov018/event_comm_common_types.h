/*
 * Types of the comm event message task (event_comm_common.c, ov018): the
 * work block of the field event that shows one message and then closes.
 * Needs u8, u16, u32, s8, s16 and s32 and ../ov011/intrude_comm_types.h from the
 * including file.
 */
#ifndef UNIT_021828B8_TYPES_H
#define UNIT_021828B8_TYPES_H



#include "../ov011/intrude_comm_types.h"
#include "../types.h"
struct GameEvent;
struct FieldMap;
struct FldMmdl;
struct WordSet;
struct Strbuf;
struct MsgBank;
struct FieldMsgBg;
struct FieldMsgWin;
struct FieldSysWin;
struct FieldMenuFunc;

/* Text box of the event (0x30 bytes): formats a message through the word set and prints it with the field message background. */
typedef struct EventCommMsgBox {
    struct WordSet *wordSet;    /* 0x00: WORDSET with the player name in slot 0 */
    struct Strbuf *text;        /* 0x04: STRBUF that receives the expanded message */
    struct Strbuf *templateText;/* 0x08: STRBUF that receives the raw message */
    struct MsgBank *msgData;    /* 0x0C: message bank of the event (archive member 0x44) */
    struct MsgBank *msgDataB;   /* 0x10: message bank, member 0x42 */
    struct MsgBank *msgDataC;   /* 0x14: message bank, member 0x43 */
    struct FieldSysWin *printer;/* 0x18: running print of the message background, 0 = none */
    struct FieldMsgWin *listWindow;  /* 0x1C */
    struct FieldMsgWin *listWindowB; /* 0x20 */
    struct FieldMsgBg *fieldMsgbg;   /* 0x24: field message background system */
    u8 printing;                /* 0x28 */
    u8 pad29[3];
    struct FieldMenuFunc *choiceHandle; /* 0x2C: yes/no menu handle */
} EventCommMsgBox;

/*
 * Common head of the talk events (0x98 bytes). The talk and talked events
 * fill it; each follow-up event gets a copy at the start of its own work.
 * Shared with intrude_subdisp.c, which walks it through the request and
 * answer sequence.
 */
typedef struct EventCommCommonWork {
    u16 heapId;                     /* 0x00 */
    u16 pad02;
    struct FldMmdl *playerMmdl;     /* 0x04: field object of this player */
    struct FldMmdl *partnerMmdl;    /* 0x08: field object of the partner */
    struct FieldMap *fieldMap;      /* 0x0C */
    EventCommMsgBox msgBox;         /* 0x10 */
    u8 peerSlot;                    /* 0x40: net ID of the partner */
    u8 talkType;                    /* 0x41: selects the follow-up event */
    u8 msgIndex;                    /* 0x42: talk status of the partner, index into the message ID tables */
    u8 pad43;
    IntrudeMemberRecord member;     /* 0x44: mission record of the partner */
    u8 myStatus[0x20];              /* 0x78: MyStatus of the partner */
} EventCommCommonWork;

#endif
