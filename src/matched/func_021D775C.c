/*
 * function: func_021D775C
 * address:  0x021D775C
 * packet:   pkt_021D775C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Looks up `key` in the u16 key array at g+4 (0x60 entries) and returns the
 * parallel u32 value at g+0xc4, or 0.  The guard wraps the `for (;;)` so the
 * three return-0 paths share one exit block; `i = count` before the guard is
 * what lets the first test fold into the loop's own bound.
 *
 * symbols:
 *   g_021F3ECC     0x021F3ECC  data
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 count;
    u16 keys[0x60];
    u32 vals[0x60];
} Tbl;

extern Tbl g_021F3ECC;

int func_021D775C(int key)
{
    Tbl *p = &g_021F3ECC;
    u32 i;

    i = p->count;
    if (i < 0x60) {
        for (;;) {
            if (p->keys[i] == key)
                return p->vals[i];
            if (p->keys[i] == 0)
                break;
            if (++i >= 0x60)
                break;
        }
    }
    return 0;
}
