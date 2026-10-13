/*
 * file:     nns_snd_player_7.c
 * function: func_02072EE0
 * address:  0x02072EE0
 * packet:   pkt_02072EE0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_0214E018     0x0214E018  data
 *   func_02060614  0x02060614  arm
 *
 * PIN ../2.0/sp2, the "kept constants" tell (docs/FRONTEND-PINS.md).  The image
 * loads the list-head pool word TWICE: `ldr r0, [pc, #0x3c]` at 0x02072EEC feeds
 * the first func_02060614 call directly, and a second `ldr r4, [pc, #0x28]` at
 * 0x02072F00 materialises it again for the loop.  1.1p1 -O4,p CSEs the pair into
 * one hoisted `ldr r4, [pc, #0x44]` above the `mov r6, r0` and then spends a
 * `mov r0, r4` at each call: the same 84 bytes with the first eight words
 * permuted, 26 concrete bytes out.  The do/while and named-local-for-the-table
 * spellings are both far worse (76 bytes out).  Under the pin the same C is
 * 84 bytes, 0 mismatches.
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed short s16; typedef signed int s32;

struct Voice {
    u8  p00[0x34];
    u16 h34;
    u8  p36[2];
    u16 h38;
};

extern char g_0214E018[];
struct DList;
extern void *func_02060614(struct DList *list, void *elem);

s32 func_02072EE0(u32 tag)
{
    struct Voice *v;
    s32 n;

    n = 0;
    v = func_02060614((struct DList *)g_0214E018, 0);
    while (v != 0) {
        if (v->h34 == 1 && v->h38 == tag) {
            n++;
        }
        v = func_02060614((struct DList *)g_0214E018, v);
    }
    return n;
}
