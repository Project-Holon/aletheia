/*
 * file:     nns_snd_arc_1.c
 * unit:     yes
 * function: NNS_SndArcSetCurrent, NNS_SndArcGetCurrent, NNS_SndArcGetSeqParam, NNS_SndArcGetSeqInfo,, NNS_SndArcGetFileSize, NNS_SndArcReadFile, NNS_SndArcGetFileAddress, NNS_SndArcSetFileAddress, NNS_SndArcSetReadChunkSize
 * address:  0x020742E4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   ptr_0214EA50  0x0214EA50  data
 *   func_02078B44  0x02078B44  arm
 *   func_02078B70  0x02078B70  arm
 */
struct FSFile;
typedef unsigned int u32;

struct SndArcInfoTable {
    u32 count;
    u32 entries[1];
};

struct SndArcInfoHeader {
    char pad00[8];
    u32  seqTableOffset;
    u32  seqArcTableOffset;
    u32  bankTableOffset;
    u32  waveArcTableOffset;
    u32  playerTableOffset;
    u32  groupTableOffset;
};

struct SndArcFileEntry {
    u32 offset;
    u32 size;
    u32 loadedData;
    u32 pad0c;
};

struct SndArcFileTable {
    u32 pad0;
    u32 pad4;
    u32 count;
    struct SndArcFileEntry entries[1];
};

typedef signed int     s32;

struct SndArc {
    char pad[0x34];
    char file[0x54];
    struct SndArcFileTable *fileTable;
    u32 pad8c;
    struct SndArcInfoHeader *infoHeader;
    int readChunkSize;
};

extern int func_02078B44(struct FSFile *file, long offset, int origin);
extern s32 func_02078B70(struct FSFile *file, void *buffer, s32 length);
struct SndArc *NNS_SndArcSetCurrent(struct SndArc *newArc);
struct SndArc *NNS_SndArcGetCurrent(void);
void *NNS_SndArcGetSeqParam(int entryNo);
void *NNS_SndArcGetSeqInfo(int entryNo);
void *NNS_SndArcGetSeqArcInfo(int entryNo);
void *NNS_SndArcGetBankInfo(int entryNo);
void *NNS_SndArcGetWaveArcInfo(int entryNo);
void *NNS_SndArcGetPlayerInfo(int entryNo);
void *NNS_SndArcGetGroupInfo(int entryNo);
u32 NNS_SndArcGetFileSize(u32 fileId);
int NNS_SndArcReadFile(u32 fileId, void *dst, int length, u32 offset);
u32 NNS_SndArcGetFileAddress(u32 fileId);
void NNS_SndArcSetFileAddress(u32 fileId, u32 address);
void NNS_SndArcSetReadChunkSize(int chunkSize);
extern struct SndArc *ptr_0214EA50;

struct SndArc *NNS_SndArcSetCurrent(struct SndArc *newArc)
{
    struct SndArc *previous = ptr_0214EA50;
    ptr_0214EA50 = newArc;
    return previous;
}

struct SndArc *NNS_SndArcGetCurrent(void)
{
    return ptr_0214EA50;
}

void *NNS_SndArcGetSeqParam(int entryNo)
{
    void *ptr = NNS_SndArcGetSeqInfo(entryNo);
    if (ptr == 0) {
        return 0;
    }
    return (char *)ptr + 4;
}

void *NNS_SndArcGetSeqInfo(int entryNo)
{
    struct SndArc *arc = ptr_0214EA50;
    struct SndArcInfoHeader *infoHeader = arc->infoHeader;
    struct SndArcInfoTable *infoTable;
    u32 offset = infoHeader->seqTableOffset;
    void *infoBase;
    if (offset == 0) {
        infoTable = 0;
    } else {
        infoTable = (struct SndArcInfoTable *)((char *)infoHeader + offset);
    }
    if (infoTable == 0) {
        return 0;
    }
    if (entryNo < 0) {
        return 0;
    }
    if ((u32)entryNo >= infoTable->count) {
        return 0;
    }
    offset = infoTable->entries[entryNo];
    infoBase = arc->infoHeader;
    if (offset == 0) {
        return 0;
    }
    return (char *)infoBase + offset;
}

void *NNS_SndArcGetSeqArcInfo(int entryNo)
{
    struct SndArc *arc = ptr_0214EA50;
    struct SndArcInfoHeader *infoHeader = arc->infoHeader;
    struct SndArcInfoTable *infoTable;
    u32 offset = infoHeader->seqArcTableOffset;
    void *infoBase;
    if (offset == 0) {
        infoTable = 0;
    } else {
        infoTable = (struct SndArcInfoTable *)((char *)infoHeader + offset);
    }
    if (infoTable == 0) {
        return 0;
    }
    if (entryNo < 0) {
        return 0;
    }
    if ((u32)entryNo >= infoTable->count) {
        return 0;
    }
    offset = infoTable->entries[entryNo];
    infoBase = arc->infoHeader;
    if (offset == 0) {
        return 0;
    }
    return (char *)infoBase + offset;
}

void *NNS_SndArcGetBankInfo(int entryNo)
{
    struct SndArc *arc = ptr_0214EA50;
    struct SndArcInfoHeader *infoHeader = arc->infoHeader;
    struct SndArcInfoTable *infoTable;
    u32 offset = infoHeader->bankTableOffset;
    void *infoBase;
    if (offset == 0) {
        infoTable = 0;
    } else {
        infoTable = (struct SndArcInfoTable *)((char *)infoHeader + offset);
    }
    if (infoTable == 0) {
        return 0;
    }
    if (entryNo < 0) {
        return 0;
    }
    if ((u32)entryNo >= infoTable->count) {
        return 0;
    }
    offset = infoTable->entries[entryNo];
    infoBase = arc->infoHeader;
    if (offset == 0) {
        return 0;
    }
    return (char *)infoBase + offset;
}

void *NNS_SndArcGetWaveArcInfo(int entryNo)
{
    struct SndArc *arc = ptr_0214EA50;
    struct SndArcInfoHeader *infoHeader = arc->infoHeader;
    struct SndArcInfoTable *infoTable;
    u32 offset = infoHeader->waveArcTableOffset;
    void *infoBase;
    if (offset == 0) {
        infoTable = 0;
    } else {
        infoTable = (struct SndArcInfoTable *)((char *)infoHeader + offset);
    }
    if (infoTable == 0) {
        return 0;
    }
    if (entryNo < 0) {
        return 0;
    }
    if ((u32)entryNo >= infoTable->count) {
        return 0;
    }
    offset = infoTable->entries[entryNo];
    infoBase = arc->infoHeader;
    if (offset == 0) {
        return 0;
    }
    return (char *)infoBase + offset;
}

void *NNS_SndArcGetPlayerInfo(int entryNo)
{
    struct SndArc *arc = ptr_0214EA50;
    struct SndArcInfoHeader *infoHeader = arc->infoHeader;
    struct SndArcInfoTable *infoTable;
    u32 offset = infoHeader->playerTableOffset;
    void *infoBase;
    if (offset == 0) {
        infoTable = 0;
    } else {
        infoTable = (struct SndArcInfoTable *)((char *)infoHeader + offset);
    }
    if (infoTable == 0) {
        return 0;
    }
    if (entryNo < 0) {
        return 0;
    }
    if ((u32)entryNo >= infoTable->count) {
        return 0;
    }
    offset = infoTable->entries[entryNo];
    infoBase = arc->infoHeader;
    if (offset == 0) {
        return 0;
    }
    return (char *)infoBase + offset;
}

void *NNS_SndArcGetGroupInfo(int entryNo)
{
    struct SndArc *arc = ptr_0214EA50;
    struct SndArcInfoHeader *infoHeader = arc->infoHeader;
    struct SndArcInfoTable *infoTable;
    u32 offset = infoHeader->groupTableOffset;
    void *infoBase;
    if (offset == 0) {
        infoTable = 0;
    } else {
        infoTable = (struct SndArcInfoTable *)((char *)infoHeader + offset);
    }
    if (infoTable == 0) {
        return 0;
    }
    if (entryNo < 0) {
        return 0;
    }
    if ((u32)entryNo >= infoTable->count) {
        return 0;
    }
    offset = infoTable->entries[entryNo];
    infoBase = arc->infoHeader;
    if (offset == 0) {
        return 0;
    }
    return (char *)infoBase + offset;
}

u32 NNS_SndArcGetFileSize(u32 fileId)
{
    struct SndArc *arc = ptr_0214EA50;
    struct SndArcFileTable *fileTable = arc->fileTable;
    if (fileId >= fileTable->count) {
        return 0;
    }
    return fileTable->entries[fileId].size;
}

int NNS_SndArcReadFile(u32 fileId, void *dst, int length, u32 offset)
{
    struct SndArc *arc = ptr_0214EA50;
    struct SndArcFileTable *fileTable = arc->fileTable;
    int bytesRead;
    int readChunkSize;
    struct SndArcFileEntry *fileEntry;

    if (fileId >= fileTable->count) {
        return -1;
    }
    readChunkSize = arc->readChunkSize;
    fileEntry = &fileTable->entries[fileId];
    if (readChunkSize == 0) {
        readChunkSize = length;
    }
    bytesRead = 0;
    if (length > 0) {
        do {
            u32 entryRemaining;
            int chunkLen = length - bytesRead;
            int readResult;
            if (chunkLen > readChunkSize) {
                chunkLen = readChunkSize;
            }
            entryRemaining = fileEntry->size - offset;
            if (chunkLen > entryRemaining) {
                chunkLen = entryRemaining;
            }
            if (chunkLen == 0) {
                break;
            }
            if (!func_02078B44((struct FSFile *)arc->file, fileEntry->offset + offset, 0)) {
                return -1;
            }
            readResult = func_02078B70((struct FSFile *)arc->file, dst, chunkLen);
            if (readResult < 0) {
                return readResult;
            }
            bytesRead += readResult;
            offset += readResult;
            dst = (char *)dst + readResult;
        } while (bytesRead < length);
    }
    return bytesRead;
}

u32 NNS_SndArcGetFileAddress(u32 fileId)
{
    struct SndArc *arc = ptr_0214EA50;
    struct SndArcFileTable *fileTable = arc->fileTable;
    if (fileId >= fileTable->count) {
        return 0;
    }
    return fileTable->entries[fileId].loadedData;
}

void NNS_SndArcSetFileAddress(u32 fileId, u32 address)
{
    struct SndArc *arc = ptr_0214EA50;
    struct SndArcFileTable *fileTable = arc->fileTable;
    fileTable->entries[fileId].loadedData = address;
}

void NNS_SndArcSetReadChunkSize(int chunkSize){ *(int *)((*(int *)(0x214EA50) + 148)) = (int)chunkSize; }
