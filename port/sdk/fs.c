/*
 * port/sdk/fs.c -- the FS module shim: FS_SeekFile, FS_ReadFile,
 * FS_CloseFile onto the host's stdio.
 *
 * These three are the SDK entry points the matched archive readers call.
 * layout/symbols_sdk.txt names them by address:
 *
 *     02078A80  FS_CloseFile   TwlSDK/libfs.TWL.HYB.a(fs_file.o)
 *     02078B44  FS_SeekFile    TwlSDK/libfs.TWL.HYB.a(fs_file.o)
 *     02078B70  FS_ReadFile    TwlSDK/libfs.TWL.HYB.a(fs_file.o)
 *
 * and the matched C spells them as ordinary externs at those addresses, so
 * the port must define both the SDK name and the `func_0207....` alias the
 * matched sources declare.  The alias is a one-line forwarder rather than a
 * second definition, so there is exactly one implementation.
 *
 * The object the matched code hands us is its own `struct ArcFile`, whose
 * first 0x48 bytes are the SDK's FSFile.  We own those 0x48 bytes and lay a
 * small record of our own into them.  Two constraints decide the layout:
 *
 *   - it must be at most 0x48 bytes;
 *   - it must not need more than 4-byte alignment, because the game's struct
 *     is 4-aligned (u8[0x48], u32, u16, u16) and a host FILE* wants 8.
 *
 * So the record stores an *index* into a small table of open FILE*s, never a
 * pointer.  That is what makes the same struct work unchanged on an LP64
 * host and on the 32-bit DS.
 */

#include <stdio.h>
#include <string.h>

#include "port.h"

#define BW_FS_MAGIC     0x42574653u  /* 'BWFS' */
#define BW_FS_MAX_OPEN  32

typedef struct BwFsRecord {
    u32 magic;
    u32 slot;      /* 1-based index into g_slots; 0 means closed */
    u32 pos;       /* current byte offset                        */
    u32 size;      /* file length in bytes                       */
    u32 reserved[(BW_FSFILE_SIZE / 4) - 4];
} BwFsRecord;

/* The whole point of the index-not-pointer choice; check it, do not hope. */
typedef char bw_fs_record_fits[(sizeof(BwFsRecord) == BW_FSFILE_SIZE) ? 1 : -1];

static FILE *g_slots[BW_FS_MAX_OPEN];

static BwFsRecord *record_of(void *file)
{
    BwFsRecord *r = (BwFsRecord *)file;

    if (r == NULL || r->magic != BW_FS_MAGIC || r->slot == 0 ||
        r->slot > BW_FS_MAX_OPEN || g_slots[r->slot - 1] == NULL) {
        bw_panic("FS", 0, "operation on a file that is not open");
    }
    return r;
}

/*
 * Port-side open.  The SDK's FS_OpenFile takes a NitroFS path through a
 * global archive table that is not decompiled yet, so the port opens by host
 * path and the callers that need a NitroFS name go through bw_data_path.
 */
int bw_fs_open(void *file, const char *host_path)
{
    BwFsRecord *r = (BwFsRecord *)file;
    FILE *fp;
    long end;
    u32 i;

    memset(r, 0, sizeof(*r));

    fp = fopen(host_path, "rb");
    if (fp == NULL) {
        return -1;
    }
    if (fseek(fp, 0, SEEK_END) != 0) {
        fclose(fp);
        return -1;
    }
    end = ftell(fp);
    if (end < 0) {
        fclose(fp);
        return -1;
    }
    rewind(fp);

    for (i = 0; i < BW_FS_MAX_OPEN; i++) {
        if (g_slots[i] == NULL) {
            g_slots[i] = fp;
            r->magic = BW_FS_MAGIC;
            r->slot = i + 1;
            r->pos = 0;
            r->size = (u32)end;
            return 0;
        }
    }
    fclose(fp);
    return -1;
}

u32 bw_fs_size(void *file)
{
    return record_of(file)->size;
}

/* ------------------------------------------------------------------ */
/* The SDK surface                                                     */
/* ------------------------------------------------------------------ */

/*
 * FS_SeekFile(file, offset, origin).  The matched callers only ever pass
 * origin 0, the SDK's FS_SEEK_SET; the other two are implemented anyway so a
 * later caller does not silently get the wrong one.
 */
#define BW_FS_SEEK_SET 0
#define BW_FS_SEEK_CUR 1
#define BW_FS_SEEK_END 2

s32 FS_SeekFile(void *file, s32 offset, u32 origin)
{
    BwFsRecord *r = record_of(file);
    long base;

    switch (origin) {
    case BW_FS_SEEK_SET: base = 0;            break;
    case BW_FS_SEEK_CUR: base = (long)r->pos;  break;
    case BW_FS_SEEK_END: base = (long)r->size; break;
    default:
        return 0;
    }
    if (base + offset < 0 || (u32)(base + offset) > r->size) {
        return 0;
    }
    r->pos = (u32)(base + offset);
    if (fseek(g_slots[r->slot - 1], (long)r->pos, SEEK_SET) != 0) {
        return 0;
    }
    return 1;
}

s32 FS_ReadFile(void *file, void *dst, s32 len)
{
    BwFsRecord *r = record_of(file);
    size_t got;

    if (len <= 0) {
        return 0;
    }
    if (r->pos + (u32)len > r->size) {
        len = (s32)(r->size - r->pos);
        if (len <= 0) {
            return 0;
        }
    }
    got = fread(dst, 1, (size_t)len, g_slots[r->slot - 1]);
    r->pos += (u32)got;
    return (s32)got;
}

s32 FS_CloseFile(void *file)
{
    BwFsRecord *r = (BwFsRecord *)file;

    if (r == NULL || r->magic != BW_FS_MAGIC || r->slot == 0 ||
        r->slot > BW_FS_MAX_OPEN) {
        return 0;
    }
    if (g_slots[r->slot - 1] != NULL) {
        fclose(g_slots[r->slot - 1]);
        g_slots[r->slot - 1] = NULL;
    }
    r->magic = 0;
    r->slot = 0;
    return 1;
}

/* ------------------------------------------------------------------ */
/* Address aliases the matched sources declare                          */
/* ------------------------------------------------------------------ */

/*
 * src/matched/func_02049578.c and src/matched/func_0204944C.c declare
 *
 *     extern void func_02078B44(struct ArcFile *arc, u32 pos, u32 origin);
 *     extern void func_02078B70(struct ArcFile *arc, void *dst, u32 size);
 *
 * and src/matched/func_02048D00.c declares func_02078A80.  Those are the SDK
 * functions above under the address spelling the matcher uses.
 */
void func_02078B44(void *file, u32 pos, u32 origin)
{
    (void)FS_SeekFile(file, (s32)pos, origin);
}

void func_02078B70(void *file, void *dst, u32 size)
{
    (void)FS_ReadFile(file, dst, (s32)size);
}

void func_02078A80(void *file)
{
    (void)FS_CloseFile(file);
}
