#ifndef BR_POKESEARCH_TYPES_H
#define BR_POKESEARCH_TYPES_H

/* The owner screen object handed to BR_POKESEARCH_CreateWork is the same record
 * as the ov184 BrDownloadOwner (sidebar, graphic, res, proc, net, zukanSource,
 * plus the downloadMode field ov185 does not read). It lives in
 * ../ov184/br_download_types.h so both regions use one definition. */
#include "../ov184/br_download_types.h"

/* Owner header for the Pokemon search (br_pokesearch) work structures of ov185.
 * The work object is allocated by BR_POKESEARCH_CreateWork (0x58 bytes); the
 * owner is the screen object handed in as the create-work argument. Fields that
 * two Obj views typed differently at one offset are a union. Pointer members are
 * void * because that is how every Obj view typed them. */

/* Pokemon search screen task work, 0x58 bytes. */
struct BrPokeSearchWork {
    union {
        void *search;                  /* 0x00 search screen from BR_POKESEARCH_Create */
        int searchHandle;
    } search;
    union {
        void *window;                  /* 0x04 prompt or message-box text window */
        int windowHandle;
    } window;
    unsigned short speciesId;          /* 0x08 chosen species id / download request key */
    unsigned short netRetry;           /* 0x0A retry counter of the network request */
    unsigned short listIndex;          /* 0x0C current list page index */
    unsigned short pad0E;              /* 0x0E alignment */
    union {
        void *profileScreen;           /* 0x10 trainer profile screen */
        int profileScreenHandle;
    } profileScreen;
    union {
        void *scene;                   /* 0x14 musical shot scene */
        int sceneHandle;
    } scene;
    union {
        void *backButton;              /* 0x18 back button of the current view */
        int backButtonHandle;
    } backButton;
    void *detailWin;                   /* 0x1C detail text window */
    int sidebarShown;                  /* 0x20 nonzero when the sidebar view is up */
    union {
        void *task;                    /* 0x24 BR_UTIL task driving the screen */
        int taskHandle;
    } task;
    union {
        void *oamData;                 /* 0x28 BMP OAM data of the sidebar */
        int oamHandle;
    } oamData;
    union {
        unsigned int printQue;         /* 0x2C print queue */
        int printQueHandle;
        void *printQuePtr;
    } printQue;
    unsigned short heapId;             /* 0x30 heap id of the work */
    unsigned short pad32;              /* 0x32 alignment */
    void *owner;                       /* 0x34 owner screen object */
    union {
        int listParam;                 /* 0x38 list parameter */
        void *listParamPtr;
    } listParam;
    union {
        void *tapFx;                   /* 0x3C tap effect */
        int tapFxHandle;
        void *tapFxPtr;
    } tapFx;
    void *table[5];                    /* 0x40 indexed pointer table */
    int count;                         /* 0x54 entry count */
};

/* Owner screen object handed to BR_POKESEARCH_CreateWork: struct BrDownloadOwner
 * from ../ov184/br_download_types.h (the shared ov184/ov185 record). */

#endif
