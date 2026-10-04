/*
 * function: func_0202EC7C
 * address:  0x0202EC7C
 * packet:   pkt_0202EC44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0200856C  0x0200856C  thumb
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

struct Sub0200852CObj;
extern u8 func_0200856C(const struct Sub0200852CObj *obj);

s32 func_0202EC7C(struct Slot *a0, u32 a1)
{
    u32 i;

    for (i = 0; i < 0x14; i++) {
        u32 v;
        if (!a0[i].flag) break;
        v = func_0200856C((const struct Sub0200852CObj *)(&a0[i]));
        if (v == a1) return i;
    }
    return 0x14;
}
