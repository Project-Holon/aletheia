#ifndef GAME_SDK_MB_H
#define GAME_SDK_MB_H

#include "types.h"

/*
 * Multiboot library of the SDK (mb module): user and game records, block table
 * and the file cache.
 */

typedef struct MBGameRegistry {
    char *romFilePathp;
    u16 *gameNamep;
    u16 *gameIntroductionp;
    char *iconCharPathp;
    char *iconPalettePathp;
    u32 ggid;
    u8 maxPlayerNum;
    u8 pad[3];
    u8 userParam[32];
} MBGameRegistry;

typedef struct MBUserInfo {
    u8 favoriteColor : 4;
    u8 playerNo : 4;
    u8 nameLength;
    u16 name[10];
} MBUserInfo;

typedef struct {
    u32 child_address;
    u32 size;
    u32 offset;
    u8 segment_no;
    u8 pad[3];
} MB_BlockInfo;

typedef struct
{
    u32 seg_src_offset[3];
    u16 seg_head_blockno[3];
    u16 block_num;
}
MB_BlockInfoTable;

typedef struct {
    u32 src;
    u32 len;
    void *ptr;
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
    unsigned active : 1;
    unsigned priority : 31;
    void (*volatile task)(struct MBiTaskInfo *);
    void (*callback)(struct MBiTaskInfo *);
    u32 param[4];
} MBiTaskInfo;

#endif
