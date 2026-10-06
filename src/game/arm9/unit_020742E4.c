/*
 * file:     unit_020742E4.c
 * unit:     yes
 * function: func_020742E4, func_020742FC, func_0207430C, func_02074324,, func_0207457C, func_020745A4, func_0207466C, func_02074694, func_020746B0
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

struct Table {
    u32 count;
    u32 entries[1];
};

struct Header {
    char pad00[8];
    u32  offset_08;
    u32  offset_0c;
    u32  offset_10;
    u32  offset_14;
    u32  offset_18;
    u32  offset_1c;
};

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

typedef signed int     s32;

struct Context {
    char pad[0x34];
    char file[0x54];
    struct TableHeader *table;
    u32 unk8c;
    struct Header *header;
    int chunk_size;
};

extern int func_02078B44(struct FSFile *file, long offset, int origin);
extern s32 func_02078B70(struct FSFile *file, void *buffer, s32 length);
struct Context *func_020742E4(struct Context *val);
struct Context *func_020742FC(void);
void *func_0207430C(int index);
void *func_02074324(int index);
void *func_02074388(int index);
void *func_020743EC(int index);
void *func_02074450(int index);
void *func_020744B4(int index);
void *func_02074518(int index);
u32 func_0207457C(u32 idx);
int func_020745A4(u32 idx, void *dst_buf, int total_len, u32 offset);
u32 func_0207466C(u32 idx);
void func_02074694(u32 idx, u32 val);
void func_020746B0(int p0);
extern struct Context *ptr_0214EA50;

struct Context *func_020742E4(struct Context *val)
{
    struct Context *old = ptr_0214EA50;
    ptr_0214EA50 = val;
    return old;
}

struct Context *func_020742FC(void)
{
    return ptr_0214EA50;
}

void *func_0207430C(int index)
{
    void *ptr = func_02074324(index);
    if (ptr == 0) {
        return 0;
    }
    return (char *)ptr + 4;
}

void *func_02074324(int index)
{
    struct Context *g = ptr_0214EA50;
    struct Header *h = g->header;
    struct Table *t;
    u32 offset = h->offset_08;
    void *base;
    if (offset == 0) {
        t = 0;
    } else {
        t = (struct Table *)((char *)h + offset);
    }
    if (t == 0) {
        return 0;
    }
    if (index < 0) {
        return 0;
    }
    if ((u32)index >= t->count) {
        return 0;
    }
    offset = t->entries[index];
    base = g->header;
    if (offset == 0) {
        return 0;
    }
    return (char *)base + offset;
}

void *func_02074388(int index)
{
    struct Context *g = ptr_0214EA50;
    struct Header *h = g->header;
    struct Table *t;
    u32 offset = h->offset_0c;
    void *base;
    if (offset == 0) {
        t = 0;
    } else {
        t = (struct Table *)((char *)h + offset);
    }
    if (t == 0) {
        return 0;
    }
    if (index < 0) {
        return 0;
    }
    if ((u32)index >= t->count) {
        return 0;
    }
    offset = t->entries[index];
    base = g->header;
    if (offset == 0) {
        return 0;
    }
    return (char *)base + offset;
}

void *func_020743EC(int index)
{
    struct Context *g = ptr_0214EA50;
    struct Header *h = g->header;
    struct Table *t;
    u32 offset = h->offset_10;
    void *base;
    if (offset == 0) {
        t = 0;
    } else {
        t = (struct Table *)((char *)h + offset);
    }
    if (t == 0) {
        return 0;
    }
    if (index < 0) {
        return 0;
    }
    if ((u32)index >= t->count) {
        return 0;
    }
    offset = t->entries[index];
    base = g->header;
    if (offset == 0) {
        return 0;
    }
    return (char *)base + offset;
}

void *func_02074450(int index)
{
    struct Context *g = ptr_0214EA50;
    struct Header *h = g->header;
    struct Table *t;
    u32 offset = h->offset_14;
    void *base;
    if (offset == 0) {
        t = 0;
    } else {
        t = (struct Table *)((char *)h + offset);
    }
    if (t == 0) {
        return 0;
    }
    if (index < 0) {
        return 0;
    }
    if ((u32)index >= t->count) {
        return 0;
    }
    offset = t->entries[index];
    base = g->header;
    if (offset == 0) {
        return 0;
    }
    return (char *)base + offset;
}

void *func_020744B4(int index)
{
    struct Context *g = ptr_0214EA50;
    struct Header *h = g->header;
    struct Table *t;
    u32 offset = h->offset_18;
    void *base;
    if (offset == 0) {
        t = 0;
    } else {
        t = (struct Table *)((char *)h + offset);
    }
    if (t == 0) {
        return 0;
    }
    if (index < 0) {
        return 0;
    }
    if ((u32)index >= t->count) {
        return 0;
    }
    offset = t->entries[index];
    base = g->header;
    if (offset == 0) {
        return 0;
    }
    return (char *)base + offset;
}

void *func_02074518(int index)
{
    struct Context *g = ptr_0214EA50;
    struct Header *h = g->header;
    struct Table *t;
    u32 offset = h->offset_1c;
    void *base;
    if (offset == 0) {
        t = 0;
    } else {
        t = (struct Table *)((char *)h + offset);
    }
    if (t == 0) {
        return 0;
    }
    if (index < 0) {
        return 0;
    }
    if ((u32)index >= t->count) {
        return 0;
    }
    offset = t->entries[index];
    base = g->header;
    if (offset == 0) {
        return 0;
    }
    return (char *)base + offset;
}

u32 func_0207457C(u32 idx)
{
    struct Context *ctx = ptr_0214EA50;
    struct TableHeader *tbl = ctx->table;
    if (idx >= tbl->count) {
        return 0;
    }
    return tbl->entries[idx].size;
}

int func_020745A4(u32 idx, void *dst_buf, int total_len, u32 offset)
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

u32 func_0207466C(u32 idx)
{
    struct Context *ctx = ptr_0214EA50;
    struct TableHeader *tbl = ctx->table;
    if (idx >= tbl->count) {
        return 0;
    }
    return tbl->entries[idx].field8;
}

void func_02074694(u32 idx, u32 val)
{
    struct Context *ctx = ptr_0214EA50;
    struct TableHeader *tbl = ctx->table;
    tbl->entries[idx].field8 = val;
}

void func_020746B0(int p0){ *(int *)((*(int *)(0x214EA50) + 148)) = (int)p0; }
