/*
 * Types of the comm event message task (event_comm_common.c, ov018): the
 * work block of the field event that shows one message and then closes.
 * Needs u8, u16, u32, s8, s16 and s32 and ../ov011/intrude_comm_types.h from the
 * including file.
 */
#ifndef UNIT_021828B8_TYPES_H
#define UNIT_021828B8_TYPES_H

struct GameEvent;

/* Text box of the event (0x30 bytes): formats a message through the word set and prints it with the field message background. */
typedef struct EventCommMsgBox {
    void *wordSet;          /* 0x00: WORDSET with the player name in slot 0 */
    void *text;             /* 0x04: STRBUF that receives the expanded message */
    void *templateText;     /* 0x08: STRBUF that receives the raw message */
    void *msgData;          /* 0x0C: message bank of the event */
    void *msgDataB;         /* 0x10 */
    void *msgDataC;         /* 0x14 */
    void *printer;          /* 0x18: running print of the message background, 0 = none */
    void *listWindow;       /* 0x1C */
    void *listWindowB;      /* 0x20 */
    void *fieldMsgbg;       /* 0x24: field message background system */
    u8 printing;            /* 0x28 */
    u8 pad29[3];
    void *choiceHandle;     /* 0x2C */
} EventCommMsgBox;

#endif
