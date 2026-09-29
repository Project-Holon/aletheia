/*
 * function: func_021A7A40
 * address:  0x021A7A40
 * packet:   pkt_ov021_021A7A40
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT*
 *
 * Levers: the 2-byte struct returned by value (stack stores, reload of byte 0),
 * `*(g + idx + 1)` for the (g+idx)[1] address, and `const Tbl *` so the
 * t->hi load schedules above the first store.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Pair { u8 lo; u8 hi; } Pair;

typedef struct Tbl {
    u16 *keys;
    u8 *lo;
    u8 *hi;
    u8 *group;
    u32 limit;
    u32 count;
} Tbl;

Pair func_021A7A40(const Tbl *t, u32 idx, u32 key)
{
    Pair r;
    u8 *g;
    u32 n;
    u32 i;
    u32 end;

    g = t->group;
    n = t->count;
    i = g[idx];
    if (idx + 1 < n)
        end = *(g + idx + 1);
    else
        end = t->limit;
    end = end - 1;
    for (; i < end; i++) {
        if (t->keys[i + 1] > key)
            break;
    }
    r.lo = t->lo[i];
    r.hi = t->hi[i];
    return r;
}
