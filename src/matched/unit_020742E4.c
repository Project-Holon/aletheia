/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * function: func_020742E4, func_020742FC, func_0207430C, func_02074324,
 *           func_02074388, func_020743EC, func_02074450, func_020744B4,
 *           func_02074518
 * address:  0x020742E4
 * packet:   pkt_020742E4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   ptr_0214EA50  0x0214EA50  data
 *
 * Header and offset table lookups for resource dispatch.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020742E4.c \
 *       --addr 0x020742E4 --arm
 */

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

struct Global {
    char pad00[0x90];
    struct Header *header;
};

extern struct Global *ptr_0214EA50;

struct Global *func_020742E4(struct Global *val)
{
    struct Global *old = ptr_0214EA50;
    ptr_0214EA50 = val;
    return old;
}

struct Global *func_020742FC(void)
{
    return ptr_0214EA50;
}

extern void *func_02074324(int index);

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
    struct Global *g = ptr_0214EA50;
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
    struct Global *g = ptr_0214EA50;
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
    struct Global *g = ptr_0214EA50;
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
    struct Global *g = ptr_0214EA50;
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
    struct Global *g = ptr_0214EA50;
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
    struct Global *g = ptr_0214EA50;
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
