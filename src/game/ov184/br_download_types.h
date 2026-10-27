#ifndef BR_DOWNLOAD_TYPES_H
#define BR_DOWNLOAD_TYPES_H

/* Struct views for br_download.c (ov184).
 *
 * BrDownloadWork is the task work that BR_DOWNLOAD_Create obtains from
 * PROCSYS_AllocProcWork(obj, 0x34, ...) and clears with MI_CpuFill8(p, 0, 0x34),
 * so its size is 0x34. Fields that two Obj views typed differently at one offset
 * but with the same width are a union.
 *
 * BrDownloadOwner is the screen object handed in as the create argument; it is
 * the pointer BR_DOWNLOAD_Create stores at work+0x30. Its fields 0x00..0x18 are
 * the same record as the ov185 BrPokeSearchOwner (sidebar, graphic, res, proc,
 * net, zukanSource); this file also uses 0x1C. */

struct BrUtilTask;
struct PrintQueue;
struct BrSidebar;
struct GameData;

struct BrDownloadOwner;

struct BrDownloadWork {
    void *scene;                   /* 0x00 musical shot scene */
    void *buttons[2];                  /* 0x04 the two download choice buttons */
    struct BrUtilTask *task;       /* 0x0C BR_UTIL task driving the screen */
    void *textWin;                     /* 0x10 message-box text window */
    void *handles[2];                  /* 0x14 the two BR_UTIL child handles */
    void *oamSys;                  /* 0x1C BMP OAM system */
    struct PrintQueue *printQue;       /* 0x20 print queue */
    unsigned short heapId;             /* 0x24 heap id of the work */
    unsigned short pad26;              /* 0x26 alignment */
    void *saveData;                /* 0x28 musical save data / scene source */
    unsigned int counter;              /* 0x2C network poll counter */
    struct BrDownloadOwner *owner;     /* 0x30 owner screen object */
};

typedef char BrDownloadWork_size_check[(sizeof(void *) != 4 || ((sizeof(struct BrDownloadWork) == 0x34))) ? 1 : -1];

struct BrDownloadOwner {
    void *fade;                        /* 0x00 fade work */
    struct BrSidebar *sidebar;         /* 0x04 sidebar handle */
    void *graphic;                 /* 0x08 BR graphic system */
    void *res;                     /* 0x0C shared BR resources */
    void *proc;                    /* 0x10 process-system context */
    void *net;                         /* 0x14 BR network work */
    struct GameData *zukanSource;      /* 0x18 zukan save source */
    int downloadMode;                  /* 0x1C 0 or 1, set when a choice is tapped */
};

#endif
