/*
 * function: func_0202ECB0
 * address:  0x0202ECB0
 * packet:   pkt_0202ECB0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02008530   0x02008530  thumb
 *   func_0200856C   0x0200856C  thumb
 *
 * Finds the first occupied slot whose two keys both match the reference
 * record's, or 0x14 when there is none.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202ECB0.c \
 *       --func func_0202ECB0 --addr 0x0202ECB0 --cc 1.1p1 --thumb
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

extern u32 func_02008530(void *p);
struct Sub0200852CObj;
extern u8 func_0200856C(const struct Sub0200852CObj *obj);

s32 func_0202ECB0(struct Slot *a0, void *b)
{
    u32 v0 = func_02008530(b);
    u32 v1 = func_0200856C(b);
    u32 i;

    for (i = 0; i < 0x14; i++) {
        u32 w, x;
        if (!a0[i].flag)
            break;
        w = func_02008530(&a0[i]);
        if (w == v0) {
            x = func_0200856C((const struct Sub0200852CObj *)(&a0[i]));
            if (x == v1)
                return i;
        }
    }
    return 0x14;
}
