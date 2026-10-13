/*
 * function: NNS_SndArcReadFile
 * address:  0x020745A4
 * packet:   pkt_0207457C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   ptr_0214EA50   0x0214EA50  data
 *   func_02078B44  0x02078B44  arm
 *   func_02078B70  0x02078B70  arm
 */

typedef unsigned int u32;

struct TableEntry {
    u32 offset;
    u32 size;
    u32 field8;
    u32 fieldC;
};

struct TableHeader {
    u32 unk0;
    u32 unk4;
    u32 count;
    struct TableEntry entries[1];
};

struct Context {
    char pad[0x34];
    char file[0x54];
    struct TableHeader *table;
    char pad90[8];
    int chunk_size;
};

extern struct Context *ptr_0214EA50;
typedef signed int     s32;
struct FSFile;
extern int func_02078B44(struct FSFile *file, long offset, int origin);
extern s32 func_02078B70(struct FSFile *file, void *buffer, s32 length);

int NNS_SndArcReadFile(u32 idx, void *dst_buf, int total_len, u32 offset)
{
    struct Context *ctx = ptr_0214EA50;
    struct TableHeader *tbl = ctx->table;
    int read_bytes;
    int chunk_size;
    struct TableEntry *entry;

    if (idx >= tbl->count) {
        return -1;
    }
    chunk_size = ctx->chunk_size;
    entry = &tbl->entries[idx];
    if (chunk_size == 0) {
        chunk_size = total_len;
    }
    read_bytes = 0;
    if (total_len > 0) {
        do {
            u32 avail;
            int rem = total_len - read_bytes;
            int res;
            if (rem > chunk_size) {
                rem = chunk_size;
            }
            avail = entry->size - offset;
            if (rem > avail) {
                rem = avail;
            }
            if (rem == 0) {
                break;
            }
            if (!func_02078B44((struct FSFile *)ctx->file, entry->offset + offset, 0)) {
                return -1;
            }
            res = func_02078B70((struct FSFile *)ctx->file, dst_buf, rem);
            if (res < 0) {
                return res;
            }
            read_bytes += res;
            offset += res;
            dst_buf = (char *)dst_buf + res;
        } while (read_bytes < total_len);
    }
    return read_bytes;
}
