#ifndef OV107_MB_PARENT_H
#define OV107_MB_PARENT_H
/*
 * Parent-side multiboot work area (NitroSDK MB library), shared by the
 * ov107 translation units unit_021F1B3C and unit_021F4560.  The pointer at
 * 0x021F6FA0 (mbc) points at an MBCommPWork; the same block is the
 * MB_CommCommonWork that WmBase.ext points at.
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef signed int s32;
typedef int BOOL;

typedef struct MBUserInfo {
    u8 favoriteColour : 4;
    u8 playerNo : 4;
    u8 nameLength;
    u16 name[10];
} MBUserInfo;

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

typedef struct MB_BlockInfoTable {
    u32 seg_src_offset[3];
    u16 seg_head_blockno[3];
    u16 block_num;
} MB_BlockInfoTable;

typedef struct MBiCacheInfo {
    u32 src;
    u32 len;
    u8 *ptr;
    u32 state;
} MBiCacheInfo;

typedef struct MBiCacheList {
    u32 lifetime;
    u32 recent;
    MBiCacheInfo *p_list;
    u32 size;
    char arc_name[4];
    u32 arc_name_len;
    void *arc_pointer;
    u8 reserved[20];
    MBiCacheInfo list[4];
} MBiCacheList;

typedef struct MBiTaskInfo {
    struct MBiTaskInfo *next;
    u32 priority;
    void (*task)(struct MBiTaskInfo *);
    void (*callback)(struct MBiTaskInfo *);
    u32 param[4];
} MBiTaskInfo;

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

typedef struct MBCommParentBlockHeader {
    u8 type;
    u8 pad1;
    u16 fid;
    u16 seqno;
} MBCommParentBlockHeader;

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

#endif
