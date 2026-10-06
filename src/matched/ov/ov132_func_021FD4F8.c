/*
 * function: func_021FD4F8
 * address:  0x021FD4F8
 * packet:   pkt_ov132_021FD4F8
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * 2026-10-05 (wave D9): witness leaf for ov010 func_02156530. Searches the
 * four 48-byte records at +0x60 for one whose id byte (+0x12) equals the key
 * and whose state word (+4) is 1; returns its word at +0x1C, else 0.
 *
 * symbols:
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Rec {
    u8 pad00[4];
    int state;
    u8 pad08[0x0A];
    u8 id;
    u8 pad13[9];
    u32 f1c;
    u8 pad20[0x10];
};

struct Ctx {
    u8 pad00[0x60];
    struct Rec rec[4];
};

u32 func_021FD4F8(struct Ctx *p, u8 key)
{
    u8 i;

    for (i = 0; i < 4; i++) {
        if (key == p->rec[i].id && p->rec[i].state == 1)
            return p->rec[i].f1c;
    }
    return 0;
}
