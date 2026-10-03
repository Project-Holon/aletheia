/*
 * function: func_021BBC58
 * address:  0x021BBC58
 * packet:   pkt_ov021_021BBC58
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BBC2C  0x021BBC2C  thumb  ov021
 *   func_0203EFC8  0x0203EFC8  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

/* 0x24-byte ring entry; the ring holds 30 of them (see func_021BBBD8) */
typedef struct Entry {
    u8 d[0x18];
    u16 h;       /* 0x18 */
    u8 key[6];   /* 0x1a, compared 6 bytes at a time */
    u8 pad[4];
} Entry;

typedef struct Ring {
    Entry e[30];
    u8 head;
    u8 tail;
    u8 pad2[2];
    int count;
} Ring;

Entry *func_021BBC2C(Ring *r, int i);
typedef signed int     s32;
s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);

/* A u16 `c` (not int/u32) is what stores c's spill before b's. */
int func_021BBC58(Ring *r, const void *b, u16 c)
{
    int i;
    Entry *p;

    for (i = r->count; i > r->count - 30; i--) {
        if (i < 0) return 1;
        p = func_021BBC2C(r, i);
        if (p != 0 && func_0203EFC8(p->key, b, 6) == 0) {
            if (p->h != c) return 1;
            return 0;
        }
    }
    return 1;
}
