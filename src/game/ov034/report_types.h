#ifndef REPORT_TYPES_H
#define REPORT_TYPES_H

#include "../types.h"

struct BmpWin;

#define REPORT_WINDOW_COUNT 8
#define REPORT_PARTY_MAX 6
#define REPORT_BAR_PIECE_COUNT 10
#define REPORT_ACTOR_COUNT (REPORT_PARTY_MAX + REPORT_BAR_PIECE_COUNT)

/* shownFlags bits */
#define REPORT_SHOWN_ICONS 1
#define REPORT_SHOWN_WINDOWS 2
#define REPORT_SHOWN_ALL (REPORT_SHOWN_ICONS | REPORT_SHOWN_WINDOWS)

/* One text line of the save report: its BMP window and a print-in-progress flag. */
typedef struct ReportWindow {
    struct BmpWin *bmpWin;
    u8 printPending;       /* set after the text is queued, cleared once the print queue has drawn it */
} ReportWindow;

/*
 * Work of the save report panel (sub-screen mode 7, overlay 34). Allocated
 * with 0x130 bytes by REPORT_Create; the panel shows the party icons, the
 * trainer card lines and a progress bar that fills while the game saves.
 */
typedef struct ReportWork {
    void *gameSystem;
    void *saveControl;
    void *printQue;
    ReportWindow windows[REPORT_WINDOW_COUNT];
    void *font;
    void *unit;                              /* actor unit */
    void *actors[REPORT_ACTOR_COUNT];        /* 0..5 party icons, 6..15 progress bar pieces */
    void *partyCharRes[REPORT_PARTY_MAX];
    void *barCharRes;
    u32 spare0[8];
    void *partyPalRes;
    void *barPalRes;
    u32 spare1[11];
    void *partyCellRes;
    void *barCellRes;
    void *tcb;                               /* save animation task */
    int saveAnimRunning;
    u32 saveCountCurrent;
    u32 saveCountMax;
    int progressTarget;                      /* written size needed for the next bar piece (8.8 fixed point) */
    int progressStep;
    u16 barPiecesLit;
    u16 pieceFrameDelay;
    int shownFlags;                          /* REPORT_SHOWN_* */
    u16 heapId;
    u16 spare2;
} ReportWork;

#endif
