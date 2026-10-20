#ifndef IRC_TEXT_SYSTEM_TYPES_H
#define IRC_TEXT_SYSTEM_TYPES_H

/* Font, message data, print queue and word set of a screen (16 bytes). */
typedef struct IrcTextSystem {
    void *font;                      /* 0x00 */
    void *msgData;                   /* 0x04 */
    void *printQueue;                /* 0x08 */
    void *wordSet;                   /* 0x0C */
} IrcTextSystem;

#endif
