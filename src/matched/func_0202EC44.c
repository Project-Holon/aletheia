/*
 * function: func_0202EC44
 * address:  0x0202EC44
 * packet:   pkt_0202EC44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200856C   0x0200856C  thumb
 *
 * Counts the occupied slots whose key matches, capped at five.  Same 0x28-byte
 * record as func_0202EC7C, matched next door.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202EC44.c \
 *       --func func_0202EC44 --addr 0x0202EC44 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef int           s32;

struct Slot {
    u8  pad[0x26];
    u8      : 4;
    u8 flag : 1;
    u8      : 3;
    u8  pad2;
};

extern u32 func_0200856C(void *p);

s32 func_0202EC44(struct Slot *a0, u32 a1)
{
    u32 i;
    u32 n = 0;

    for (i = 0; i < 0x14; i++) {
        u32 v;
        if (!a0[i].flag)
            break;
        v = func_0200856C(&a0[i]);
        if (v == a1)
            n++;
    }

    if (n > 5)
        n = 5;
    return n;
}
