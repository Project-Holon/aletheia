#ifndef PLIST_MESSAGE_TYPES_H
#define PLIST_MESSAGE_TYPES_H

#include "../types.h"

/* Party list message box: one 0x38 byte object per list screen, created by
   PLIST_MESSAGE_Create and stored in PokelistWork.messageWindow (see
   pokelist_types.h). It owns the bottom text window, the text stream printer
   and the word set that fills the message placeholders. The including file
   defines u8, u16 and u32 first. */

struct BmpWin;
struct KeyCursor;
struct PrintSys;
struct Strbuf;
struct Tcbl;
struct TextStream;
struct WordSet;

/* Window shapes for PLIST_MESSAGE_OpenWindow; PLIST_MESSAGE_KIND_CLOSED is the idle state. */
enum {
    PLIST_MESSAGE_KIND_ONE_LINE = 0,
    PLIST_MESSAGE_KIND_ONE_LINE_SHORT = 1,
    PLIST_MESSAGE_KIND_BOX_NARROW = 2,
    PLIST_MESSAGE_KIND_BOX_WIDE = 3,
    PLIST_MESSAGE_KIND_CLOSED = 4
};

typedef struct PlistMessage {
    u32 windowKind;                   /* 0x00: PLIST_MESSAGE_KIND_* */
    struct BmpWin *window;            /* 0x04 */
    struct Tcbl *taskList;            /* 0x08: runs the text stream tasks */
    struct TextStream *stream;        /* 0x0C: running stream printer, 0 when none */
    struct Strbuf *streamText;        /* 0x10: text the stream prints, freed with it */
    struct KeyCursor *keyCursor;      /* 0x14: wait-for-key arrow */
    u8 streamWait[8];                 /* 0x18: stream wait state */
    u32 waitForKey;                   /* 0x20: 1 = stream ends on a key press */
    u32 printing;                     /* 0x24: 1 while the direct print runs */
    struct PrintSys *printSys;        /* 0x28 */
    struct WordSet *wordSet;          /* 0x2C: message placeholder values */
    u32 promptRequested;              /* 0x30: show the prompt icon after the print */
    u8 *prompt;                       /* 0x34: prompt icon object */
} PlistMessage;
typedef char PlistMessage_SizeCheck[(sizeof(PlistMessage) == 0x38) ? 1 : -1];

/* The DS code declares the stream callback as int (int); the SDK callback type is u8 (u32). */
#ifdef __MWERKS__
typedef int PlistStreamCbRet;
typedef int PlistStreamCbArg;
#else
typedef u8 PlistStreamCbRet;
typedef u32 PlistStreamCbArg;
#endif

#endif
