/*
 * nns_snd_arc_types.h: NitroSystem sound archive (SDAT) and sound heap types
 * for nns_snd_arc.c.
 */
#ifndef NNS_SND_ARC_TYPES_H
#define NNS_SND_ARC_TYPES_H

#include "../types.h"
#include "../arm9/snd_bank.h"

/* Load flags of the NNSi_SndArcLoad* functions. */
#define NNS_SND_ARC_LOAD_SEQ    0x1
#define NNS_SND_ARC_LOAD_BANK   0x2
#define NNS_SND_ARC_LOAD_WAVE   0x4
#define NNS_SND_ARC_LOAD_SEQARC 0x8

/* Item types of a group info entry. */
#define NNS_SND_ARC_GROUP_SEQ     0
#define NNS_SND_ARC_GROUP_BANK    1
#define NNS_SND_ARC_GROUP_WAVEARC 2
#define NNS_SND_ARC_GROUP_SEQARC  3

#include "../arm9/nns_fnd_types.h"

#include "../sdk_fs.h"

/* Callback run when a sound heap block is released. */
typedef void (*NNSSndHeapDisposeCallback)(void *buffer, u32 size, u32 data1, u32 data2);

/* Header of one allocation in a sound heap; the buffer follows at +0x20. */
typedef struct NNSiSndHeapBlock {
    NNSFndLink                link;
    u32                       size;
    NNSSndHeapDisposeCallback callback;
    u32                       data1;
    u32                       data2;
    u8                        pad18[8];
} NNSiSndHeapBlock;

/* One saved state of a sound heap: the blocks allocated since it. */
typedef struct NNSiSndHeapLevel {
    NNSFndList blockList;
    NNSFndLink link;
} NNSiSndHeapLevel;

typedef struct NNSSndHeap {
    NNSFndHeapHandle handle;
    NNSFndList       levelList;
} NNSSndHeap;

/* Sound archive info block: offsets of the per-kind info tables. */
typedef struct NNSSndArcInfoHeader {
    u8  pad00[8];
    u32 seqTableOffset;
    u32 seqArcTableOffset;
    u32 bankTableOffset;
    u32 waveArcTableOffset;
    u32 playerTableOffset;
    u32 groupTableOffset;
} NNSSndArcInfoHeader;

typedef struct NNSSndArcInfoTable {
    u32 count;
    u32 entries[1];
} NNSSndArcInfoTable;

typedef struct NNSSndArcFatEntry {
    u32 offset;
    u32 size;
    u32 loadedData;
    u32 pad0c;
} NNSSndArcFatEntry;

typedef struct NNSSndArcFatTable {
    u32 signature;
    u32 blockSize;
    u32 count;
    NNSSndArcFatEntry entries[1];
} NNSSndArcFatTable;

/* Opaque FS_ file object (0x48 bytes). */
/* FS file identifier: archive plus file index. */
/* Sound archive object (NNSSndArc), owned by this header. */
typedef struct NNSSndArc {
    u8  header[0x10];             /* 0x00 SDAT file header, copied from the file */
    u32 symbolOffset;             /* 0x10 */
    u32 symbolSize;               /* 0x14 */
    u32 infoOffset;               /* 0x18 */
    u32 infoSize;                 /* 0x1C */
    u32 fatOffset;                /* 0x20 */
    u32 fatSize;                  /* 0x24 */
    u8  pad28[8];                 /* 0x28 file block offset and size */
    u32 fileOpen;                 /* 0x30 */
    FSFile file;                  /* 0x34 */
    FSFileID fileId;              /* 0x7C */
    u8  pad84[4];
    NNSSndArcFatTable *fatBlock;  /* 0x88 */
    void *symbolBlock;            /* 0x8C */
    NNSSndArcInfoHeader *infoBlock; /* 0x90 */
    int readChunkSize;            /* 0x94 */
} NNSSndArc;

typedef struct NNSSndArcSeqInfo {
    u32 fileId;
    u16 bankNo;
} NNSSndArcSeqInfo;

typedef struct NNSSndArcSeqArcInfo {
    u32 fileId;
} NNSSndArcSeqArcInfo;

typedef struct NNSSndArcBankInfo {
    u32 fileId;
    u16 waveArcNo[4];
} NNSSndArcBankInfo;

/* Word 0 of a wave archive info entry: the file id and the load mode bit. */
typedef union NNSSndArcWaveArcInfo {
    unsigned word;
    struct {
        unsigned fileId : 24;
        unsigned isIndividual : 1;
        unsigned reserved : 7;
    } bits;
} NNSSndArcWaveArcInfo;

typedef struct NNSSndArcPlayerInfo {
    u8    playableSeqCount;
    u8    pad01;
    u16   allocatableChannel;
    void *heapSize;
} NNSSndArcPlayerInfo;

typedef struct NNSSndArcGroupItem {
    u8  type;
    u8  loadFlag;
    u16 pad02;
    u32 itemNo;
} NNSSndArcGroupItem;

typedef struct NNSSndArcGroupInfo {
    u32 count;
    NNSSndArcGroupItem items[1];
} NNSSndArcGroupInfo;

/* Cursor and record of the bank wave iterator. */
typedef struct SNDBankWaveIter {
    u32 position;
    u32 end;
} SNDBankWaveIter;

typedef struct SNDBankWaveRecord {
    u8  type;
    u8  pad01;
    u16 waveNo;
    u16 waveArcNo;
    u16 pad06;
    u32 pad08;
} SNDBankWaveRecord;

#endif
