#ifndef OV107_MB_PARENT_H
#define OV107_MB_PARENT_H
/*
 * Parent-side multiboot work area (NitroSDK MB library), shared by the
 * ov107 translation units mb_parent and mb_wm_base.  The pointer at
 * 0x021F6FA0 (mbc) points at an MBCommPWork; the same block is the
 * MB_CommCommonWork that WmBase.ext points at.
 */

#include "../types.h"

#include "../sdk_mb.h"

typedef struct MBGameInfo {
    u8 pad0[0x14];
    u32 ggid;                                   /* 0x14 */
    u8 maxPlayerNum;                            /* 0x18 */
    u8 pad19[0x4DC - 0x19];
} MBGameInfo;

typedef struct MbDownloadFileInfoHeader {
    u32 arm9EntryAddr;
    u32 arm7EntryAddr;
    u32 reserved;
} MbDownloadFileInfoHeader;

/* per-file parent state, 0x5D4 bytes */
typedef struct MBiParentFileInfo {
    union {
        MbDownloadFileInfoHeader header;        /* 0x000 */
        u8 dl_fileinfo[0xE4];
    };
    union {
        MBGameInfo game_info;                   /* 0x0E4 */
        struct {
            u8 pad0E4[0x5A4 - 0xE4];
            MB_BlockInfoTable blockinfo_table;  /* 0x5A4 */
            MBGameInfo *game_info_ptr;          /* 0x5B8 */
            u32 pad5BC;
        };
    };
    u16 currentb;                               /* 0x5C0 */
    u16 nextb;                                  /* 0x5C2 */
    u16 pollbmp;                                /* 0x5C4 */
    u16 gameinfo_child_bmp;                     /* 0x5C6 */
    u16 gameinfo_changed_bmp;                   /* 0x5C8 */
    u8 active;                                  /* 0x5CA */
    u8 update;                                  /* 0x5CB */
    MBiCacheList *cache_list;                   /* 0x5CC */
    u32 *card_mapping;                          /* 0x5D0 */
} MBiParentFileInfo;

typedef struct MB_CommCommonWork {
    u32 sendbuf[256];                           /* 0x0000 */
    u32 recvbuf[960];                           /* 0x0400 */
    MBUserInfo user;                            /* 0x1300 */
    u16 isMbInitialized;                        /* 0x1316 */
    int block_size_max;                         /* 0x1318 */
    int start_mp_busy;                          /* 0x131C */
    int is_started_ex;                          /* 0x1320 */
} MB_CommCommonWork;

#include "../ov107/mb_block_types.h"

typedef void (*MBCommPStateCallback)(u16 child_aid, u32 status, void *arg);

typedef struct MBCommPWork {
    MB_CommCommonWork common;                   /* 0x0000 */
    u8 pad1324[0x1340 - sizeof(MB_CommCommonWork)];
    MBUserInfo childUser[15];                   /* 0x1340 */
    u16 childversion[15];                       /* 0x148A */
    u32 childggid[15];                          /* 0x14A8 */
    MBCommPStateCallback parent_callback;       /* 0x14E4 */
    int p_comm_state[15];                       /* 0x14E8 */
    u8 file_num;                                /* 0x1524 */
    u8 cur_fileid;                              /* 0x1525 */
    s8 fileid_of_child[15];                     /* 0x1526 */
    u8 child_num;                               /* 0x1535 */
    u16 child_entry_bmp;                        /* 0x1536 */
    u8 pad1538[0x1754 - 0x1538];
    u16 req2child[15];                          /* 0x1754 */
    MBUserInfo childUserCopy;                   /* 0x1772 */
    MBiParentFileInfo fileinfo[16];             /* 0x1788 */
    u8 pad74C8[0x7CE0 - 0x74C8];
    MBiTaskInfo cur_task;                       /* 0x7CE0 */
} MBCommPWork;

extern MB_CommCommonWork *mbc;
#define pPwork ((MBCommPWork *)mbc)

void *MB_CommGetChildUser(unsigned short child_aid);
int MB_CommIsBootable(unsigned short child_aid);
int MB_CommResponseRequest(unsigned short child_aid, int ack);
void MBi_CommChangeParentState(unsigned short child, int state, void *arg);
void MBi_CommChangeParentStateCallbackOnly(u16 child, int state, void *arg);
void MBi_CommParentCallback(u16 type, void *arg);
void MBi_CommParentRecvData(void *arg);
int MBi_CommParentSendMsg(u8 type, u16 pollbmp);
int MBi_CommParentSendDLFileInfo(void);
void MBi_ReloadCache(MBiTaskInfo *p_task);
int MBi_CommParentSendBlock(void);
void MBi_calc_sendblock(u8 file_id);
u16 MBi_calc_nextsendblock(unsigned long next_block, unsigned long next_block_req);
BOOL IsChildAidValid(u16 child_aid);
void MBi_CommCallParentError(u16 aid, u16 errcode);

#endif
